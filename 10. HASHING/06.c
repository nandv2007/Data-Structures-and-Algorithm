#include <stdio.h>
#include <stdlib.h>
int global_m;
int compare_elements(const void* a, const void* b) {
    int val_a = *(int*)a;
    int val_b = *(int*)b;
    int rem_a = val_a % global_m;
    int rem_b = val_b % global_m;
    if (rem_a != rem_b) return rem_a - rem_b;
    return val_a - val_b;
}
int main() {
    int m, q, n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d %d", &m, &q, &n) == 3) {
        global_m = m;
        int* arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        qsort(arr, n, sizeof(int), compare_elements);
        int max_rating = 0;
        int left = 0;
        long long max_diff = 2LL * q * m;
        for (int right = 0; right < n; right++) {
            while (arr[right] % m != arr[left] % m || (long long)arr[right] - arr[left] > max_diff) {
                left++;
            }
            int current_window_size = right - left + 1;
            if (current_window_size > max_rating) {
                max_rating = current_window_size;
            }
        }
        printf("%d\n", max_rating);
        free(arr);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        long long *arr = (long long *)malloc(n * sizeof(long long));
        for (int i = 0; i < n; i++) {
            if (scanf("%lld", &arr[i]) != 1) break;
        }
        for (int i = 1; i < n; i++) {
            long long key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
            if (i == 3) {
                for (int k = 0; k < n; k++) {
                    printf("%lld%s", arr[k], (k == n - 1) ? "" : " ");
                }
                printf("\n");
            }
        }
        for (int k = 0; k < n; k++) {
            printf("%lld%s", arr[k], (k == n - 1) ? "" : " ");
        }
        printf("\n");
        free(arr);
    }
    return 0;
}

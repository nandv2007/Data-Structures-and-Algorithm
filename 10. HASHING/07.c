#include <stdio.h>
#include <stdlib.h>
#define MAXN 2005
long long arr[MAXN];
long long pref[MAXN];
long long* mss_values;
int compare_long_long(const void* a, const void* b) {
    long long val_a = *(long long*)a;
    long long val_b = *(long long*)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        pref[0] = 0;
        for (int i = 0; i < n; i++) {
            scanf("%lld", &arr[i]);
            pref[i + 1] = pref[i] + arr[i];
        }
        long long total_subarrays = (long long)n * (n + 1) / 2;
        mss_values = (long long*)malloc(total_subarrays * sizeof(long long));
        long long idx = 0;
        for (int j = 0; j < n; j++) {
            long long max_pref = pref[j + 1];
            long long current_mss = arr[j];
            for (int i = j; i >= 0; i--) {
                if (pref[i + 1] > max_pref) {
                    max_pref = pref[i + 1];
                }
                long long max_starting_at_i = max_pref - pref[i];
                if (i == j) {
                    current_mss = max_starting_at_i;
                } else {
                    if (max_starting_at_i > current_mss) {
                        current_mss = max_starting_at_i;
                    }
                }
                mss_values[idx++] = current_mss;
            }
        }
        qsort(mss_values, total_subarrays, sizeof(long long), compare_long_long);
        long long unique_sum = 0;
        if (total_subarrays > 0) {
            unique_sum += mss_values[0];
            for (long long i = 1; i < total_subarrays; i++) {
                if (mss_values[i] != mss_values[i - 1]) {
                    unique_sum += mss_values[i];
                }
            }
        }
        printf("%lld\n", unique_sum);
        free(mss_values);
    }
    return 0;
}
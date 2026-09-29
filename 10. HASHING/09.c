#include <stdio.h>
#include <stdlib.h>
#define MAX_VAL 1000005
int div_cnt[MAX_VAL];
int freq[MAX_VAL];
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    for (int i = 1; i < MAX_VAL; i++) {
        for (int j = i; j < MAX_VAL; j += i) {
            div_cnt[j]++;
        }
    }
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            int val;
            if (scanf("%d", &val) == 1) {
                freq[div_cnt[val]]++;
            }
        }
        long long total_pairs = 0;
        for (int i = 0; i < MAX_VAL; i++) {
            if (freq[i] > 1) {
                total_pairs += (long long)freq[i] * (freq[i] - 1) / 2;
            }
        }
        printf("%lld\n", total_pairs);
    }
    return 0;
}

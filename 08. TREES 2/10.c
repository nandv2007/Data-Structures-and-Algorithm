#include <stdio.h>
#include <stdlib.h>
#define MAX_CAP 1000005
int freq[MAX_CAP];
int main() {
    int m, n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &m, &n) == 2) {
        int max_val = 0;
        for (int i = 0; i < m; i++) {
            int x;
            if (scanf("%d", &x) == 1) {
                freq[x]++;
                if (x > max_val) max_val = x;
            }
        }
        long long max_profit = 0;
        int cur = max_val;
        while (n > 0 && cur > 0) {
            if (freq[cur] > 0) {
                long long take = (n < freq[cur]) ? n : freq[cur];
                max_profit += take * cur;
                freq[cur - 1] += take;
                freq[cur] -= take;
                n -= take;
            } else {
                cur--;
            }
        }
        printf("%lld\n", max_profit);
    }
    return 0;
}

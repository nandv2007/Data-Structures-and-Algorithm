#include <stdio.h>
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            long long d;
            if (scanf("%d %lld", &n, &d) == 2) {
                long long x[1005];
                for (int i = 0; i < n; i++) {
                    if (scanf("%lld", &x[i]) != 1) break;
                }
                long long curr_day = d;
                for (int i = n - 1; i >= 0; i--) {
                    curr_day = (curr_day / x[i]) * x[i];
                }
                printf("%lld\n", curr_day);
            }
        }
    }
    return 0;
}

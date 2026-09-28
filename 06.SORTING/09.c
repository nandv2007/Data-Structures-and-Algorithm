#include <stdio.h>
#include <string.h>
int max(int a, int b) { return (a > b) ? a : b; }
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n, k, p;
            if (scanf("%d %d %d", &n, &k, &p) != 3) break;
            int dp[1501];
            memset(dp, 0, sizeof(dp));
            for (int i = 0; i < n; i++) {
                int pref[31];
                pref[0] = 0;
                for (int j = 1; j <= k; j++) {
                    int val;
                    scanf("%d", &val);
                    pref[j] = pref[j - 1] + val;
                }
                for (int j = p; j >= 0; j--) {
                    for (int x = 1; x <= k && x <= j; x++) {
                        dp[j] = max(dp[j], dp[j - x] + pref[x]);
                    }
                }
            }
            printf("%d\n", dp[p]);
        }
    }
    return 0;
}

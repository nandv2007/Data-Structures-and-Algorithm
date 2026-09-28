#include <stdio.h>
#include <stdlib.h>
int pref[1005][1005];
int main() {
    int n, q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 1; i <= n; i++) {
            char row[1005];
            scanf("%s", row);
            for (int j = 1; j <= n; j++) {
                int tree = (row[j - 1] == '*') ? 1 : 0;
                pref[i][j] = tree + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }
        for (int i = 0; i < q; i++) {
            int y1, x1, y2, x2;
            if (scanf("%d %d %d %d", &y1, &x1, &y2, &x2) == 4) {
                int total = pref[y2][x2] - pref[y1 - 1][x2] - pref[y2][x1 - 1] + pref[y1 - 1][x1 - 1];
                printf("%d\n", total);
            }
        }
    }
    return 0;
}

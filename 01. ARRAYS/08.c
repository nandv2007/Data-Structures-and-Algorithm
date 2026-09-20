#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int t, n, m, i, j, x1, y1, x2, y2, sum;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        int C[n][m];
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                scanf("%d", &C[i][j]);
            }
        }
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        sum = 0;
        for (i = x1 - 1; i <= x2 - 1; i++) {
            for (j = y1 - 1; j <= y2 - 1; j++) {
                sum += C[i][j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
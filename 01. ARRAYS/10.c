#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a[100], i, j, temp, sum = 0, rank = 1;
        scanf("%d", &n);
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (a[i] > a[j]) {
                    temp = a[i];
                    a[i] = a[j];
                    a[j] = temp;
                }
            }
        }
        for (i = 0; i < n; i++) {
            if (i > 0 && a[i] != a[i - 1])
                rank++;
            sum += rank;
        }
        printf("%d\n", sum);
    }
    return 0;
}
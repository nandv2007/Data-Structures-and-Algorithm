#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int t, n, a[100];
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int start = 0;
        int found = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] <= a[i - 1]) {
                if (i - 1 > start) {
                    printf("(%d %d)", start, i - 1);
                    found = 1;
                }
                start = i;
            }
        }
        if (n - 1 > start) {
            printf("(%d %d)", start, n - 1);
            found = 1;
        }
        if (!found)
            printf("No Profit");
        printf("\n");
    }
    return 0;
}
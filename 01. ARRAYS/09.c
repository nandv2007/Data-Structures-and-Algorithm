#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int r, c, i, j;
    scanf("%d %d", &r, &c);
    int arr[r][c];
    int row[r], col[c];
    for (i = 0; i < r; i++)
        row[i] = 0;
    for (j = 0; j < c; j++)
        col[j] = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (row[i] == 1 || col[j] == 1)
                arr[i][j] = 1;
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
    return 0;
}
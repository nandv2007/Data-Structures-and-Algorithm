#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int p, q;
    scanf("%d %d", &p, &q);
    char a[1000][1000];
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            int layer = i;
            if (j < layer)
                layer = j;
            if (p - 1 - i < layer)
                layer = p - 1 - i;
            if (q - 1 - j < layer)
                layer = q - 1 - j;
            if (layer % 2 == 0)
                a[i][j] = 'Y';
            else
                a[i][j] = '0';
        }
    }
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            printf("%c", a[i][j]);
            if (j < q - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
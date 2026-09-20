#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int n, a[1000], temp;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < n - 1; i += 2) {
        temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    return 0;
}
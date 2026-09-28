#include <stdio.h>
#include <stdlib.h>
int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}
int main() {
    printf("CH.SC.U4CSE25248\n");
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) return 0;
        int *a = (int*)malloc(n * sizeof(int));
        int *b = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &a[i]) != 1) return 0;
        }
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &b[i]) != 1) return 0;
        }
        qsort(a, n, sizeof(int), compare_asc);
        qsort(b, n, sizeof(int), compare_desc);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % b[i] == 0 || b[i] % a[i] == 0) {
                count++;
            }
        }
        printf("%d\n", count);
        free(a);
        free(b);
    }
    return 0;
}
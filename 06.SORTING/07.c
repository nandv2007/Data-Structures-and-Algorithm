#include <stdio.h>
#include <stdlib.h>
int compare_asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int compare_desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            if (scanf("%d", &n) != 1) break;
            int* a = (int*)malloc(n * sizeof(int));
            int* b = (int*)malloc(n * sizeof(int));
            for (int i = 0; i < n; i++) scanf("%d", &a[i]);
            for (int i = 0; i < n; i++) scanf("%d", &b[i]);
            qsort(a, n, sizeof(int), compare_asc);
            qsort(b, n, sizeof(int), compare_desc);
            long long min_product = 0;
            for (int i = 0; i < n; i++) {
                min_product += (long long)a[i] * b[i];
            }
            printf("%lld\n", min_product);
            free(a);
            free(b);
        }
    }
    return 0;
}

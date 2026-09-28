#include <stdio.h>
#include <stdlib.h>
void insertionSort(long int *p,long int n) {
    long int i, j, key;
    for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j--;
        }
        p[j + 1] = key;
    }
}
int main() {
    printf("CH.SC.U4CSE25248\n");
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while(q--) {
        long int n, i, j;
        if (scanf("%ld", &n) != 1) return 0;
        long int *a = (long int*)malloc(n * sizeof(long int));
        long int *b = (long int*)malloc(n * sizeof(long int));
        for (i = 0; i < n; i++) {
            a[i] = 0;
            b[i] = 0;
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                long int val;
                if (scanf("%ld", &val) != 1) return 0;
                a[i] += val;
                b[j] += val;
            }
        }
        insertionSort(a, n);
        insertionSort(b, n);
        int possible = 1;
        for(i=0;i<n;i++) {
            if (a[i] != b[i]) {
                possible = 0;
                break;
            }
        }
        if (possible) printf("Possible\n");
        else printf("Impossible\n");
        free(a);
        free(b);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int code[200005];
int deg[200005];
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) deg[i] = 1;
        for (int i = 0; i < n - 2; i++) {
            scanf("%d", &code[i]);
            deg[code[i]]++;
        }
        int ptr = 1;
        while (deg[ptr] != 1) ptr++;
        int leaf = ptr;
        for (int i = 0; i < n - 2; i++) {
            int v = code[i];
            printf("%d %d\n", leaf, v);
            deg[leaf]--;
            deg[v]--;
            if (deg[v] == 1 && v < ptr) {
                leaf = v;
            } else {
                ptr++;
                while (deg[ptr] != 1) ptr++;
                leaf = ptr;
            }
        }
        int first = 1;
        for (int i = 1; i <= n; i++) {
            if (deg[i] == 1) {
                if (first) { printf("%d", i); first = 0; }
                else printf(" %d", i);
            }
        }
        printf("\n");
    }
    return 0;
}

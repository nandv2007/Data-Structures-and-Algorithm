#include <stdio.h>
#include <stdlib.h>
int tree[400005];
int arr[100005];
void build(int k, int l, int r) {
    if (l == r) { tree[k] = 1; return; }
    int mid = l + (r - l) / 2;
    build(2 * k, l, mid);
    build(2 * k + 1, mid + 1, r);
    tree[k] = tree[2 * k] + tree[2 * k + 1];
}
int query_and_remove(int k, int l, int r, int p) {
    tree[k]--;
    if (l == r) return arr[l];
    int mid = l + (r - l) / 2;
    if (tree[2 * k] >= p) return query_and_remove(2 * k, l, mid, p);
    else return query_and_remove(2 * k + 1, mid + 1, r, p - tree[2 * k]);
}
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 1; i <= n; i++) scanf("%d", &arr[i]);
        build(1, 1, n);
        for (int i = 0; i < n; i++) {
            int p;
            if (scanf("%d", &p) == 1) {
                printf("%d%s", query_and_remove(1, 1, n, p), (i == n - 1) ? "" : " ");
            }
        }
        printf("\n");
    }
    return 0;
}

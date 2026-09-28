#include <stdio.h>
#include <stdlib.h>
long long tree[400005];
long long arr[200005];
long long min_val(long long a, long long b) { return (a < b) ? a : b; }
void build(int node, int start, int end) {
    if (start == end) { tree[node] = arr[start]; return; }
    int mid = start + (end - start) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = min_val(tree[2 * node], tree[2 * node + 1]);
}
long long query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 2e18;
    if (l <= start && end <= r) return tree[node];
    int mid = start + (end - start) / 2;
    return min_val(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
}
int main() {
    int n, q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
        build(1, 1, n);
        for (int i = 0; i < q; i++) {
            int a, b;
            if (scanf("%d %d", &a, &b) == 2) {
                printf("%lld\n", query(1, 1, n, a, b));
            }
        }
    }
    return 0;
}

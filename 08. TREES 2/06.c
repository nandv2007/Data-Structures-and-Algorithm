#include <stdio.h>
#include <stdlib.h>
#define MAXN 200005
long long tree[4 * MAXN];
long long lazy_c[4 * MAXN];
long long lazy_x[4 * MAXN];
long long arr[MAXN];
long long get_sum_x(long long L, long long R) {
    return (L + R) * (R - L + 1) / 2;
}
void push(int node, int L, int R) {
    if (lazy_c[node] == 0 && lazy_x[node] == 0) return;
    int mid = L + (R - L) / 2;
    lazy_c[2 * node] += lazy_c[node];
    lazy_x[2 * node] += lazy_x[node];
    tree[2 * node] += lazy_c[node] * (mid - L + 1) + lazy_x[node] * get_sum_x(L, mid);
    lazy_c[2 * node + 1] += lazy_c[node];
    lazy_x[2 * node + 1] += lazy_x[node];
    tree[2 * node + 1] += lazy_c[node] * (R - mid) + lazy_x[node] * get_sum_x(mid + 1, R);
    lazy_c[node] = 0;
    lazy_x[node] = 0;
}
void build(int node, int L, int R) {
    if (L == R) { tree[node] = arr[L]; return; }
    int mid = L + (R - L) / 2;
    build(2 * node, L, mid);
    build(2 * node + 1, mid + 1, R);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update(int node, int L, int R, int ql, int qr, long long c, long long x) {
    if (ql <= L && R <= qr) {
        lazy_c[node] += c;
        lazy_x[node] += x;
        tree[node] += c * (R - L + 1) + x * get_sum_x(L, R);
        return;
    }
    push(node, L, R);
    int mid = L + (R - L) / 2;
    if (ql <= mid) update(2 * node, L, mid, ql, qr, c, x);
    if (qr > mid) update(2 * node + 1, mid + 1, R, ql, qr, c, x);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}
long long query(int node, int L, int R, int ql, int qr) {
    if (ql <= L && R <= qr) return tree[node];
    push(node, L, R);
    int mid = L + (R - L) / 2;
    long long res = 0;
    if (ql <= mid) res += query(2 * node, L, mid, ql, qr);
    if (qr > mid) res += query(2 * node + 1, mid + 1, R, ql, qr);
    return res;
}
int main() {
    int n, q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 1; i <= n; i++) scanf("%lld", &arr[i]);
        build(1, 1, n);
        for (int i = 0; i < q; i++) {
            int type, a, b;
            if (scanf("%d %d %d", &type, &a, &b) == 3) {
                if (type == 1) {
                    long long c = 1 - a;
                    long long x = 1;
                    update(1, 1, n, a, b, c, x);
                } else {
                    printf("%lld\n", query(1, 1, n, a, b));
                }
            }
        }
    }
    return 0;
}

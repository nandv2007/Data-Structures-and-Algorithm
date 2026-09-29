#include <stdio.h>
#include <stdlib.h>
typedef struct { long long val; int id; } Node;
Node min_h[200005], max_h[200005];
int min_sz = 0, max_sz = 0;
int active[200005];
long long ans[100005];
void push_min(Node n) {
    int i = ++min_sz;
    while (i > 1 && min_h[i / 2].val > n.val) { min_h[i] = min_h[i / 2]; i /= 2; }
    min_h[i] = n;
}
void push_max(Node n) {
    int i = ++max_sz;
    while (i > 1 && max_h[i / 2].val < n.val) { max_h[i] = max_h[i / 2]; i /= 2; }
    max_h[i] = n;
}
Node pop_min() {
    Node res = min_h[1], last = min_h[min_sz--];
    int i = 1, child;
    while (2 * i <= min_sz) {
        child = 2 * i;
        if (child < min_sz && min_h[child + 1].val < min_h[child].val) child++;
        if (last.val <= min_h[child].val) break;
        min_h[i] = min_h[child]; i = child;
    }
    min_h[i] = last;
    return res;
}
Node pop_max() {
    Node res = max_h[1], last = max_h[max_sz--];
    int i = 1, child;
    while (2 * i <= max_sz) {
        child = 2 * i;
        if (child < max_sz && max_h[child + 1].val > max_h[child].val) child++;
        if (last.val >= max_h[child].val) break;
        max_h[i] = max_h[child]; i = child;
    }
    max_h[i] = last;
    return res;
}
int main() {
    int n, q, id_counter = 0;
    long long current_sum = 0;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 0; i < n; i++) {
            long long v;
            scanf("%lld", &v);
            current_sum += v;
            Node n_node = {v, id_counter};
            active[id_counter++] = 1;
            push_min(n_node);
            push_max(n_node);
        }
        ans[0] = current_sum;
        for (int k = 1; k < n; k++) {
            while (min_sz > 0 && !active[min_h[1].id]) pop_min();
            Node min_node = pop_min();
            active[min_node.id] = 0;
            while (max_sz > 0 && !active[max_h[1].id]) pop_max();
            Node max_node = pop_max();
            active[max_node.id] = 0;
            long long diff = max_node.val - min_node.val;
            current_sum = current_sum - min_node.val - max_node.val + diff;
            ans[k] = current_sum;
            Node new_node = {diff, id_counter};
            active[id_counter++] = 1;
            push_min(new_node);
            push_max(new_node);
        }
        for (int i = 0; i < q; i++) {
            int k;
            scanf("%d", &k);
            printf("%lld\n", ans[k]);
        }
    }
    return 0;
}

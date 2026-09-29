#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int u, v;
    int l;
    int *tokens;
} Road;
int find_set(int i, int *parent) {
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i], parent);
}
int is_connected(int n, int m, Road *roads, int *excluded) {
    int *parent = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++) parent[i] = i;
    int components = n;
    for (int i = 0; i < m; i++) {
        int valid = 1;
        for (int j = 0; j < roads[i].l; j++) {
            if (excluded[roads[i].tokens[j]]) {
                valid = 0;
                break;
            }
        }
        if (valid) {
            int root_u = find_set(roads[i].u, parent);
            int root_v = find_set(roads[i].v, parent);
            if (root_u != root_v) {
                parent[root_u] = root_v;
                components--;
            }
        }
    }
    free(parent);
    return components == 1;
}
int main() {
    int n, m, k;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d %d", &n, &m, &k) == 3) {
        long long *c = (long long *)malloc((k + 1) * sizeof(long long));
        for (int i = 1; i <= k; i++) scanf("%lld", &c[i]);
        Road *roads = (Road *)malloc(m * sizeof(Road));
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &roads[i].u, &roads[i].v, &roads[i].l);
            roads[i].tokens = (int *)malloc(roads[i].l * sizeof(int));
            for (int j = 0; j < roads[i].l; j++) scanf("%d", &roads[i].tokens[j]);
        }
        int *excluded = (int *)calloc(k + 1, sizeof(int));
        if (!is_connected(n, m, roads, excluded)) {
            printf("-1\n");
        } else {
            for (int i = k; i >= 1; i--) {
                excluded[i] = 1;
                if (!is_connected(n, m, roads, excluded)) excluded[i] = 0;
            }
            long long total_cost = 0;
            for (int i = 1; i <= k; i++) {
                if (!excluded[i]) total_cost += c[i];
            }
            printf("%lld\n", total_cost);
        }
        for (int i = 0; i < m; i++) free(roads[i].tokens);
        free(roads);
        free(c);
        free(excluded);
    }
    return 0;
}

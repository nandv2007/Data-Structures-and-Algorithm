#include <stdio.h>
#include <stdlib.h>
typedef struct { int u, v, w; } Edge;
int parent[5005];
Edge edges[100005];
int find_set(int i) { return (parent[i] == i) ? i : (parent[i] = find_set(parent[i])); }
int compare_edges(const void* a, const void* b) { return ((Edge*)b)->w - ((Edge*)a)->w; }
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n, m;
            if (scanf("%d %d", &n, &m) != 2) break;
            for (int i = 1; i <= n; i++) parent[i] = i;
            for (int i = 0; i < m; i++) scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
            qsort(edges, m, sizeof(Edge), compare_edges);
            long long max_spanning_weight = 0;
            int edges_connected = 0;
            for (int i = 0; i < m; i++) {
                int root_u = find_set(edges[i].u);
                int root_v = find_set(edges[i].v);
                if (root_u != root_v) {
                    parent[root_u] = root_v;
                    max_spanning_weight += edges[i].w;
                    edges_connected++;
                    if (edges_connected == n - 1) break;
                }
            }
            printf("%lld\n", max_spanning_weight);
        }
    }
    return 0;
}

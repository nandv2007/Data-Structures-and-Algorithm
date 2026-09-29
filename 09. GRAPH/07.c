#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
int parent[MAXN], size[MAXN];
int num_components, max_size;
int find_set(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);
}
void union_sets(int u, int v) {
    int root_u = find_set(u);
    int root_v = find_set(v);
    if (root_u != root_v) {
        if (size[root_u] < size[root_v]) {
            int temp = root_u;
            root_u = root_v;
            root_v = temp;
        }
        parent[root_v] = root_u;
        size[root_u] += size[root_v];
        if (size[root_u] > max_size) max_size = size[root_u];
        num_components--;
    }
}
int main() {
    int n, m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &m) == 2) {
        num_components = n;
        max_size = 1;
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            union_sets(u, v);
            printf("%d %d\n", num_components, max_size);
        }}
    return 0;
}

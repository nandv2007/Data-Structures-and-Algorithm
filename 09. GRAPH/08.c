#include <stdio.h>
#include <stdlib.h>
#define MAXN 200005
int head[MAXN], to_node[2 * MAXN], next_edge[2 * MAXN], edge_cnt = 0;
int is_matched[MAXN], max_matching_ans = 0;
void add_edge(int u, int v) {
    to_node[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}
void dfs(int u, int p) {
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to_node[e];
        if (v != p) {
            dfs(v, u);
            if (!is_matched[v] && !is_matched[u]) {
                is_matched[v] = 1;
                is_matched[u] = 1;
                max_matching_ans++;
            }
        }
    }
}
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i <= n; i++) head[i] = -1;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            if (scanf("%d %d", &u, &v) == 2) {
                if (u >= 1 && u <= n && v >= 1 && v <= n) {
                    add_edge(u, v);
                    add_edge(v, u);
                }
            }
        }
        dfs(1, 0);
        printf("%d\n", max_matching_ans);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100005
int head[MAXN], to_node[2 * MAXN], next_edge[2 * MAXN], edge_cnt = 0;
char s[MAXN];
int counts[MAXN][26];
void add_edge(int u, int v) {
    to_node[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt++;
}
void dfs(int u, int p) {
    counts[u][s[u - 1] - 'a'] = 1;
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to_node[e];
        if (v != p) {
            dfs(v, u);
            for (int i = 0; i < 26; i++) {
                counts[u][i] += counts[v][i];
            }}}}
int main() {
    int n, q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        scanf("%s", s);
        for (int i = 0; i <= n; i++) head[i] = -1;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
            add_edge(v, u);
        }
        dfs(1, 0);
        for (int i = 0; i < q; i++) {
            int u;
            char c;
            scanf("%d %c", &u, &c);
            printf("%d\n", counts[u][c - 'a']);
        }
    }
    return 0;
}

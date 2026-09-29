#include <stdio.h>
#include <stdlib.h>
#define MAXM 200005
#define MAXE 400005
int head[MAXM], to_node[MAXE], next_edge[MAXE], ecnt = 0;
int rhead[MAXM], rto_node[MAXE], rnext_edge[MAXE], recnt = 0;
int visited[MAXM], stack[MAXM], top = 0;
int scc_id[MAXM], scc_cnt = 0;
char result[MAXM];
void add_edge(int u, int v) {
    to_node[ecnt] = v; next_edge[ecnt] = head[u]; head[u] = ecnt++;
    rto_node[recnt] = u; rnext_edge[recnt] = rhead[v]; rhead[v] = recnt++;
}
void dfs1(int u) {
    visited[u] = 1;
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to_node[e];
        if (!visited[v]) dfs1(v);
    }
    stack[top++] = u;
}
void dfs2(int u, int id) {
    scc_id[u] = id;
    for (int e = rhead[u]; e != -1; e = rnext_edge[e]) {
        int v = rto_node[e];
        if (!scc_id[v]) dfs2(v, id);
    }
}
int main() {
    int n, m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &m) == 2) {
        int total_nodes = 2 * m;
        for (int i = 1; i <= total_nodes; i++) head[i] = rhead[i] = -1;
        for (int i = 0; i < n; i++) {
            char t1, t2;
            int x1, x2;
            if (scanf(" %c %d %c %d", &t1, &x1, &t2, &x2) == 4) {
                int u = (t1 == '+') ? x1 : x1 + m;
                int not_u = (t1 == '+') ? x1 + m : x1;
                int v = (t2 == '+') ? x2 : x2 + m;
                int not_v = (t2 == '+') ? x2 + m : x2;
                add_edge(not_u, v);
                add_edge(not_v, u);
            }
        }
        for (int i = 1; i <= total_nodes; i++) { if (!visited[i]) dfs1(i); }
        for (int i = top - 1; i >= 0; i--) {
            int u = stack[i];
            if (!scc_id[u]) { scc_cnt++; dfs2(u, scc_cnt); }
        }
        int possible = 1;
        for (int i = 1; i <= m; i++) {
            if (scc_id[i] == scc_id[i + m]) { possible = 0; break; }
        }
        if (!possible) {
            printf("IMPOSSIBLE\n");
        } else {
            for (int i = 1; i <= m; i++) {
                if (scc_id[i] > scc_id[i + m]) result[i] = '+';
                else result[i] = '-';
            }
            for (int i = 1; i <= m; i++) {
                printf("%c%s", result[i], (i == m) ? "" : " ");
            }
            printf("\n");
        }
    }
    return 0;
}

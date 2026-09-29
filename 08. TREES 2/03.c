#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
#define MAXM 200005
int head[MAXN], to_v[MAXM], nxt_e[MAXM], ecnt = 0;
int dfn[MAXN], low[MAXN], timer = 0;
int stack[MAXN], top = 0, in_stack[MAXN];
int scc_id[MAXN], scc_cnt = 0;
int rep_node[MAXN], in_deg[MAXN], out_deg[MAXN];
int src_list[MAXN], snk_list[MAXN], src_cnt = 0, snk_cnt = 0;
int max_val(int a, int b) { return (a > b) ? a : b; }
void add_edge(int u, int v) {
    to_v[ecnt] = v;
    nxt_e[ecnt] = head[u];
    head[u] = ecnt++;
}
void tarjan(int u) {
    dfn[u] = low[u] = ++timer;
    stack[top++] = u;
    in_stack[u] = 1;
    for (int e = head[u]; e != -1; e = nxt_e[e]) {
        int v = to_v[e];
        if (!dfn[v]) {
            tarjan(v);
            if (low[v] < low[u]) low[u] = low[v];
        } else if (in_stack[v]) {
            if (dfn[v] < low[u]) low[u] = dfn[v];
        }}
    if (low[u] == dfn[u]) {
        scc_cnt++;
        rep_node[scc_cnt] = u;
        while (1) {
            int v = stack[--top];
            in_stack[v] = 0;
            scc_id[v] = scc_cnt;
            if (u == v) break;
        }}}
int main() {
    int n, m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) head[i] = -1;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u, v);
        }
        for (int i = 1; i <= n; i++) { if (!dfn[i]) tarjan(i); }
        if (scc_cnt == 1) { printf("0\n"); return 0; }
        for (int u = 1; u <= n; u++) {
            for (int e = head[u]; e != -1; e = nxt_e[e]) {
                int v = to_v[e];
                if (scc_id[u] != scc_id[v]) {
                    out_deg[scc_id[u]]++;
                    in_deg[scc_id[v]]++;
                }
            }
        }
        for (int i = 1; i <= scc_cnt; i++) {
            if (in_deg[i] == 0) src_list[src_cnt++] = rep_node[i];
            if (out_deg[i] == 0) snk_list[snk_cnt++] = rep_node[i];
        }
        int ans = max_val(src_cnt, snk_cnt);
        printf("%d\n", ans);
        for (int i = 0; i < ans; i++) {
            int u = snk_list[i % snk_cnt];
            int v = src_list[(i + 1) % src_cnt];
            printf("%d %d\n", u, v);
        }
    }
    return 0;
}

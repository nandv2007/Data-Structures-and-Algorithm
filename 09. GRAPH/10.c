#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 505
#define MAXM 4005
int head[MAXN], to_node[MAXM], next_edge[MAXM], cap[MAXM], flow[MAXM], ecnt = 0;
int parent_edge[MAXN], queue[MAXN], visited[MAXN];
int orig_u[MAXM], orig_v[MAXM], orig_cnt = 0;
void link(int i, int h) {
    orig_u[orig_cnt] = i; orig_v[orig_cnt] = h; orig_cnt++;
    to_node[ecnt] = h; cap[ecnt] = 1; flow[ecnt] = 0; next_edge[ecnt] = head[i]; head[i] = ecnt++;
    to_node[ecnt] = i; cap[ecnt] = 1; flow[ecnt] = 0; next_edge[ecnt] = head[h]; head[h] = ecnt++;
}
int bfs(int n, int s, int t) {
    for (int i = 1; i <= n; i++) parent_edge[i] = -1;
    int front = 0, rear = 0;
    queue[rear++] = s;
    parent_edge[s] = -2;
    while (front < rear) {
        int u = queue[front++];
        for (int e = head[u]; e != -1; e = next_edge[e]) {
            int v = to_node[e];
            if (parent_edge[v] == -1 && cap[e] - flow[e] > 0) {
                parent_edge[v] = e;
                if (v == t) return 1;
                queue[rear++] = v;
            }
        }
    }
    return 0;
}
void dfs_reachable(int u) {
    visited[u] = 1;
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to_node[e];
        if (!visited[v] && cap[e] - flow[e] > 0) {
            dfs_reachable(v);
        }
    }
}
int main() {
    int n, m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) head[i] = -1;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            link(u, v);
        }
        while (bfs(n, 1, n)) {
            int curr = n;
            while (curr != 1) {
                int e = parent_edge[curr];
                flow[e]++;
                flow[e ^ 1]--;
                curr = to_node[e ^ 1];
            }
        }
        dfs_reachable(1);
        int closed_streets_cnt = 0;
        for (int i = 0; i < orig_cnt; i++) {
            int u = orig_u[i], v = orig_v[i];
            if ((visited[u] && !visited[v]) || (!visited[u] && visited[v])) {
                closed_streets_cnt++;
            }
        }
        printf("%d\n", closed_streets_cnt);
        for (int i = 0; i < orig_cnt; i++) {
            int u = orig_u[i], v = orig_v[i];
            if ((visited[u] && !visited[v]) || (!visited[u] && visited[v])) {
                printf("%d %d\n", u, v);
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 505
#define MAXM 2005
int head[MAXN], to_node[MAXM], next_edge[MAXM], cap[MAXM], flow[MAXM], ecnt = 0;
int parent_edge[MAXN], queue[MAXN];
void add_edge(int u, int v) {
    to_node[ecnt] = v; cap[ecnt] = 1; flow[ecnt] = 0; next_edge[ecnt] = head[u]; head[u] = ecnt++;
    to_node[ecnt] = u; cap[ecnt] = 0; flow[ecnt] = 0; next_edge[ecnt] = head[v]; head[v] = ecnt++;
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
int max_flow(int s, int t, int n) {
    int total_flow = 0;
    while (bfs(n, s, t)) {
        int curr = t;
        while (curr != s) {
            int e = parent_edge[curr];
            flow[e]++;
            flow[e ^ 1]--;
            curr = to_node[e ^ 1];
        }
        total_flow++;
    }
    return total_flow;
}
void trace_path(int u, int t, int *path, int *len) {
    path[(*len)++] = u;
    if (u == t) return;
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        if (e % 2 == 0 && flow[e] == 1) {
            flow[e] = 0;
            trace_path(to_node[e], t, path, len);
            return;
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
            add_edge(u, v);
        }
        int k = max_flow(1, n, n);
        printf("%d\n", k);
        for (int i = 0; i < k; i++) {
            int path[MAXN], len = 0;
            trace_path(1, n, path, &len);
            printf("%d\n", len);
            for (int j = 0; j < len; j++) {
                printf("%d%s", path[j], (j == len - 1) ? "" : " ");
            }
            printf("\n");
        }
    }
    return 0;
}
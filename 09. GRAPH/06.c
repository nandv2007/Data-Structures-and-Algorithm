#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 505
#define MAXK 1005
int head[MAXN], to_girl[MAXK], next_pair[MAXK], ecnt = 0;
int match_boy_of_girl[MAXN], visited[MAXN];
void add_pair(int u, int v) {
    to_girl[ecnt] = v;
    next_pair[ecnt] = head[u];
    head[u] = ecnt++;}
int dfs(int u) {
    for (int e = head[u]; e != -1; e = next_pair[e]) {
        int v = to_girl[e];
        if (visited[v]) continue;
        visited[v] = 1;
        if (match_boy_of_girl[v] < 0 || dfs(match_boy_of_girl[v])) {
            match_boy_of_girl[v] = u;
            return 1;}}
    return 0;}
int main() {
    int n, m, k;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d %d", &n, &m, &k) == 3) {
        for (int i = 1; i <= n; i++) head[i] = -1;
        for (int i = 1; i <= m; i++) match_boy_of_girl[i] = -1;
        for (int i = 0; i < k; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            add_pair(u, v);}
        int pairs_count = 0;
        for (int i = 1; i <= n; i++) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) pairs_count++;
        }
        printf("%d\n", pairs_count);
        for (int i = 1; i <= m; i++) {
            if (match_boy_of_girl[i] > 0) {
                printf("%d %d\n", match_boy_of_girl[i], i);
            }}}
    return 0;
}

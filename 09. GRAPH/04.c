#include <stdio.h>
#include <stdlib.h>
int parent[100005];
int reps[100005];
int find_set(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find_set(parent[i]);
}
int main() {
    int n, m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < m; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            int r_u = find_set(u);
            int r_v = find_set(v);
            if (r_u != r_v) parent[r_u] = r_v;
        }
        int rep_cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (parent[i] == i) {
                reps[rep_cnt++] = i;
            }
        }
        printf("%d\n", rep_cnt - 1);
        for (int i = 1; i < rep_cnt; i++) {
            printf("%d %d\n", reps[0], reps[i]);
        }
    }
    return 0;
}

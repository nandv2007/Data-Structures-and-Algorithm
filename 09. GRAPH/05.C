#include <stdio.h>
#include <stdlib.h>
#define MAXN 300005
int parent1[MAXN], weight1[MAXN];
int parent2[MAXN], block_parent[MAXN];
int vis[MAXN], query_id = 0;
int find1(int i) {
    if (parent1[i] == i) return i;
    int p = parent1[i];
    int root = find1(p);
    weight1[i] ^= weight1[p];
    parent1[i] = root;
    return root;
}
int find2(int i) {
    if (parent2[i] == i) return i;
    return parent2[i] = find2(parent2[i]);
}
int main() {
    int n, q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 1; i <= n; i++) {
            parent1[i] = parent2[i] = i;
            weight1[i] = block_parent[i] = 0;
        }
        while (q--) {
            int u, v, x;
            if (scanf("%d %d %d", &u, &v, &x) == 3) {
                int r1_u = find1(u);
                int r1_v = find1(v);
                if (r1_u != r1_v) {
                    parent1[r1_u] = r1_v;
                    weight1[r1_u] = weight1[u] ^ weight1[v] ^ x;
                    block_parent[r1_u] = v;
                    printf("YES\n");
                } else {
                    int path_xor = weight1[u] ^ weight1[v];
                    if ((path_xor ^ x) != 1) {
                        printf("NO\n");
                    } else {
                        int b_u = find2(u), b_v = find2(v);
                        if (b_u == b_v) {
                            printf("NO\n");
                        } else {
                            query_id++;
                            int lca = 0;
                            int curr_u = b_u, curr_v = b_v;
                            while (1) {
                                if (curr_u != 0) {
                                    if (vis[curr_u] == query_id) { lca = curr_u; break; }
                                    vis[curr_u] = query_id;
                                    curr_u = (block_parent[curr_u] == 0) ? 0 : find2(block_parent[curr_u]);
                                }
                                if (curr_v != 0) {
                                    if (vis[curr_v] == query_id) { lca = curr_v; break; }
                                    vis[curr_v] = query_id;
                                    curr_v = (block_parent[curr_v] == 0) ? 0 : find2(block_parent[curr_v]);
                                }
                            }
                            curr_u = b_u;
                            while (curr_u != lca) {
                                int next_u = (block_parent[curr_u] == 0) ? 0 : find2(block_parent[curr_u]);
                                parent2[curr_u] = lca;
                                curr_u = next_u;
                            }
                            curr_v = b_v;
                            while (curr_v != lca) {
                                int next_v = (block_parent[curr_v] == 0) ? 0 : find2(block_parent[curr_v]);
                                parent2[curr_v] = lca;
                                curr_v = next_v;
                            }
                            printf("YES\n");
                        }
                    }
                }
            }
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int p1[100005], p2[100005];
int au[100005], av[100005], ac = 0;
int L1[100005], L2[100005], s1 = 0, s2 = 0;
int find1(int i) { return (p1[i] == i) ? i : (p1[i] = find1(p1[i])); }
int find2(int i) { return (p2[i] == i) ? i : (p2[i] = find2(p2[i])); }
void merge1(int i, int j) { int rA = find1(i), rB = find1(j); if (rA != rB) p1[rA] = rB; }
void merge2(int i, int j) { int rA = find2(i), rB = find2(j); if (rA != rB) p2[rA] = rB; }
int main() {
    int n, m1, m2;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d %d", &n, &m1, &m2) == 3) {
        for (int i = 1; i <= n; i++) p1[i] = p2[i] = i;
        for (int i = 0; i < m1; i++) { int u, v; scanf("%d %d", &u, &v); merge1(u, v); }
        for (int i = 0; i < m2; i++) { int u, v; scanf("%d %d", &u, &v); merge2(u, v); }
        for (int i = 2; i <= n; i++) {
            if (find1(1) != find1(i) && find2(1) != find2(i)) {
                au[ac] = 1; av[ac] = i; ac++;
                merge1(1, i); merge2(1, i);
            }
        }
        for (int i = 2; i <= n; i++) {
            if (find1(1) != find1(i)) L1[s1++] = i;
            if (find2(1) != find2(i)) L2[s2++] = i;
        }
        int idx1 = 0, idx2 = 0;
        while (idx1 < s1 && idx2 < s2) {
            int u = L1[idx1], v = L2[idx2];
            if (find1(1) == find1(u)) { idx1++; continue; }
            if (find2(1) == find2(v)) { idx2++; continue; }
            au[ac] = u; av[ac] = v; ac++;
            merge1(u, v); merge2(u, v);
            idx1++; idx2++;
        }
        printf("%d\n", ac);
        for (int i = 0; i < ac; i++) printf("%d %d\n", au[i], av[i]);
    }
    return 0;
}

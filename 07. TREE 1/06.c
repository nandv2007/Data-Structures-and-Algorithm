#include <stdio.h>
#include <stdlib.h>
int up[200005][20];
void link(int employee, int boss) {
    up[employee][0] = boss;}
int get_kth_ancestor(int x, int k) {
    for (int j = 19; j >= 0; j--) {
        if ((k >> j) & 1) {
            x = up[x][j];
            if (x == -1) return -1;
        }}
    return x;}
int main() {
    int n, q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < 20; j++) up[i][j] = -1;
        }
        for (int i = 2; i <= n; i++) {
            int boss;
            if (scanf("%d", &boss) == 1) {
                link(i, boss);
            }}
        for (int j = 1; j < 20; j++) {
            for (int i = 1; i <= n; i++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }}}
        for (int i = 0; i < q; i++) {
            int x, k;
            if (scanf("%d %d", &x, &k) == 2) {
                printf("%d\n", get_kth_ancestor(x, k));
            }}}
    return 0;
}

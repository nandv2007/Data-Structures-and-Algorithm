#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 100005
int b_crush[MAXN], g_crush[MAXN];
int b_beats[MAXN], g_beats[MAXN];
int b_recv[MAXN], g_recv[MAXN];
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            if (scanf("%d", &n) != 1) break;
            for (int i = 1; i <= n; i++) scanf("%d", &b_crush[i]);
            for (int i = 1; i <= n; i++) scanf("%d", &g_crush[i]);
            for (int i = 1; i <= n; i++) {
                b_beats[i] = g_crush[b_crush[i]];
                g_beats[i] = b_crush[g_crush[i]];
                b_recv[i] = g_recv[i] = 0;
            }
            for (int i = 1; i <= n; i++) {
                if (b_beats[i] != i) b_recv[b_beats[i]]++;
                if (g_beats[i] != i) g_recv[g_beats[i]]++;
            }
            int max_beatings = 0;
            for (int i = 1; i <= n; i++) {
                if (b_recv[i] > max_beatings) max_beatings = b_recv[i];
                if (g_recv[i] > max_beatings) max_beatings = g_recv[i];
            }
            int mutual_pairs = 0;
            for (int i = 1; i <= n; i++) {
                int target_b = b_beats[i];
                if (target_b > i && target_b != i && b_beats[target_b] == i) mutual_pairs++;
                int target_g = g_beats[i];
                if (target_g > i && target_g != i && g_beats[target_g] == i) mutual_pairs++;
            }
            printf("%d %d\n", max_beatings, mutual_pairs);
        }
    }
    return 0;
}

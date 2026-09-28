#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int key;
    int weight;
} Item;
int compare_items(const void* a, const void* b) {
    return ((Item*)a)->key - ((Item*)b)->key;
}
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            if (scanf("%d", &n) != 1) break;
            Item* raw = (Item*)malloc(n * sizeof(Item));
            for (int i = 0; i < n; i++) {
                int x, y, h;
                scanf("%d %d %d", &x, &y, &h);
                raw[i].key = x - y;
                raw[i].weight = h;
            }
            qsort(raw, n, sizeof(Item), compare_items);
            Item* groups = (Item*)malloc((n + 2) * sizeof(Item));
            int g_cnt = 0;
            for (int i = 0; i < n; i++) {
                if (g_cnt > 0 && groups[g_cnt].key == raw[i].key) {
                    groups[g_cnt].weight += raw[i].weight;
                } else {
                    g_cnt++;
                    groups[g_cnt].key = raw[i].key;
                    groups[g_cnt].weight = raw[i].weight;
                }
            }
            int* fwd = (int*)calloc(g_cnt + 2, sizeof(int));
            int* bwd = (int*)calloc(g_cnt + 2, sizeof(int));
            for (int i = 1; i <= g_cnt; i++) fwd[i] = fwd[i - 1] + groups[i].weight;
            for (int i = g_cnt; i >= 1; i--) bwd[i] = bwd[i + 1] + groups[i].weight;
            int possible = 0;
            for (int i = 1; i <= g_cnt; i++) {
                if (fwd[i - 1] == bwd[i + 1]) { possible = 1; break; }
            }
            if (!possible) {
                for (int i = 0; i <= g_cnt; i++) {
                    if (fwd[i] == bwd[i + 1]) { possible = 1; break; }
                }
            }
            if (possible) printf("YES\n");
            else printf("NO\n");
            free(raw);
            free(groups);
            free(fwd);
            free(bwd);
        }
    }
    return 0;
}

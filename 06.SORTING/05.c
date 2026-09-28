#include <stdio.h>
#include <stdlib.h>
typedef struct {
    long long l;
    long long r;
} Seg;
int compare_segs(const void* a, const void* b) {
    long long diff = ((Seg*)a)->l - ((Seg*)b)->l;
    if (diff < 0) return -1;
    if (diff > 0) return 1;
    return 0;
}
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            long long L;
            if (scanf("%d %lld", &n, &L) != 2) break;
            Seg* all_segs = (Seg*)malloc(n * sizeof(Seg));
            for (int i = 0; i < n; i++) {
                scanf("%lld %lld", &all_segs[i].l, &all_segs[i].r);
            }
            int possible = 0;
            Seg* valid = (Seg*)malloc(n * sizeof(Seg));
            for (int i = 0; i < n; i++) {
                long long target_a = all_segs[i].l;
                long long target_b = target_a + L;
                int v_count = 0;
                for (int j = 0; j < n; j++) {
                    if (all_segs[j].l >= target_a && all_segs[j].r <= target_b) {
                        valid[v_count++] = all_segs[j];
                    }
                }
                if (v_count == 0) continue;
                qsort(valid, v_count, sizeof(Seg), compare_segs);
                long long curr = target_a;
                for (int j = 0; j < v_count; j++) {
                    if (valid[j].l <= curr) {
                        if (valid[j].r > curr) {
                            curr = valid[j].r;
                        }
                    } else {
                        break;
                    }
                }
                if (curr == target_b) {
                    possible = 1;
                    break;
                }
            }
            if (possible) printf("Yes\n");
            else printf("No\n");
            free(all_segs);
            free(valid);
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n, k;
            if (scanf("%d %d", &n, &k) == 2) {
                int max_dist = 0;
                for (int i = 0; i < n; i++) {
                    int dist;
                    if (scanf("%d", &dist) == 1) {
                        if (dist > max_dist) {
                            max_dist = dist;
                        }
                    }
                }
                if (max_dist > k) {
                    printf("%d\n", max_dist - k);
                } else {
                    printf("-1\n");
                }
            }
        }
    }
    return 0;
}
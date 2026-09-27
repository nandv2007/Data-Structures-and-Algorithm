#include <stdio.h>
int main() {
    int n, count = 0;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            long long w, h;
            if (scanf("%lld %lld", &w, &h) == 2) {
                if ((10 * w >= 16 * h && 10 * w <= 17 * h) || (10 * h >= 16 * w && 10 * h <= 17 * w)) {
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}

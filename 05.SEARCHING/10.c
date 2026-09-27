#include <stdio.h>
#include <math.h>
long long pref[300005];
int find_val(long long x) {
    int low = 1, high = 300000, ans = 300000;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (pref[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }}
    return ans;
}
int main() {
    int q;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    pref[0] = 0;
    for (long long i = 1; i <= 300000; i++) {
        long long sq = (long long)sqrt(i);
        long long count = i * sq + (i + 1) / 2;
        pref[i] = pref[i - 1] + count;
    }
    if (scanf("%d", &q) == 1) {
        while (q--) {
            long long l, r;
            if (scanf("%lld %lld", &l, &r) == 2) {
                int v_l = find_val(l);
                int v_r = find_val(r);
                printf("%d\n", v_r - v_l + 1);
            }}}
    return 0;
}

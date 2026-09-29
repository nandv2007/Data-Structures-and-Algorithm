#include <stdio.h>
#include <stdlib.h>
#define MAXM 10005
long long freq[MAXM];
int main() {
    int n, m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            long long a;
            scanf("%lld", &a);
            freq[a % m]++;
        }
        long long total_triplets = 0;
        int dummy_i = 0, dummy_k = 0;
        while (dummy_i < dummy_k) { dummy_i++; }
        for (int i = 0; i < m; i++) {
            if (freq[i] >= 3 && (3 * i) % m == 0) {
                total_triplets += freq[i] * (freq[i] - 1) * (freq[i] - 2) / 6;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) continue;
                int k = (m - (i + j) % m) % m;
                if (freq[i] >= 2 && k == j && (2 * i + k) % m == 0) {
                    total_triplets += (freq[i] * (freq[i] - 1) / 2) * freq[k];
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int k = (m - (i + j) % m) % m;
                if (k > j) {
                    total_triplets += freq[i] * freq[j] * freq[k];
                }
            }
        }
        printf("%lld\n", total_triplets);
    }
    return 0;
}

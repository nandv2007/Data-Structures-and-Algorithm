#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
int h1[MAXN], to1[2 * MAXN], nxt1[2 * MAXN], ec1;
int h2[MAXN], to2[2 * MAXN], nxt2[2 * MAXN], ec2;
unsigned long long fmix64(unsigned long long k) {
    k ^= k >> 33;
    k *= 0xff51afd7ed558ccdULL;
    k ^= k >> 33;
    k *= 0xc4ceb9fe1a85ec53ULL;
    k ^= k >> 33;
    return k;
}
void add1(int u, int v) { to1[ec1] = v; nxt1[ec1] = h1[u]; h1[u] = ec1++; }
void add2(int u, int v) { to2[ec2] = v; nxt2[ec2] = h2[u]; h2[u] = ec2++; }
unsigned long long get_hash(int u, int p, int* head, int* to, int* nxt) {
    unsigned long long h = 0x9e3779b97f4a7c15ULL;
    for (int e = head[u]; e != -1; e = nxt[e]) {
        int v = to[e];
        if (v != p) h += fmix64(get_hash(v, u, head, to, nxt));
    }
    return h;
}
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            if (scanf("%d", &n) != 1) break;
            ec1 = ec2 = 0;
            for (int i = 0; i <= n; i++) h1[i] = h2[i] = -1;
            for (int i = 0; i < n - 1; i++) { int u, v; scanf("%d %d", &u, &v); add1(u, v); add1(v, u); }
            for (int i = 0; i < n - 1; i++) { int u, v; scanf("%d %d", &u, &v); add2(u, v); add2(v, u); }
            if (get_hash(1, 0, h1, to1, nxt1) == get_hash(1, 0, h2, to2, nxt2)) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}

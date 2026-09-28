#include <stdio.h>
#include <stdlib.h>
typedef struct { char type; int arg1; int arg2; } Query;
int bit[600005], comp[600005], salaries[200005], bit_size;
Query queries[200005];
int cmp_int(const void* a, const void* b) { return (*(int*)a - *(int*)b); }
void update(int idx, int val) { for (; idx <= bit_size; idx += idx & -idx) bit[idx] += val; }
int query(int idx) { int sum = 0; for (; idx > 0; idx -= idx & -idx) sum += bit[idx]; return sum; }
int find_le(int val) {
    int low = 1, high = bit_size, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (comp[mid] <= val) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }
    return ans;
}
int find_ge(int val) {
    int low = 1, high = bit_size, ans = bit_size + 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (comp[mid] >= val) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }
    return ans;
}
int main() {
    int n, q, c_cnt = 0;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        for (int i = 1; i <= n; i++) { scanf("%d", &salaries[i]); comp[++c_cnt] = salaries[i]; }
        for (int i = 0; i < q; i++) {
            scanf(" %c %d %d", &queries[i].type, &queries[i].arg1, &queries[i].arg2);
            comp[++c_cnt] = queries[i].arg2;
            if (queries[i].type == '?') comp[++c_cnt] = queries[i].arg1;
        }
        qsort(comp + 1, c_cnt, sizeof(int), cmp_int);
        bit_size = 0;
        for (int i = 1; i <= c_cnt; i++) { if (bit_size == 0 || comp[i] != comp[bit_size]) comp[++bit_size] = comp[i]; }
        for (int i = 1; i <= n; i++) update(find_le(salaries[i]), 1);
        for (int i = 0; i < q; i++) {
            if (queries[i].type == '!') {
                int emp = queries[i].arg1, new_sal = queries[i].arg2;
                update(find_le(salaries[emp]), -1);
                salaries[emp] = new_sal;
                update(find_le(new_sal), 1);
            } else {
                int l = find_ge(queries[i].arg1), r = find_le(queries[i].arg2);
                printf("%d\n", query(r) - query(l - 1));
            }
        }
    }
    return 0;
}

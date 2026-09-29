#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int val;
    int idx;
} Element;
typedef struct {
    int first;
    int last;
} Position;
int compare_elements(const void* a, const void* b) {
    Element* e1 = (Element*)a;
    Element* e2 = (Element*)b;
    if (e1->val != e2->val) return (e1->val < e2->val) ? -1 : 1;
    return e1->idx - e2->idx;
}
int compare_ints(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        Element* arr = (Element*)malloc(n * sizeof(Element));
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i].val);
            arr[i].idx = i;
        }
        qsort(arr, n, sizeof(Element), compare_elements);
        Position* uniques = (Position*)malloc(n * sizeof(Position));
        int* first_indices = (int*)malloc(n * sizeof(int));
        int u_cnt = 0;
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && arr[j].val == arr[i].val) j++;
            uniques[u_cnt].first = arr[i].idx;
            uniques[u_cnt].last = arr[j - 1].idx;
            first_indices[u_cnt] = arr[i].idx;
            u_cnt++;
            i = j;
        }
        qsort(first_indices, u_cnt, sizeof(int), compare_ints);
        long long total_unique_pairs = 0;
        for (int k = 0; k < u_cnt; k++) {
            int target = uniques[k].last;
            int low = 0, high = u_cnt - 1, count = 0;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (first_indices[mid] < target) {
                    count = mid + 1;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            total_unique_pairs += count;
        }
        printf("%lld\n", total_unique_pairs);
        free(arr);
        free(uniques);
        free(first_indices);
    }
    return 0;
}

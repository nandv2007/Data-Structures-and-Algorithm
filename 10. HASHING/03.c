#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char name[12];
    long long x;
} Record;
int compare_records(const void* a, const void* b) {
    Record* r1 = (Record*)a;
    Record* r2 = (Record*)b;
    int cmp = strcmp(r1->name, r2->name);
    if (cmp != 0) return cmp;
    if (r1->x > r2->x) return -1;
    if (r1->x < r2->x) return 1;
    return 0;
}
int main() {
    int t;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int n;
            if (scanf("%d", &n) != 1) break;
            Record* records = (Record*)malloc(n * sizeof(Record));
            for (int i = 0; i < n; i++) {
                scanf("%s %lld", records[i].name, &records[i].x);
            }
            qsort(records, n, sizeof(Record), compare_records);
            char best_name[12] = "";
            long long best_sum = -1;
            int i = 0;
            while (i < n) {
                int j = i;
                long long current_festival_sum = 0;
                int count = 0;
                while (j < n && strcmp(records[j].name, records[i].name) == 0) {
                    if (count < 3) {
                        current_festival_sum += records[j].x;
                        count++;
                    }
                    j++;
                }
                if (current_festival_sum > best_sum) {
                    best_sum = current_festival_sum;
                    strcpy(best_name, records[i].name);
                } else if (current_festival_sum == best_sum) {
                    if (strlen(best_name) == 0 || strcmp(records[i].name, best_name) < 0) {
                        strcpy(best_name, records[i].name);
                    }
                }
                i = j;
            }
            printf("%s %lld\n", best_name, best_sum);
            free(records);
        }
    }
    return 0;
}

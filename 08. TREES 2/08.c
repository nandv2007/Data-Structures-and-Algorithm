#include <stdio.h>
#include <stdlib.h>
#define HASH_SIZE 200003
typedef struct {
    int age;
    int count;
    int is_occupied;
} HashEntry;
HashEntry hash_table[HASH_SIZE];
int get_and_inc_count(int age) {
    int idx = (age % HASH_SIZE + HASH_SIZE) % HASH_SIZE;
    while (hash_table[idx].is_occupied) {
        if (hash_table[idx].age == age) {
            hash_table[idx].count++;
            return hash_table[idx].count;
        }
        idx = (idx + 1) % HASH_SIZE;
    }
    hash_table[idx].age = age;
    hash_table[idx].count = 1;
    hash_table[idx].is_occupied = 1;
    return 1;
}
int main() {
    int n;
    long long m;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %lld", &n, &m) == 2) {
        int max_count = 0;
        int max_age = -1;
        for (int i = 0; i < n; i++) {
            int current_age;
            if (scanf("%d", &current_age) == 1) {
                int current_count = get_and_inc_count(current_age);
                if (current_count > max_count || (current_count == max_count && current_age > max_age)) {
                    max_count = current_count;
                    max_age = current_age;
                }
                printf("%d %d\n", max_age, max_count);
            }
        }
    }
    return 0;
}
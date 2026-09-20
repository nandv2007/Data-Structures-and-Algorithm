#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    char nums[13][20] = {
        "ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX",
        "SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE"
    };
    int a[100];
    int n = 0;
    while (scanf("%d", &a[n]) == 1) {
        if (a[n] == 999)
            break;
        n++;
    }
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf(".");
    int max[26] = {0};
    for (int i = 0; i < n; i++) {
        int count[26] = {0};
        for (int j = 0; nums[a[i]][j] != '\0'; j++)
            count[nums[a[i]][j] - 'A']++;
        for (int j = 0; j < 26; j++) {
            if (count[j] > max[j])
                max[j] = count[j];
        }
    }
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < max[i]; j++)
            printf(" %c", 'A' + i);
    }
    return 0;
}
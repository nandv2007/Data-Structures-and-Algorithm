#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int dollar, items;
    char name[10][50];
    int price[10], afford[10] = {0};
    scanf("%d %d", &dollar, &items);
    for (int i = 0; i < items; i++)
        scanf("%s %d", name[i], &price[i]);
    for (int i = 0; i < items; i++) {
        int min = -1;
        for (int j = 0; j < items; j++) {
            if (!afford[j] && price[j] <= dollar) {
                if (min == -1 || price[j] < price[min])
                    min = j;
            }
        }
        if (min == -1)
            break;
        afford[min] = 1;
        dollar = dollar - price[min];
    }
    int found = 0;
    for (int i = 0; i < items; i++) {
        if (afford[i]) {
            printf("I can afford %s\n", name[i]);
            found = 1;
        } else {
            printf("I can't afford %s\n", name[i]);
        }
    }
    if (!found)
        printf("I need more Dollar!\n");

    printf("%d\n", dollar);

    return 0;
}
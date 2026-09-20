#include <stdio.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int n;
    int val[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
    char sym[][3] = {"R","BR","G","BG","B","ZB","P","ZP","Z","BZ","W","BW","B"};
    while (scanf("%d", &n) == 1) {
        printf("The Roman numeral representation of %d is: ", n);
        char buf[100];
        int i = 0;
        for (int j = 0; j < 13; j++) {
            while (n >= val[j]) {
                int k = 0;
                while (sym[j][k] != '\0') {
                    buf[i++] = sym[j][k++];
                }
                n = n - val[j];
            }
        }
        buf[i] = '\0';
        printf("%s\n", buf);
    }
    return 0;
}
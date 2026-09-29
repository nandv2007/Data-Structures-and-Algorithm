#include <stdio.h>
#include <string.h>
int main() {
    char str[1005];
    int count[256] = {0};
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (fgets(str, sizeof(str), stdin)) {
        int len = strlen(str);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--;
        }
        for (int i = 0; i < len; i++) {
            count[(unsigned char)str[i]]++;
        }
        int max_count = 0;
        char max_char = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] > max_count) {
                max_count = count[i];
                max_char = (char)i;
            }
        }
        printf("%c %d\n", max_char, max_count);
    }
    return 0;
}

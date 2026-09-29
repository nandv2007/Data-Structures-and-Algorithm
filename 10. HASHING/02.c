#include <stdio.h>
#include <math.h>
int main() {
    int t;
    double phi = (1.0 + sqrt(5.0)) / 2.0;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &t) == 1) {
        while (t--) {
            int a, b;
            if (scanf("%d %d", &a, &b) == 2) {
                if (a > b) { int temp = a; a = b; b = temp; }
                int n = b - a;
                int expected_a = (int)(n * phi);
                if (a == expected_a) printf("sami\n");
                else printf("canthi\n");
            }
        }
    }
    return 0;
}

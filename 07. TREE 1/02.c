#include <stdio.h>
#include <stdlib.h>
int inPos[100005];
void printPostOrder(int inStart, int inEnd, int* preIdx, int* pre) {
    if (inStart > inEnd) return;
    int rootVal = pre[(*preIdx)++];
    int rootIdx = inPos[rootVal];
    printPostOrder(inStart, rootIdx - 1, preIdx, pre);
    printPostOrder(rootIdx + 1, inEnd, preIdx, pre);
    printf("%d ", rootVal);
}
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        int* pre = (int*)malloc(n * sizeof(int));
        int* in = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
        for (int i = 0; i < n; i++) {
            scanf("%d", &in[i]);
            inPos[in[i]] = i;
        }
        int preIdx = 0;
        printPostOrder(0, n - 1, &preIdx, pre);
        printf("\n");
        free(pre);
        free(in);
    }
    return 0;
}

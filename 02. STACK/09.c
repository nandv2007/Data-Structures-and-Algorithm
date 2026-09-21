#include <stdio.h>
int q[1000], front=0, rear=0;
void push(int x) {
    int size=rear-front;
    q[rear++]=x;
    for(int i=0;i<size;i++) {
        q[rear]=q[front++];
        rear++;
    }
}
int pop() {
    return q[front++];
}
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int n,m,x;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) {
        scanf("%d",&x);
        push(x);
    }
    printf("%d\n",q[front]);
    for(int i=0;i<m;i++)
        pop();
    printf("%d",q[front]);
    return 0;
}
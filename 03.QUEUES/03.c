#include<stdio.h>
#define MAX 100
int q[MAX],front=0,rear=0;
void enqueue(int x){
    q[rear++]=x;
}
void dequeue(){
    if(front<rear)
        front++;
}
int main(){
    int n,i,j;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&j);
        enqueue(j);
    }
    printf("Dequeuing elements:\n");
    while(front<rear){
        dequeue();
        for(i=front;i<rear;i++)
            printf("%d ",q[i]);
        printf("\n");
    }
    return 0;
}
#include<stdio.h>
#define MAX 100
int q[MAX],front=-1,rear=-1;
void enqueue(int data){
    if(rear==MAX-1)
        return;
    if(front==-1)
        front=0;
    rear++;
    q[rear]=data;
    printf("Enqueuing %d\n",data);
}
void disp(){
    int i;
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    for(i=front;i<=rear;i++)
        printf("%d ",q[i]);
    printf("\n");
}
int main(){
    int n,i,data;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        enqueue(data);
        disp();
    }
    return 0;
}
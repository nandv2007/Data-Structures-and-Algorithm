#include <stdio.h>
int queue[100];
int front=-1,rear=-1;
void enqueue(int data,int l){
    if(rear==l-1)
        return;
    if(front==-1)
        front=0;
    queue[++rear]=data;
}
void reverse(){
    int i,j,temp;
    for(i=front,j=rear;i<j;i++,j--){
        temp=queue[i];
        queue[i]=queue[j];
        queue[j]=temp;
    }}
int main(){
    int n,i,data;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        enqueue(data,n);
    }
    printf("Queue:");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    printf("\n");
    reverse();
    printf("Reversed Queue:");
    for(i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    return 0;
}
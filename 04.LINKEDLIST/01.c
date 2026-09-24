#include <stdio.h>
#include <stdlib.h>
#define ROLL_NO "CH.SC.U4CSE25248"
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue(int data,int l){
    struct node *n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->next=NULL;
    if(front==NULL)
        front=rear=n;
    else{
        rear->next=n;
        rear=n;
    }}
void reverse(){
    struct node *prev=NULL,*cur=front,*next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    rear=front;
    front=prev;
}
int main(){
    int n,i,data;
    printf("%s\n",ROLL_NO);
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        enqueue(data,n);
    }
    printf("Queue:");
    struct node *t=front;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    printf("\n");
    reverse();
    printf("Reversed Queue:");
    t=front;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;
    }
    return 0;
}
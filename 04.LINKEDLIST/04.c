#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *start=NULL;
void display(){
    struct node *p=start;
    printf("Linked List:->");
    while(p!=NULL){
        printf("%d",p->data);
        if(p->next!=NULL)
            printf("->");
        p=p->next;
    }}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    int n,x,p,i;
    struct node *newnode,*temp,*prev;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=NULL;
        if(start==NULL)
            start=newnode;
        else{
            temp=start;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }}
    scanf("%d",&p);
    scanf("%d",&x);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(start!=NULL&&start->data==p){
        newnode->next=start;
        start=newnode;
        display();
        return 0;
    }
    temp=start;
    while(temp!=NULL&&temp->data!=p){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Node not found!\n");
        display();
    }
    else{
        newnode->next=temp;
        prev->next=newnode;
        display();
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
struct Node *head=NULL;
void insertSorted(int data){
    struct Node *n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    if(head==NULL){
        head=n;
        n->next=head;
        return;
    }
    if(data<head->data){
        struct Node *p=head;
        while(p->next!=head)
            p=p->next;
        n->next=head;
        p->next=n;
        head=n;
        return;
    }
    struct Node *p=head;
    while(p->next!=head && p->next->data<data)
        p=p->next;
    n->next=p->next;
    p->next=n;
}
void display(){
    if(head==NULL)
        return;
    struct Node *p=head;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insertSorted(x);
    }
    display();
    return 0;
}
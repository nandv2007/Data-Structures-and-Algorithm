#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
void insertBegin(int data){
    struct Node *n=(struct Node*)malloc(sizeof(struct Node));
    n->data=data;
    n->prev=NULL;
    n->next=head;
    if(head!=NULL)
        head->prev=n;
    head=n;
}
void display(){
    struct Node *t=head;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->next;}
    printf("\n");
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        insertBegin(x);}
    display();
    struct Node *t=head,*p=NULL;
    while(t!=NULL){
        p=t;
        t=t->next;}
    t=p;
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->prev;}
    printf("\n");
    return 0;
}
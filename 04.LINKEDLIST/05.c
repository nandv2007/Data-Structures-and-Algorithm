#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void insert_Data(struct node **head,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(*head==NULL)
        *head=newnode;
    else{
        struct node *temp=*head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
void delete_Alt(struct node **head){
    struct node *a=*head,*b;
    while(a!=NULL&&a->next!=NULL){
        b=a->next;
        a->next=b->next;
        free(b);
        a=a->next;
    }
}
void display(struct node *head){
    while(head!=NULL){
        printf("%d",head->data);
        if(head->next!=NULL)
            printf(" ");
        head=head->next;
    }
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    int n,i;
    struct node *head=NULL;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        insert_Data(&head,i);
    delete_Alt(&head);
    display(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node **head,int data){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    if(*head==NULL){
        *head=newnode;
        newnode->next=*head;
    }
    else{
        struct node *temp=*head;
        while(temp->next!=*head)
            temp=temp->next;
        temp->next=newnode;
        newnode->next=*head;
    }
}
void display(struct node *head){
    if(head==NULL)
        return;
    struct node *temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("\n");
}
void split(struct node *head,struct node **head1,struct node **head2){
    struct node *slow=head,*fast=head;
    if(head==NULL||head->next==head){
        *head1=head;
        *head2=NULL;
        return;
    }
    while(fast->next!=head&&fast->next->next!=head){
        slow=slow->next;
        fast=fast->next->next;
    }
    if(fast->next->next==head)
        fast=fast->next;
    *head1=head;
    *head2=slow->next;
    slow->next=*head1;
    fast->next=*head2;
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    struct node *head=NULL,*head1=NULL,*head2=NULL;
    int n,data,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&data);
        create(&head,data);
    }
    printf("Complete linked list:");
    display(head);
    split(head,&head1,&head2);
    printf("First half:");
    display(head1);
    printf("Second half:");
    display(head2);
    return 0;
}
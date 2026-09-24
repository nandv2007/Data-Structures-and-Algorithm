#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void create(struct node **head,int data){
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
void print(struct node *head){
    while(head!=NULL)
    {
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
struct node *reverse(struct node *head)
{
    struct node *prev=NULL,*cur=head,*next;
    while(cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
void fold(struct node **head)
{
    struct node *slow=*head,*fast=*head;
    while(fast->next!=NULL&&fast->next->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    struct node *second=slow->next;
    slow->next=NULL;
    second=reverse(second);
    struct node *first=*head,*temp1,*temp2;
    while(second!=NULL)
    {
        temp1=first->next;
        temp2=second->next;
        first->next=second;
        second->next=temp1;
        first=temp1;
        second=temp2;
    }
}
int main()
{
    printf("Roll No: CH.SC.U4CSE25248\n");
    struct node *head=NULL;
    int n,data,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&data);
        create(&head,data);
    }
    printf("Link list data:");
    print(head);
    fold(&head);
    printf("Link list data after fold:");
    print(head);
    return 0;
}
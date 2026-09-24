#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int GetNth(struct node *head,int index){
    int i=0;
    while(head!=NULL){
        if(i==index)
            return head->data;
        i++;
        head=head->next;
    }
    return -1;
}
void display(struct node *head){
    printf("Linked list:-->");
    while(head!=NULL){
        printf("%d",head->data);
        if(head->next!=NULL)
            printf("-->");
        head=head->next;
    }
    printf("\n");
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    int n,i,x,index;
    struct node *head=NULL,*newnode;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=x;
        newnode->next=head;
        head=newnode;
    }
    scanf("%d",&index);
    display(head);
    printf("Node at index=%d:%d",index,GetNth(head,index));
    return 0;
}
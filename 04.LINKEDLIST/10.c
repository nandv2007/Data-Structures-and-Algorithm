#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
int main(){
    int n,d,i,x;
    struct Node *head=NULL,*temp,*newnode;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        newnode=(struct Node*)malloc(sizeof(struct Node));
        newnode->data=x;
        newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }else{
            temp=head;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=newnode;
        }
    }
    scanf("%d",&d);
    for(i=0;i<d;i++){
        temp=head;
        head=head->next;
        free(temp);
    }
    printf("Linked List:->");
    temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        if(temp->next!=NULL)
            printf("->");
        temp=temp->next;
    }
    printf("\n");
    return 0;
}
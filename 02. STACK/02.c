#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
typedef struct myStack{
    Node *top;
}myStack;
void push(int data,myStack *ms){
    Node *newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=ms->top;
    ms->top=newNode;
}
int pop(myStack *ms){
    if(ms->top==NULL)
        return -1;
    Node *temp=ms->top;
    int data=temp->data;
    ms->top=temp->next;
    free(temp);
    return data;
}
void merge(myStack *ms1,myStack *ms2){
    if(ms1->top==NULL){
        ms1->top=ms2->top;
        return;
    }
    Node *temp=ms1->top;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=ms2->top;}
int main(){
    int n,m,i,x;
    myStack ms1={NULL},ms2={NULL};
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        push(x,&ms1);}
    for(i=0;i<m;i++){
        scanf("%d",&x);
        push(x,&ms2);}
    merge(&ms1,&ms2);
    Node *temp=ms1.top;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;}
    printf("\n");
    return 0;
}
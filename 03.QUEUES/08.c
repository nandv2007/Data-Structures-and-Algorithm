#include<stdio.h>
#include<stdlib.h>
struct Node{
    int page;
    struct Node*prev;
    struct Node*next;
};
struct Queue{
    struct Node*front;
    struct Node*rear;
    int size;
    int capacity;
};
void moveToFront(struct Queue*q,struct Node*node){
    if(node==q->front)
        return;
    if(node==q->rear){
        q->rear=node->prev;
        q->rear->next=NULL;
    }else{
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    node->prev=NULL;
    node->next=q->front;
    q->front->prev=node;
    q->front=node;
}
void enQueue(struct Queue*q,int page,struct Node**hash){
    struct Node*newNode;
    if(hash[page]!=NULL){
        moveToFront(q,hash[page]);
        return;
    }
    newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->page=page;
    newNode->prev=NULL;
    newNode->next=q->front;
    if(q->front==NULL){
        q->front=q->rear=newNode;
    }else{
        q->front->prev=newNode;
        q->front=newNode;
    }
    q->size++;
    hash[page]=newNode;
    if(q->size>q->capacity){
        struct Node*temp=q->rear;
        q->rear=q->rear->prev;
        q->rear->next=NULL;
        hash[temp->page]=NULL;
        free(temp);
        q->size--;
    }
}
void display(struct Queue*q){
    struct Node*temp=q->front;
    while(temp!=NULL){
        printf("%d ",temp->page);
        temp=temp->next;
    }
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    struct Queue q;
    struct Node*hash[10]={NULL};
    int n,m,page,i;
    scanf("%d%d",&n,&m);
    q.front=NULL;
    q.rear=NULL;
    q.size=0;
    q.capacity=m;
    for(i=0;i<n;i++){
        scanf("%d",&page);
        enQueue(&q,page,hash);
    }
    display(&q);
    return 0;
}
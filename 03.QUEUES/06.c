#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct Queue{
    struct Node *front;
    struct Node *rear;
} Queue;
void enQueue(Queue* q, int value){
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    if (q->front == NULL){
        q->front = newNode;
        q->rear = newNode;
        newNode->next = q->front;}
    else{
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }}
int deQueue(Queue* q){
    struct Node *temp;
    int value;
    if (q->front == NULL)
        return -1;
    value = q->front->data;
    if (q->front == q->rear){
        free(q->front);
        q->front = NULL;
        q->rear = NULL;}
    else{
        temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);}
    return value;
}
void displayQueue(struct Queue* q){
    struct Node *temp;
    if (q->front == NULL)
        return;
    temp = q->front;
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != q->front);
    printf("\n");
}
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    Queue q;
    int n, value, i;
    int deleted;
    q.front = NULL;
    q.rear = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++){
        scanf("%d", &value);
        enQueue(&q, value);
    }
    printf("Elements in Circular Queue are:");
    displayQueue(&q);
    deleted = deQueue(&q);
    printf("Deleted value = %d\n", deleted);
    deleted = deQueue(&q);
    printf("Deleted value = %d", deleted);
    printf("Elements in Circular Queue are:");
    displayQueue(&q);
    return 0;
}
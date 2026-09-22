#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct Queue {
    struct node *front;
    struct node *rear;
};
void enQueue(struct Queue *q, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    if (q->front == NULL) {
        q->front = q->rear = newNode;
        newNode->next = q->front;
    } else {
        newNode->next = q->front;
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int deQueue(struct Queue *q) {
    int value;
    struct node *temp;
    if (q->front == NULL)
        return -1;
    value = q->front->data;
    if (q->front == q->rear) {
        free(q->front);
        q->front = q->rear = NULL;
    } else {
        temp = q->front;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(temp);
    }
    return value;
}
void displayQueue(struct Queue *q) {
    struct node *temp;
    if (q->front == NULL)
        return;
    temp = q->front;
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != q->front);
}
int main() {
    printf("Roll No: CH.SC.U4CSE25248\n");
    struct Queue q;
    int n, value, i;
    q.front = NULL;
    q.rear = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &value);
        enQueue(&q, value);
    }
    displayQueue(&q);
    deQueue(&q);
    return 0;
}
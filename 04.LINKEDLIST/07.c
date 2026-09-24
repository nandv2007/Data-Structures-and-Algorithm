#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
void insert(struct node **head_ref, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
        return;
    }
    struct node *present = *head_ref;
    if (data <= (*head_ref)->data) {
        while (present->next != *head_ref)
            present = present->next;
        present->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }
    while (present->next != *head_ref &&
           present->next->data < data)
        present = present->next;
    new_node->next = present->next;
    present->next = new_node;
}
void display(struct node *head) {
    if (head == NULL)
        return;
    struct node *p = head;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);}
int main() {
    printf("Roll No: CH.SC.U4CSE25248\n");
    int n, x;
    struct node *head = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        insert(&head, x);
    }
    display(head);
    return 0;
}
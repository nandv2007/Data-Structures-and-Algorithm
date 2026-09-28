#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left,*right;};
struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;}
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;}
void postorder(struct node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }}
int main() {
    int n, val;
    struct node* root = NULL;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            if (scanf("%d", &val) == 1) {
                root = insert(root, val);
            }}
        postorder(root);
        printf("\n");
    }
    return 0;
}

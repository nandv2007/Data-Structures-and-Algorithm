#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node {
    int key;
    int priority;
    struct Node *left, *right;
};
struct Node* create_node(int key) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key;
    n->priority = rand();
    n->left = n->right = NULL;
    return n;
}
struct Node* right_rotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    return x;
}
struct Node* left_rotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
    y->left = x;
    x->right = y;
    return y;
}
struct Node* insert(struct Node* root, int key) {
    if (root == NULL) return create_node(key);
    if (key == root->key) return root;
    if (key < root->key) {
        root->left = insert(root->left, key);
        if (root->left->priority > root->priority) root = right_rotate(root);
    } else {
        root->right = insert(root->right, key);
        if (root->right->priority > root->priority) root = left_rotate(root);
    }
    return root;
}
int lower_bound(struct Node* root, int y) {
    int ans = -1;
    while (root != NULL) {
        if (root->key >= y) {
            ans = root->key;
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return ans;
}
int main() {
    srand(time(NULL));
    int n, q;
    struct Node* root = NULL;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d %d", &n, &q) == 2) {
        while (q--) {
            int type, val;
            if (scanf("%d %d", &type, &val) == 2) {
                if (type == 1) {
                    root = insert(root, val);
                } else {
                    printf("%d\n", lower_bound(root, val));
                }
            }
        }
    }
    return 0;
}

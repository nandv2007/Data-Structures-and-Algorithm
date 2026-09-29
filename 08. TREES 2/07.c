#include <stdio.h>
#include <stdlib.h>
#include <time.h>
struct Node {
    int key;
    int priority;
    int freq;
    struct Node *left, *right;
};
struct Node* create_node(int key) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->key = key;
    n->priority = rand();
    n->freq = 1;
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
    x->right = T2;
    return y;
}
struct Node* insert(struct Node* root, int key, int* size_changed) {
    if (root == NULL) {
        *size_changed = 1;
        return create_node(key);
    }
    if (key == root->key) {
        if (root->freq < 2) {
            root->freq++;
            *size_changed = 1;
        } else {
            *size_changed = 0;
        }
        return root;
    }
    if (key < root->key) {
        root->left = insert(root->left, key, size_changed);
        if (root->left->priority > root->priority) root = right_rotate(root);
    } else {
        root->right = insert(root->right, key, size_changed);
        if (root->right->priority > root->priority) root = left_rotate(root);
    }
    return root;
}
struct Node* find(struct Node* root, int key) {
    if (root == NULL || root->key == key) return root;
    if (key < root->key) return find(root->left, key);
    return find(root->right, key);
}
void print_ascending(struct Node* root) {
    if (root == NULL) return;
    print_ascending(root->left);
    printf("%d ", root->key);
    print_ascending(root->right);
}
void print_descending(struct Node* root) {
    if (root == NULL) return;
    print_descending(root->right);
    if (root->freq == 2) printf("%d ", root->key);
    print_descending(root->left);
}
int main() {
    srand(time(NULL));
    int n, q, val;
    struct Node* root = NULL;
    int current_size = 0;
    int max_val = -1;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &val);
            int changed = 0;
            root = insert(root, val, &changed);
            if (changed) current_size++;
            if (val > max_val) max_val = val;
        }
        if (scanf("%d", &q) == 1) {
            for (int i = 0; i < q; i++) {
                scanf("%d", &val);
                if (val > max_val) {
                    int changed = 0;
                    root = insert(root, val, &changed);
                    current_size++;
                    max_val = val;
                } else if (val < max_val) {
                    struct Node* target = find(root, val);
                    if (target == NULL || target->freq < 2) {
                        int changed = 0;
                        root = insert(root, val, &changed);
                        current_size++;
                    }
                }
                printf("%d\n", current_size);
            }
        }
        print_ascending(root);
        print_descending(root);
        printf("\n");
    }
    return 0;
}

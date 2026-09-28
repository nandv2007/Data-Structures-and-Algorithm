#include <stdio.h>
#include <stdlib.h>
#define MAXN 100005
int head[MAXN], to[2 * MAXN], next_edge[2 * MAXN], edge_cnt = 0;
int deg[MAXN], parent_node[MAXN];
struct TrieNode {
    int val;
    struct TrieNode *child;
    struct TrieNode *sibling;};
void add_edge(int u, int v) {
    to[edge_cnt] = v;
    next_edge[edge_cnt] = head[u];
    head[u] = edge_cnt++;
    deg[u]++;}
struct TrieNode* create_node(int val) {
    struct TrieNode* n = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    n->val = val;
    n->child = NULL;
    n->sibling = NULL;
    return n;}
long long total_trips = 0;
struct TrieNode* insert_trie(struct TrieNode* root, int val) {
    struct TrieNode* curr = root->child;
    struct TrieNode* prev = NULL;
    while (curr != NULL) {
        if (curr->val == val) return curr;
        prev = curr;
        curr = curr->sibling;}
    struct TrieNode* new_n = create_node(val);
    total_trips++;
    if (prev == NULL) root->child = new_n;
    else prev->sibling = new_n;
    return new_n;}
void dfs(int u, int p) {
    parent_node[u] = p;
    for (int e = head[u]; e != -1; e = next_edge[e]) {
        int v = to[e];
        if (v != p) dfs(v, u);}}
int main() {
    int n;
    printf("Roll Number: CH.SC.U4CSE25248\n");
    if (scanf("%d", &n) == 1) {
        for (int i = 0; i <= n; i++) head[i] = -1;
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            if (scanf("%d %d", &u, &v) == 2) {
                add_edge(u, v);
                add_edge(v, u);}}
        dfs(1, 0);
        struct TrieNode* root = create_node(-1);
        for (int i = 1; i <= n; i++) {
            struct TrieNode* curr_trie = root;
            int curr_node = i;
            while (curr_node != 0) {
                curr_trie = insert_trie(curr_trie, deg[curr_node]);
                curr_node = parent_node[curr_node];}}
        printf("%lld\n", total_trips);}
    return 0;
}

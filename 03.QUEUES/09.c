#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;};
struct node *f = NULL;
struct node *r = NULL;
void enqueue(int d){
    struct node *n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if(f == NULL){
        f = r = n;
        r->next = f;}
    else{
        r->next = n;
        r = n;
        r->next = f;}
}
int dequeue(){
    int d;
    struct node *t;
    if(f == NULL)
        return -1;
    d = f->data;
    if(f == r) {
        free(f);
        f = r = NULL;
    }
    else {
        t = f;
        f = f->next;
        r->next = f;
        free(t);
    }
    return d;
}
void display(){
    struct node *t;
    if(f == NULL)
        return;
    t = f;
    do{
        printf("%d ",t->data);
        t = t->next;
    }while(t != f);
    printf("\n");
}
int main(){
    int n,i,d;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&d);
        enqueue(d);
    }
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}
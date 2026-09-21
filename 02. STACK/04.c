#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct{
    char a[MAX];
    int top;
}twoStacks;
void push1(char x,twoStacks *s){s->a[++s->top]=x;}
void push2(char x,twoStacks *s){s->a[++s->top]=x;}
char pop1(twoStacks *s){return s->a[s->top--];}
char pop2(twoStacks *s){return s->a[s->top--];}
int main(){
    char str[MAX];
    twoStacks s1,s2;
    int i,ok=1;
    s1.top=-1;
    s2.top=-1;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%s",str);
    for(i=0;str[i]!='\0';i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{')
            push1(str[i],&s1);
        else if(str[i]==')'||str[i]==']'||str[i]=='}'){
            if(s1.top==-1){
                ok=0;
                break;}
            char x=pop1(&s1);
            if((str[i]==')'&&x!='(')||(str[i]==']'&&x!='[')||(str[i]=='}'&&x!='{')){
                ok=0;
                break;
            }}}
    if(s1.top!=-1)
        ok=0;
    if(ok)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
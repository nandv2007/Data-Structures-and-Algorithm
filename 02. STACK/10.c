#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[100][100];
int top=-1;
void push(char s[]) {
    strcpy(stack[++top],s);
}
void pop(char s[]) {
    strcpy(s,stack[top--]);
}
void postToPre(char post[]) {
    char a[100],b[100],temp[100];
    for(int i=0;post[i]!='\0';i++) {
        if(isalnum(post[i])) {
            temp[0]=post[i];
            temp[1]='\0';
            push(temp);
        } else {
            pop(a);
            pop(b);
            temp[0]=post[i];
            temp[1]='\0';
            strcat(temp,b);
            strcat(temp,a);
            push(temp);
        }
    }
    printf("%s",stack[top]);
}
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    char post[100];
    scanf("%s",post);
    postToPre(post);
    return 0;
}
#include <stdio.h>
#define MAX 100
int main()
{
    char s[MAX],stack[MAX];
    int top=-1,i,ok=1;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%s",s);
    for(i=0;s[i]!='\0';i++){
        if(s[i]=='('||s[i]=='['||s[i]=='{')
            stack[++top]=s[i];
        else if(s[i]==')'||s[i]==']'||s[i]=='}'){
            if(top==-1){
                ok=0;
                break;
            }
            if((s[i]==')'&&stack[top]!='(')||(s[i]==']'&&stack[top]!='[')||(s[i]=='}'&&stack[top]!='{')){
                ok=0;
                break;
            }
            top--;
        }
    }
    if(top!=-1)
        ok=0;
    if(ok)
        printf("Balanced");
    else
        printf("Not Balanced");
    return 0;
}
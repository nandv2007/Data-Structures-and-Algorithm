#include <stdio.h>
#include <stdlib.h>
int main() {
    printf("Roll.No: CH.SC.U4CSE25248\n");
    int n;
    scanf("%d",&n);
    long long *arr=malloc(n*sizeof(long long));
    long long *st=malloc(n*sizeof(long long));
    int *next=malloc(n*sizeof(int));
    int *stack=malloc(n*sizeof(int));
    int top=-1;
    for(int i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    for(int i=n-1;i>=0;i--){
        while(top>=0 && arr[stack[top]]<=arr[i])
            top--;
        if(top==-1)
            next[i]=-1;
        else
            next[i]=stack[top];
        stack[++top]=i;
    }
    for(int i=n-1;i>=0;i--) {
        if(next[i]==-1)
            st[i]=arr[i];
        else
            st[i]=arr[i]^st[next[i]];
    }
    long long ans=0;
    for(int i=0;i<n;i++) {
        if(st[i]>ans)
            ans=st[i];
    }
    printf("%lld",ans);
    free(arr);
    free(st);
    free(next);
    free(stack);
    return 0;
}
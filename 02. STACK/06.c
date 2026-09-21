#include <stdio.h>
#define MAX 1000
void calculateSpan(int price[],int n,int S[])
{
    int stack[MAX],top=-1,i;
    for(i=0;i<n;i++){
        while(top!=-1&&price[stack[top]]<=price[i])
            top--;
        if(top==-1)
            S[i]=i+1;
        else
            S[i]=i-stack[top];
        stack[++top]=i;
    }
}
void printArray(int arr[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}
int main()
{
    int n,price[MAX],S[MAX],i;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&price[i]);
    calculateSpan(price,n,S);
    printArray(S,n);
    return 0;
}
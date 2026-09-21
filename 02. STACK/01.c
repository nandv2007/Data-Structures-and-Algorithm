#include <stdio.h>
int main()
{
    int n,i,j;
    int a[1000000];
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=0;
    j=n-1;
    while(i<=j)
    {
        if(a[i]>a[j])
        {
            printf("1 ");
            j--;
        }
        else if(a[i]<a[j])
        {
            printf("2 ");
            i++;
        }
        else
        {
            printf("0 ");
            i++;
            j--;
        }
    }
    return 0;
}
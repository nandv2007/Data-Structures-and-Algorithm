#include<stdio.h>
int main(){
    int t,m,i,j,k,sum,max;
    char s[105];
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        scanf("%s",s);
        k=(m+1)/2;
        sum=0;
        for(i=0;i<k;i++)
            sum+=s[i]-'0';
        max=sum;
        for(i=k;i<m;i++){
            sum=sum-(s[i-k]-'0')+(s[i]-'0');
            if(sum>max)
                max=sum;
        }
        printf("%d\n",max);
    }
    return 0;
}
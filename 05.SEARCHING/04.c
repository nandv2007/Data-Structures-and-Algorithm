#include<stdio.h>
int gcd(int a,int b){
    while(b!=0){
        int t=a%b;
        a=b;
        b=t;
    }
    return a;
}
int hexsum(int n){
    int sum=0,r;
    while(n>0){
        r=n%16;
        sum=sum+r;
        n=n/16;
    }
    return sum;
}
int main(){
    int t,l,r,i,count,s;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&l,&r);
        count=0;
        for(i=l;i<=r;i++){
            s=hexsum(i);
            if(gcd(i,s)>1)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
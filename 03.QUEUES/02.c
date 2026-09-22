#include<stdio.h>
#include<string.h>
#define MAX 200005
int p0[4*MAX],p1[4*MAX],s0[4*MAX],s1[4*MAX],b0[4*MAX],b1[4*MAX],len[4*MAX];
char a[MAX];
void pull(int k){
    int x=k*2,y=x+1;
    len[k]=len[x]+len[y];
    p0[k]=p0[x]==len[x]?len[x]+p0[y]:p0[x];
    p1[k]=p1[x]==len[x]?len[x]+p1[y]:p1[x];
    s0[k]=s0[y]==len[y]?len[y]+s0[x]:s0[y];
    s1[k]=s1[y]==len[y]?len[y]+s1[x]:s1[y];
    b0[k]=b0[x]>b0[y]?b0[x]:b0[y];
    b1[k]=b1[x]>b1[y]?b1[x]:b1[y];
    if(s0[x]+p0[y]>b0[k])b0[k]=s0[x]+p0[y];
    if(s1[x]+p1[y]>b1[k])b1[k]=s1[x]+p1[y];
}
void build(int k,int l,int r){
    if(l==r){
        len[k]=1;
        if(a[l]=='0')p0[k]=s0[k]=b0[k]=1;
        else p1[k]=s1[k]=b1[k]=1;
        return;
    }
    int m=(l+r)/2;
    build(k*2,l,m);
    build(k*2+1,m+1,r);
    pull(k);
}
void update(int k,int l,int r,int pos){
    if(l==r){
        p0[k]=p1[k]=s0[k]=s1[k]=b0[k]=b1[k]=0;
        if(a[l]=='0')p0[k]=s0[k]=b0[k]=1;
        else p1[k]=s1[k]=b1[k]=1;
        return;
    }
    int m=(l+r)/2;
    if(pos<=m)update(k*2,l,m,pos);
    else update(k*2+1,m+1,r,pos);
    pull(k);
}
int main(){
    int n,m,x;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%s",a+1);
    n=strlen(a+1);
    scanf("%d",&m);
    build(1,1,n);
    while(m--){
        scanf("%d",&x);
        a[x]=a[x]=='0'?'1':'0';
        update(1,1,n,x);
        printf("%d\n",b0[1]>b1[1]?b0[1]:b1[1]);
    }
    return 0;
}
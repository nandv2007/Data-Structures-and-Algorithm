#include <stdio.h>
#define MAX 100005
#define S 82
int a[MAX],d[MAX],seg[S][4*MAX];
int digitsum(int x){
    int s=0;
    while(x>0){
        s+=x%10;
        x/=10;
    }
    return s;}
int max(int x,int y){
    return x>y?x:y;
}
void build(int node,int l,int r,int k){
    if(l==r)
    {
        if(d[l]<k)
            seg[k][node]=a[l];
        else
            seg[k][node]=0;
        return;
    }
    int mid=(l+r)/2;
    build(node*2,l,mid,k);
    build(node*2+1,mid+1,r,k);
    seg[k][node]=max(seg[k][node*2],seg[k][node*2+1]);
}
int findpos(int node,int l,int r,int ql,int k,int val){
    if(r<ql || seg[k][node]<=val)
        return -1;
    if(l==r)
        return l;
    int mid=(l+r)/2;
    int x=findpos(node*2,l,mid,ql,k,val);
    if(x!=-1)
        return x;
    return findpos(node*2+1,mid+1,r,ql,k,val);
}
int main()
{
    int n,q,i,x,k,pos;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        d[i]=digitsum(a[i]);
    }
    for(k=1;k<=81;k++)
        build(1,1,n,k);
    while(q--)
    {
        scanf("%d",&x);
        k=d[x];
        pos=findpos(1,1,n,x+1,k,a[x]);
        if(pos==-1)
            printf("-1 ");
        else
            printf("%d ",pos);
    }
    return 0;
}
#include<stdio.h>
#define MAX 3
int q[MAX],front=0,rear=0,size=0;
void insert(int x){
    int i;
    if(size<3){
        q[rear++]=x;
        size++;
    }else if(x>q[2]){
        q[2]=x;
    }else return;
    for(i=size-1;i>0;i--){
        if(q[i]>q[i-1]){
            int t=q[i];
            q[i]=q[i-1];
            q[i-1]=t;
        }
    }
}
int main(){
    int n,a,i;
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a);
        insert(a);
        if(size<3)
            printf("-1\n");
        else
            printf("%d\n",q[0]*q[1]*q[2]);
    }
    return 0;
}
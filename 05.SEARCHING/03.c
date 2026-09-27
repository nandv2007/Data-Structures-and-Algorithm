#include<stdio.h>
int main(){
    printf("Roll No: CH.SC.U4CSE25248\n");
    int T;
    scanf("%d",&T);
    while(T--){
        int R,C,L;
        int A[309][309];
        scanf("%d%d%d",&R,&C,&L);
        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
                scanf("%d",&A[i][j]);
        int ans=0;
        for(int left=0;left<C;left++){
            for(int right=left;right<C;right++){
                int height=0;
                for(int i=0;i<R;i++){
                    int mn=A[i][left];
                    int mx=A[i][left];
                    for(int j=left+1;j<=right;j++){
                        if(A[i][j]<mn) mn=A[i][j];
                        if(A[i][j]>mx) mx=A[i][j];
                    }
                    if(mx-mn<=L){
                        height++;
                        int area=height*(right-left+1);
                        if(area>ans) ans=area;
                    }else{
                        height=0;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

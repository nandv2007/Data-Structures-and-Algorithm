#include<stdio.h>
int main(){
    int n,i,j,temp;
    int arr[1000];
    printf("Roll No: CH.SC.U4CSE25248\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    int count=1;
    for(i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            count++;
            if(count==3){
                printf("%d\n",arr[i]);
                return 0;
            }
        }
    }
    return 0;
}
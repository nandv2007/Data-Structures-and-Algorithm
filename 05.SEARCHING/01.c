#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 20
int main(){
    char var[3][LEN];
    double m=0,d=0,x=0;
    int qm=0,qd=0,qx=0,i;
    printf("Roll No: CH.SC.U4CSE25248\n");
    for(i=0;i<3;i++){
        scanf("%s",var[i]);
        if(strcmp(var[i],"M")==0){
            scanf("%s",var[i]);
            if(strcmp(var[i],"?")==0)
                qm=1;
            else
                m=atof(var[i]);
        }else if(strcmp(var[i],"D")==0){
            scanf("%s",var[i]);
            if(strcmp(var[i],"?")==0)
                qd=1;
            else
                d=atof(var[i]);
        }else if(strcmp(var[i],"X")==0){
            scanf("%s",var[i]);
            if(strcmp(var[i],"?")==0)
                qx=1;
            else
                x=atof(var[i]);
        }
    }
    if(qm)
        printf("M %.2f\n",-d*x);
    else if(qd)
        printf("D %.2f\n",-m/x);
    else if(qx)
        printf("X %.2f\n",-m/d);
    return 0;
}
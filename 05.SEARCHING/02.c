#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MAX 100
#define LEN 101
char names[MAX][LEN];
char gems[11][20]={"Lapis","Topaz","Tourmaline","Sapphire","Peridot","Ruby","Pearl","Emerald","Diamond","Aquamarine","Amethyst"};
int gemrank(char *s){
    int i;
    char temp[LEN],*p;
    strcpy(temp,s);
    p=strtok(temp," ");
    while(p!=NULL){
        for(i=0;i<11;i++){
            if(strcasecmp(p,gems[i])==0)
                return i;
        }
        p=strtok(NULL," ");
    }
    return 100;
}
int compare(const void *a,const void *b){
    char *s1=(char *)a;
    char *s2=(char *)b;
    int r1=gemrank(s1);
    int r2=gemrank(s2);
    int i,c;
    if(r1!=r2)
        return r1-r2;
    for(i=0;s1[i]!='\0'&&s2[i]!='\0';i++){
        c=tolower(s1[i])-tolower(s2[i]);
        if(c!=0)
            return c;
    }
    return tolower(s1[i])-tolower(s2[i]);
}
int main(){
    int n=0,i;
    char temp[LEN];
    printf("Roll No: CH.SC.U4CSE25248\n");
    while(n<MAX){
        fgets(temp,LEN,stdin);
        temp[strcspn(temp,"\n")]='\0';
        if(strcmp(temp,"END")==0)
            break;
        strcpy(names[n],temp);
        n++;
    }
    qsort(names,n,sizeof(names[0]),compare);
    printf("Sort\n");
    for(i=0;i<n;i++)
        printf("%s\n",names[i]);
    return 0;
}
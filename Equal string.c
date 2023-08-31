#include<stdio.h>
#include<string.h>
void main(){
    char str1[10],str2[10];
    int l,m,flag=0;
    printf("enter string 1: ");
    scanf("%[^\n]",str1);
    printf("enter string2: ");
    scanf("%[^\n]",str2);
    for(int l=0;str1[l]!='\0';l++);
    for(int m=0;str2[m]!='\0';m++);
    if(l==m){
        for(int i=0;i<l;i++){
            if(str1[i]!=str2[i]){
                flag=1;
            }
        }
        if(flag==0){
            printf("equal");
        }
        else{
            printf("not equal");
        }
    }
}

    
    


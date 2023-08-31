#include<stdio.h>
#include<string.h>
void main(){
    char ptr[50],rev[50];
    printf("enter string: ");
    scanf("%[^\n]",ptr);
    int n;
    for(n=0;*(ptr+n)!='\0';n++);
    for(int i=0,j=n-1;i<n;i++,j--){
        *(rev+i)=*(ptr+j);
    }
    printf("reverse is %s",rev);
}

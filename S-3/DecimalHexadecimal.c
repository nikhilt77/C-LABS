#include<stdio.h>
#include<stdlib.h>
#define max 20
int stack[max];
int top=-1;
void push(int a){
    if(top==max-1){
        printf("Stack overflow");
    }
    else{
        top++;
        stack[top]=a;
    }
}
void main(){
    int x,rem;
    printf("enter number:");
    scanf("%d",&x);
    while(x>0){
       rem=x%16;
       push(rem);
       x=x/16;
    }
    while(top!=-1){
    if(stack[top]<10){
        printf("%d",stack[top]);
    }
    else{
        printf("%c",stack[top]+55);
        
    }
    top--;
    }
}

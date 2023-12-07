#include<stdlib.h>
#include<stdio.h>
#define max 20
int stack[max];
int top=-1;
void push(int x){
    if(top==max-1){
        printf("Stack overflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
int convert(int n){
    int rem,div;
    while(n!=0){
        rem=n%2;
        push(rem);
        n=n/2;
    }
}
void display(){
    if(top==-1){
        printf("Error noted in Code\n");
    }
    else{
        printf("Binary:\n");
        for(int i=top;i>=0;i--){
            printf("%d",stack[i]);
        }
    }
}
void main(){
    int data;
    printf("Enter the decimal number: ");
    scanf("%d",&data);
    convert(data);
    display();
    
}

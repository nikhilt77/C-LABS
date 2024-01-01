#include<stdio.h>
#include<stdlib.h>
#define max 20
int top=-1;
char stack[max];
void push(int x){
    if(top==max-1){
        printf("Stack overflow\n");
    }
    else{
        top++;
        stack[top]=x;
    }
}
void pushC(char x){
    if(top==max-1){
        printf("Stack overflow\n");
    }
   else{
        top++;
        stack[top]=x;
   }
}
void convert(int n){
    int rem;
    while(n!=0){
        rem=n%16;
        if(rem<10){
            push(rem+48);
        }
        else{
            switch(rem){
                case 10:pushC('A');
                        break;
                case 11:pushC('B');
                        break;
                case 12:pushC('C');
                        break;  
                case 13:pushC('D');
                        break;
                case 14:pushC('E');
                        break;
                case 15:pushC('F');
                        break;
                default:printf("Error\n");
            }
        }
        n=n/16;
    }
}
void display(){
    if(top==-1){
        printf("Stack Underflow\n");
    }
    else{
        printf("Hexadecimal:\n");
        for(int i=top;i>=0;i--){
            printf("%c",stack[i]);
        }
    }
}
void main(){
    int data;
    printf("Enter decimal number:");
    scanf("%d",&data);
    convert(data);
    display();
    
}

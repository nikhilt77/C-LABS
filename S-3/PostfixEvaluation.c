#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<math.h>
#define M_Size 100
int stack[M_Size];
int top=-1;
void push(int data){
    top++;
    stack[top]=data;
}
int pop(){
    top--;
    return stack[top+1];
}
bool isOperator(char c){
    switch(c){
        case '*':
        case '-':
        case '+':
        case '/':
        case '^':return 1;
        default:return 0;
    }
    
}
int convert(char c){
    return c-48;
}
void perform(int b,char c,int a){
    int var;
    switch(c){

        case '+':var=a+b;break;
        case '-':var=a-b;break;
        case '*':var=a*b;break;
        case '/':var=a/b;break;
        case '^':var=pow(a,b);break;
    }
    push(var);
}
void pass(char c){
    if(isOperator(c)){
        perform(pop(),c,pop());
    }
    else{
        push(convert(c));
    }
}
void main(){
    char postfix[M_Size];
    printf("Enter postfix expression:");
    scanf("%s",&postfix);
    for(int i=0;postfix[i]!='\0';i++){
        pass(postfix[i]);
    }
    printf("Result:\n");
    printf("%d",stack[top]);
}


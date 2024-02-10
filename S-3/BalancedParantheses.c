#include<stdio.h>
#include<string.h>
#define max 20
char stack[max];
int top=-1;
void push(char c){
    if(top==max-1){
        printf("Stack Overflow\n");
    }
    else{
        top++;
        stack[top]=c;
    }
}
char pop(){
    if(top==-1){
        printf("Stack Empty\n");
    }
    else{
        return stack[top--];
        
    }
}
int isBalanced(){
    for(int i=0;i<strlen(stack);i++){
        if(stack[i]=='('){
            push(stack[i]);
        }
        else if(stack[i]==')'){
            if(pop()!='('){
                return 1;
            }
        }
    }
    if(top!=-1){
        return 1;
    }
    return 0;
}
int main(){
    int chk;
    printf("Enter Expression:");
    scanf("%s",stack);
    chk=isBalanced();
    if(chk==1){
        printf("Not Balanced\n");
    }
    else{
        printf("Balanced\n");
    }
}

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
int similar(char c1,char c2){
    if(c1=='('&&c2==')'){
        return 1;
    }
    else if(c1=='{'&&c2=='}'){
        return 1;
    }
    else if(c1=='['&&c2==']'){
        return 1;
    }
    else{
        return 0;
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
        if(stack[i]=='('||stack[i]=='{'||stack[i]=='['){
            push(stack[i]);
        }
        else if(stack[i]==')'||stack[i]=='}'||stack[i]==']'){
            if(top==-1||!similar(pop(),stack[i])){
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

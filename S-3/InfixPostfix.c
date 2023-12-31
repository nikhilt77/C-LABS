#include<stdio.h>
#include<ctype.h>
#define max 20
int j=0;

int main(){

    char infix[max],postfix[max];
    printf("Enter postfix expression:");
    gets(infix);
    convert(infix,postfix);
    puts(postfix);
    return 0;
}
int preced(char c){
    if(c=='+'||c=='-'){
        return 1;
    }
    else if(c=='*'||c=='/'){
        return 2;
    }
    else if(c=='^'){
        return 3;
    }
    else{
        return -1;
    }
}
void convert(char infix[],char postfix[]){
    char stack[max];
    int top=-1;
    for(int i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='('){
            stack[++top]=infix[i];
        }
        else if(infix[i]==')'){
            while(top!=-1&&stack[top]!='('){
                postfix[j++]=stack[top--];
            }
            top--;
        }
        else if(top!=-1&&preced(infix[i])<=preced(stack[top])){
            postfix[j++]=stack[top--];
            stack[++top]=infix[i];
            
        }
        else {
            stack[++top]=infix[i];
        }
    }
        while(top!=-1){
            postfix[j++]=stack[top--];
        }
        postfix[j]='\0';
    }
    

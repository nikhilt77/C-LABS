#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define M_size 100
int S[100],top=-1;
void push(int x){
    if(top!=M_size-1){
        top=top+1;
        S[top]=x;
    }
}
String pop(){
    if(top!=-1){
        top=top-1;
        return S[top+1];
    }
}
bool isOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='^'||ch=='/'){
        return true;
    }
    else{
        return false;
    }
}
void main(){
    String A[30];
    float r;
    printf("Enter Expression:");
    for(int i=0;i<30;i++){
        scanf("%s",&A[i]);
    }
    int i=0;
    while(i!=A.length()){
        if(A[i]>='0'&& A[i]<'9'){
            int n=A[i];
            push(n);
        }
        else if(isOperator(A[i])){
            String o2=pop();
            String o1=pop();
            if(A[i]=='*'){
                r=o1*o2;
            }
            else if(A[i]=='/'){
                r=o1/o2;
            }
            else if(A[i]=='+'){
                r=o1+o2;
            }
            else if(A[i]=='-'){
                r=o1-o2;
            }
            else{
                r=o1^o2;
            }
        }
        push(r);
        }
        i++;
    
    printf(pop());
    }

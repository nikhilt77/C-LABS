#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void display();
void push();
void peek();
bool isEmpty();
bool isFull();
void pop();
int top=-1;
int stack[100];
void main(){
    int opt;
    printf("!:Display stack\n");
    printf("2:Push\n");
    printf("3:Peek\n");
    printf("4:Pop\n");
    printf("5:Exit\n");
    printf("Display Option:");
    scanf("%d",&opt);
    switch(opt){
        case 1:display();
        break;
        case 2:push();
        break;
        case 3:peek();
        break;
        case 4:pop();
        break;
        case 5:exit(0);
        break;
        default:printf("Invalid");
     }
     main();
}
bool isEmpty(){
    if(top==-1)
    return true;
    else
    return false;
}
bool isFull(){
    if(top==99)
    return true;
    else
    return false;
}
void display(){
    if(!isEmpty()){
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
    else{
        printf("Stack underflow");
    }
}
void push(){
    if(!isFull()){
        int element;
        printf("Enter element:");
        scanf("%d",&element);
        top++;
        stack[top]=element;
    }
    else{
        printf("Stack overflow\n");
    }
}    
void peek(){
    if(!isEmpty()){
        printf("%d",stack[top]);
        //top--;
    }
    else{
        printf("Stack underflow");
    }
}

void pop(){
    if(!isEmpty()){
        top--;
    }
    else{
        printf("Stack underflow");
    }
}

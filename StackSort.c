#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 20
int stack[max];
int stack2[max];
int top2=-1;
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
int pop(){
    if(top==-1){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        return stack[top--];
    }
}
void push2(int x){
    if(top2==max-1){
        printf("Stack Overflow\n");
    }
    else{
        top2++;
        stack2[top2]=x;
    }
}
int pop2(){
    if(top2==-1){
        printf("Stack underflow\n");
        return -1;
    }
    else{
        return stack2[top2--];
    }
}
void sort(){
    int temp;
     while(top!=-1){
         temp=pop();
         while(top2!=-1&&temp<stack2[top2]){
             push(pop2());
         }
         push2(temp);
     }
     while(top2!=-1){
         push(pop2());
     }
}
void display(){
    if(top==-1){
        printf("Nothing to print\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",stack[i]);
        }
    }
}
void main(){
    int n,data;
    printf("Enter no. of data:");
    scanf("%d",&n);
    printf("Enter data:");
    for(int i=0;i<n;i++){
        scanf("%d",&stack[i]);
        push(stack[i]);
    }
    printf("Original array\n");
    display();
    printf("Sorted array\n");
    sort();
    display();
}

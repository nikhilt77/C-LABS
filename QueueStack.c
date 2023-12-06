#include<stdio.h>
#include<stdbool.h>
#define max 20
int stack1[max];
int stack2[max];
int top1=-1;
int top2=-1;

bool isEmpty(){
    if(top1==-1)
    return true;
    else
    return false;
}

bool isFull(){
    if(top1==max-1)
    return true;
    else
    return false;
}

void push1(int data){
    if(!isFull()){
        top1++;
        stack1[top1]=data;
    }
    else{
        printf("Stack Overflow\n");
    }
}

int pop1(){
    int data = stack1[top1];
    top1--;
    return data;
}

void push2(int data){
    top2++;
    stack2[top2]=data;
}

int pop2(){
    int data = stack2[top2];
    top2--;
    return data;
}

void enqueue(int data){
    push1(data);
}

void dequeue(){
    if(top1==-1&&top2==-1){
        printf("Queue underflow\n");
    }
    else{ 
        if(top2==-1){
            while(top1!=-1){
                push2(pop1());
            }
        }
        printf("Dequeued Element is %d\n",pop2());
    }
}

void display(){
    for(int i=top1;i>=0;i--){
        printf("%d ",stack1[i]);
    }
    printf("\n");
}

int main(){
    int ch,data;
    while(true){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data to enter:");
                   scanf("%d",&data);
                   enqueue(data);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:exit(0);
                   break;
            default:printf("Invalid choice\n");       
        }
    }
    return 0;
}

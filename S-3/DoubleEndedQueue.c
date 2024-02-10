#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 20
int dq[max];
int front=-1;
int rear=-1;
void insertFront(int data){
    if((front==0&&rear==max-1)||front==rear+1){
        printf("Queue is full\n");
    }
    else if(front==-1){
        front=0;
        rear=0;
    }
    else if(front==0){
        front=max-1;
    }
    else{
        front--;
    }
    dq[front]=data;
}
void insertRear(int data){
    if((front==0&&rear==max-1)||front==rear+1){
        printf("Queue is full\n");
    }
    else if(rear==-1){
        rear=0;
        front=0;
    }
    else if(rear==max-1){
        rear=0;
    }
    else{
        rear++;
    }
    dq[rear]=data;
}
void deleteFront(){
    if(front==-1){
        printf("Queue underflow\n");
    }
    else if(front==max-1){
        front=0;
    }
    else{
        front++;
    }
}
void deleteRear(){
    if(front==-1){
        printf("Queue underflow\n");
    }
    else if(rear==0){
        rear=max-1;
    }
    else{
        rear--;
    }
}
void display(){
    int i = front;
    if(front == -1){
        printf("Queue empty\n");
    }
    else{
        while(i != rear){
            printf("%d ", dq[i]);
            i = (i + 1) % max;
        }
        printf("%d\n", dq[rear]); 
    }
}

int main(){
    int ch,data;
    while(true){
        printf("1.Insert at Front\n2.Insert at Rear\n3.Delete From front\n4.Delete at Rear\n5.Display\n6.Exit\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&data);
                    insertFront(data);
                    break;
            case 2: printf("Enter data:");
                    scanf("%d",&data);
                    insertRear(data);
                    break;  
            case 3:deleteFront();
                    break;
            case 4:deleteRear();
                    break;
            case 5:display();
                    break;
            case 6: exit(0);
            		break;
            default:printf("Invalid choice\n");		
        }
    }
}

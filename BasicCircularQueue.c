#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define max 20
int CQ[max];
int front=-1;
int rear=-1;
void enqueue(int x){
    if((rear+1)%max==front){
        printf("Queue overflow\n");
    }
    else if(front==-1 && rear==-1){
        front=0;
        rear=0;
        CQ[rear]=x;
    }
    else{
        rear=(rear+1)%max;
        CQ[rear]=x;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue underflow\n");
    }
    else if(front=rear){
        front=0;
        rear=0;
    }
    else{
        front=(front+1)%max;
    }

}
void display(){
    if(front==-1&&rear==-1){
        printf("Queue underflow\n");
    }
    else{
        printf("Circular Queue:\n");
        for(int i=front;i<=rear;i++){
            printf("%d ",CQ[i]);
        }
    }
}
void main(){
    int n,ch;
    while(true){
        printf("1.Enqueue\n.2.Dequeue\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("enter element:");
                    scanf("%d",&n);
                    enqueue(n);
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

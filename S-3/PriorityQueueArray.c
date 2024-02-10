#include<stdio.h>
//#include<stdlib.h>
#include<stdbool.h>
#define max 20
struct pq{
    int data;
    int priority;
};
struct pq p[max];

int front=-1;
int rear=-1;
void enqueue(int data,int priority){
    if(front==-1&&rear==-1){
        front=0;
        rear=0;
        p[rear].data=data;
        p[rear].priority=priority;
    }
    else if(rear==max-1){
        printf("Queue overflow");
    }
    else{
            rear++;
            p[rear].data=data;
            p[rear].priority=priority;
    }
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue underflow\n");
    }
    else{
        front++;
    }
}
void display(){
    struct pq temp;
    for(int i=front;i<rear;i++){
        for(int j=front;j<rear-i-1;j++){
            if(p[j].priority>p[j+1].priority){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
    for(int i=front;i<=rear;i++){
        printf("%d\t",p[i].data);
    }
    printf("\n");
}
int main(){
    int ch,key,priority;
    while(true){
        printf("1.Enqueue\n2.Dequeue\n3.Display\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&key);
                    scanf("%d",&priority);
                    enqueue(key,priority);
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            default:printf("Entered choice is invalid\n");        
        }
    }
    return 0;
}

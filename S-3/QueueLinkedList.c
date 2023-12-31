#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
struct node*front=NULL;
struct node*rear=NULL;
void enqueue(int x){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->data=x;
    if(front==NULL){
        front=newnode;
        rear=newnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else {
        rear->next=newnode;
        rear=newnode;
        newnode->next=NULL;

    }
    }
    void dequeue(){
        struct node*temp=front;
        if(front==NULL){
            printf("Queue is empty\n");
            return;
        }
        if(front==rear){
            front=rear=NULL;
        }
        else{
            front=front->next;
        }
        free(temp);

    }
    void display(){
        struct node*temp=front;
        if(front==NULL){
            printf("Queue is empty\n");
            return;
        }
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }

int main(){
    int x;
    printf("Enter the number of elements to be inserted in the queue\n");
    scanf("%d",&x);
    int ch;
    printf("Enter choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ch);
    while(ch!=4){
        if(ch==1){
            int y;
            printf("Enter the element to be inserted\n");
            scanf("%d",&y);
            enqueue(y);
        }
        else if(ch==2){
            dequeue();
        }
        else if(ch==3){
            display();
        }
        else{
            printf("Invalid choice\n");
        }
        scanf("%d",&ch);
    }
    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node*next;
}*current,*front,*rear,*newnode;
void insertFront(int x){
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    if(front==NULL){
        front=newnode;
        rear=newnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else{
        newnode->next=front;
        front=newnode;
    }
    return;
}

void insertRear(int x){
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    if(front==NULL){
        front=newnode;
        rear=newnode;
        front->next=NULL;
        rear->next=NULL;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=NULL;
    }
    return;
}
void deleteFront(){
    if(front==NULL){
        printf("Nothing to delete\n");
    }
    else{
        current=front;
        front=front->next;
        free(current);
    }
    return;
}
void deleteRear(){
    if(front==NULL){
        printf("Nothing to delete\n");
    }
    else{
        current=front;
        while(current->next!=rear){
            current=current->next;
        }
        current->next=NULL;
        free(rear);
        rear=current;
    }
    return;
}
void display(){
    if(front==NULL){
        printf("Nothing to display\n");
    }
    else{
        current=front;
        while(current->next!=NULL){
            printf("%d->",current->data);
            current=current->next;
        }
        printf("%d",current->data);
        
    }
        printf("\n");
    }
int main(){
    int x,ch;
    while(true){
    printf("1.InsertFront\n2.InsertRear\n3.DeleteFront\n4.DeleteRear\n5.Display\n6.Exit\n");
    printf("Enter your choice:\n");
    scanf("%d",&ch);
    switch(ch){
        case 1:
        printf("Enter the element to be inserted:\n");
        scanf("%d",&x);
        insertFront(x);
        break;
        case 2:
        printf("Enter the element to be inserted:\n");
        scanf("%d",&x);
        insertRear(x);
        break;
        case 3:
        deleteFront();
        break;
        case 4:
        deleteRear();
        break;
        case 5:
        display();
        break;
        case 6:
        exit(0);
        break;
        default:
        printf("Invalid choice\n");}
}
}

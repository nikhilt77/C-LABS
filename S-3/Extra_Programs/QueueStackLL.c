#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*top;
}*head1=NULL,*head2=NULL,*current;

void push(struct node**head,int data){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->top=NULL;
    newnode->data=data;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        newnode->top=*head;
        *head=newnode;
    }
}

int pop(struct node**p){
    if(*p==NULL){
        printf("Stack Underflow\n");
        //return INT_MIN;
    }
    else{
        int popped=(*p)->data;
        struct node*temp=*p;
        *p=(*p)->top;
        free(temp);
        return popped;
    }
}

void enqueue(int data){
    push(&head1,data);
}

int dequeue(){
    if(head1==NULL && head2==NULL){
        printf("Underflow\n");
        //return INT_MIN;
    }
    else{
        if(head2==NULL){
            while(head1!=NULL){
                push(&head2,pop(&head1));
            }
        }
        return pop(&head2);
    }
}

void display(){
    struct node*curr=head2;
    while(curr->top!=NULL){
        printf("%d",curr->data);
        curr=curr->top;
    }
    printf("%d",curr->data);
}

void main(){
    int ch,data;
    while(true){
        printf("1.Enqueue\n2.Dequeue\n3.Display\nEnter choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&data);
                    enqueue(data);
                    break;
            case 2:printf("Dequeued: %d\n", dequeue());
                    break;
            case 3:display();
                break;
            default:printf("Invalid Option\n");    
        }
    }
}

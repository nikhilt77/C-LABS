#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    int priority;
    struct node*next;
}*head=NULL,*temp=NULL,*newnode=NULL,*current;
struct node*create(int data,int priority){
    newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->data=data;
    newnode->priority=priority;
    return newnode;
}
void enqueue(struct node**head,int data,int priority){
    current=*head;
    newnode=create(data,priority);
    if((*head)==NULL){
        newnode->next=*head;
        *head=newnode;
    }
    else if((*head)->priority>priority){
        newnode->next=*head;
        *head=newnode;
    }
    else{
        while(current->next!=NULL&&current->next->priority<priority){
                current=current->next;
        }
        newnode->next=current->next;
        current->next=newnode;
    }
}
void deque(struct node**head){
    temp=*head;
    *head=(*head)->next;
    free(temp);
}
void display(struct node*head){
    current=head;
    while(current->next!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
   printf("->%d\n",current->data);
}
int main(){
    int ch,n,p;
    while(true){
        printf("1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter element and priority:");
                    scanf("%d",&n);
                    scanf("%d",&p);
                    enqueue(&head,n,p);
                    break;
            case 2:deque(&head);
                    break;
            case 3:display(head);
                    break;
            default:printf("Invalid choice");        
        }
    }
    return 0;
}

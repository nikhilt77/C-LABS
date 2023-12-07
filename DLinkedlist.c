#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*prev;
    struct node*next;
}*current,*head,*tail,*newnode,*temp;

void addFront(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        tail=newnode;
        head=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}

void deleteFront(){
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else{
        temp=head;
        head=head->next;
        if(head!=NULL)
            head->prev=NULL;
        else
            tail=NULL;
        free(temp);
    }
}

void insertEnd(int x){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(tail==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void deleteEnd(){
    if(tail==NULL){
        printf("Nothing to delete\n");
    }
    else{
        temp=tail;
        tail=tail->prev;
        if(tail!=NULL)
            tail->next=NULL;
        else
            head=NULL;
        free(temp);
    }
}

void insertSpecific(int x,int search){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        current=head;
        while(current!=NULL){
            if(current->data==search){
                newnode->next=current->next;
                newnode->prev=current;
                if(current->next!=NULL)
                    current->next->prev=newnode;
                else
                    tail=newnode;
                current->next=newnode;
                return;
            }
            current=current->next;
        }
        printf("Element not found\n");
    }
}

void deleteSpecific(int search){
    if(head==NULL){
        printf("Nothing to delete\n");
    }
    else{
        current=head;
        while(current!=NULL){
            if(current->data==search){
                if(current->prev!=NULL)
                    current->prev->next=current->next;
                else
                    head=current->next;
                if(current->next!=NULL)
                    current->next->prev=current->prev;
                else
                    tail=current->prev;
                free(current);
                return;
            }
            current=current->next;
        }
        printf("Element not found\n");
    }
}

void display(){
    if(head==NULL){
        printf("Nothing to display\n");
    }
    else{
        current=head;
        while(current!=NULL){
            printf("<-%d->",current->data);
            current=current->next;
        }
        printf("\n");
    }
}

int main(){
    int ch,data,search;
    
    while(true){
        printf("1.Insert at front\n2.Delete at Front\n3.Insert at rear\n4.Delete at rear\n5.Insert at position\n6.Delete at position\n7.Display\n8.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                   scanf("%d",&data);
                   addFront(data);
                   break;
            case 2:deleteFront();
                   break;
            case 3:printf("Enter data:");
                   scanf("%d",&data);
                   insertEnd(data);
                   break;
            case 4:deleteEnd();
                   break;
            case 5:printf("Enter data:");
                   scanf("%d",&data);
                   printf("Enter search:");
                   scanf("%d",&search);
                   insertSpecific(data,search);
                   break;
            case 6:printf("Enter search:");
                   scanf("%d",&search);
                   deleteSpecific(search);
                   break;
            case 7:display();
                   break;
            case 8:exit(0);
            default:printf("Invalid\n");
        }
    }
    return 0;
}

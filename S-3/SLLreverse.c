#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node*next;
}*current=NULL,*head,*next,*prev,*newnode,*temp;
struct node*createNode(int data){
    newnode=malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
struct node*insertFront(struct node*head,int data){
    if(head==NULL){
        createNode(data);
        head = newnode;
    }
    else{
        newnode=createNode(data);
        newnode->next=head;
        head=newnode;
    }
    return head;
}
struct node*insertLast(struct node*head,int data){
    if(head==NULL){
        createNode(data);
    }
    else{
        current=head;
        newnode=createNode(data);
        while(current!=NULL){
            current=current->next;
        }
        current->next=newnode;
        current=newnode;
    }
    return head;
}
struct node*reverse(struct node*head){
    prev=NULL;
    current=head;
    next=NULL;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}
struct node*deleteFront(struct node*head){
    if(head==NULL){
        printf("List empty");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        current=head;
        head=head->next;
        free(current);
    }
    return head;
}
struct node*deleteRear(struct node*head){
    if(head==NULL){
        printf("List empty");
    }
    else if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        current=head;
        while(current->next->next!=NULL){
            current=current->next;
        }
        temp=current->next;
        current->next=NULL;
        free(temp);
    }
    return head;
}
void display(struct node*head){
    current=head;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
}
int main(){
    int ch,key;
    head=NULL;
    while(true){
        printf("1.Insert at Front\n2.Insert at Rear\n3.Reverse\n4.Delete at Front\n5.Delete at Rear\n6.Display\n");
        printf("Enter choice");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&key);
                    head=insertFront(head,key);
                    display(head);
                    break;
            case 2:printf("Enter data:");
                    scanf("%d",&key);
                    head=insertLast(head,key);
                    break;
            case 3:head=reverse(head);
                    break;
            case 4:head=deleteFront(head);
                    break;
            case 5:head=deleteRear(head);
                    break;
            case 6:display(head);
                    break;
        }
    }
}

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};
struct node*head1=NULL;
struct node*head2=NULL;
struct node*head3=NULL;
struct node*tail1=NULL;
struct node*tail2=NULL;
struct node*tail3=NULL;

void add(struct node**head,struct node**tail,int data){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->prev=NULL;
    newnode->data=data;
    if(*head==NULL){
        *head=*tail=newnode;
    }
    else{
        (*tail)->next=newnode;
        newnode->prev=*tail;
        *tail=newnode;
    }
}
void sort(struct node**h){
    if(*h==NULL){
        printf("Empty\n");
    }
    for(struct node*i=*h;i!=NULL;i=i->next){
        for(struct node*j=i->next;j!=NULL;j=j->next){
            if(i->data>=j->data){
                int temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }
}
void merge(struct node*t1,struct node*t2){
    while(t1!=NULL&&t2!=NULL){
        if(t1->data<=t2->data){
            add(&head3,&tail3,t1->data);
            t1=t1->next;
        }
        else{
            add(&head3,&tail3,t2->data);
            t2=t2->next;
        }
    }
    while(t1!=NULL){
        add(&head3,&tail3,t1->data);
        t1=t1->next;
    }
    while(t2!=NULL){
        add(&head3,&tail3,t2->data);
        t2=t2->next;
    }
}
void reverse(struct node*tail){
    struct node*curr=tail;
    while(curr->prev!=NULL){
        printf("<-%d->",curr->data);
        curr=curr->prev;
    }
    printf("%d\n",curr->data);
}
void display(struct node**h2){
    struct node*current=*h2;
    while(current->next!=NULL){
        printf("<-%d->",current->data);
        current=current->next;
    }
    printf("%d\n",current->data);
}
void main(){
    int ch,data;
    while(true){
        printf("1.Insert 1\n2.Insert 2\n3.Merge\n4.Reverse\n5.Display\nEnter choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&data);
                    add(&head1,&tail1,data);
                    sort(&head1);
                    display(&head1);
                    break;
            case 2:printf("Enter data:");
                    scanf("%d",&data);
                    add(&head2,&tail2,data);
                    sort(&head2);
                    display(&head2);
                    break;
            case 3:merge(head1,head2);
                    display(&head3);
                    break;
            case 4:reverse(tail3);
                    break;
            case 5:sort(&head3);
                    display(&head3);
                    break;
            default:printf("Invalid choice\n");        
        }
    }
}       

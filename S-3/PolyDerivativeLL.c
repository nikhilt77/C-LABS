#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int coeff;
    int expo;
    struct node*next;
}*head1=NULL,*head2=NULL,*current;
void add(struct node**head,int coeff,int expo){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->expo=expo;
    newnode->next=NULL;
    
    if(*head==NULL){
        current=*head=newnode;
    }
    else{
        current->next=newnode;
        current=newnode;
    }
}
void derivative(struct node*p1){
    while(p1!=NULL){
        add(&head2,p1->coeff*p1->expo,p1->expo-1);
        p1=p1->next;
    }
    printf("\n");
}
void display(struct node**h1){
    struct node*curr=*h1;
    while(curr->next!=NULL){
        printf("%dx^%d+",curr->coeff,curr->expo);
        curr=curr->next;
    }
    printf("%dx^%d",curr->coeff,curr->expo);
}

void main(){
    int ch,c1,e1;
    while(true){
        printf("1.Insert\n.2.Derivative\nEnter Choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter coefficient and exponent:");
                    scanf("%d %d",&c1,&e1);
                    add(&head1,c1,e1);
                    display(&head1);
                    break;
            case 2: derivative(head1);
                    display(&head2);
                    break;
            default:printf("Invalid Option\n");        
                    
        }
    }
}

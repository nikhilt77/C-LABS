#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
struct node{
    int coeff;
    int exp;
    struct node*next;
}*head1=NULL,*head2=NULL,*head3=NULL,*temp,*current,*newnode;
void add(struct node**head,int coeff,int exp){
    newnode=malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->next=NULL;
    if(*head==NULL){
        current=*head=newnode;
    }
    else{
        current->next=newnode;
        current=newnode;
    }
}
void check(struct node*p1,struct node*p2){
    while(p1!=NULL&&p2!=NULL){
        if(p1->exp==p2->exp){
            add(&head3,p1->coeff+p2->coeff,p1->exp);
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->exp>p2->exp){
            add(&head3,p1->coeff,p1->exp);
            p1=p1->next;
        }
        else{
            add(&head3,p2->coeff,p2->exp);
            p2=p2->next;
        }
        while(p1!=NULL){
            add(&head3,p1->coeff,p1->exp);
            p1=p1->next;
        }
        while(p2!=NULL){
            add(&head3,p2->coeff,p2->exp);
            p2=p2->next;
        }
    }
}
void display(struct node**head){
    current=*head;
    while(current->next!=NULL){
        printf("%dx^%d+",current->coeff,current->exp);
        current=current->next;
    }
     printf("%dx^%d\n",current->coeff,current->exp);
     
}
void main(){
    int ch,c1,e1,c2,e2;
    while(true){
        printf("1.Polynomial 1\n2.Polynomial 2\n3.Add\n4.Display\5Exit\nEnter choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter coefficient and exponent of 1:");
                    scanf("%d",&c1);
                    scanf("%d",&e1);
                    add(&head1,c1,e1);
                    break;
            case 2:printf("Enter coefficient and exponent of 2:");
                    scanf("%d",&c2);
                    scanf("%d",&e2);
                    add(&head2,c2,e2);
                    break;   
            case 3:check(head1,head2);
                    break;
            case 4:display(&head1);
                    display(&head2);
                    display(&head3);
                    break;
            case 5:exit(0);
                    break;
            default:printf("Invalid");        
        }
    }
}

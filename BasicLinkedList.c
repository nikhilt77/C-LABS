#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};
int main(){
    struct node*first=malloc(sizeof(struct node));
    first->data=40;
    first->next=NULL;
    struct node*second=malloc(sizeof(struct node));
    second->data=50;
    second->next=NULL;
    first->next=second;
    struct node*third=malloc(sizeof(struct node));
    third->data=60;
    third->next=NULL;
    second->next=third;
    struct node*current=first;
    while(current!=NULL){
        printf("%d->",current->data);
        current=current->next;
    }
    return 0;
}
/*  OUTPUT-
    40->50->60
*/

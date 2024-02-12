#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define max 20
char str[max];
struct node{
    char c;
    struct node*next;
};
struct node*head=NULL;
struct node*createNode(char d){
    struct node*newnode=malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->c=d;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node*current = head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next=newnode;
    }
    return newnode;
}
void delete(){
    char t;
    struct node*current=head;
    struct node*temp;
    struct node*del;
    while(current!=NULL){
        t=current->c;
        temp =current;
        while(temp->next!=NULL){
            if(temp->next->c==t){
                del=temp->next;
                temp->next=temp->next->next;
                free(del);
            }
            else{
            temp=temp->next;
            }
        }
        current=current->next;
    }
}
void display(){
    struct node*disp=head;
    while(disp!=NULL){
        printf("%c",disp->c);
        disp=disp->next;
    }
}
void main(){
    int ch;
    while(true){
        printf("1.Input\n2.Delete\n3.Display\nEnter Choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter string:");
                    scanf("%s",str);
                    for(int i=0;i<strlen(str);i++){
                        createNode(str[i]);
                    }
                    display();
                    break;
            case 2:delete();
                    display();
                    break;
            case 3:display();
                    break;
            default:printf("Invalid choice\n");        
        }
    }
}

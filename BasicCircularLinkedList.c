#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node*next;
}*current,*temp,*head,*tail,*newnode;

void insert(int x){
    newnode=malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    
    if(tail==NULL){
        head=newnode;
        tail=newnode;
        newnode->next=head;
    }
    else{
        tail->next = newnode;
        newnode->next = head;
        tail = newnode;
    }
}

void delete(){
    if(head==NULL && tail==NULL){
        printf("Nothing to delete\n");
    }
    else{
        temp=head;
        if(head == tail) {
            head = NULL;
            tail = NULL;
        } else {
            tail->next=head->next;
            head=head->next;
        }
        free(temp);
    }
}

void display(){
    if(head==NULL && tail==NULL){
        printf("Nothing to display\n");
    }
    else{
        current=head;
        do {
            printf("%d->",current->data);
            current=current->next;
        } while(current!=head);
        printf("\n");
    }
}

int main(){
    int ch,data;
    while(true){
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        printf("Enter choice:");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter data:");
                    scanf("%d",&data);
                    insert(data);
                    break;
            case 2:delete();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid\n");
        }
    }
    return 0;
}

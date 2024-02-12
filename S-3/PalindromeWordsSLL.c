#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct node{
    char data[50];
    struct node*next;
};
struct node*head=NULL;

void create(char data[]){
    struct node*newnode=malloc(sizeof(struct node));
    struct node*current=head;
    strcpy(newnode->data, data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        while(current->next != NULL){
            current = current->next;
        }
        current->next=newnode;
    }
}

int isPalindrome(char c[]){
    int start=0,end,l;
    l=strlen(c);
    end=l-1;
    while(start<end){
        if(c[start]!=c[end]){
            return 0;
        }
        start++;
        end--;
    }
    return 1;
}

void display(){
    struct node*curr=head;
    while(curr!=NULL){
        if(isPalindrome(curr->data)){
            printf("%s->",curr->data);
        }
        curr=curr->next;
    }
}

void main(){
    int ch;
    char str[50];
    while(true){
        printf("1.Insert\n2.Display\nEnter Choice:\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter word:");
                    scanf("%s",str);
                    create(str);
                    break;
            case 2:display();
                    break;
            default:printf("Invalid Choice\n");        
        }
    }
}

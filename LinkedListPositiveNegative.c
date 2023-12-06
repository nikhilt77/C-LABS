#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void create(struct node** head, int x){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void Positive(struct node** head, int x){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void Negative(struct node** head, int x){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;
    if(*head == NULL){
        *head = newnode;
    }
    else{
        struct node* current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void printList(struct node* head){
    struct node* current = head;
    while(current != NULL){
        printf("%d->", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct node* head = NULL;
    struct node* positive = NULL;
    struct node* negative = NULL;
    int n, data;
    printf("Enter number of nodes:");
    scanf("%d", &n);
    printf("Enter data:");
    for(int i = 0; i < n; i++){
        scanf("%d", &data);
        create(&head, data);
    }
    struct node* current = head;
    while(current != NULL){
        if(current->data >= 0){
            Positive(&positive, current->data);
        }
        else{
            Negative(&negative, current->data);
        }
        current = current->next;
    }
    printf("Positive list\n");
    printList(positive);
    printf("Negative List\n");
    printList(negative);
    return 0;
}

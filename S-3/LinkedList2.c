#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main() {
    int n;
    struct node *head = NULL; // Initialize head to NULL
    struct node *current = NULL;
    struct node *newnode = NULL;
    struct node *ptr = NULL;

    printf("Enter number of nodes:");
    scanf("%d", &n);
    printf("Enter Data:");
    for (int i = 0; i < n; i++) {
        newnode = malloc(sizeof(struct node));

       // printf("Enter Data:");
        scanf("%d", &newnode->data);
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            current = newnode;
        } else {
            current->next = newnode;
            current = newnode;
        }
 
    }
    
        printf("Display\n");
        ptr = head;
        while (ptr != NULL) {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }

    return 0;
}

#include<stdio.h> // Include standard input and output library
#include<stdlib.h> // Include standard library for dynamic memory allocation

// Define the structure for a node in the linked list
struct node{
    int data; // Data of the node
    struct node*next; // Pointer to the next node
}*current,*head,*newnode,*result,*a,*b; // Declare global pointers

// Function to insert a node in a sorted manner in the linked list
void insertSorted(struct node**head,int x){
    newnode=malloc(sizeof(struct node)); // Allocate memory for a new node
    newnode->data=x; // Assign the input data to the new node
    newnode->next=NULL; // Set the next pointer of the new node to NULL

    // If the list is empty or the new node's data is less than the head's data
    if(*head==NULL||(*head)->data >= newnode->data){
        newnode->next=*head; // Point the new node to the current head
        *head=newnode; // Make the new node the head
    }
    else{
        current=*head; // Start from the head
        // Traverse the list until we find the correct position for the new node
        while(current->next!=NULL&&current->next->data<newnode->data){
            current=current->next; // Move to the next node
        }
        newnode->next=current->next; // Point the new node to the node after the current node
        current->next=newnode; // Point the current node to the new node
    }
}

// Function to merge two sorted linked lists
struct node*merge(struct node*a,struct node*b){
    struct node*result=NULL; // Initialize the result list as NULL

    // If one of the lists is empty, return the other list
    if(a==NULL){
    return b;
    }
    else if(b==NULL){
    return a;
    }

    // Compare the data of the heads of the two lists and add the smaller one to the result list
    else if(a->data<=b->data){
        result=a; // Add 'a' to the result list
        result->next=merge(a->next,b); // Recursively merge the rest of the list
    }
    else{
        result=b; // Add 'b' to the result list
        result->next=merge(a,b->next); // Recursively merge the rest of the list
    }
    return result; // Return the result list
}

// Function to print the linked list
void printList(struct node*temp){
    while(temp!=NULL){ // While there are nodes in the list
        printf("%d\t",temp->data); // Print the data of the current node
        temp=temp->next; // Move to the next node
    }
}

// Main function
int main(){
    result=NULL; // Initialize the result list as NULL
    a=NULL; // Initialize the first list as NULL
    b=NULL; // Initialize the second list as NULL
    int x,n,m; // Declare variables for input and loop control

    printf("Enter number of nodes of Linked List:"); // Prompt the user for input
    scanf("%d",&n); // Read the input
    printf("Enter elements of sorted list 1:"); // Prompt the user for input
    for(int i=0;i<n;i++){ // For each element
        scanf("%d",&x); // Read the element
        insertSorted(&a,x); // Insert the element in the first list
    }

    printf("Enter number of nodes of Linked List 2:"); // Prompt the user for input
    scanf("%d",&m); // Read the input
    printf("Enter elements of sorted list 2:"); // Prompt the user for input
    for(int i=0;i<m;i++){ // For each element
        scanf("%d",&x); // Read the element
        insertSorted(&b,x); // Insert the element in the second list
    }

    result=merge(a,b); // Merge the two lists

    printf("Merged Sorted List:\n"); // Print a message
    printList(result); // Print the result list

    return 0; // Return 0 to indicate successful execution
}

#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int deque[MAX];
int left = -1, right = -1;

void insert_left(int data) {
    if((left == 0 && right == MAX-1) || (left == right+1)) {
        printf("Queue is full\n");
        return;
    }
    if (left == -1) {
        left = 0;
        right = 0;
    }
    else if(left == 0)
        left = MAX - 1;
    else
        left = left-1;
    
    deque[left] = data;
}

void insert_right(int data) {
    if((left == 0 && right == MAX-1) || (left == right+1)) {
        printf("Queue is full\n");
        return;
    }
    if (left == -1) {
        left = 0;
        right = 0;
    }
    else if(right == MAX-1)
        right = 0;
    else
        right = right+1;
    
    deque[right] = data;
}

void delete_left() {
    if (left == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted from left is : %d\n", deque[left]);
    
    if(left == right) {
        left = -1;
        right=-1;
    }
    else if(left == MAX-1)
        left = 0;
    else
        left = left+1;
}

void delete_right() {
    if (left == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Element deleted from right is : %d\n", deque[right]);
    
    if(left == right) {
        left = -1;
        right=-1;
    }
    else if(right == 0)
        right = MAX-1;
    else
        right = right-1;
}

void display_queue() {
    int front = left, rear = right;
    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements in the deque are : ");
    if(front <= rear) {
        while(front <= rear){
            printf("%d ",deque[front]);
            front++;
        }
    } else {
        while(front <= MAX-1) {
            printf("%d ", deque[front]);
            front++;
        }
        front = 0;
        while(front <= rear) {
            printf("%d ",deque[front]);
            front++;
        }
    }
    printf("\n");
}
int main() {
    int choice, data;

    while(1) {
        printf("\n1.Insert at left\n2.Insert at right\n3.Delete from left\n4.Delete from right\n5.Display\n6.Quit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);

        switch(choice) {
            case 1:
                printf("Input the data for insertion at left : ");
                scanf("%d", &data);
                insert_left(data);
                break;
            case 2:
                printf("Input the data for insertion at right : ");
                scanf("%d", &data);
                insert_right(data);
                break;
            case 3:
                delete_left();
                break;
            case 4:
                delete_right();
                break;
            case 5:
                display_queue();
                break;
            case 6:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }

    return 0;
}

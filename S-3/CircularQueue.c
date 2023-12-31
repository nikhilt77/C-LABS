#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define Max 5

int Q[Max];
int rear = -1, front = -1;

bool isEmpty(); // Function prototype

void display() {
    if (isEmpty()) {
        printf("Queue is empty\n");
    } else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", Q[i]);
        }
        printf("\n");
    }
}

bool isEmpty() {
    return front == -1 && rear == -1;
}

bool isFull() {
    return (rear + 1) % Max == front;
}

void enqueue(int element) {
    if (isFull()) {
        printf("Queue Overflow\n");
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % Max;
    }
    Q[rear] = element;
    display();
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow\n");
        return;
    } else {
        front = (front + 1) % Max;
    }
    display();
}

int main() {
    int element, opt;
    while (true) {
        printf("1: Display\n");
        printf("2: Enqueue\n");
        printf("3: Dequeue\n");
        printf("Enter Option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                display();
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 3:
                dequeue();
                break;
            default:
                printf("Invalid option\n");
        }
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* create_node(int value) {
    struct Node* node = malloc(sizeof(struct Node));
    if (node == NULL) {
        printf("Failed to allocate memory for node\n");
        exit(EXIT_FAILURE);
    }
    node->value = value;
    node->next = head;
    head = node;
    return node;
}

void free_nodes() {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    struct Node* node1 = create_node(1);
    struct Node* node2 = create_node(2);
    struct Node* node3 = create_node(3);

    printf("Created nodes with values: %d, %d, %d\n", node1->value, node2->value, node3->value);

    free_nodes();

    return 0;
}

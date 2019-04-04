#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

void list_print(node_t *head);
void list_push(node_t *head, int val);

int main(int argc, char *argv[])
{
    const long length = strtol(argv[1], NULL, 10); // Convert char/string into long.
}

void list_print(node_t *head)
{
    node_t *current = head; // Point the current node to the head of the list.

    while (current != NULL) // Iterate through the sequence until the last node is reached.
    {
        printf("%d\n", current->data); // Print the value of the current node.
        current = current->next;       // Point the current node to the next node.
    }
}

void list_push(node_t *head, int data)
{
    node_t *current = head; // Point the current node to the head of the list.

    while (current->next != NULL) // Iterate through the sequence until the last node is reached.
    {
        current = current->next; // Point the current node to the next node.
    }

    current->next = malloc(sizeof(node_t)); // Allocate space for the new node and point the latest node to it.
    current->next->data = data;             // Populate the added node with the passed in data argument.
    current->next->next = NULL;             // Declare the added node to be the end of the list.
}
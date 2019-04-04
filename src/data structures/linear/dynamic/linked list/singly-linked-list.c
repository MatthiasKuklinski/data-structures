#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t *list_constructor();
void list_free(node_t *head);
void list_print(node_t *head);
void list_push(node_t *head, int val);

int main(int argc, char *argv[])
{
    const long length = strtol(argv[1], NULL, 10); // Convert char/string into long.
    node_t *list = list_constructor(1);            // Create a list and populate the first element with integer 1.
    for (long i = 0; i < length - 1; ++i)
    {
        list_push(list, i + 2);
    }
    list_print(list);
    list_free(list);
}

node_t *list_constructor(int data)
{
    node_t *head = malloc(sizeof(node_t));
    if (head == NULL) // Check if mempory was successfully allocated.
        exit(0);      // Exit the program if no memory was available.

    head->data = data; // Populate the node with the passed in data.
    head->next = NULL; // Declare the node to represent the end of the list.

    return head;
}

void list_free(node_t *head)
{
    node_t *current;

    while (current != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
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
    if (current->next == NULL)              // Check if mempory was successfully allocated.
        exit(0);                            // Exit the program if no memory was available.
    current->next->data = data;             // Populate the added node with the passed in data argument.
    current->next->next = NULL;             // Declare the added node to represent the end of the list.
}
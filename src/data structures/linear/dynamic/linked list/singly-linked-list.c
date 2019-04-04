#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *create();
void free(node *head);
void print(node *head);
void push(node *head, int val);

int main(int argc, char *argv[])
{
/*     const long length = strtol(argv[1], NULL, 10); // Convert char/string into long.
    node *list = list_constructor(1);              // Create a list and populate the first element with integer 1.
    for (long i = 0; i < length - 1; ++i)          //
    {
        list_push(list, i + 2);
    }
    list_print(list);
    list_free(list); */
}

node *create(int data, node *successor)
{
    node *temp_node = malloc(sizeof(node));
    if (temp_node == NULL) // Check if mempory was successfully allocated.
    {
        printf("Error creating a new node: memory allocation failed.\n"); // Print the error message to the user.
        exit(0);                                                          // Exit the program if no memory was available.
    }
    temp_node->data = data;      // Populate the node with the passed in data.
    temp_node->next = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void list_free(node *head)
{
    node *current;

    while (current != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

void list_print(node *head)
{
    node *current = head; // Point the current node to the head of the list.

    while (current != NULL) // Iterate through the sequence until the last node is reached.
    {
        printf("%d\n", current->data); // Print the value of the current node.
        current = current->next;       // Point the current node to the next node.
    }
}

void list_push(node *head, int data)
{
    node *current = head; // Point the current node to the head of the list.

    while (current->next != NULL) // Iterate through the sequence until the last node is reached.
    {
        current = current->next; // Point the current node to the next node.
    }

    current->next = malloc(sizeof(node)); // Allocate space for the new node and point the latest node to it.
    if (current->next == NULL)            // Check if mempory was successfully allocated.
        exit(0);                          // Exit the program if no memory was available.
    current->next->data = data;           // Populate the added node with the passed in data argument.
    current->next->next = NULL;           // Declare the added node to represent the end of the list.
}
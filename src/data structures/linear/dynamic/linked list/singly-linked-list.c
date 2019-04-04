#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef void (*callback)(node *data);

node *sll_create(int data, node *successor);
void sll_traverse(node *head, callback cb);
int sll_length();
void sll_insert(node *head, int data, int index);
void sll_free(node *head);

int main(int argc, char *argv[])
{
    node *list = sll_node_create(1, NULL);
}

node *sll_create(int data, node *successor)
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

void sll_traverse(node *head, callback cb)
{
    node *temp_node = head;
    while (temp_node != NULL)
    {
        cb(temp_node);
        temp_node = temp_node->next;
    }
}

int sll_length(node *head)
{
    node *temp_node = head;
    int length = 0;
    while (temp_node != NULL)
    {
        ++length;
        temp_node = temp_node->next;
    }
    return length;
}

void sll_insert(node *head, int data, int index)
{
    node *temp_node = head;
    for (int i = 0; i < index; i++)
    {
        if (i == index - 1)
        {
            temp_node->next = sll_create(data, temp_node->next);
            return;
        }

        temp_node = temp_node->next;
    }
}

void sll_free(node *head)
{
    node *temp_node;

    while (temp_node != NULL)
    {
        temp_node = head;
        head = head->next;
        free(temp_node);
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
* /
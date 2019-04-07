#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

void sll_print(node_t *node)
{
    printf("%d\n", node->value);
}

node_t *sll_create(const int value, node_t *successor)
{
    node_t *temp_node = malloc(sizeof(node_t)); // Allocate memory.

    if (!temp_node) // Check if mempory was successfully allocated.
    {
        printf("Error creating a new node: memory allocation failed.\n"); // Print the error message to the user.
        exit(1);                                                          // Exit the program if no memory could be allocated.
    }

    temp_node->value = value;    // Populate the node with the passed in data.
    temp_node->next = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void sll_traverse(node_t *node, const callback cb)
{
    while (node) // Iterate through the list.
    {
        cb(node);          // Execute the callback.
        node = node->next; // Point to the successor of the current node.
    }
}

void sll_delete(node_t *node)
{
    node_t *temp_node;

    while (temp_node = node) // Iterate through the list and temporarly store the current node.
    {
        node = node->next; // Point to the address of the successor of the current node.
        free(temp_node);   // Deallocate the memory.
    }
}

int sll_length(node_t *node)
{
    int length = 0; // Set the length to zero.
    while (node)    // Iterate through the list.
    {
        ++length;          // Increment the counter on each iteration.
        node = node->next; // Point to the successor of the current node.
    }

    return length; // Return the computed length.
}

void sll_append(node_t *node, const int value)
{
    while (node->next)
        node = node->next;

    node->next = sll_create(value, NULL);
}

/* void sll_insert(const node *head, const int value, const int index);
{
    if (!head) // Check if the list was initialized.
    {
        printf("Error inserting a new node: head of list is uninitialized.\n");
        return;
    }

    node *temp_node = head;
    for (int i = 1; i <= index; i++)
    {
        if (i == index)
        {
            if (i == 0) // Insert at the beginning of the list.
            {
                temp_node = head;
                head->next = sll_create(temp_node->data, temp_node->next);
                head->data = data;
                return;
            }

            temp_node->next = sll_create(data, temp_node->next); // Insert at the requested index at the list.
            return;
        }

        temp_node = temp_node->next;

        if (!temp_node)
        {
            temp_node = sll_create(data, NULL); // Insert at the end of the list (if the requested index is greater than the list length).
            return;
        }
    }
} */
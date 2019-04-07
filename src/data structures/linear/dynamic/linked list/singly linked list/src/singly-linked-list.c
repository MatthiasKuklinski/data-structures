#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

// Callbacks
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
    if (node)
    {
        while (node->next)
            node = node->next;

        node->next = sll_create(value, NULL);
    }
}

void sll_insert(node_t *node, const int value, const unsigned int index)
{
    if (!node) // Check if the initial node exists.
    {
        printf("Error inserting a new node: head of list is uninitialized.\n");
        return;
    }

    if (index == 0) // Check if the requested insert should be at the head of the list.
    {
        node_t *temp_node = node;                                   // Copy the node.
        node->next = sll_create(temp_node->value, temp_node->next); // Point the successor of the head to the new (old head) node.
        node->value = value;                                        // Change the head node value to the requested value.
    }
    else if (index >= sll_length(node)) // Check if the requested insert should be at the end of the list.
    {
        sll_append(node, value);
    }
    else
    {
        for (int i = 1; i < index; ++i) // Iterate through the list until the requested index(-1) is reached.
        {
            node = node->next;
        }

        node->next = sll_create(value, node->next); // Point the successor of the head to the new (old head) node.
    }
}
#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

// Callbacks
void sll_print(node_t *node)
{
    printf("%d\n", node->value);
}

node_t *sll_construct(const int value, node_t *successor)
{
    node_t *temp_node = malloc(sizeof(node_t)); // Allocate memory.

    if (!temp_node) // Check if mempory was successfully allocated.
        return NULL;

    temp_node->value = value;    // Populate the node with the passed in data.
    temp_node->next = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void sll_destruct(node_t *node)
{
    node_t *temp_node;

    while (temp_node = node) // Iterate through the list and temporarly store the current node.
    {
        node = node->next; // Point to the address of the successor of the current node.
        free(temp_node);   // Deallocate the memory.
    }
}

void sll_prepend(node_t *node, const int value)
{
    if (!node)
        return;

    node_t *temp_node = node;                                      // Copy the node.
    node->next = sll_construct(temp_node->value, temp_node->next); // Point the successor of the head to the new (old head) node.
    node->value = value;                                           // Change the head node value to the requested value.
}

void sll_append(node_t *node, const int value)
{
    if (!node)
        return;

    while (node->next)
        node = node->next;

    node->next = sll_construct(value, NULL);
}

void sll_insert(node_t *node, const int value, const unsigned int index)
{
    if (!node) // Check if the initial node exists.
        return;

    for (int i = 1; i < index; ++i) // Iterate through the list until the requested index(-1) is reached.
        node = node->next;

    node->next = sll_construct(value, node->next); // Point the successor of the head to the new (old head) node.
}

void sll_pop(node_t *node, const unsigned int index)
{
    if (!node)
        return;

    for (int i = 1; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->next;

    node_t *temp_node = node->next;
    node->next = node->next->next;
    free(temp_node);
}

node_t *sll_pop_first(node_t *node)
{
    if (!node)
        return NULL;

    node_t *temp_node = node->next;
    free(node);
    return temp_node;
}

void sll_pop_last(node_t *node)
{
    if (!node)
        return;

    while (node->next->next)
        node = node->next;

    free(node->next);
    node->next = NULL;
}

node_t *sll_get(node_t *node, const unsigned int index)
{
    if (!node)
        return NULL;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->next;

    return node;
}

void sll_set(node_t *node, const unsigned int index, const int value)
{
    if (!node)
        return;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->next;

    node->value = value;
}

void sll_traverse(node_t *node, const sll_callback cb)
{
    while (node) // Iterate through the list.
    {
        cb(node);          // Execute the callback.
        node = node->next; // Point to the successor of the current node.
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
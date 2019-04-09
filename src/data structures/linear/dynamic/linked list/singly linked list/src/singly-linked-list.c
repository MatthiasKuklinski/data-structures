#include "../include/singly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

// Callbacks
void sll_print(sll_node_t *node)
{
    printf("%d\n", node->value);
}

sll_node_t *sll_construct(const int value, sll_node_t *successor)
{
    sll_node_t *temp_node = malloc(sizeof(sll_node_t)); // Allocate memory.

    if (!temp_node) // Check if mempory was successfully allocated.
        return NULL;

    temp_node->value = value;         // Populate the node with the passed in data.
    temp_node->successor = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void sll_destruct(sll_node_t *node)
{
    sll_node_t *temp_node;

    while (temp_node = node) // Iterate through the list and temporarly store the current node.
    {
        node = node->successor; // Point to the address of the successor of the current node.
        free(temp_node);        // Deallocate the memory.
    }
}

void sll_prepend(sll_node_t *node, const int value)
{
    if (!node)
        return;

    sll_node_t *temp_node = node;                                            // Copy the node.
    node->successor = sll_construct(temp_node->value, temp_node->successor); // Point the successor of the head to the new (old head) node.
    node->value = value;                                                     // Change the head node value to the requested value.
}

void sll_append(sll_node_t *node, const int value)
{
    if (!node)
        return;

    while (node->successor)
        node = node->successor;

    node->successor = sll_construct(value, NULL);
}

void sll_insert(sll_node_t *node, const int value, const unsigned int index)
{
    if (!node) // Check if the initial node exists.
        return;

    for (int i = 1; i < index; ++i) // Iterate through the list until the requested index(-1) is reached.
        node = node->successor;

    node->successor = sll_construct(value, node->successor); // Point the successor of the head to the new (old head) node.
}

void sll_pop(sll_node_t *node, const unsigned int index)
{
    if (!node)
        return;

    for (int i = 1; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    sll_node_t *temp_node = node->successor;
    node->successor = node->successor->successor;
    free(temp_node);
}

sll_node_t *sll_pop_first(sll_node_t *node)
{
    if (!node)
        return NULL;

    sll_node_t *temp_node = node->successor;
    free(node);
    return temp_node;
}

void sll_pop_last(sll_node_t *node)
{
    if (!node)
        return;

    while (node->successor->successor)
        node = node->successor;

    free(node->successor);
    node->successor = NULL;
}

sll_node_t *sll_get(sll_node_t *node, const unsigned int index)
{
    if (!node)
        return NULL;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    return node;
}

void sll_set(sll_node_t *node, const unsigned int index, const int value)
{
    if (!node)
        return;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    node->value = value;
}

void sll_traverse(sll_node_t *node, const sll_callback cb)
{
    while (node) // Iterate through the list.
    {
        cb(node);               // Execute the callback.
        node = node->successor; // Point to the successor of the current node.
    }
}

int sll_length(sll_node_t *node)
{
    int length = 0; // Set the length to zero.
    while (node)    // Iterate through the list.
    {
        ++length;               // Increment the counter on each iteration.
        node = node->successor; // Point to the successor of the current node.
    }

    return length; // Return the computed length.
}

sll_node_t *sll_reverse(sll_node_t *node)
{
    if (!node)
        return node;

    sll_node_t *predecessor = NULL;
    sll_node_t *successor;
    while (node)
    {
        successor = node->successor;
        node->successor = predecessor;
        predecessor = node;
        node = successor;
    }
    return predecessor;
}
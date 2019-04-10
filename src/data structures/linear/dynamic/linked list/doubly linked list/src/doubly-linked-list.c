#include "../include/doubly-linked-list.h"

#include <stdio.h>
#include <stdlib.h>

dll_node_t *dll_construct(const int value, dll_node_t *predecessor, dll_node_t *successor)
{
    dll_node_t *temp_node = malloc(sizeof(dll_node_t)); // Allocate memory.

    if (!temp_node) // Check if mempory was successfully allocated.
        return NULL;

    temp_node->value = value; // Populate the node with the passed in data.
    temp_node->predecessor = predecessor;
    temp_node->successor = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}

void dll_destruct(dll_node_t *node)
{
    dll_node_t *temp_node;

    while (temp_node = node) // Iterate through the list and temporarly store the current node.
    {
        node = node->successor; // Point to the address of the successor of the current node.
        free(temp_node);        // Deallocate the memory.
    }
}
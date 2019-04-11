#include <dll_node.h>

#include <stdio.h>
#include <stdlib.h>

dll_node_t *dll_node(const int value, dll_node_t *predecessor, dll_node_t *successor)
{
    dll_node_t *node = malloc(sizeof(dll_node_t)); // Allocate memory.

    if (!node) // Check if mempory was successfully allocated.
        return NULL;

    node->value = value; // Populate the node with the passed in data.
    node->predecessor = predecessor;
    node->successor = successor; // Declare the node to represent the end of the list.

    return node; // Return a pointer to the new node.
}
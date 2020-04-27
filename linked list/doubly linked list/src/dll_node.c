#include <dll_node.h>

#include <stdio.h>
#include <stdlib.h>

dll_node_t *dll_node(const int value, dll_node_t *predecessor, dll_node_t *successor)
{
    dll_node_t *node = malloc(sizeof(dll_node_t)); // Try to allocate memory for the head node.

    if (!node) // Check if memory was successfully allocated.
        return NULL;

    node->value = value;             // Set the value.
    node->predecessor = predecessor; // Set the predecessor.
    node->successor = successor;     // Set the successor.

    return node; // Return a pointer to the created node.
}
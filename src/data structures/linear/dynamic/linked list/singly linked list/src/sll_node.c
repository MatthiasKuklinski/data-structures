#include <sll_node.h>

#include <stdio.h>
#include <stdlib.h>

sll_node_t *sll_node(const int value, sll_node_t *successor)
{
    sll_node_t *temp_node = malloc(sizeof(sll_node_t)); // Allocate memory.

    if (!temp_node) // Check if mempory was successfully allocated.
        return NULL;

    temp_node->value = value;         // Populate the node with the passed in data.
    temp_node->successor = successor; // Declare the node to represent the end of the list.

    return temp_node; // Return a pointer to the new node.
}
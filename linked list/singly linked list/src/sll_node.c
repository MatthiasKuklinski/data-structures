#include <sll_node.h>

#include <stdio.h>
#include <stdlib.h>

sll_node_t *sll_node(const int element, sll_node_t *next)
{
    sll_node_t *sll_node = NULL;                  // Initialize a null pointer for the node structure itself.
    if (!(sll_node = malloc(sizeof(sll_node_t)))) // Try to allocate sufficient memory on the heap.
        return NULL;

    sll_node->element = element; // Initialize the nodes element with the passed in element value.
    sll_node->next = next;       // Store the memory address of the the successing node.
    return sll_node;
}
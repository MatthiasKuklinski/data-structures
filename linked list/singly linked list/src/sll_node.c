#include "sll_node.h"

#include <stdio.h>
#include <stdlib.h>

sll_node_t *sll_node(const int element, sll_node_t *next, status_code_t *status_code)
{
    sll_node_t *sll_node = NULL;                  // Initialize a null pointer for the node structure itself.
    if (!(sll_node = malloc(sizeof(sll_node_t)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return sll_node;                      // Sll_node will be null, since there is no sufficient memory on the heap.
    }

    sll_node->element = element; // Initialize the nodes element with the passed in element value.
    sll_node->next = next;       // Store the memory address of the the successing node.

    *status_code = success; // Set the correspoding status code.
    return sll_node;
}
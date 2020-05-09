#include "dll_node.h"

#include <stdio.h>
#include <stdlib.h>

dll_node_t *dll_node(const int element, dll_node_t *prev, dll_node_t *next, status_code_t *status_code)
{
    dll_node_t *dll_node = NULL;                  // Initialize a null pointer for the node structure itself.
    if (!(dll_node = malloc(sizeof(dll_node_t)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return dll_node;                      // Dll_node will be null, since there is no sufficient memory on the heap.
    }

    dll_node->element = element; // Initialize the nodes element with the passed in element value.
    dll_node->prev = prev;       // Store the memory address of the the preceding node.
    dll_node->next = next;       // Store the memory address of the the succeeding node.

    *status_code = success; // Set the correspoding status code.
    return dll_node;
}
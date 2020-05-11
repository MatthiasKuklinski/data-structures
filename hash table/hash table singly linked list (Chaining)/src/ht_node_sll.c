#include "ht_node_sll.h"

#include <stdio.h>

ht_node_sll_t *ht_node_sll(const char *key, const char *element, status_code_t *status_code)
{
    ht_node_sll_t *ht_node_sll = NULL; // Initialize a null pointer for the node structure itself.

    // Try to allocate sufficient memory on the heap.
    if (!(ht_node_sll = malloc(sizeof(ht_node_sll_t))) || !(ht_node_sll->key = malloc(strlen(key) + 1)) || !(ht_node_sll->element = malloc(strlen(element) + 1)))
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return ht_node_sll;                   // ht_node_sll will be null, since there was no sufficient memory on the heap to be allocated for it.
    }

    strcpy(ht_node_sll->key, key);         // Copy the key argument into the node key.
    strcpy(ht_node_sll->element, element); // Copy the element argument into the node element.

    ht_node_sll->next = NULL; // Signal that this node has no successor.

    *status_code = success; // Set the correspoding status code.
    return ht_node_sll;
}
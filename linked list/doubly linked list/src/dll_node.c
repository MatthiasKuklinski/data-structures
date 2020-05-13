#include "dll_node.h"

dll_node_t *dll_node_alloc(const size_t element, dll_node_t *prev, dll_node_t *next)
{
    dll_node_t *dll_node = malloc(sizeof(dll_node_t));

    dll_node->element = element;
    dll_node->prev = prev;
    dll_node->next = next;

    return dll_node;
}

void dll_node_dealloc(dll_node_t **dll_node)
{
    free(*dll_node);
    *dll_node = NULL;
}
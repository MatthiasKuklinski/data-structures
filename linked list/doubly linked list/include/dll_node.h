#pragma once

#include <stdlib.h>

typedef struct dll_node
{
    size_t element;
    struct dll_node *prev;
    struct dll_node *next;
} dll_node_t;

dll_node_t *dll_node_alloc(const size_t element, dll_node_t *prev, dll_node_t *next);
void dll_node_dealloc(dll_node_t **dll_node);
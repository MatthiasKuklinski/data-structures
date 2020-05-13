#pragma once

#include <stdlib.h>

typedef struct sll_node
{
    size_t element;
    struct sll_node *next;
} sll_node_t;

sll_node_t *sll_node_alloc(const size_t element, sll_node_t *next);
void sll_node_dealloc(sll_node_t **sll_node);
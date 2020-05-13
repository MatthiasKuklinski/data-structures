#pragma once

#include <stdlib.h>

typedef struct sll_node
{
    int element;
    struct sll_node *next;
} sll_node_t;

sll_node_t *sll_node_alloc(const int element, sll_node_t *next);
void sll_node_dealloc(sll_node_t **sll_node);
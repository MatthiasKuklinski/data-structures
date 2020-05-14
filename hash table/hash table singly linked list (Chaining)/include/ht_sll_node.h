#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct ht_sll_node
{
    char *key;
    char *element;
    struct ht_sll_node *next;
} ht_sll_node_t;

ht_sll_node_t *ht_sll_node_alloc(const char *key, const char *element, ht_sll_node_t *next);
void ht_sll_node_dealloc(ht_sll_node_t **ht_sll_node);
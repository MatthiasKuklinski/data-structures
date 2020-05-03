#pragma once

#include "sll_node.h"

typedef enum status_code
{
    success = 0,
    sll_node_ptr_is_null = -1,
    insufficient_heap_mem = -2,
} status_code_t;

int sll_length(sll_node_t *sll_head_node, status_code_t *status_code);
void sll_delete(sll_node_t *sll_head_node, status_code_t *status_code);
void sll_insert(sll_node_t *sll_head_node, const int element, const unsigned int index, status_code_t *status_code);
void sll_prepend(sll_node_t *sll_head_node, const int element, status_code_t *status_code);
void sll_append(sll_node_t *sll_head_node, const int element, status_code_t *status_code);

/*
void sll_pop(sll_node_t *node, const unsigned int index);
void sll_pop_first(sll_node_t **node);
void sll_pop_last(sll_node_t *node);

sll_node_t *sll_get(sll_node_t *node, const unsigned int index);
void sll_set(sll_node_t *node, const unsigned int index, const int value);
*/

// void sll_reverse(sll_node_t **node);
void sll_traverse(sll_node_t *node, void (*fp)(sll_node_t *), status_code_t *status_code);
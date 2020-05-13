#pragma once

#include <stdlib.h>

#include "sll_node.h"

void sll_dealloc(sll_node_t **sll_head_node);
void sll_insert(sll_node_t *sll_head_node, const size_t element, const size_t index);
void sll_append(sll_node_t *sll_head_node, const size_t element);
void sll_prepend(sll_node_t *sll_head_node, const size_t element);
void sll_pop(sll_node_t **sll_head_node, const size_t index);
void sll_pop_first(sll_node_t **sll_head_node);
void sll_pop_last(sll_node_t **sll_head_node);
sll_node_t *sll_get(const sll_node_t *sll_head_node, const size_t index);
void sll_set(sll_node_t *sll_head_node, const size_t index, const size_t element);
void sll_reverse(sll_node_t **sll_head_node);
void sll_traverse(sll_node_t **sll_head_node, void (*fp)(sll_node_t **sll_node));
size_t sll_length(const sll_node_t *sll_head_node);
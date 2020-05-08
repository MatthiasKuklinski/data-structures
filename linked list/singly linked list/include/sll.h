#pragma once

#include "sll_status_codes.h"
#include "sll_node.h"

int sll_length(sll_node_t *sll_head_node, status_code_t *status_code);
void sll_delete(sll_node_t *sll_head_node, status_code_t *status_code);
void sll_insert(sll_node_t *sll_head_node, const int element, const unsigned int index, status_code_t *status_code);
void sll_prepend(sll_node_t *sll_head_node, const int element, status_code_t *status_code);
void sll_append(sll_node_t *sll_head_node, const int element, status_code_t *status_code);
void sll_pop(sll_node_t *sll_head_node, const unsigned int index, status_code_t *status_code);
void sll_pop_first(sll_node_t **sll_head_node, status_code_t *status_code);
void sll_pop_last(sll_node_t *sll_head_node, status_code_t *status_code);
sll_node_t *sll_get(sll_node_t *sll_head_node, const unsigned int index, status_code_t *status_code);
void sll_set(sll_node_t *sll_head_node, const unsigned int index, const int element, status_code_t *status_code);
void sll_reverse(sll_node_t **sll_head_node, status_code_t *status_code);
void sll_traverse(sll_node_t *sll_head_node, void (*fp)(sll_node_t *), status_code_t *status_code);
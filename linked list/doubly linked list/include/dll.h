#pragma once

#include "dll_status_codes.h"
#include "dll_node.h"

int dll_length(dll_node_t *dll_head_node, status_code_t *status_code);
void dll_delete(dll_node_t **dll_head_node, status_code_t *status_code);
void dll_insert(dll_node_t *dll_head_node, const int element, const unsigned int index, status_code_t *status_code);
void dll_prepend(dll_node_t *dll_head_node, const int element, status_code_t *status_code);
void dll_append(dll_node_t *dll_head_node, const int element, status_code_t *status_code);
void dll_pop(dll_node_t **dll_head_node, const unsigned int index, status_code_t *status_code);
void dll_pop_first(dll_node_t **dll_head_node, status_code_t *status_code);
void dll_pop_last(dll_node_t **dll_head_node, status_code_t *status_code);
dll_node_t *dll_get(dll_node_t *dll_head_node, const unsigned int index, status_code_t *status_code);
void dll_set(dll_node_t *dll_head_node, const unsigned int index, const int element, status_code_t *status_code);
void dll_reverse(dll_node_t **dll_head_node, status_code_t *status_code);
void dll_traverse(dll_node_t *dll_head_node, void (*fp)(dll_node_t *), status_code_t *status_code);
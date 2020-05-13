#pragma once

#include "dll_node.h"

void dll_dealloc(dll_node_t **dll_head_node);
void dll_insert(dll_node_t *dll_head_node, const size_t element, const size_t index);
void dll_append(dll_node_t *dll_head_node, const size_t element);
void dll_prepend(dll_node_t *dll_head_node, const size_t element);
void dll_pop(dll_node_t **dll_head_node, const size_t index);
void dll_pop_first(dll_node_t **dll_head_node);
void dll_pop_last(dll_node_t **dll_head_node);
dll_node_t *dll_get(const dll_node_t *dll_head_node, const size_t index);
void dll_set(dll_node_t *dll_head_node, const size_t index, const size_t element);
void dll_reverse(dll_node_t **dll_head_node);
void dll_traverse(dll_node_t **dll_head_node, void (*fp)(dll_node_t **dll_node));
size_t dll_length(const dll_node_t *dll_head_node);
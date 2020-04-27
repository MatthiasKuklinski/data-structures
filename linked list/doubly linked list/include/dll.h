#pragma once
#include "dll_node.h"

typedef void (*dll_callback)(dll_node_t *node);

void dll_delete(dll_node_t *node);

void dll_insert(dll_node_t *node, const int value, const unsigned int index);
void dll_prepend(dll_node_t *node, const int value);
void dll_append(dll_node_t *node, const int value);

void dll_pop(dll_node_t *node, const unsigned int index);
void dll_pop_first(dll_node_t **node);
void dll_pop_last(dll_node_t *node);

dll_node_t *dll_get(dll_node_t *node, const unsigned int index);
void dll_set(dll_node_t *node, const unsigned int index, int value);

void dll_reverse(dll_node_t **node);
void dll_traverse(dll_node_t *node, const dll_callback cb);
unsigned long dll_length(dll_node_t *node);
#pragma once
#include "doubly-linked-list-node.h"

typedef void (*dll_callback)(dll_node_t *node);

dll_node_t *dll_construct(const int value, dll_node_t *predecessor, dll_node_t *successor);
void dll_destruct(dll_node_t *node);

void dll_traverse(dll_node_t *node, const dll_callback cb);
void dll_print(dll_node_t *node);
#pragma once
#include "doubly-linked-list-node.h"

dll_node_t *dll_construct(const int value, dll_node_t *predecessor, dll_node_t *successor);
void dll_destruct(dll_node_t *node);
#pragma once
#include "dll_node.h"

typedef void (*dll_callback)(dll_node_t *node);

void dll_destroy(dll_node_t *node);

void dll_prepend(dll_node_t *node, const int value);
void dll_append(dll_node_t *node, const int value);

void dll_traverse(dll_node_t *node, const dll_callback cb);
void dll_print(dll_node_t *node);
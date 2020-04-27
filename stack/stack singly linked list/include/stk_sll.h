#pragma once

#include <stk_sll_node.h>

typedef void (*stk_sll_callback)(stk_sll_node_t *node);

stk_sll_node_t *stk_sll(const int value, stk_sll_node_t *successor);
void stk_sll_delete(stk_sll_node_t *node);
void stk_sll_traverse(stk_sll_node_t *node, const stk_sll_callback cb);
void stk_sll_push(stk_sll_node_t *node, const int value);
void stk_sll_pop(stk_sll_node_t *node);
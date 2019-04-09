#pragma once
#include "singly-linked-list-node.h"

typedef void (*sll_callback)(sll_node_t *node);

sll_node_t *sll_construct(const int value, sll_node_t *successor);
void sll_destruct(sll_node_t *node);

void sll_prepend(sll_node_t *node, const int value);
void sll_append(sll_node_t *node, const int value);
void sll_insert(sll_node_t *node, const int value, const unsigned int index);

void sll_pop(sll_node_t *node, const unsigned int index);
sll_node_t *sll_pop_first(sll_node_t *node);
void sll_pop_last(sll_node_t *node);

sll_node_t *sll_get(sll_node_t *node, const unsigned int index);
void sll_set(sll_node_t *node, const unsigned int index, const int value);

void sll_traverse(sll_node_t *node, const sll_callback cb);
int sll_length(sll_node_t *node);
void sll_print(sll_node_t *node);
sll_node_t *sll_reverse(sll_node_t *node);
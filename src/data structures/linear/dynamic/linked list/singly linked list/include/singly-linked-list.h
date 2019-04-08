#pragma once
#include "singly-linked-list-node.h"

typedef void (*sll_callback)(node_t *node);

node_t *sll_construct(const int value, const node_t *successor);
void sll_destruct(node_t *node);

void sll_prepend(node_t *node, const int value);
void sll_append(node_t *node, const int value);
void sll_insert(node_t *node, const int value, const unsigned int index);

void sll_pop(node_t *node, const unsigned int index);
void sll_pop_first(node_t *node);
void sll_pop_last(node_t *node);

node_t *sll_get(node_t *node, const unsigned int index);
void sll_set(node_t *node, const unsigned int index, const int value);

void sll_traverse(node_t *node, const sll_callback cb);
int sll_length(node_t *node);
void sll_print(node_t *node);
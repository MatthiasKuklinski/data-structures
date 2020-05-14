#pragma once

#include "ht_sll_node.h"

typedef struct ht_sll
{
    ht_sll_node_t **hashes;
    size_t capacity;
} ht_sll_t;

ht_sll_t *ht_sll_alloc(const size_t capacity);
void ht_sll_dealloc(ht_sll_t **ht_sll);
void ht_sll_set(ht_sll_t *ht_sll, const char *key, const char *element);
ht_sll_node_t *ht_sll_get(ht_sll_t *ht_sll, const char *key);
size_t compHash(const size_t capacity, const char *key);
void ht_sll_traverse(ht_sll_t **ht_sll, void (*fp)(ht_sll_node_t **ht_sll_node));
void ht_sll_remove(ht_sll_t *ht_sll, const char *key);
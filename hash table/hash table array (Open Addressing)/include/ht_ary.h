#pragma once

#include "ht_ary_entry.h"

#include <stdlib.h>

typedef struct ht_ary
{
    ht_ary_entry_t **hashes;
    size_t capacity;
} ht_ary_t;

ht_ary_t *ht_ary_alloc(const size_t capacity);
void ht_ary_dealloc(ht_ary_t **ht_ary);
void ht_ary_set(ht_ary_t *ht_ary, ht_ary_entry_t *ht_ary_entry);
ht_ary_entry_t *ht_ary_get(ht_ary_t *ht_ary, const char *key);
size_t compHash(const size_t capacity, const char *key);
void ht_ary_traverse(ht_ary_t **ht_ary, void (*fp)(ht_ary_entry_t **ht_ary_entry));
void ht_ary_remove(ht_ary_t *ht_ary, const char *key);
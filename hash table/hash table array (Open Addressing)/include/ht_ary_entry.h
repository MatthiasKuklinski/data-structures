#pragma once

#include <stdlib.h>
#include <string.h>

typedef struct ht_ary_entry
{
    char *key;
    char *element;
} ht_ary_entry_t;

ht_ary_entry_t *ht_ary_entry_alloc(const char *key, const char *element);
void ht_ary_entry_dealloc(ht_ary_entry_t **ht_ary_entry);
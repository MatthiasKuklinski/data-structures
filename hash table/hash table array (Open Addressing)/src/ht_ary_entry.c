#include "ht_ary_entry.h"

ht_ary_entry_t *ht_ary_entry_alloc(const char *key, const char *element)
{
    ht_ary_entry_t *ht_ary_entry = malloc(sizeof(ht_ary_entry_t));
    ht_ary_entry->key = malloc(strlen(key) + 1);
    ht_ary_entry->element = malloc(strlen(element) + 1);

    strcpy(ht_ary_entry->key, key);
    strcpy(ht_ary_entry->element, element);

    return ht_ary_entry;
}

void ht_ary_entry_dealloc(ht_ary_entry_t **ht_ary_entry)
{
    free((*ht_ary_entry)->key);
    free((*ht_ary_entry)->element);
    free(*ht_ary_entry);
    *ht_ary_entry = NULL;
}
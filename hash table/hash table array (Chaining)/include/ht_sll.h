#pragma once

#include <stdlib.h>

#include "ht_sll_status_codes.h"
#include "ht_entry_sll.h"

typedef struct ht_sll
{
    ht_entry_sll_t **entries;
} ht_sll_t;

ht_sll_t *ht_sll(size_t capacity, status_code_t *status_code);
void ht_sll_set(ht_sll_t *ht, const char *key, const char *element, status_code_t *status_code);
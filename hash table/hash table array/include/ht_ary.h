#pragma once

#include "ht_ary_status_codes.h"
#include "ht_entry_ary.h"

typedef struct ht_ary
{
    ht_entry_ary_t **entries;
} ht_ary_t;

ht_ary_t *ht_ary(size_t capacity, status_code_t * status_code);
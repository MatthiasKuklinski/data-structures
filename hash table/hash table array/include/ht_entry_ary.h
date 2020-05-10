#pragma once

#include "ht_ary_status_codes.h"

typedef struct ht_entry_ary
{
    char *key;
    char *element;
    struct ht_entry_ary *next;
} ht_entry_ary_t;

ht_entry_ary_t *ht_entry_ary(const char *key, const char *element, status_code_t *status_code);
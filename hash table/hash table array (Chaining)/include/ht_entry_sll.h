#pragma once

#include "ht_sll_status_codes.h"

typedef struct ht_entry_sll
{
    char *key;
    char *element;
    struct ht_entry_sll *next;
} ht_entry_sll_t;

ht_entry_sll_t *ht_entry_sll(const char *key, const char *element, status_code_t *status_code);
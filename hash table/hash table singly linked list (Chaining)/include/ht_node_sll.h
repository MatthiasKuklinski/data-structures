#pragma once

#include <stdlib.h>

#include "ht_sll_status_codes.h"

typedef struct ht_node_sll
{
    char *key;
    char *element;
    struct ht_node_sll *next;
} ht_node_sll_t;

ht_node_sll_t *ht_node_sll(const char *key, const char *element, status_code_t *status_code);
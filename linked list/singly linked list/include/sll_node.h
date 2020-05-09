#pragma once

#include "sll_status_codes.h"

typedef struct sll_node
{
    int element;           // Store the value of the node.
    struct sll_node *next; // Point to the successing node.
} sll_node_t;

sll_node_t *sll_node(const int element, sll_node_t *next, status_code_t *status_code); // Construct the node structure.
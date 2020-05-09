#pragma once

#include "dll_status_codes.h"

typedef struct dll_node
{
    int element;           // Store the value of the node.
    struct dll_node *prev; // Point to the preceding node.
    struct dll_node *next; // Point to the succeeding node.
} dll_node_t;

dll_node_t *dll_node(const int element, dll_node_t *prev, dll_node_t *next, status_code_t *status_code);
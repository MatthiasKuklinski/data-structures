#pragma once

typedef struct node
{
    int value;
    struct node *predecessor;
    struct node *successor;
} dll_node_t;

dll_node_t *dll_node_construct(const int value, dll_node_t *predecessor, dll_node_t *successor);
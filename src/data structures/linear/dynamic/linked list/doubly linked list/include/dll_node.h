#pragma once

typedef struct node
{
    int value;
    struct node *predecessor;
    struct node *successor;
} dll_node_t;

dll_node_t *dll_node(const int value, const dll_node_t *predecessor, const dll_node_t *successor);
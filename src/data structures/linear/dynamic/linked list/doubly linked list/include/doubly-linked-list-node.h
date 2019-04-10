#pragma once

typedef struct node
{
    int value;
    struct node *predecessor;
    struct node *successor;
} dll_node_t;
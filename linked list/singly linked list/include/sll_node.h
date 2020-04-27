#pragma once

typedef struct node
{
    int value;
    struct node *successor;
} sll_node_t;

sll_node_t *sll_node(const int value, sll_node_t *successor);
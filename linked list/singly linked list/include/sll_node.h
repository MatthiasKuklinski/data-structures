#pragma once

typedef struct sll_node
{
    int element;       // Store the value of the node.
    struct node *next; // Point to the successing node.
} sll_node_t;

sll_node_t *sll_node(const int element, sll_node_t *next); // Construct the node structure.
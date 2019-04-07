#pragma once

typedef struct node
{
    int value;
    struct node *next;
} node_t;

typedef void (*callback)(node_t *node);

node_t *sll_create(const int value, node_t *successor);
void sll_traverse(node_t *node, const callback cb);
void sll_delete(node_t *node);
int sll_length(node_t *node);
void sll_append(node_t *node, const int value);
// void sll_insert(const node *head, const int value, const int index);
void sll_print(node_t *node);
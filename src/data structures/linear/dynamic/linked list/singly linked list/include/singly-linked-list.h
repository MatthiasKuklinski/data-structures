#pragma once

typedef struct node
{
    int value;
    struct node *next;
} node_t;

typedef void (*sll_callback)(node_t *node);

node_t *sll_create(const int value, node_t *successor);
void sll_traverse(node_t *node, const sll_callback cb);
void sll_free(node_t *node);
void sll_delete(node_t *node, const unsigned int index);
int sll_length(node_t *node);
void sll_prepend(node_t *node, const int value);
void sll_append(node_t *node, const int value);
void sll_insert(node_t *node, const int value, const unsigned int index);
void sll_print(node_t *node);
node_t *sll_get(node_t *node, const int index);

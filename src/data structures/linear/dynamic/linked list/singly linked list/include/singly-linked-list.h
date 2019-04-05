#pragma once

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef void (*callback)(node *value);

node *sll_create(const int value, const node *successor);
void sll_traverse(const node *head, const callback cb);
void sll_print(node *value);
int sll_length(node *head);
void sll_insert(node *head, int value, int index);
void sll_free(node *head);
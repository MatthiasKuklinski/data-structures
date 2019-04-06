#pragma once

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef void (*callback)(node *value);

node *sll_create(const int value, const node *successor);
void sll_traverse(const node *head, const callback cb);
int sll_length(const node *head);
// void sll_insert(const node *head, const int value, const int index);
void sll_print(node *value);
void sll_delete(node *head);
#pragma once

typedef struct node
{
    int data;
    struct node *next;
} node;

typedef void (*callback)(node *data);

node *sll_create(int data, node *successor);
void sll_traverse(node *head, callback cb);
void sll_print(node *data);
int sll_length(node *head);
void sll_insert(node *head, int data, int index);
void sll_free(node *head);
#include <stk_sll.h>

#include <stdio.h>
#include <stdlib.h>

stk_sll_node_t *stk_sll(const int value, stk_sll_node_t *successor)
{
    stk_sll_node_t *temp_node = malloc(sizeof(stk_sll_node_t));

    if (!temp_node)
        return NULL;

    temp_node->value = value;
    temp_node->successor = successor;

    return temp_node;
}

void stk_sll_delete(stk_sll_node_t *node)
{
    stk_sll_node_t *temp_node;

    while (temp_node = node) // Iterate through the list and temporarly store the current node.
    {
        node = node->successor; // Point to the address of the successor of the current node.
        free(temp_node);        // Deallocate the memory.
    }
}

void stk_sll_traverse(stk_sll_node_t *node, const stk_sll_callback cb)
{
    while (node) // Iterate through the list.
    {
        cb(node);               // Execute the callback.
        node = node->successor; // Point to the successor of the current node.
    }
}

void stk_sll_push(stk_sll_node_t *node, const int value)
{
    if (!node)
        return;

    while (node->successor)
        node = node->successor;

    node->successor = stk_sll(value, NULL);
}

void stk_sll_pop(stk_sll_node_t *node)
{
    if (!node)
        return;

    while (node->successor->successor)
        node = node->successor;

    free(node->successor);
    node->successor = NULL;
}
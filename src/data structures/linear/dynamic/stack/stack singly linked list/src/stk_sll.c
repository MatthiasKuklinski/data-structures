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
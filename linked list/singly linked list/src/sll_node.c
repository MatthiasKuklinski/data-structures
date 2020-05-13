#include "sll_node.h"

sll_node_t *sll_node_alloc(const size_t element, sll_node_t *next)
{
    sll_node_t *sll_node = malloc(sizeof(sll_node_t));

    sll_node->element = element;
    sll_node->next = next;

    return sll_node;
}

void sll_node_dealloc(sll_node_t **sll_node)
{
    free(*sll_node);
    *sll_node = NULL;
}
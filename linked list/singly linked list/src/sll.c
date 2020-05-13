#include "sll.h"

size_t sll_length(const sll_node_t *sll_head_node)
{
    size_t n = 0;
    while (sll_head_node)
    {
        n++;
        sll_head_node = sll_head_node->next;
    }
    return n;
}

void sll_dealloc(sll_node_t **sll_head_node)
{
    sll_traverse(sll_head_node, sll_node_dealloc);
}

void sll_insert(sll_node_t *sll_head_node, const size_t element, const size_t index)
{
    for (size_t i = 1; i < index; ++i)
        sll_head_node = sll_head_node->next;

    sll_head_node->next = sll_node_alloc(element, sll_head_node->next);
}

void sll_prepend(sll_node_t *sll_head_node, const size_t element)
{
    // Create a new succeeding node and point the next pointer at it.
    // Set the former head node element as the new node's element.
    sll_head_node->next = sll_node_alloc(sll_head_node->element, sll_head_node->next);
    sll_head_node->element = element;
}

void sll_append(sll_node_t *sll_head_node, const size_t element)
{
    while (sll_head_node->next)
        sll_head_node = sll_head_node->next;

    sll_head_node->next = sll_node_alloc(element, NULL);
}

void sll_pop(sll_node_t **sll_head_node, const size_t index)
{
    if (index == 0)
    {
        sll_pop_first(sll_head_node);
        return;
    }

    if (index == sll_length(*sll_head_node) - 1)
    {
        sll_pop_last(sll_head_node);
        return;
    }

    sll_node_t *temp_sll_node = *sll_head_node;
    for (size_t i = 1; i < index; ++i) // Iterate through the list until index - 1.
        temp_sll_node = temp_sll_node->next;

    sll_node_t *temp_popped_sll_node = temp_sll_node->next;
    // Set the node's (at index - 1) succeeding node to the node at index + 1.
    temp_sll_node->next = temp_popped_sll_node->next;
    sll_node_dealloc(&temp_popped_sll_node);
}

void sll_pop_first(sll_node_t **sll_head_node)
{
    sll_node_t *temp_sll_head_node = *sll_head_node;
    *sll_head_node = (*sll_head_node)->next;
    sll_node_dealloc(&temp_sll_head_node);
}

void sll_pop_last(sll_node_t **sll_head_node)
{
    sll_node_t *temp_sll_head_node = *sll_head_node;
    while (temp_sll_head_node->next->next)
        temp_sll_head_node = temp_sll_head_node->next;

    sll_node_dealloc(&temp_sll_head_node->next);
}

sll_node_t *sll_get(const sll_node_t *sll_head_node, const size_t index)
{
    for (size_t i = 0; i < index; ++i)
        sll_head_node = sll_head_node->next;

    return (sll_node_t *)sll_head_node;
}

void sll_set(sll_node_t *sll_head_node, const size_t index, const size_t element)
{
    for (size_t i = 0; i < index; ++i)
        sll_head_node = sll_head_node->next;

    sll_head_node->element = element;
}

void sll_reverse(sll_node_t **sll_head_node)
{
    sll_node_t *temp_prev_sll_node, *temp_next_sll_node = NULL;

    // Temporarily store the address of the succeeding node.
    // Point the node's succeeding pointer to its former preceeding node.
    // Temporarily store the address of the current node.
    // Continue with the next node.

    while (*sll_head_node)
    {
        temp_next_sll_node = (*sll_head_node)->next;
        (*sll_head_node)->next = temp_prev_sll_node;
        temp_prev_sll_node = *sll_head_node;
        *sll_head_node = temp_next_sll_node;
    }

    *sll_head_node = temp_prev_sll_node; // Set the former tail node as the new head node.
}

void sll_traverse(sll_node_t **sll_head_node, void (*fp)(sll_node_t **sll_node))
{
    sll_node_t *temp_sll_head_node = *sll_head_node;
    sll_node_t *temp_next_sll_node = temp_sll_head_node;

    while (temp_next_sll_node)
    {
        temp_next_sll_node = temp_sll_head_node->next;
        fp(&temp_sll_head_node);
        temp_sll_head_node = temp_next_sll_node;
    }
}
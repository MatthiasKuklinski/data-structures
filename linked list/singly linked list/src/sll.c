#include "sll.h"

#include <stdio.h>

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
    for (int i = 1; i < index; ++i)
        sll_head_node = sll_head_node->next;

    sll_head_node->next = sll_node_alloc(element, sll_head_node->next);
}

void sll_prepend(sll_node_t *sll_head_node, const size_t element)
{
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

    sll_node_t *temp_node = *sll_head_node;
    for (int i = 1; i < index; ++i)
        temp_node = temp_node->next;

    sll_node_t *temp_popped_node = temp_node->next; // Temporarily store the address of the node to be popped.
    temp_node->next = temp_node->next->next;        // Update the succeeding node address.
    sll_node_dealloc(&temp_popped_node);            // Deallocate the memory at the address of the popped node.
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
    sll_node_t *temp_prev_node = NULL; // Temporarily store the address of the preceding node (for the first element of the list it has to be null).
    sll_node_t *temp_next_node;

    while (*sll_head_node)
    {
        temp_next_node = (*sll_head_node)->next; // Temporarily store the address of the succeeding node.
        (*sll_head_node)->next = temp_prev_node; // Point the succeeding node to its former succeeding node.
        temp_prev_node = *sll_head_node;         // Temporarily store the address of the current node, which will be represented as the preceding node in the next iteration.
        *sll_head_node = temp_next_node;         // Iterate onto the next node.
    }

    *sll_head_node = temp_prev_node; // Point the new head node the former tail node.
}

void sll_traverse(sll_node_t **sll_head_node, void (*fp)(sll_node_t **sll_node))
{
    // Temporarily copy the head pointer.
    sll_node_t *temp_sll_head_node = *sll_head_node;
    // Temporarily store the address of the succeeding node.
    sll_node_t *temp_next_sll_node = temp_sll_head_node;

    while (temp_next_sll_node)
    {
        temp_next_sll_node = temp_sll_head_node->next;
        fp(&temp_sll_head_node);
        temp_sll_head_node = temp_next_sll_node;
    }
}
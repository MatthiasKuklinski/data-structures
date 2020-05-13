#include <dll.h>

size_t dll_length(const dll_node_t *dll_head_node)
{
    size_t n = 0;
    while (dll_head_node)
    {
        n++;
        dll_head_node = dll_head_node->next;
    }
    return n;
}

void dll_dealloc(dll_node_t **dll_head_node)
{
    dll_traverse(dll_head_node, dll_node_dealloc);
}

void dll_insert(dll_node_t *dll_head_node, const size_t element, const size_t index)
{
    for (size_t i = 1; i < index; ++i)
        dll_head_node = dll_head_node->next;

    dll_head_node->next = dll_node_alloc(element, dll_head_node, dll_head_node->next);
}

void dll_prepend(dll_node_t *dll_head_node, const size_t element)
{
    // Create a new succeeding node and point the next pointer at it.
    dll_head_node->next = dll_node_alloc(dll_head_node->element, dll_head_node, dll_head_node->next);
    dll_head_node->element = element; // Set the former head node element as the new node's element.

    // Check if the former head node pointed to a succeeding node.
    // If this case occurs point the prev pointer of that node to the new node (former head node).
    if (dll_head_node->next->next)
        dll_head_node->next->next->prev = dll_head_node->next;
}

void dll_append(dll_node_t *dll_head_node, const size_t element)
{
    while (dll_head_node->next)
        dll_head_node = dll_head_node->next;

    dll_head_node->next = dll_node_alloc(element, dll_head_node, NULL);
}

void dll_pop(dll_node_t **dll_head_node, const size_t index)
{
    if (index == 0)
    {
        dll_pop_first(dll_head_node);
        return;
    }

    if (index == dll_length(*dll_head_node) - 1)
    {
        dll_pop_last(dll_head_node);
        return;
    }

    dll_node_t *temp_dll_node = *dll_head_node;
    for (size_t i = 1; i < index; ++i) // Iterate through the list until index - 1.
        temp_dll_node = temp_dll_node->next;

    dll_node_t *temp_popped_dll_node = temp_dll_node->next;
    // Set the node's (at index - 1) succeeding node to the node at index + 1.
    temp_dll_node->next = temp_popped_dll_node->next;
    // Set the popped node's (at index) succeeding node's predecessor to the node at index - 1.
    temp_popped_dll_node->next->prev = temp_dll_node;
    dll_node_dealloc(&temp_popped_dll_node);
}

void dll_pop_first(dll_node_t **dll_head_node)
{
    dll_node_t *temp_dll_head_node = *dll_head_node;
    *dll_head_node = (*dll_head_node)->next;

    if (*dll_head_node) // Check if the former head node has a succeeding node.
        (*dll_head_node)->prev = NULL;

    dll_node_dealloc(&temp_dll_head_node);
}

void dll_pop_last(dll_node_t **dll_head_node)
{
    if (!(*dll_head_node)->next) // Check if there is only a single node in the list.
    {
        dll_node_dealloc(dll_head_node);
        return;
    }

    dll_node_t *temp_dll_head_node = *dll_head_node;
    while (temp_dll_head_node->next->next)
        temp_dll_head_node = temp_dll_head_node->next;

    dll_node_dealloc(&temp_dll_head_node->next);
}

dll_node_t *dll_get(const dll_node_t *dll_head_node, const size_t index)
{
    for (size_t i = 0; i < index; ++i)
        dll_head_node = dll_head_node->next;

    return (dll_node_t *)dll_head_node;
}

void dll_set(dll_node_t *dll_head_node, const size_t index, const size_t element)
{
    for (size_t i = 0; i < index; ++i)
        dll_head_node = dll_head_node->next;

    dll_head_node->element = element;
}

void dll_reverse(dll_node_t **dll_head_node)
{
    dll_node_t *temp_prev_dll_node, *temp_next_dll_node = NULL;

    // Temporarily store the address of the succeeding node.
    // Point the node's preceeding pointer to its former succeeding node.
    // Point the node's succeeding pointer to its former preceeding node.
    // Temporarily store the address of the current node.
    // Continue with the next node.

    while (*dll_head_node)
    {
        temp_next_dll_node = (*dll_head_node)->next;
        (*dll_head_node)->prev = temp_next_dll_node;
        (*dll_head_node)->next = temp_prev_dll_node;
        temp_prev_dll_node = *dll_head_node;
        *dll_head_node = temp_next_dll_node;
    }

    *dll_head_node = temp_prev_dll_node; // Set the former tail node as the new head node.
}

void dll_traverse(dll_node_t **dll_head_node, void (*fp)(dll_node_t **dll_node))
{
    dll_node_t *temp_dll_head_node = *dll_head_node;
    dll_node_t *temp_next_dll_node = temp_dll_head_node;

    while (temp_next_dll_node)
    {
        temp_next_dll_node = temp_dll_head_node->next;
        fp(&temp_dll_head_node);
        temp_dll_head_node = temp_next_dll_node;
    }
}

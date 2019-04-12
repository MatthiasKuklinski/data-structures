#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void dll_destroy(dll_node_t *node)
{
    dll_node_t *temp_node;

    while ((temp_node = node)) // Iterate through the list and temporarly store the current node.
    {
        node = node->successor; // Point to the address of the successor of the current node.
        free(temp_node);        // Deallocate the memory.
    }
    node = NULL; // Set the head node to NULL.
}

void dll_traverse(dll_node_t *node, const dll_callback cb)
{
    while (node)
    {
        cb(node);               // Execute the callback.
        node = node->successor; // Point to the successor of the current node.
    }
}

void dll_prepend(dll_node_t *node, const int value)
{
    if (!node)
        return;

    node->successor = dll_node(node->value, node, node->successor); // Create a copy of the node and assign the provided value ("move" the node to the second position).
    node->value = value;

    if (node->successor->successor) // Check if a successor of the created node exists.
        node->successor->successor->predecessor = node->successor;
}

void dll_append(dll_node_t *node, const int value)
{
    if (!node)
        return;

    while (node->successor)
        node = node->successor;

    node->successor = dll_node(value, node, NULL);
}

void dll_insert(dll_node_t *node, const int value, const unsigned int index)
{
    if (!node)
        return;

    if (index >= dll_length(node))
        dll_append(node, value);
    else if (index == 0)
        dll_prepend(node, value);
    else
    {
        for (int i = 1; i < index; ++i) // Iterate through the list until the requested index(-1) is reached.
            node = node->successor;

        node->successor = dll_node(value, node, node->successor); // Point the successor of the head to the new (old head) node.
    }
}

void dll_pop(dll_node_t *node, const unsigned int index)
{
    if (!node)
        return;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    dll_node_t *temp_node = node;
    node->predecessor->successor = node->successor;
    node->successor->predecessor = node->predecessor;
    free(temp_node);
}

void dll_pop_first(dll_node_t **node)
{
    if (!node)
        return;

    if (!((*node)->successor)) // Check if a successor exists.
    {
        dll_destroy(*node); // Invoke destroy() since the only element of the list was requested to be popped.
        return;
    }

    dll_node_t *temp_node = *node;

    (*node) = (*node)->successor; // Set the former (head)node to point to the next node.
    (*node)->predecessor = NULL;  // Set the predecessor to NULL, since the node will represent the head of the list.
    free(temp_node);              // Deallocate memory of the former (head)node.
}

void dll_pop_last(dll_node_t *node)
{
    if (!node)
        return;

    if (!node->successor)
    {
        dll_destroy(node); // Invoke destroy() since the only element of the list was requested to be popped.
        return;
    }

    while (node->successor)
        node = node->successor;

    node->predecessor->successor = NULL;
    free(node);
}

dll_node_t *dll_get(dll_node_t *node, const unsigned int index)
{
    if (!node)
        return NULL;

    for (unsigned int i = 0; i < index && node->successor; ++i)
        node = node->successor;

    return node;
}

unsigned long dll_length(dll_node_t *node)
{
    if (!node)
        return 0;

    unsigned long n = 1;

    while ((node = node->successor))
        ++n;

    return n;
}

// TODO: Adjust return type to fit bigger sizes.
unsigned long dll_size(dll_node_t *node)
{
    if (!node)
        return 0;

    return dll_length(node) * sizeof(int);
}
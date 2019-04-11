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
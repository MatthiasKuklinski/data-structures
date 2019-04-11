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

void dll_print(dll_node_t *node)
{
    printf("%d\n", node->value);
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

    node->successor = dll_node(value, node->predecessor, NULL);
}

unsigned long dll_length(dll_node_t *node)
{
    unsigned long n = 0;

    while (node)
    {
        ++n;
        node = node->successor;
    }

    return n;
}
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

void dll_prepend(dll_node_t *head, const int value)
{
    if (!head)
        return;

    head->successor = dll_node(head->value, head, head->successor); // Create a copy of head with the provided value ("move" the node to the second position).
    head->value = value;
}
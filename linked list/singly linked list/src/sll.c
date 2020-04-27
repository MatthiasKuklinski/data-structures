#include <sll.h>

#include <stdio.h>
#include <stdlib.h>

void sll_delete(sll_node_t *node)
{
    sll_node_t *temp_node;

    while ((temp_node = node)) // Iterate through the list and temporarly store the current node.
    {
        node = node->successor; // Point to the address of the successor of the current node.
        free(temp_node);        // Deallocate the memory.
    }
    node = NULL; // Set the head node to NULL.
}

void sll_insert(sll_node_t *node, const int value, const unsigned int index)
{
    if (!node) // Validate node.
        return;

    if (index >= sll_length(node)) // Check if index is greater or equal than the length of the list.
        sll_append(node, value);   // Call the append function.
    else if (index == 0)           // Check if index is 0.
        sll_prepend(node, value);  // Call the prepend function.
    else
    {
        for (int i = 1; i < index; ++i) // Iterate through the list until the requested index(-1) is reached.
            node = node->successor;

        node->successor = sll_node(value, node->successor); // Insert the successing node and adjust the predecessor of the former successor.
    }
}

void sll_prepend(sll_node_t *node, const int value)
{
    if (!node) // Validate node.
        return;

    node->successor = sll_node(node->value, node->successor); // Create a copy of the node and assign the provided value ("move" the node to the second position).
    node->value = value;                                      // Replace the old node value with the new node value.
}

void sll_append(sll_node_t *node, const int value)
{
    if (!node) // Validate node.
        return;

    while (node->successor) // Traverse the list until the last node.
        node = node->successor;

    node->successor = sll_node(value, NULL); // Append a new node at the end of the list.
}

void sll_pop(sll_node_t *node, const unsigned int index)
{
    if (!node) // Validate node.
        return;

    for (int i = 1; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    sll_node_t *temp_node = node->successor;      // Store the address of the current node temporarily.
    node->successor = node->successor->successor; // Update the successing node address.
    free(temp_node);                              // Deallocate the memory at the address of the popped node.
}

void sll_pop_first(sll_node_t **node)
{
    if (!node) // Validate node.
        return;

    if (!((*node)->successor)) // Check if a successor exists.
    {
        sll_delete(*node); // Invoke destroy function since the only element of the list was requested to be popped.
        return;
    }

    sll_node_t *temp_node = *node; // Store the address of the current node temporarily.
    (*node) = (*node)->successor;  // Set the former (head)node to point to the next node.
    free(temp_node);
}

void sll_pop_last(sll_node_t *node)
{
    if (!node) // Validate node.
        return;

    if (!node->successor) // Check if a successor exists.
    {
        sll_delete(node); // Invoke destroy function since the only element of the list was requested to be popped.
        return;
    }

    while (node->successor->successor) // Traverse the list until the forelast node.
        node = node->successor;

    free(node->successor);  // Deallocate the memory at the address of the popped node.
    node->successor = NULL; // Set the successor to NULL in order to mark the end of the list.
}

sll_node_t *sll_get(sll_node_t *node, const unsigned int index)
{
    if (!node) // Validate node.
        return NULL;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    return node;
}

void sll_set(sll_node_t *node, const unsigned int index, const int value)
{
    if (!node) // Validate node.
        return;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    node->value = value; // Update the value.
}

int sll_length(sll_node_t *node)
{
    if (!node) // Validate node.
        return 0;

    unsigned long n = 1;

    while ((node = node->successor)) // Traverse the list until the last node.
        ++n;                         // Increment the count on each iteration.

    return n;
}

void sll_reverse(sll_node_t **node)
{
    if (!node) // Validate node.
        return;

    sll_node_t *predecessor = NULL;
    sll_node_t *successor;
    while (*node)
    {
        successor = (*node)->successor;   // Store the address of the succeeding node.
        (*node)->successor = predecessor; // Set the successor to its predecessor.
        predecessor = *node;              // Update the predecessor.
        *node = successor;                // Jump to the next node.
    }

    *node = predecessor;
}

void sll_traverse(sll_node_t *node, const sll_callback cb)
{
    while (node) // Iterate through the list.
    {
        cb(node);               // Execute the callback.
        node = node->successor; // Point to the successor of the current node.
    }
}
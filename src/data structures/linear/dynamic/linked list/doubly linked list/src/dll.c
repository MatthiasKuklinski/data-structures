#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

void dll_insert(dll_node_t *node, const int value, const unsigned int index)
{
    if (!node) // Validate node.
        return;

    if (index >= dll_length(node)) // Check if index is greater or equal than the length of the list.
        dll_append(node, value);   // Call the append function.
    else if (index == 0)           // Check if index is 0.
        dll_prepend(node, value);  // Call the prepend function.
    else
    {
        for (int i = 1; i < index; ++i) // Iterate through the list until the requested index(-1) is reached.
            node = node->successor;

        node->successor = dll_node(value, node, node->successor); // Insert the successing node and adjust the predecessor of the former successor.
    }
}

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
    if (!node) // Validate node.
        return;

    node->successor = dll_node(node->value, node, node->successor); // Create a copy of the node and assign the provided value ("move" the node to the second position).
    node->value = value;                                            // Replace the old node value with the new node value.

    if (node->successor->successor)                                // Check if a successor of the created node exists.
        node->successor->successor->predecessor = node->successor; // Set the successors predecessing node to the created node in second position of the list.
}

void dll_append(dll_node_t *node, const int value)
{
    if (!node) // Validate node.
        return;

    while (node->successor) // Traverse the list until the last node.
        node = node->successor;

    node->successor = dll_node(value, node, NULL); // Append a new node at the end of the list.
}

void dll_pop(dll_node_t *node, const unsigned int index)
{
    if (!node) // Validate node.
        return;

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        node = node->successor;

    dll_node_t *temp_node = node;                     // Store the address of the current node temporarily.
    node->predecessor->successor = node->successor;   // Update the predecessors successor.
    node->successor->predecessor = node->predecessor; // Update the successors predecessor.
    free(temp_node);                                  // Deallocate the memory at the address of the popped node.
}

void dll_pop_first(dll_node_t **node)
{
    if (!node) // Validate node.
        return;

    if (!((*node)->successor)) // Check if a successor exists.
    {
        dll_destroy(*node); // Invoke destroy function since the only element of the list was requested to be popped.
        return;
    }

    dll_node_t *temp_node = *node; // Store the address of the current node temporarily.

    (*node) = (*node)->successor; // Set the former (head)node to point to the next node.
    (*node)->predecessor = NULL;  // Set the predecessor to NULL, since the node will represent the head of the list.
    free(temp_node);              // Deallocate the memory at the address of the popped node.
}

void dll_pop_last(dll_node_t *node)
{
    if (!node) // Validate node.
        return;

    if (!node->successor) // Check if a successor exists.
    {
        dll_destroy(node); // Invoke destroy function since the only element of the list was requested to be popped.
        return;
    }

    while (node->successor) // Traverse the list until the last node.
        node = node->successor;

    node->predecessor->successor = NULL; // Set the predecessors successor to NULL in order to mark the end of the list.
    free(node);                          // Deallocate the memory at the address of the popped node.
}

dll_node_t *dll_get(dll_node_t *node, const unsigned int index)
{
    if (!node) // Validate node.
        return NULL;

    for (unsigned int i = 0; i < index && node->successor; ++i) // Iterate through the list until the requested index or the last element is reached.
        node = node->successor;

    return node;
}

void dll_set(dll_node_t *node, const unsigned int index, int value)
{
    if (!node) // Validate node.
        return;

    for (unsigned int i = 0; i < index && node->successor; ++i) // Iterate through the list until the requested index or the last element is reached.
        node = node->successor;

    node->value = value; // Update the value.
}

void dll_reverse(dll_node_t **node)
{
    if (!node) // Validate node.
        return;

    dll_node_t *current = *node; // Store the address of the head node temporarily.
    dll_node_t *temp_node = NULL;

    while (current)
    {
        temp_node = current->predecessor;          // Store the address of the predecessing node.
        current->predecessor = current->successor; // Change the address of the the predecessing node to the successing node.
        current->successor = temp_node;            // Change the address of the succesing node to the previously stored address of the predecessing node.
        current = current->predecessor;            // Change the address of the current node to the currents predecessing node (former successing node).
    }

    *node = temp_node->predecessor; // Set the head node to the former tail node.
}

unsigned long dll_length(dll_node_t *node)
{
    if (!node) // Validate node.
        return 0;

    unsigned long n = 1;

    while ((node = node->successor)) // Traverse the list until the last node.
        ++n;                         // Increment the count on each iteration.

    return n;
}
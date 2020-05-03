#include <sll.h>

#include <stdio.h>
#include <stdlib.h>

int sll_length(sll_node_t *sll_head_node, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    unsigned long n = 1;
    while ((sll_head_node = sll_head_node->next)) // Traverse through the list until the last node is reached.
        n++;                                      // Increment the count after each iteration.

    *status_code = success; // Set the correspoding status code.
    return n;
}

void sll_delete(sll_node_t *sll_head_node, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    sll_node_t *temp_node;
    while ((temp_node = sll_node)) // Iterate through the list and temporarily store the current node.
    {
        sll_head_node = sll_head_node->next; // Store the pointer to the successing node.
        free(temp_node);                     // Deallocate the memory for the current node.
        temp_node = NULL;                    // Avoid a dangling pointer.
    }

    sll_head_node = NULL;   // Point the head node of the list to NULL.
    *status_code = success; // Set the correspoding status code.
}

void sll_insert(sll_node_t *sll_head_node, const int element, const unsigned int index, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (index >= sll_length(sll_head_node, status_code))               // Check if the element to be inserted should be appended to the list.
        sll_append(sll_head_node, element, status_code);  // Call the append function.
    else if (index == 0)                                  // Check if the element to be inserted should be prepended to the list.
        sll_prepend(sll_head_node, element, status_code); // Call the prepend function.
    else
    {
        for (int i = 1; i < index; ++i)          // Traverse through the list until the requested index minus one is reached.
            sll_head_node = sll_head_node->next; // Store the pointer to the successing node.

        sll_head_node->next = sll_node(element, sll_head_node->next); // Insert the successing node into the list by pointing the predecessing node of the former successing node to it.
    }

    *status_code = success; // Set the correspoding status code.
}

void sll_prepend(sll_node_t *sll_head_node, const int element, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    sll_head_node->next = sll_node(sll_head_node->element, sll_head_node->next); // Create a copy of the node and assign the provided value (place the node to the second position(index of 1)).
    sll_head_node->element = element;                                            // Replace the old node element with the new node element.

    *status_code = success; // Set the correspoding status code.
}

void sll_append(sll_node_t *sll_head_node, const int element, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    while (sll_head_node->next)              // Traverse through the list until the last node is reached.
        sll_head_node = sll_head_node->next; // Set the sll_head_node pointer to its successing node.

    sll_head_node->next = sll_node(element, NULL); // Append a new node at the end of the list.
    *status_code = success;                        // Set the correspoding status code.
}

/*
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
*/
void sll_traverse(sll_node_t *sll_head_node, void (*fp)(sll_node_t *), status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    while (sll_head_node) // Iterate through the list.
    {
        fp(sll_head_node);               // Execute the callback.
        sll_head_node = sll_head_node->next; // Point to the successor of the current node.
    }
}
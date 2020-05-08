#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

int sll_length(sll_node_t *sll_head_node, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return 0;
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
    while ((temp_node = sll_head_node)) // Iterate through the list and temporarily store the current node.
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

    if (index >= sll_length(sll_head_node, status_code))  // Check if the element to be inserted should be appended to the list.
        sll_append(sll_head_node, element, status_code);  // Call the append function.
    else if (index == 0)                                  // Check if the element to be inserted should be prepended to the list.
        sll_prepend(sll_head_node, element, status_code); // Call the prepend function.
    else
    {
        for (int i = 1; i < index; ++i)          // Traverse through the list until the requested index minus one is reached.
            sll_head_node = sll_head_node->next; // Store the pointer to the successing node.

        sll_head_node->next = sll_node(element, sll_head_node->next, status_code); // Insert the successing node into the list by pointing the predecessing node of the former successing node to it.
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

    sll_head_node->next = sll_node(sll_head_node->element, sll_head_node->next, status_code); // Create a copy of the node and assign the provided value (place the node to the second position(index of 1)).
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

    sll_head_node->next = sll_node(element, NULL, status_code); // Append a new node at the end of the list.
    *status_code = success;                        // Set the correspoding status code.
}

void sll_pop(sll_node_t *sll_head_node, const unsigned int index, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    for (int i = 1; i < index; ++i) // Iterate through the list until the requested index is reached.
        sll_head_node = sll_head_node->next;

    sll_node_t *temp_node = sll_head_node->next;     // Store the address of the current node temporarily.
    sll_head_node->next = sll_head_node->next->next; // Update the successing node address.
    free(temp_node);                                 // Deallocate the memory at the address of the popped node.
    *status_code = success;                          // Set the correspoding status code.
}

void sll_pop_first(sll_node_t **sll_head_node, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (!((*sll_head_node)->next)) // Check if a successor exists.
    {
        sll_delete(*sll_head_node, status_code); // Invoke destroy function since the only element of the list was requested to be popped.
        return;
    }

    sll_node_t *temp_node = *sll_head_node;    // Store the address of the current node temporarily.
    (*sll_head_node) = (*sll_head_node)->next; // Set the former (head)node to point to the next node.
    free(temp_node);
    *status_code = success; // Set the correspoding status code.
}

void sll_pop_last(sll_node_t *sll_head_node, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (!sll_head_node->next) // Check if a successor exists.
    {
        sll_delete(sll_head_node, status_code); // Invoke destroy function since the only element of the list was requested to be popped.
        return;
    }

    while (sll_head_node->next->next) // Traverse the list until the forelast node.
        sll_head_node = sll_head_node->next;

    free(sll_head_node->next);  // Deallocate the memory at the address of the popped node.
    sll_head_node->next = NULL; // Set the successor to NULL in order to mark the end of the list.
    *status_code = success;     // Set the correspoding status code.
}

sll_node_t *sll_get(sll_node_t *sll_head_node, const unsigned int index, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return NULL;
    }

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        sll_head_node = sll_head_node->next;

    *status_code = success; // Set the correspoding status code.
    return sll_head_node;
}

void sll_set(sll_node_t *sll_head_node, const unsigned int index, const int element, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        sll_head_node = sll_head_node->next;

    sll_head_node->element = element; // Update the value.
    *status_code = success;           // Set the correspoding status code.
}

void sll_reverse(sll_node_t **sll_head_node, status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    sll_node_t *prev = NULL;
    sll_node_t *next;
    while (*sll_head_node)
    {
        next = (*sll_head_node)->next; // Store the address of the succeeding node.
        (*sll_head_node)->next = prev; // Set the successor to its predecessor.
        prev = *sll_head_node;         // Update the predecessor.
        *sll_head_node = next;         // Jump to the next node.
    }

    *sll_head_node = prev;
    *status_code = success; // Set the correspoding status code.
}

void sll_traverse(sll_node_t *sll_head_node, void (*fp)(sll_node_t *), status_code_t *status_code)
{
    if (!sll_head_node) // Check if the list pointer is defined.
    {
        *status_code = sll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    while (sll_head_node) // Iterate through the list.
    {
        fp(sll_head_node);                   // Execute the callback.
        sll_head_node = sll_head_node->next; // Point to the successor of the current node.
    }
    *status_code = success; // Set the correspoding status code.
}
#include <dll.h>

#include <stdio.h>
#include <stdlib.h>

int dll_length(dll_node_t *dll_head_node, status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return 0;
    }

    unsigned long n = 1;                          // Length has to be at least one, since at least one node exists.
    while ((dll_head_node = dll_head_node->next)) // Traverse through the list until the last node is reached.
        n++;                                      // Increment the count after each iteration.

    *status_code = success; // Set the correspoding status code.
    return n;
}

void dll_delete(dll_node_t **dll_head_node, status_code_t *status_code)
{
    if (!(*dll_head_node)) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    dll_node_t *temp_head_node;
    while ((temp_head_node = *dll_head_node)) // Iterate through the list and temporarily store the current node.
    {
        *dll_head_node = (*dll_head_node)->next; // Store the pointer to the succeeding node.
        free(temp_head_node);                    // Deallocate the memory for the current node.
        temp_head_node = NULL;                   // Avoid a dangling pointer.
    }

    *status_code = success; // Set the correspoding status code.
}

void dll_insert(dll_node_t *dll_head_node, const int element, const unsigned int index, status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (index >= dll_length(dll_head_node, status_code))  // Check if the element to be inserted should be appended to the list.
        dll_append(dll_head_node, element, status_code);  // Call the append function.
    else if (index == 0)                                  // Check if the element to be inserted should be prepended to the list.
        dll_prepend(dll_head_node, element, status_code); // Call the prepend function.
    else
    {
        for (int i = 1; i < index; ++i)          // Traverse through the list until the requested index minus one is reached.
            dll_head_node = dll_head_node->next; // Store the pointer to the succeeding node.

        dll_head_node->next = dll_node(element, dll_head_node, dll_head_node->next, status_code); // Insert the succeeding node and adjust the predecessor of the former successor.
    }

    *status_code = success; // Set the correspoding status code.
}

void dll_prepend(dll_node_t *dll_head_node, const int element, status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    dll_head_node->next = dll_node(dll_head_node->element, dll_head_node, dll_head_node->next, status_code); // Create a copy of the node and assign the provided value ("move" the node to the second position).
    dll_head_node->element = element;                                                                        // Replace the old node value with the new node value.

    if (dll_head_node->next->next)                             // Check if a successor of the created node exists.
        dll_head_node->next->next->prev = dll_head_node->next; // Set the successors preceding node to the created node in second position of the list.

    *status_code = success; // Set the correspoding status code.
}

void dll_append(dll_node_t *dll_head_node, const int element, status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    while (dll_head_node->next)              // Traverse through the list until the last node is reached.
        dll_head_node = dll_head_node->next; // Set the dll_head_node pointer to its succeeding node.

    dll_head_node->next = dll_node(element, dll_head_node, NULL, status_code); // Append a new node at the end of the list.

    *status_code = success; // Set the correspoding status code.
}

void dll_pop(dll_node_t **dll_head_node, const unsigned int index, status_code_t *status_code)
{
    if (!(*dll_head_node)) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (index >= dll_length(*dll_head_node, status_code)) // Check if the requested index is in range.
    {
        *status_code = index_out_of_bounds; // Set the correspoding status code.
        return;
    }

    if (index == 0) // Check if the requested index is at the beginning of the list.
    {
        dll_pop_first(dll_head_node, status_code); // Pop the first node from the list.
        return;
    }

    if (index == dll_length(*dll_head_node, status_code) - 1) // Check if the requested index is at the end of the list.
    {
        dll_pop_last(dll_head_node, status_code); // Pop the last node from the list.
        return;
    }

    dll_node_t *temp_node = *dll_head_node; // Temporarily store the address of the head node.
    for (int i = 1; i < index; ++i)         // Iterate through the list until the requested index is reached.
        temp_node = temp_node->next;

    dll_node_t *temp_popped_node = temp_node->next;        // Temporarily store the address of the node to be popped.
    temp_popped_node->prev->next = temp_popped_node->next; // Update the predecessors successor.
    temp_popped_node->next->prev = temp_popped_node->prev; // Update the successors predecessor.
    free(temp_popped_node);                                // Deallocate the memory at the address of the popped node.

    *status_code = success; // Set the correspoding status code.
}

void dll_pop_first(dll_node_t **dll_head_node, status_code_t *status_code)
{
    if (!(*dll_head_node)) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (!((*dll_head_node)->next)) // Check if a successor exists.
    {
        dll_delete(dll_head_node, status_code); // Delete the entire list, since the only existing node was requested to be popped.
        return;
    }

    dll_node_t *temp_node = *dll_head_node;  // Temporarily store the address of the head node.
    *dll_head_node = (*dll_head_node)->next; // Set the former (head)node to point to the next node.
    (*dll_head_node)->prev = NULL;           // Set the preceding node pointer to null, since this will mark the new head node of the list.
    free(temp_node);                         // Deallocate the memory at the address of the popped node.

    *status_code = success; // Set the correspoding status code.
}

void dll_pop_last(dll_node_t **dll_head_node, status_code_t *status_code)
{
    if (!(*dll_head_node)) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (!((*dll_head_node)->next)) // Check if a successor exists.
    {
        dll_delete(dll_head_node, status_code); // Delete the entire list, since the only existing node was requested to be popped.
        return;
    }

    dll_node_t *temp_node = *dll_head_node; // Temporarily store the address of the head node.
    while (temp_node->next->next)           // Traverse the list until the forelast node.
        temp_node = temp_node->next;

    free(temp_node->next);  // Deallocate the memory at the address of the popped node.
    temp_node->next = NULL; // Set the predecessors successor to NULL in order to mark the end of the list.

    *status_code = success; // Set the correspoding status code.
}

dll_node_t *dll_get(dll_node_t *dll_head_node, const unsigned int index, status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return NULL;
    }

    if (index >= dll_length(dll_head_node, status_code))
    {
        *status_code = index_out_of_bounds; // Set the correspoding status code.
        return NULL;
    }

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        dll_head_node = dll_head_node->next;

    *status_code = success; // Set the correspoding status code.
    return dll_head_node;
}

void dll_set(dll_node_t *dll_head_node, const unsigned int index, const int element, status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (index >= dll_length(dll_head_node, status_code))
    {
        *status_code = index_out_of_bounds; // Set the correspoding status code.
        return;
    }

    for (int i = 0; i < index; ++i) // Iterate through the list until the requested index is reached.
        dll_head_node = dll_head_node->next;

    dll_head_node->element = element; // Update the value.
    *status_code = success;           // Set the correspoding status code.
}

void dll_reverse(dll_node_t **dll_head_node, status_code_t *status_code)
{
    if (!(*dll_head_node)) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    dll_node_t *temp_prev_node = NULL;              // Temporarily store the address of the preceding node (for the first element of the list it has to be null).
    dll_node_t *temp_current_node = *dll_head_node; // Temporarily store the address of the current node.

    while (temp_current_node)
    {
        temp_prev_node = temp_current_node->prev;          // Store the address of the preceding node.
        temp_current_node->prev = temp_current_node->next; // Point the preceding node to the succeeding node.
        temp_current_node->next = temp_prev_node;          // Point the succesing node to the previously stored address of the preceding node.
        temp_current_node = temp_current_node->prev;       // Iterate onto the next node by changing the address of the current node to the currents preceding node (former succeeding node).
    }

    *dll_head_node = temp_prev_node->prev; // Point the new head node the former tail node.

    *status_code = success; // Set the correspoding status code.
}

void dll_traverse(dll_node_t *dll_head_node, void (*fp)(dll_node_t *), status_code_t *status_code)
{
    if (!dll_head_node) // Check if the list pointer is defined.
    {
        *status_code = dll_node_ptr_is_null; // Set the correspoding status code.
        return;
    }

    while (dll_head_node) // Iterate through the list.
    {
        fp(dll_head_node);                   // Execute the callback.
        dll_head_node = dll_head_node->next; // Point to the successor of the current node.
    }

    *status_code = success; // Set the correspoding status code.
}
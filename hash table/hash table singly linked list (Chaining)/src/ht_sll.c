#include "ht_sll.h"

#include <stdio.h>

ht_sll_t *ht_sll(const unsigned long capacity, status_code_t *status_code)
{
    ht_sll_t *ht = NULL;            // Initialize a null pointer for the hash table structure itself.
    if (!(ht = malloc(sizeof(ht)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return ht;                            // Hash table be null, since there was no sufficient memory on the heap to be allocated for it.
    }

    ht->nodes = NULL;                                            // Initialize a null pointer for the hash table nodes array.
    if (!(ht->nodes = malloc(sizeof(ht_node_sll_t) * capacity))) // Try to allocate sufficient memory on the heap.
    {
        free(ht);                             // Free the allocated memory for the hash table structure itself.
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return NULL;
    }

    ht->capacity = capacity;
    for (unsigned long i = 0; i < capacity; ++i) // Iterate through the hash table nodes and set each node to null.
        ht->nodes[i] = NULL;

    *status_code = success; // Set the correspoding status code.
    return ht;
}

// djb2
unsigned long hash(const unsigned long capacity, const char *key)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % capacity;
}

void ht_sll_set(ht_sll_t *ht, const char *key, const char *element, status_code_t *status_code)
{
    if (!ht) // Check if the table pointer is defined.
    {
        *status_code = ht_sll_ptr_is_null; // Set the correspoding status code.
        return;
    }

    unsigned long hash_index = hash(ht->capacity, key);
    if (!ht->nodes[hash_index]) // Check if the hash table already contains an node at the generated hash index.
    {
        ht->nodes[hash_index] = ht_node_sll(key, element, status_code); // Create a new node and map it to the slot position.

        *status_code = success; // Set the correspoding status code.
        return;
    }

    ht_node_sll_t *temp_ht_node;
    ht_node_sll_t *ht_node = ht->nodes[hash_index];

    while (ht_node) // Iterate through the hash tables node(entry) nodes.
    {
        if (strcmp(ht_node->key, key) == 0) // Check if the list already contains the key.
        {
            free(ht_node->element);                                // Deallocate the memory.
            ht_node->element = NULL;                               // Avoid a dangling pointer.
            if (!(ht_node->element = malloc(strlen(element) + 1))) // Try to allocate sufficient memory on the heap.
            {
                *status_code = insufficient_heap_mem; // Set the correspoding status code.
                return;
            }
            strcpy(ht_node->element, element); // Populate the node element by copying the element argument into it.

            *status_code = success; // Set the correspoding status code.
            return;
        }

        temp_ht_node = ht_node;  // Temporarily store the current node.
        ht_node = ht_node->next; // Get the successing node.
    }

    temp_ht_node->next = ht_node_sll(key, element, status_code); // Append a new node at the end of the list, since no duplicate key was found.

    *status_code = success; // Set the correspoding status code.
}

ht_node_sll_t *ht_sll_get(ht_sll_t *ht, const char *key, status_code_t *status_code)
{
    if (!ht) // Check if the table pointer is defined.
    {
        *status_code = ht_sll_ptr_is_null; // Set the correspoding status code.
        return NULL;
    }

    unsigned long hash_index = hash(ht->capacity, key);
    if (!ht->nodes[hash_index])
    {
        *status_code = key_does_not_exist; // Set the correspoding status code.
        return ht->nodes[hash_index];
    }

    ht_node_sll_t *ht_node = ht->nodes[hash_index];

    while (ht_node)
    {
        if (strcmp(ht_node->key, key) == 0) // Check if the list already contains the key.
        {
            *status_code = success; // Set the correspoding status code.
            return ht_node;
        }

        ht_node = ht_node->next; // Get the successing node.
    }

    *status_code = success; // Set the correspoding status code.
    return NULL;
}

void ht_sll_traverse(ht_sll_t *ht, void (*fp)(ht_node_sll_t *), status_code_t *status_code)
{
    if (!ht) // Check if the table pointer is defined.
    {
        *status_code = ht_sll_ptr_is_null; // Set the correspoding status code.
        return;
    }

    for (unsigned long i = 0; i < ht->capacity; ++i)
    {
        fp(ht->nodes[i]);
    }

    *status_code = success; // Set the correspoding status code.
}

void ht_sll_remove(ht_sll_t *ht, const char *key, status_code_t *status_code)
{
    if (!ht) // Check if the table pointer is defined.
    {
        *status_code = ht_sll_ptr_is_null; // Set the correspoding status code.
        return;
    }

    unsigned long hash_index = hash(ht->capacity, key);

    if (!ht->nodes[hash_index]) // Check if the hash table contains a node at the generated hash index.
    {
        *status_code = key_does_not_exist; // Set the correspoding status code.
        return;
    }

    unsigned long index = 0;
    ht_node_sll_t *temp_ht_node = ht->nodes[hash_index];
    ht_node_sll_t *temp_prev_ht_node = NULL;

    while (temp_ht_node) // Iterate through the hash tables node(entry) nodes.
    {
        if (strcmp(temp_ht_node->key, key) == 0) // Check if the list already contains the key.
        {
            if (index == 0 && !temp_ht_node->next) // Check for a first element without a succeeding node.
                ht->nodes[hash_index] = NULL;      // Point the head node to null, since the list will be empty after removing.

            if (index == 0 && temp_ht_node->next)           // Check for a first element with a succeeding node.
                ht->nodes[hash_index] = temp_ht_node->next; // Point the head node to the succeeding node, since the first element will be removed.

            if (index != 0 && !temp_ht_node->next) // Check for a last element without a succeeding node.
                temp_prev_ht_node->next = NULL;    // Point the previous nodes successor node to null, since the former successing node will be removed.

            if (index != 0 && temp_ht_node->next)             // Check for elements inside the list.
                temp_prev_ht_node->next = temp_ht_node->next; // Point the previous nodes successor node to the current node, since the former successing node will be removed.

            free(temp_ht_node->key);      // Deallocate the memory for the key.
            free(temp_ht_node->element);  // Deallocate the memory for the element.
            free(temp_ht_node);           // Deallocate the memory for the removed node itself.
            temp_ht_node->key = NULL;     // Avoid a dangling pointer (defensive programming).
            temp_ht_node->element = NULL; // Avoid a dangling pointer (defensive programming).

            *status_code = success; // Set the correspoding status code.
            return;
        }

        temp_prev_ht_node = temp_ht_node;  // Temporarily store the current node.
        temp_ht_node = temp_ht_node->next; // Get the successing node.
        index++;
    }

    *status_code = key_does_not_exist; // Set the correspoding status code.
}

void ht_sll_delete(ht_sll_t **ht, status_code_t *status_code)
{
    if (!*ht) // Check if the table pointer is defined.
    {
        *status_code = ht_sll_ptr_is_null; // Set the correspoding status code.
        return;
    }

    ht_node_sll_t *temp_ht_node_sll, *temp_next_ht_node_sll;
    for (unsigned long i = 0; i < (*ht)->capacity; ++i)
    {
        temp_ht_node_sll = (*ht)->nodes[i];
        while (temp_ht_node_sll)
        {
            free(temp_ht_node_sll->key);
            free(temp_ht_node_sll->element);
            temp_ht_node_sll->key = NULL;     // Avoid a dangling pointer (defensive programming).
            temp_ht_node_sll->element = NULL; // Avoid a dangling pointer (defensive programming).

            temp_next_ht_node_sll = temp_ht_node_sll->next;
            free(temp_ht_node_sll);
            temp_ht_node_sll = NULL; // Avoid a dangling pointer (defensive programming).
            temp_ht_node_sll = temp_next_ht_node_sll;
        }
    }

    free((*ht)->nodes);
    (*ht)->nodes = NULL;
    (*ht) = NULL;              // Avoid a dangling pointer (defensive programming).
    *status_code = success; // Set the correspoding status code.
}

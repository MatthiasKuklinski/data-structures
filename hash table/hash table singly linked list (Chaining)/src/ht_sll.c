#include "ht_sll.h";

ht_sll_t *ht_sll(size_t capacity, status_code_t *status_code)
{
    ht_sll_t *ht = NULL;            // Initialize a null pointer for the hash table structure itself.
    if (!(ht = malloc(sizeof(ht)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return ht;                            // Hash table be null, since there was no sufficient memory on the heap to be allocated for it.
    }

    ht->entries = NULL;                      // Initialize a null pointer for the hash table entries array.
    if (!(ht->entries = malloc(sizeof(ht)))) // Try to allocate sufficient memory on the heap.
    {
        free(ht);                             // Free the allocated memory for the hash table structure itself.
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return NULL;
    }

    for (size_t i = 0; i < capacity; ++i) // Iterate through the hash table entries and set each node to null.
        ht->entries[i] = NULL;

    *status_code = success; // Set the correspoding status code.
    return ht;
}

void ht_sll_set(ht_sll_t *ht, const char *key, const char *element, status_code_t *status_code)
{
    unsigned int hash_index = 1;

    if (!ht->entries[hash_index]) // Check if the hash table already contains an node at the generated hash index.
    {
        ht->entries[hash_index] = ht_node_sll(key, element, status_code); // Create a new node and map it to the slot position.

        *status_code = success; // Set the correspoding status code.
        return;
    }

    ht_node_sll_t *ht_node = ht->entries[hash_index];
    while (!ht_node) // Iterate through the hash table node entries.
        ht_node = ht_node->next;

    ht_node->next = ht_node_sll(key, element, status_code);

    *status_code = success; // Set the correspoding status code.
}

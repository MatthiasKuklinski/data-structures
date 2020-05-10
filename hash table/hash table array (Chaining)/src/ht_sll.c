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

    for (size_t i = 0; i < capacity; ++i) // Iterate through the hash table entries and set each entry to null.
        ht->entries[i] = NULL;

    *status_code = success;
    return ht;
}

void ht_sll_set(ht_sll_t *ht, const char *key, const char *element, status_code_t *status_code)
{
    unsigned int slot = 123213123;

    if (ht->entries[slot])
    {
        ht->entries[slot] = ht_entry_sll(key, element, status_code);
        return;
    }
}
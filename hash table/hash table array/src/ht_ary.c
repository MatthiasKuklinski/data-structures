#include "ht_ary.h";

#include <stdlib.h>

ht_ary_t *ht_ary(size_t capacity, status_code_t *status_code)
{
    ht_ary_t *ht = NULL;            // Initialize a null pointer for the hash table structure itself.
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
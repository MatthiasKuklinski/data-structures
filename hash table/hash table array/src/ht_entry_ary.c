#include "ht_entry_ary.h";

#include <stdlib.h>

ht_entry_ary_t *ht_entry_ary(const char *key, const char *element, status_code_t *status_code)
{
    ht_entry_ary_t *ht_entry_ary = NULL; // Initialize a null pointer for the entry structure itself.
    ht_entry_ary->key = NULL;            // Initialize a null pointer for the entry key (string).
    ht_entry_ary->element = NULL;        // Initialize a null pointer for the entry element (string).

    // Try to allocate sufficient memory on the heap.
    if (!(ht_entry_ary = malloc(strlen(key) + 1)) || !(ht_entry_ary = malloc(strlen(key) + 1)) || !(ht_entry_ary = malloc(sizeof(ht_entry_ary_t))))
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return ht_entry_ary;                  // ht_entry_ary will be null, since there was no sufficient memory on the heap to be allocated for it.
    }

    strcpy(ht_entry_ary->key, key);         // Copy the key argument into the entry key.
    strcpy(ht_entry_ary->element, element); // Copy the element argument into the entry element.

    ht_entry_ary->next = NULL; // Signal that this entry has no successor.

    *status_code = success; // Set the correspoding status code.
    return ht_entry_ary;
}
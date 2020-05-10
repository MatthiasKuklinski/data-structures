#include "ht_entry_sll.h";

ht_entry_sll_t *ht_entry_sll(const char *key, const char *element, status_code_t *status_code)
{
    ht_entry_sll_t *ht_entry_sll = NULL; // Initialize a null pointer for the entry structure itself.
    ht_entry_sll->key = NULL;            // Initialize a null pointer for the entry key (string).
    ht_entry_sll->element = NULL;        // Initialize a null pointer for the entry element (string).

    // Try to allocate sufficient memory on the heap.
    if (!(ht_entry_sll = malloc(strlen(key) + 1)) || !(ht_entry_sll = malloc(strlen(key) + 1)) || !(ht_entry_sll = malloc(sizeof(ht_entry_sll_t))))
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return ht_entry_sll;                  // ht_entry_sll will be null, since there was no sufficient memory on the heap to be allocated for it.
    }

    strcpy(ht_entry_sll->key, key);         // Copy the key argument into the entry key.
    strcpy(ht_entry_sll->element, element); // Copy the element argument into the entry element.

    ht_entry_sll->next = NULL; // Signal that this entry has no successor.

    *status_code = success; // Set the correspoding status code.
    return ht_entry_sll;
}
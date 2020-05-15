#include "ht_ary.h"

ht_ary_t *ht_ary_alloc(const size_t capacity)
{
    ht_ary_t *ht_ary = malloc(sizeof(ht_ary_t));
    ht_ary->hashes = malloc(sizeof(ht_ary_entry_t *) * capacity);

    ht_ary->capacity = capacity;

    // Iterate through the hash table and set each entry pointer to null.
    for (size_t i = 0; i < capacity; ++i)
        ht_ary->hashes[i] = NULL;

    return ht_ary;
}

// http://www.cse.yorku.ca/~oz/hash.html (djb2)
size_t compHash(const size_t capacity, const char *key)
{
    size_t hash = 5381;
    int c;

    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    // Return a value greater or equal zero and smaller or equal the hash table's capacity.
    return hash % capacity;
}

void ht_ary_set(ht_ary_t *ht_ary, ht_ary_entry_t *ht_ary_entry)
{
    size_t hash = compHash(ht_ary->capacity, ht_ary_entry->key);
    for (size_t i = 0; i < ht_ary->capacity; ++i)
    {
        hash = (hash + i) % ht_ary->capacity;
        if (!ht_ary->hashes[hash])
        {
            ht_ary->hashes[hash] = ht_ary_entry;
            return;
        }
    }
}

ht_ary_entry_t *ht_ary_get(ht_ary_t *ht_ary, const char *key)
{
    size_t hash = compHash(ht_ary->capacity, key);
    for (size_t i = 0; i < ht_ary->capacity; ++i)
    {
        hash = (hash + i) % ht_ary->capacity;
        if (ht_ary->hashes[hash] && strcmp(ht_ary->hashes[hash]->key, key) == 0)
            return ht_ary->hashes[hash];
    }

    // If no matching hash and no matching key was found the key doesn't exist.
    return NULL;
}

void ht_ary_remove(ht_ary_t *ht_ary, const char *key)
{
    size_t hash = compHash(ht_ary->capacity, key);
    for (size_t i = 0; i < ht_ary->capacity; ++i)
    {
        hash = (hash + i) % ht_ary->capacity;
        if (ht_ary->hashes[hash] && strcmp(ht_ary->hashes[hash]->key, key) == 0)
        {
            ht_ary_entry_dealloc(&ht_ary->hashes[hash]);
            return;
        }
    }
}

void ht_ary_traverse(ht_ary_t **ht_ary, void (*fp)(ht_ary_entry_t **ht_ary_entry))
{
    for (size_t i = 0; i < (*ht_ary)->capacity; ++i)
    {
        fp(&(*ht_ary)->hashes[i]);
    }
}

void ht_ary_dealloc(ht_ary_t **ht_ary)
{
    for (size_t i = 0; i < (*ht_ary)->capacity; ++i)
    {
        if ((*ht_ary)->hashes[i])
            ht_ary_entry_dealloc(&(*ht_ary)->hashes[i]);
    }

    free((*ht_ary)->hashes);
    free(*ht_ary);
    *ht_ary = NULL;
}

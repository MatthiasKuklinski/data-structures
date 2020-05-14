#include "ht_sll.h"

ht_sll_t *ht_sll_alloc(const size_t capacity)
{
    ht_sll_t *ht_sll = malloc(sizeof(ht_sll_t));
    ht_sll->hashes = malloc(sizeof(ht_sll_node_t) * capacity);

    ht_sll->capacity = capacity;

    // Iterate through the hash table and set each node pointer to null.
    for (size_t i = 0; i < capacity; ++i)
        ht_sll->hashes[i] = NULL;

    return ht_sll;
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

void ht_sll_set(ht_sll_t *ht_sll, const char *key, const char *element)
{
    size_t hash = compHash(ht_sll->capacity, key);
    // Check if the hash already exists in the table.
    if (!ht_sll->hashes[hash])
    {
        ht_sll->hashes[hash] = ht_sll_node_alloc(key, element, NULL);
        return;
    }

    ht_sll_node_t *temp_prev_ht_sll_node;
    ht_sll_node_t *temp_ht_sll_node = ht_sll->hashes[hash];

    while (temp_ht_sll_node) // Iterate through the list.
    {
        // Replace the element if the list already contains the key.
        if (strcmp(temp_ht_sll_node->key, key) == 0)
        {
            free(temp_ht_sll_node->element);
            temp_ht_sll_node->element = malloc(strlen(element) + 1);
            strcpy(temp_ht_sll_node->element, element);
            return;
        }

        temp_prev_ht_sll_node = temp_ht_sll_node;
        temp_ht_sll_node = temp_ht_sll_node->next;
    }

    // Append a new node at the end of the list, since no duplicate key was found.
    temp_prev_ht_sll_node->next = ht_sll_node_alloc(key, element, NULL);
}

ht_sll_node_t *ht_sll_get(ht_sll_t *ht_sll, const char *key)
{
    size_t hash = compHash(ht_sll->capacity, key);
    if (!ht_sll->hashes[hash])
        return NULL;

    ht_sll_node_t *temp_ht_sll_node = ht_sll->hashes[hash];

    while (temp_ht_sll_node)
    {
        if (strcmp(temp_ht_sll_node->key, key) == 0)
            return temp_ht_sll_node;

        temp_ht_sll_node = temp_ht_sll_node->next;
    }

    // If no matching hash and no matching key was found the key doesn't exist.
    return NULL;
}

void ht_sll_remove(ht_sll_t *ht_sll, const char *key)
{

    size_t hash = compHash(ht_sll->capacity, key);
    if (!ht_sll->hashes[hash])
        return;

    size_t index = 0;

    ht_sll_node_t *temp_ht_sll_node = ht_sll->hashes[hash];
    ht_sll_node_t *temp_prev_ht_sll_node = NULL;
    while (temp_ht_sll_node) // Iterate through the hash tables node(entry) nodes.
    {
        if (strcmp(temp_ht_sll_node->key, key) == 0) // Check if the list contains the key.
        {
            // Check for a head node without a succeeding node.
            if (index == 0 && !temp_ht_sll_node->next)
                ht_sll->hashes[hash] = NULL;

            // Check for a head node with a succeeding node.
            if (index == 0 && temp_ht_sll_node->next)
                ht_sll->hashes[hash] = temp_ht_sll_node->next;

            if (index != 0 && !temp_ht_sll_node->next) // Check for a tail node.
                temp_prev_ht_sll_node->next = NULL;

            if (index != 0 && temp_ht_sll_node->next) // Check for nodes inside the list.
                temp_prev_ht_sll_node->next = temp_ht_sll_node->next;

            ht_sll_node_dealloc(&temp_ht_sll_node);
            return;
        }

        temp_prev_ht_sll_node = temp_ht_sll_node;
        temp_ht_sll_node = temp_ht_sll_node->next;
        index++;
    }
}

void ht_sll_traverse(ht_sll_t **ht_sll, void (*fp)(ht_sll_node_t **ht_sll_node))
{
    for (size_t i = 0; i < (*ht_sll)->capacity; ++i)
    {
        fp(&(*ht_sll)->hashes[i]);
    }
}

void ht_sll_dealloc(ht_sll_t **ht_sll)
{
    ht_sll_node_t *temp_next_ht_sll_node;
    for (size_t i = 0; i < (*ht_sll)->capacity; ++i)
    {
        while ((*ht_sll)->hashes[i])
        {
            temp_next_ht_sll_node = (*ht_sll)->hashes[i]->next;
            ht_sll_node_dealloc(&(*ht_sll)->hashes[i]);
            (*ht_sll)->hashes[i] = temp_next_ht_sll_node;
        }
    }

    free((*ht_sll)->hashes);
    free(*ht_sll);
    (*ht_sll) = NULL;
}

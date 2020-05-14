#include "ht_sll_node.h"

ht_sll_node_t *ht_sll_node_alloc(const char *key, const char *element, ht_sll_node_t *next)
{
    ht_sll_node_t *ht_sll_node = malloc(sizeof(ht_sll_node_t));
    ht_sll_node->key = malloc(strlen(key) + 1);
    ht_sll_node->element = malloc(strlen(element) + 1);

    strcpy(ht_sll_node->key, key);
    strcpy(ht_sll_node->element, element);
    ht_sll_node->next = next;

    return ht_sll_node;
}

void ht_sll_node_dealloc(ht_sll_node_t **ht_sll_node)
{
    free((*ht_sll_node)->key);
    free((*ht_sll_node)->element);
    free(*ht_sll_node);
    *ht_sll_node = NULL;
}
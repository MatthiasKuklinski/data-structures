#include <stk_sll.h>

#include <stdio.h>
#include <stdlib.h>

stk_sll_node_t *stk_sll(const int value, stk_sll_node_t *successor)
{
    stk_sll_node_t *temp_node = malloc(sizeof(stk_sll_node_t));

    if (!temp_node)
        return NULL;

    temp_node->value = value;
    temp_node->successor = successor;

    return temp_node;
}

void stk_sll_delete(stk_sll_node_t *node)
{
  stk_sll_node_t *temp_node;

  while (temp_node = node) // Iterate through the list and temporarly store the current node.
  {
    node = node->successor; // Point to the address of the successor of the current node.
    free(temp_node);        // Deallocate the memory.
  }
}
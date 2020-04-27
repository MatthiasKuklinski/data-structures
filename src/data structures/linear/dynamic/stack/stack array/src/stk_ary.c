#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

stk_ary_t *stk_ary(const unsigned int capacity)
{
    stk_ary_t *stk_ary = malloc(sizeof(stk_ary_t));              // Allocate memory for the stack itself.
    stk_ary->capacity = capacity;                                // Set capacity.
    stk_ary->i = -1;                                             // Set the index to < 0 (empty).
    stk_ary->elements = malloc(stk_ary->capacity * sizeof(int)); // Allocate memory for the related array in accordance to the capacity.

    return stk_ary;
}

int stk_ary_is_empty(stk_ary_t *stk_ary)
{
    return stk_ary->i < 0; // Check if the stk_ary index is smaller than 0 and return the result.
}

int stk_ary_is_full(stk_ary_t *stk_ary)
{
    return stk_ary->i == stk_ary->capacity - 1;
}

void stk_ary_push(stk_ary_t *stk_ary, const unsigned int element)
{
    if (stk_ary && !stk_ary_is_full(stk_ary))      // Check if the stack has available capacity to store one more element.
        stk_ary->elements[++stk_ary->i] = element; // Increment the index and append the requested element.
}

void stk_ary_pop(stk_ary_t *stk_ary)
{
    if (stk_ary && !stk_ary_is_empty(stk_ary)) // Check if stk_ary is defined or if there are available elements to be removed.
        stk_ary->i--;                          // Decrement the index(element is not removed).
}

int stk_ary_peek(stk_ary_t *stk_ary)
{
    return stk_ary->elements[stk_ary->i];
}

void stk_ary_delete(stk_ary_t **stk_ary)
{
    if (!*stk_ary) // Check if stk_ary is defined.
        return;

    free((*stk_ary)->elements); // Deallocate the elements array.
    free(*stk_ary);             // Deallocate the stack.
    *stk_ary = NULL;            // Point the pointer to NULL(avoid).
}
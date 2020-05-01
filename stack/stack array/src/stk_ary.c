#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

stk_ary_t *stk_ary(const unsigned int capacity)
{
    stk_ary_t *stk_ary = malloc(sizeof(stk_ary_t));              // Allocate memory for the stack structure itself.
    stk_ary->capacity = capacity;                                // Set the maximum capacity the stack can hold.
    stk_ary->i = -1;                                             // Set the index to < 0 (empty).
    stk_ary->elements = malloc(stk_ary->capacity * sizeof(int)); // Allocate memory for the related array in accordance to the capacity.

    return stk_ary;
}

int stk_ary_is_empty(const stk_ary_t *stk_ary)
{
    return stk_ary->i < 0; // Check if the stk_ary index is smaller than 0 and return the result.
}

int stk_ary_is_full(const stk_ary_t *stk_ary)
{
    return stk_ary->i == stk_ary->capacity - 1; // Check if the index is of the same size as the capacity -1 and return the result.
}

void stk_ary_push(stk_ary_t *stk_ary, const unsigned int element)
{
    if (stk_ary && !stk_ary_is_full(stk_ary))      // Check if the stack is defined and whether it has available capacity in order to store one more element.
        stk_ary->elements[++stk_ary->i] = element; // Increment the index and append the requested element.
}

void stk_ary_pop(stk_ary_t *stk_ary)
{
    if (stk_ary && !stk_ary_is_empty(stk_ary)) // Check if the stack is defined and whether it stores at least one element to be removed.
        stk_ary->i--;                          // Decrement the index(do not remove/overwrite the element effectively, but prevent access to it).
}

int stk_ary_peek(stk_ary_t *stk_ary)
{
    return stk_ary->elements[stk_ary->i]; // Access and return the element at the top of the stack.
}

void stk_ary_delete(stk_ary_t **stk_ary)
{
    if (!*stk_ary) // Check if stk_ary is defined.
        return;

    free((*stk_ary)->elements); // Deallocate the elements array.
    free(*stk_ary);             // Deallocate the stack.
    *stk_ary = NULL;            // Avoid a dangling pointer.
}
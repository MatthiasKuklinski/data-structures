#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

stk_ary_t *stk_ary(unsigned int capacity)
{
    stk_ary_t *stk_ary = malloc(sizeof(stk_ary_t));           // Allocate memory.
    stk_ary->capacity = capacity;                             // Set capacity.
    stk_ary->top = -1;                                        // Set the top to < 0 (empty).
    stk_ary->array = malloc(stk_ary->capacity * sizeof(int)); // Allocate memory for the related array.

    return stk_ary;
}

void stk_ary_push(stk_ary_t *stk_ary, int value)
{
    stk_ary->array[++stk_ary->top] = value; // Increment top and append the requested value.
}

void stk_ary_pop(stk_ary_t **stk_ary)
{
    (*stk_ary)->array = realloc((*stk_ary)->array, (*stk_ary)->top-- * sizeof(int));
}
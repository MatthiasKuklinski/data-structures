#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

stk_ary_t *stk_ary(unsigned int capacity)
{
    stk_ary_t *stk_ary = malloc(sizeof(stk_ary_t));           // Allocate memory.
    stk_ary->capacity = capacity;                             // Set capacity.
    stk_ary->top = -1;                                        // Set the top to < 0 (empty).
    stk_ary->items = malloc(stk_ary->capacity * sizeof(int)); // Allocate memory for the related array.

    return stk_ary;
}

int stk_ary_empty(stk_ary_t *stk_ary)
{
    if (!stk_ary)
        return 0;

    return stk_ary->top < 0;
}

void stk_ary_push(stk_ary_t *stk_ary, int item)
{
    if (!stk_ary)
        return;

    stk_ary->items[++stk_ary->top] = item; // Increment top and append the requested item.
}

void stk_ary_pop(stk_ary_t **stk_ary)
{
    if (!stk_ary)
        return;

    (*stk_ary)->items = realloc((*stk_ary)->items, (*stk_ary)->top-- * sizeof(int));
}
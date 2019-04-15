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

int stk_ary_full(stk_ary_t *stk_ary)
{
    if (!stk_ary || stk_ary->top < 0) // Check if the stack holds at least one item(don't compare top with capacity at this point, since top would be casted into unsigned int).
        return 0;

    if (stk_ary->top < stk_ary->capacity - 1) // Check if there is free capacity available.
        return 0;

    return 1;
}

void stk_ary_push(stk_ary_t *stk_ary, const int item)
{
    if (stk_ary && !stk_ary_full(stk_ary))
        stk_ary->items[++stk_ary->top] = item; // Increment top and append the requested value.
}

void stk_ary_pop(stk_ary_t *stk_ary)
{
    if (!stk_ary || stk_ary_empty(stk_ary)) // Check if items can be popped.
        return;

    stk_ary->top--;
}

void stk_ary_delete(stk_ary_t **stk_ary)
{
    if (!*stk_ary)
        return;

    free((*stk_ary)->items); // Deallocate the items array.
    free(*stk_ary);          // Deallocate the stack.
    *stk_ary = NULL;
}
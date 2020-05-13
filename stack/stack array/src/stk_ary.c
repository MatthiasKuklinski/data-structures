#include "stk_ary.h"
#include <stdio.h>
stk_ary_t *stk_ary_alloc(const long capacity)
{
    stk_ary_t *stk_ary = malloc(sizeof(stk_ary_t));
    stk_ary->elements = malloc(capacity * sizeof(long));

    stk_ary->capacity = capacity;
    stk_ary->top = -1;

    return stk_ary;
}

unsigned short stk_ary_is_empty(const stk_ary_t *stk_ary)
{
    return stk_ary->top < 0;
}

unsigned short stk_ary_is_full(const stk_ary_t *stk_ary)
{
    return stk_ary->top == stk_ary->capacity - 1;
}

void stk_ary_push(stk_ary_t *stk_ary, const size_t element)
{
    if (!stk_ary_is_full(stk_ary))
        stk_ary->elements[++stk_ary->top] = element;
}

void stk_ary_pop(stk_ary_t *stk_ary)
{
    if (!stk_ary_is_empty(stk_ary))
        stk_ary->top--;
}

size_t stk_ary_peek(const stk_ary_t *stk_ary)
{
    if (!stk_ary_is_empty(stk_ary))
        return stk_ary->elements[stk_ary->top];
    else
    {
        return -1;
    }
}

void stk_ary_traverse(stk_ary_t *stk_ary, void (*fp)(size_t **element))
{
    size_t *temp_ptr_element; // Store the address of an element (necessary, since it is a rvalue).
    for (long i = stk_ary->top; i > -1; --i)
    {
        temp_ptr_element = &stk_ary->elements[i];
        fp(&temp_ptr_element);
    }
}

void stk_ary_dealloc(stk_ary_t **stk_ary)
{
    free((*stk_ary)->elements);
    free(*stk_ary);
    *stk_ary = NULL;
}
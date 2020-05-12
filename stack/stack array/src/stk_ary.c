#include "stk_ary.h"

stk_ary_t *stk_ary_alloc(const int capacity, status_t *status)
{
    stk_ary_t *stk_ary = NULL;
    if (!(stk_ary = malloc(sizeof(stk_ary_t))))
    {
        *status = insufficient_heap_mem;
        return NULL;
    }

    stk_ary->elements = NULL;
    if (!(stk_ary->elements = malloc(capacity * sizeof(int))))
    {
        free(stk_ary);
        *status = insufficient_heap_mem;
        return NULL;
    }

    stk_ary->capacity = capacity;
    stk_ary->top = -1;

    *status = success;
    return stk_ary;
}

unsigned short stk_ary_is_empty(const stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return 1;
    }

    *status = success;
    return stk_ary->top < 0;
}

unsigned short stk_ary_is_full(const stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return 0;
    }

    *status = success;
    return stk_ary->top == stk_ary->capacity - 1;
}

void stk_ary_push(stk_ary_t *stk_ary, const int element, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    if (stk_ary_is_full(stk_ary, status))
    {
        *status = stk_ary_full;
        return;
    }

    stk_ary->elements[++stk_ary->top] = element;

    *status = success;
}

void stk_ary_pop(stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    if (stk_ary_is_empty(stk_ary, status))
    {
        *status = stk_ary_empty;
        return;
    }

    stk_ary->top--;

    *status = success;
}

int stk_ary_peek(const stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return -1;
    }

    if (stk_ary_is_empty(stk_ary, status))
    {
        *status = stk_ary_empty;
        return -1;
    }

    *status = success;
    return stk_ary->elements[stk_ary->top];
}

void stk_ary_traverse(const stk_ary_t *stk_ary, void (*fp)(int *), status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    if (stk_ary_is_empty(stk_ary, status))
    {
        *status = stk_ary_empty;
        return;
    }

    for (int i = stk_ary->top; i > -1; --i)
    {
        fp(&stk_ary->elements[i]);
    }

    *status = success;
}

void stk_ary_dealloc(stk_ary_t **stk_ary, status_t *status)
{
    if (!*stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    free((*stk_ary)->elements);
    free(*stk_ary);
    *stk_ary = NULL;

    *status = success;
}
#pragma once

#include <stdlib.h>

typedef struct stk_ary
{
    long top, capacity;
    size_t *elements;
} stk_ary_t;

stk_ary_t *stk_ary_alloc(const long capacity);
void stk_ary_dealloc(stk_ary_t **stk_ary);
void stk_ary_push(stk_ary_t *stk_ary, const size_t element);
void stk_ary_pop(stk_ary_t *stk_ary);
size_t stk_ary_peek(const stk_ary_t *stk_ary);
void stk_ary_traverse(stk_ary_t *stk_ary, void (*fp)(size_t **element));
unsigned short stk_ary_is_empty(const stk_ary_t *stk_ary);
unsigned short stk_ary_is_full(const stk_ary_t *stk_ary);
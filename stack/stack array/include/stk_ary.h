#pragma once

#include <stdlib.h>

#include "stk_ary_status.h"

typedef struct stk_ary
{
    int top, capacity;
    int *elements;
} stk_ary_t;

stk_ary_t *stk_ary_alloc(const int capacity, status_t *status);
void stk_ary_dealloc(stk_ary_t **stk_ary, status_t *status);
void stk_ary_push(stk_ary_t *stk_ary, const int element, status_t *status);
void stk_ary_pop(stk_ary_t *stk_ary, status_t *status);
int stk_ary_peek(const stk_ary_t *stk_ary, status_t *status);
void stk_ary_traverse(const stk_ary_t *stk_ary, void (*fp)(int *), status_t *status);
unsigned short stk_ary_is_empty(const stk_ary_t *stk_ary, status_t *status);
unsigned short stk_ary_is_full(const stk_ary_t *stk_ary, status_t *status);
#pragma once

typedef struct stk_ary
{
    int top;
    unsigned int capacity;
    int *items;
} stk_ary_t;

stk_ary_t *stk_ary(unsigned int capacity);
void stk_ary_push(stk_ary_t *stk_ary, int item);
void stk_ary_pop(stk_ary_t **stk_ary);
#pragma once

typedef struct stk_ary
{
    int top;
    unsigned int capacity;
    int *array;
} stk_ary_t;

stk_ary_t *stk_ary(unsigned int capacity);
void push(stk_ary_t *stk_ary, int value);
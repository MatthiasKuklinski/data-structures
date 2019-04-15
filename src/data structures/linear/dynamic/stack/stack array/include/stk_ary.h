#pragma once

typedef struct stk_ary
{
    int top;
    unsigned int capacity;
    int *items;
} stk_ary_t;

stk_ary_t *stk_ary(unsigned int capacity);
int stk_ary_empty(stk_ary_t *stk_ary);
int stk_ary_full(stk_ary_t *stk_ary);
void stk_ary_push(stk_ary_t *stk_ary, int item);
void stk_ary_pop(stk_ary_t **stk_ary);
void stk_ary_delete(stk_ary_t **stk_ary);
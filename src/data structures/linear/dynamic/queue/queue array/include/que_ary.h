#pragma once

typedef struct que_ary
{
    unsigned int capacity, length;
    int *elements;
} que_ary_t;

que_ary_t *que_ary(unsigned int capacity);
int que_ary_empty(que_ary_t *que_ary);
int que_ary_full(que_ary_t *que_ary);
// void que_ary_enqueue(que_ary_t *que_ary, int item);
void que_ary_delete(que_ary_t **que_ary);
#pragma once

typedef struct que_ary
{
    unsigned int capacity, length;
    int *elements;
} que_ary_t;

que_ary_t *que_ary(unsigned int capacity);
void que_ary_delete(que_ary_t **que_ary);
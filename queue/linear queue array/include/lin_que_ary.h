#pragma once

typedef struct lin_que_ary
{
    long capacity, front, rear;
    int *elements;
} lin_que_ary_t;

lin_que_ary_t *lin_que_ary_alloc(const long capacity);
void lin_que_ary_dealloc(lin_que_ary_t **lin_que_ary);
void lin_que_ary_enqueue(lin_que_ary_t *lin_que_ary, int element);
void lin_que_ary_dequeue(lin_que_ary_t *lin_que_ary);
int lin_que_ary_peek(const lin_que_ary_t *lin_que_ary);
void lin_que_ary_traverse(const lin_que_ary_t *lin_que_ary, void (*fp)(int **element));
unsigned short lin_que_ary_is_empty(const lin_que_ary_t *lin_que_ary);
unsigned short lin_que_ary_is_full(const lin_que_ary_t *lin_que_ary);
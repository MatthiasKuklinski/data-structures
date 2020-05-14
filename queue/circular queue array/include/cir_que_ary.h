#pragma once

typedef struct cir_que_ary
{
    long capacity, front, rear;
    int *elements;
} cir_que_ary_t;

cir_que_ary_t *cir_que_ary_alloc(const long capacity);
void cir_que_ary_dealloc(cir_que_ary_t **cir_que_ary);
void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element);
void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary);
int cir_que_ary_peek(const cir_que_ary_t *cir_que_ary);
void cir_que_ary_traverse(const cir_que_ary_t *cir_que_ary, void (*fp)(int **element));
unsigned short cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary);
unsigned short cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary);
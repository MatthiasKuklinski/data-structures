#pragma once

#include "cir_que_ary_status.h"

typedef struct cir_que_ary
{
    int capacity, front, rear;
    int *elements;
} cir_que_ary_t;

cir_que_ary_t *cir_que_ary_alloc(const int capacity, status_t *status);
void cir_que_ary_dealloc(cir_que_ary_t **cir_que_ary, status_t *status);
void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element, status_t *status);
void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary, status_t *status);
int cir_que_ary_peek(const cir_que_ary_t *cir_que_ary, status_t *status);
void cir_que_ary_traverse(const cir_que_ary_t *cir_que_ary, void (*fp)(int *), status_t *status);
unsigned short cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary, status_t *status);
unsigned short cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary, status_t *status);
#include <cir_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

cir_que_ary_t *cir_que_ary_alloc(const int capacity, status_t *status)
{
    cir_que_ary_t *cir_que_ary = NULL;
    if (!(cir_que_ary = malloc(sizeof(cir_que_ary_t))))
    {
        *status = insufficient_heap_mem;
        return cir_que_ary;
    }

    cir_que_ary->elements = NULL;
    if (!(cir_que_ary->elements = malloc(cir_que_ary->capacity * sizeof(int))))
    {
        free(cir_que_ary);
        *status = insufficient_heap_mem;
        return NULL;
    }

    cir_que_ary->capacity = capacity;
    cir_que_ary->front = cir_que_ary->rear = -1;

    *status = success;
    return cir_que_ary;
}

unsigned short cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary, status_t *status)
{
    if (!cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return cir_que_ary->rear == -1;
}

unsigned short cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary, status_t *status)
{
    if (!cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return (cir_que_ary->rear == cir_que_ary->capacity - 1 && cir_que_ary->front == 0) || cir_que_ary->front == cir_que_ary->rear + 1;
}

void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element, status_t *status)
{
    if (!cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return;
    }

    if (cir_que_ary_is_full(cir_que_ary, status))
    {
        *status = cir_que_ary_full;
        return;
    }

    if (cir_que_ary->front == -1)
        cir_que_ary->front++;

    cir_que_ary->rear = (cir_que_ary->rear + 1) % cir_que_ary->capacity;
    cir_que_ary->elements[cir_que_ary->rear] = element;
    
    *status = success;
}

void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary, status_t *status)
{
    if (!cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return;
    }

    if (cir_que_ary_is_empty(cir_que_ary, status))
    {
        *status = cir_que_ary_empty;
        return;
    }

    if (cir_que_ary->front == cir_que_ary->rear)
        cir_que_ary->front = cir_que_ary->rear = -1;
    else
        cir_que_ary->front = (cir_que_ary->front + 1) % cir_que_ary->capacity;

    *status = success;
}

int cir_que_ary_peek(const cir_que_ary_t *cir_que_ary, status_t *status)
{
    if (!cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return -1;
    }

    if (cir_que_ary_is_empty(cir_que_ary, status))
    {
        *status = cir_que_ary_empty;
        return -1;
    }

    *status = success;
    return cir_que_ary->elements[cir_que_ary->front];
}

void cir_que_ary_traverse(const cir_que_ary_t *cir_que_ary, void (*fp)(int *), status_t *status)
{
    if (!cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return;
    }

    if (cir_que_ary_is_empty(cir_que_ary, status))
    {
        *status = cir_que_ary_empty;
        return;
    }

    for (int i = cir_que_ary->front; i != cir_que_ary->rear; i = (i + 1) % cir_que_ary->capacity)
        fp(&cir_que_ary->elements[i]);

    fp(&cir_que_ary->elements[cir_que_ary->rear]);
    
    *status = success;
}

void cir_que_ary_dealloc(cir_que_ary_t **cir_que_ary, status_t *status)
{
    if (!*cir_que_ary)
    {
        *status = cir_que_ary_ptr_is_null;
        return;
    }

    free((*cir_que_ary)->elements);
    free(*cir_que_ary);
    *cir_que_ary = NULL;

    *status = success;
}
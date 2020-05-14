#include <cir_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

cir_que_ary_t *cir_que_ary_alloc(const long capacity)
{
    cir_que_ary_t *cir_que_ary = malloc(sizeof(cir_que_ary_t));
    cir_que_ary->elements = malloc(capacity * sizeof(int));

    cir_que_ary->capacity = capacity;
    cir_que_ary->front = cir_que_ary->rear = -1; // Represent an empty queue.

    return cir_que_ary;
}

unsigned short cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary)
{
    return cir_que_ary->front == -1;
}

unsigned short cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary)
{
    return (cir_que_ary->rear == cir_que_ary->capacity - 1 && cir_que_ary->front == 0) || cir_que_ary->front == cir_que_ary->rear + 1;
}

void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element)
{
    if (cir_que_ary_is_full(cir_que_ary))
        return;

    // If the rear index +1 is smaller than the capacity, set the rear index at rear index +1.
    // If the rear index +1 equals the capacity, set the rear index in a circular manner.
    cir_que_ary->rear = (cir_que_ary->rear + 1) % cir_que_ary->capacity;
    cir_que_ary->elements[cir_que_ary->rear] = element;

    if (cir_que_ary->front == -1) // Check if the queue is enqueued for the first time.
        cir_que_ary->front++;
}

void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary)
{
    if (cir_que_ary_is_empty(cir_que_ary))
        return;

    // Check if front index equals the rear index (signals an empty queue).
    if (cir_que_ary->front == cir_que_ary->rear)
        cir_que_ary->front = cir_que_ary->rear = -1; // Represent an empty queue.
    else
        cir_que_ary->front = (cir_que_ary->front + 1) % cir_que_ary->capacity;
}

int cir_que_ary_peek(const cir_que_ary_t *cir_que_ary)
{
    return cir_que_ary->elements[cir_que_ary->front];
}

void cir_que_ary_traverse(const cir_que_ary_t *cir_que_ary, void (*fp)(int **element))
{
    if (cir_que_ary_is_empty(cir_que_ary))
        return;

    // Temporarily store the address of an element (necessary, since it is a rvalue).
    int *temp_ptr_element;
    for (long i = cir_que_ary->front; i != cir_que_ary->rear; i = (i + 1) % cir_que_ary->capacity)
    {
        temp_ptr_element = &cir_que_ary->elements[i];
        fp(&temp_ptr_element);
    }

    temp_ptr_element = &cir_que_ary->elements[cir_que_ary->rear];
    fp(&temp_ptr_element);
}

void cir_que_ary_dealloc(cir_que_ary_t **cir_que_ary)
{
    free((*cir_que_ary)->elements);
    free(*cir_que_ary);
    *cir_que_ary = NULL;
}
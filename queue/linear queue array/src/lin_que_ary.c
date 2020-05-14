#include <lin_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

lin_que_ary_t *lin_que_ary_alloc(const long capacity)
{
    lin_que_ary_t *lin_que_ary = malloc(sizeof(lin_que_ary_t));
    lin_que_ary->elements = malloc(capacity * sizeof(int));

    lin_que_ary->capacity = capacity;
    lin_que_ary->front = lin_que_ary->rear = -1; // Represent an empty queue.

    return lin_que_ary;
}

unsigned short lin_que_ary_is_empty(const lin_que_ary_t *lin_que_ary)
{
    return lin_que_ary->front == -1;
}

unsigned short lin_que_ary_is_full(const lin_que_ary_t *lin_que_ary)
{
    return lin_que_ary->rear == lin_que_ary->capacity - 1;
}

void lin_que_ary_enqueue(lin_que_ary_t *lin_que_ary, int element)
{
    if (lin_que_ary_is_full(lin_que_ary))
        return;

    // Increment the rear index and store the element afterwards at the incremented index.
    lin_que_ary->elements[++lin_que_ary->rear] = element;

    if (lin_que_ary->front == -1) // Check if the queue is enqueued for the first time.
        lin_que_ary->front++;
}

void lin_que_ary_dequeue(lin_que_ary_t *lin_que_ary)
{
    if (lin_que_ary_is_empty(lin_que_ary))
        return;

    lin_que_ary->front++;

    // Check if front index overtook the rear index (signals an empty queue).
    if (lin_que_ary->front > lin_que_ary->rear)
        lin_que_ary->front = lin_que_ary->rear = -1; // Represent an empty queue.
}

int lin_que_ary_peek(const lin_que_ary_t *lin_que_ary)
{
    return lin_que_ary->elements[lin_que_ary->front];
}

void lin_que_ary_traverse(const lin_que_ary_t *lin_que_ary, void (*fp)(int **element))
{
    if (lin_que_ary_is_empty(lin_que_ary))
        return;

    // Temporarily store the address of an element (necessary, since it is a rvalue).
    int *temp_ptr_element;
    for (long i = lin_que_ary->front; i <= lin_que_ary->rear; ++i)
    {
        temp_ptr_element = &lin_que_ary->elements[i];
        fp(&temp_ptr_element);
    }
}

void lin_que_ary_dealloc(lin_que_ary_t **lin_que_ary)
{
    free((*lin_que_ary)->elements);
    free(*lin_que_ary);
    *lin_que_ary = NULL;
}
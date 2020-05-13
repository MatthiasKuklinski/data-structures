#include <lin_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

lin_que_ary_t *lin_que_ary_alloc(const int capacity, status_t *status)
{
    lin_que_ary_t *lin_que_ary = NULL;
    if (!(lin_que_ary = malloc(sizeof(lin_que_ary_t))))
    {
        *status = insufficient_heap_mem;
        return lin_que_ary;
    }

    lin_que_ary->elements = NULL;
    if (!(lin_que_ary->elements = malloc(capacity * sizeof(int))))
    {
        free(lin_que_ary);
        *status = insufficient_heap_mem;
        return NULL;
    }

    lin_que_ary->capacity = capacity;
    lin_que_ary->front = lin_que_ary->rear = -1;

    *status = success;
    return lin_que_ary;
}

unsigned short lin_que_ary_is_empty(const lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return lin_que_ary->rear == -1;
}

unsigned short lin_que_ary_is_full(const lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary) // Check if the queue pointer is defined.
    {
        *status = lin_que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status = success;                                     // Set the correspoding status code.
    return lin_que_ary->rear == lin_que_ary->capacity - 1; // Check if the upper bound index is of the same size as the capacity substracted by one and return the result.
}

void lin_que_ary_enqueue(lin_que_ary_t *lin_que_ary, int element, status_t *status)
{
    if (!lin_que_ary) // Check if the queue pointer is defined.
    {
        *status = lin_que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (lin_que_ary_is_full(lin_que_ary, status)) // Check if the queue array has available capacity in order to store one more element.
    {
        *status = lin_que_ary_full; // Set the correspoding status code.
        return;
    }

    if (lin_que_ary->front == -1) // Check if the queue is enqueued for the first time(doesn't hold any elements).
        lin_que_ary->front++;     // Increment the lower bound on initial initialization.

    lin_que_ary->elements[++lin_que_ary->rear] = element; // Increment the upper bound and store the element afterwards at the incremented index.

    *status = success; // Set the correspoding status code.
}

void lin_que_ary_dequeue(lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    if (lin_que_ary_is_empty(lin_que_ary, status))
    {
        *status = lin_que_ary_empty;
        return;
    }

    lin_que_ary->front++;

    if (lin_que_ary->front > lin_que_ary->rear)
        lin_que_ary->front = lin_que_ary->rear = -1;

    *status = success;
}

int lin_que_ary_peek(const lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return -1;
    }

    if (lin_que_ary_is_empty(lin_que_ary, status))
    {
        *status = lin_que_ary_empty;
        return -1;
    }

    *status = success;
    return lin_que_ary->elements[lin_que_ary->front];
}

void lin_que_ary_traverse(const lin_que_ary_t *lin_que_ary, void (*fp)(int *), status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    if (lin_que_ary_is_empty(lin_que_ary, status))
    {
        *status = lin_que_ary_empty;
        return;
    }

    for (int i = lin_que_ary->front; i <= lin_que_ary->rear; i++)
        fp(&lin_que_ary->elements[i]);

    *status = success;
}

void lin_que_ary_dealloc(lin_que_ary_t **lin_que_ary, status_t *status)
{
    if (!*lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    free((*lin_que_ary)->elements);
    free(*lin_que_ary);
    *lin_que_ary = NULL;

    *status = success;
}
#include <cir_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

cir_que_ary_t *cir_que_ary(const int capacity, status_code_t *status_code)
{
    cir_que_ary_t *cir_que_ary = NULL;                  // Initialize a null pointer for the queue structure itself.
    if (!(cir_que_ary = malloc(sizeof(cir_que_ary_t)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return cir_que_ary;                   // Cir_que_ary will be null, since there is no sufficient memory on the heap.
    }

    cir_que_ary->capacity = capacity; // Set the capacity the queue can hold.

    cir_que_ary->elements = NULL;                                               // Initialize a null pointer for the elements array.
    if (!(cir_que_ary->elements = malloc(cir_que_ary->capacity * sizeof(int)))) // Try to allocate sufficient memory on the heap.
    {
        free(cir_que_ary);                    // Free the allocated memory for the queue structure itself.
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return NULL;
    }

    cir_que_ary->front = cir_que_ary->rear = -1; // Set the lower and upper bound indice to -1(represent an empty queue).

    *status_code = success; // Set the correspoding status code.
    return cir_que_ary;
}

int cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary, status_code_t *status_code)
{
    if (!cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;         // Set the correspoding status code.
    return cir_que_ary->rear == -1; // Check if the upper bound index points to at least a single element.
}

int cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary, status_code_t *status_code)
{
    if (!cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status_code = success; // Set the correspoding status code.
    // Check if the upper bound index is of the same size as the capacity substracted by one, as well as if the lower bound index is at least zero (check for non-circular order).
    // Alternatively check if the lower bound is one index ahead of the upper bound (check for circular order).
    return (cir_que_ary->rear == cir_que_ary->capacity - 1 && cir_que_ary->front == 0) || cir_que_ary->front == cir_que_ary->rear + 1;
}

void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element, status_code_t *status_code)
{
    if (!cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (cir_que_ary_is_full(cir_que_ary, status_code)) // Check if the queue array has available capacity in order to store one more element.
    {
        *status_code = cir_que_ary_full; // Set the correspoding status code.
        return;
    }

    if (cir_que_ary->front == -1) // Check if the queue is enqueued for the first time(doesn't hold any elements).
        cir_que_ary->front++;     // Increment the lower bound on initial initialization.

    cir_que_ary->rear = (cir_que_ary->rear + 1) % cir_que_ary->capacity; // Set the higher bound index accordingly.
    cir_que_ary->elements[cir_que_ary->rear] = element;                  // Increment the upper bound and store the element afterwards at the incremented index.
    
    *status_code = success;                                              // Set the correspoding status code.
}

void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary, status_code_t *status_code)
{
    if (!cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (cir_que_ary_is_empty(cir_que_ary, status_code)) // Check if the queue array has available capacity in order to store one more element.
    {
        *status_code = cir_que_ary_empty; // Set the correspoding status code.
        return;
    }

    if (cir_que_ary->front == cir_que_ary->rear)     // Check if the lower bound overtook the upper bound(Indication for an an empty queue).
        cir_que_ary->front = cir_que_ary->rear = -1; // Set the lower and upper bound indice to -1(represent an empty queue).
    else
        cir_que_ary->front = (cir_que_ary->front + 1) % cir_que_ary->capacity; // Set the lower bound index accordingly.

    *status_code = success; // Set the correspoding status code.
}

int cir_que_ary_peek(const cir_que_ary_t *cir_que_ary, status_code_t *status_code)
{
    if (!cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    if (cir_que_ary_is_empty(cir_que_ary, status_code)) // Check if the queue array stores at least one removable element.
    {
        *status_code = cir_que_ary_empty; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;                           // Set the correspoding status code.
    return cir_que_ary->elements[cir_que_ary->front]; // Access and return the element at the front of the queue.
}

void cir_que_ary_traverse(cir_que_ary_t *cir_que_ary, void (*fp)(int *), status_code_t *status_code)
{
    if (!cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (cir_que_ary_is_empty(cir_que_ary, status_code)) // Check if the queue array stores at least one removable element.
    {
        *status_code = cir_que_ary_empty; // Set the correspoding status code.
        return;
    }

    for (int i = cir_que_ary->front; i != cir_que_ary->rear; i = (i + 1) % cir_que_ary->capacity)
        fp(&cir_que_ary->elements[i]);

    fp(&cir_que_ary->elements[cir_que_ary->rear]); // Access the last element in the queue array, since it was ignored.
    
    *status_code = success;                        // Set the correspoding status code.
}

void cir_que_ary_delete(cir_que_ary_t **cir_que_ary, status_code_t *status_code)
{
    if (!*cir_que_ary) // Check if the queue pointer is defined.
    {
        *status_code = cir_que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    free((*cir_que_ary)->elements); // Deallocate the elements array.
    free(*cir_que_ary);             // Deallocate the queue.
    *cir_que_ary = NULL;            // Avoid a dangling pointer.
    
    *status_code = success;         // Set the correspoding status code.
}
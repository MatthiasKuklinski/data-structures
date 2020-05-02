#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

que_ary_t *que_ary(const int capacity, status_code_t *status_code)
{
    que_ary_t *que_ary = NULL;                  // Initialize a null pointer for the queue structure itself.
    if (!(que_ary = malloc(sizeof(que_ary_t)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return que_ary;                       // Que_ary will be null, since there is no sufficient memory on the heap.
    }

    que_ary->capacity = capacity; // Set the capacity the queue can hold.

    que_ary->elements = NULL;                                           // Initialize a null pointer for the elements array.
    if (!(que_ary->elements = malloc(que_ary->capacity * sizeof(int)))) // Try to allocate sufficient memory on the heap.
    {
        free(que_ary);                        // Free the allocated memory for the queue structure itself.
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return NULL;
    }

    que_ary->front = que_ary->rear = -1; // Set the lower and upper bound indice to -1(represent an empty queue).

    *status_code = success; // Set the correspoding status code.
    return que_ary;
}

int que_ary_is_empty(const que_ary_t *que_ary, status_code_t *status_code)
{
    if (!que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;     // Set the correspoding status code.
    return que_ary->rear == -1; // Check if the upper bound index points to at least a single element.
}

int que_ary_is_full(const que_ary_t *que_ary, status_code_t *status_code)
{
    if (!que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;                        // Set the correspoding status code.
    return que_ary->rear == que_ary->capacity - 1; // Check if the upper bound index is of the same size as the capacity substracted by one and return the result.
}

void que_ary_enqueue(que_ary_t *que_ary, int element, status_code_t *status_code)
{
    if (!que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (que_ary_is_full(que_ary, status_code)) // Check if the queue array has available capacity in order to store one more element.
    {
        *status_code = que_ary_full; // Set the correspoding status code.
        return;
    }

    if (que_ary->front == -1) // Check if the queue is enqueued for the first time(doesn't hold any elements).
        que_ary->front++;     // Increment the lower bound on initial initialization.

    que_ary->elements[++que_ary->rear] = element; // Increment the upper bound and store the element afterwards at the incremented index.
    *status_code = success;                       // Set the correspoding status code.
}

void que_ary_dequeue(que_ary_t *que_ary, status_code_t *status_code)
{
    if (!que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (que_ary_is_empty(que_ary, status_code)) // Check if the queue array has available capacity in order to store one more element.
    {
        *status_code = que_ary_empty; // Set the correspoding status code.
        return;
    }

    que_ary->front++; // Increment the lower bound(do not remove/overwrite the element effectively, but prevent access to it).

    if (que_ary->front > que_ary->rear)      // Check if the lower bound overtook the upper bound(Indication for an an empty queue).
        que_ary->front = que_ary->rear = -1; // Set the lower and upper bound indice to -1(represent an empty queue).

    *status_code = success; // Set the correspoding status code.
}

int que_ary_peek(const que_ary_t *que_ary, status_code_t *status_code)
{
    if (!que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    if (que_ary_is_empty(que_ary, status_code)) // Check if the queue array stores at least one removable element.
    {
        *status_code = que_ary_empty; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;                   // Set the correspoding status code.
    return que_ary->elements[que_ary->front]; // Access and return the element at the front of the queue.
}

void que_ary_traverse(que_ary_t *que_ary, void (*fp)(int *), status_code_t *status_code)
{
    if (!que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (que_ary_is_empty(que_ary, status_code)) // Check if the queue array stores at least one removable element.
    {
        *status_code = que_ary_empty; // Set the correspoding status code.
        return;
    }

    for (int i = que_ary->front; i <= que_ary->rear; i++)
        fp(&que_ary->elements[i]);

    *status_code = success; // Set the correspoding status code.
}

void que_ary_delete(que_ary_t **que_ary, status_code_t *status_code)
{
    if (!*que_ary) // Check if the queue pointer is defined.
    {
        *status_code = que_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    free((*que_ary)->elements); // Deallocate the elements array.
    free(*que_ary);             // Deallocate the queue.
    *que_ary = NULL;            // Avoid a dangling pointer.
    *status_code = success;     // Set the correspoding status code.
}
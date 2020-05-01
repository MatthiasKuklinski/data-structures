#include <cir_que_ary.h>

#include <stdio.h>
#include <stdlib.h>

cir_que_ary_t *cir_que_ary(const unsigned int capacity)
{
    cir_que_ary_t *cir_que_ary = malloc(sizeof(cir_que_ary_t));          // Allocate memory for the queue structure itself.
    cir_que_ary->capacity = capacity;                                    // Set the maximum capacity the queue can hold.
    cir_que_ary->length = 0;                                             // Initialize the length to 0.
    cir_que_ary->front = cir_que_ary->rear = -1;                         // Set the lower and upper bound indice to -1(represent an empty queue).
    cir_que_ary->elements = malloc(cir_que_ary->capacity * sizeof(int)); // Allocate memory for the related array in accordance to the capacity.

    return cir_que_ary;
}

int cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary)
{
    return cir_que_ary->length < 1; // Check if the queue length is smaller than one and return the result.
}

int cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary)
{
    return cir_que_ary->length == cir_que_ary->capacity; // Check if the length is of the same size as the capacity and return the result.
}

void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element)
{
    if (cir_que_ary && !cir_que_ary_is_full(cir_que_ary)) // Check if the queue is defined and whether it has available capacity in order to store one more element.
    {
        if (cir_que_ary->front == -1) // Check if the queue is enqueued for the first time(doesn't hold any elements).
            cir_que_ary->front++;     // Increment the lower bound.

        if (cir_que_ary->rear == cir_que_ary->capacity - 1)
        {
            cir_que_ary->rear = (cir_que_ary->rear + 1) % cir_que_ary->capacity;
            cir_que_ary->elements[cir_que_ary->rear] = element;
        }
        else
            cir_que_ary->elements[++cir_que_ary->rear] = element; // Increment the upper bound and store the element afterwards.

        cir_que_ary->length++; // Increment the length.
    }
}

void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary)
{
    if (cir_que_ary && !cir_que_ary_is_empty(cir_que_ary)) // Check if the queue is defined and whether it stores at least one element to be removed.
    {
        if (cir_que_ary->front == cir_que_ary->capacity - 1) // Check whether the lower bound index equals the maximum capacity.
            cir_que_ary->front = 0;                          // Reset the lower bound(do not remove/overwrite the element effectively, but prevent access to it).
        else
            cir_que_ary->front++; // Increment the lower bound(do not remove/overwrite the element effectively, but prevent access to it).
        cir_que_ary->length--;    // Decrement the length.
    }
}

int cir_que_ary_peek(cir_que_ary_t *cir_que_ary)
{
    return cir_que_ary->elements[cir_que_ary->front]; // Access and return the element at the front of the queue.
}

void cir_que_ary_delete(cir_que_ary_t **cir_que_ary)
{
    if (!*cir_que_ary)
        return;

    free((*cir_que_ary)->elements); // Deallocate the elements array.
    free(*cir_que_ary);             // Deallocate the queue.
    *cir_que_ary = NULL;            // Avoid a dangling pointer.
}
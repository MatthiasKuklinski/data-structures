#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

que_ary_t *que_ary(const unsigned int capacity)
{
    que_ary_t *que_ary = malloc(sizeof(que_ary_t));              // Allocate memory for the queue structure itself.
    que_ary->capacity = capacity;                                // Set the maximum capacity the queue can hold.
    que_ary->length = 0;                                         // Initialize the length to 0.
    que_ary->front = que_ary->rear = -1;                         // Set the lower and upper bound indice to -1(represent an empty queue).
    que_ary->elements = malloc(que_ary->capacity * sizeof(int)); // Allocate memory for the related array in accordance to the capacity.

    return que_ary;
}

int que_ary_is_empty(const que_ary_t *que_ary)
{
    return que_ary->length < 1; // Check if the queue length is smaller than one and return the result.
}

int que_ary_is_full(const que_ary_t *que_ary)
{
    return que_ary->rear == que_ary->capacity - 1; // Check if the upper bound index is of the same size as the capacity substracted by one and return the result.
}

void que_ary_enqueue(que_ary_t *que_ary, int element)
{
    if (que_ary && !que_ary_is_full(que_ary)) // Check if the queue is defined and whether it has available capacity in order to store one more element.
    {
        if (que_ary->front == -1) // Check if the queue is enqueued for the first time(doesn't hold any elements).
            que_ary->front++;     // Increment the lower bound.

        que_ary->elements[++que_ary->rear] = element; // Increment the upper bound and store the element afterwards.
        que_ary->length++;                            // Increment the length.
    }
}

void que_ary_dequeue(que_ary_t *que_ary)
{
    if (que_ary && !que_ary_is_empty(que_ary)) // Check if the queue is defined and whether it stores at least one element to be removed.
    {
        que_ary->front++;  // Increment the lower bound(do not remove/overwrite the element effectively, but prevent access to it).
        que_ary->length--; // Decrement the length.

        if (que_ary->front > que_ary->rear)      // Check if the lower bound overtook the upper bound(signal an empty queue).
            que_ary->front = que_ary->rear = -1; // Set the lower and upper bound indice to -1(represent an empty queue).
    }
}

int que_ary_peek(que_ary_t *que_ary)
{
    return que_ary->elements[que_ary->front]; // Access and return the element at the front of the queue.
}

void que_ary_delete(que_ary_t **que_ary)
{
    if (!*que_ary)
        return;

    free((*que_ary)->elements); // Deallocate the elements array.
    free(*que_ary);             // Deallocate the queue.
    *que_ary = NULL;            // Avoid a dangling pointer.
}
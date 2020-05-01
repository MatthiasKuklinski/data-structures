#pragma once

typedef struct que_ary
{
    unsigned int capacity, length; // Store the maximum capacity and current length of the queue.
    int front, rear;               // Store the lower and upper bound indice respectively.
    int *elements;                 // Point to the first element of the queue(element at the front of the queue).
} que_ary_t;

que_ary_t *que_ary(const unsigned int capacity);       // Construct the queue structure.
int que_ary_is_empty(const que_ary_t *que_ary);        // Check if the queue is empty.
int que_ary_is_full(const que_ary_t *que_ary);         // Check if the queue is full.
void que_ary_enqueue(que_ary_t *que_ary, int element); // Add an element at the end of the queue.
void que_ary_dequeue(que_ary_t *que_ary);              // Remove an element from the front of the queue.
int que_ary_peek(que_ary_t *que_ary);                  // Get the element at the front of the queue.
void que_ary_delete(que_ary_t **que_ary);              // Free the allocated memory.
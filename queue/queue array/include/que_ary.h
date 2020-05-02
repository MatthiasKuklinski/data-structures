#pragma once

typedef enum status_code
{
    success = 0,
    que_ary_ptr_is_null = -1,
    insufficient_heap_mem = -2,
    que_ary_full = -3,
    que_ary_empty = -4
} status_code_t;

typedef struct que_ary
{
    int capacity;    // Store the maximum capacity of the queue.
    int front, rear; // Store the lower(front) and the upper(rear) bound index respectively.
    int *elements;   // Point to the first element of the queue(element at the front of the queue).
} que_ary_t;

que_ary_t *que_ary(const int capacity, status_code_t *status_code);                       // Construct the queue structure.
int que_ary_is_empty(const que_ary_t *que_ary, status_code_t *status_code);               // Check if the queue is empty.
int que_ary_is_full(const que_ary_t *que_ary, status_code_t *status_code);                // Check if the queue is full.
void que_ary_enqueue(que_ary_t *que_ary, int element, status_code_t *status_code);        // Add an element at the end of the queue.
void que_ary_dequeue(que_ary_t *que_ary, status_code_t *status_code);                     // Remove an element from the front of the queue.
int que_ary_peek(const que_ary_t *que_ary, status_code_t *status_code);                   // Get the element at the front of the queue.
void que_ary_traverse(que_ary_t *que_ary, void (*fp)(int *), status_code_t *status_code); // Traverse through the queue elements array and call the passed in function
void que_ary_delete(que_ary_t **que_ary, status_code_t *status_code);                     // Free the allocated memory.
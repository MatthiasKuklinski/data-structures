#pragma once

typedef enum status_code
{
    success = 0,
    cir_que_ary_ptr_is_null = -1,
    insufficient_heap_mem = -2,
    cir_que_ary_full = -3,
    cir_que_ary_empty = -4
} status_code_t;

typedef struct cir_que_ary
{
    int capacity;    // Store the maximum capacity of the queue.
    int front, rear; // Store the lower(front) and the upper(rear) bound index respectively.
    int *elements;   // Point to the first element of the queue(element at the front of the queue).
} cir_que_ary_t;

cir_que_ary_t *cir_que_ary(const int capacity, status_code_t *status_code);                           // Construct the queue structure.
int cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary, status_code_t *status_code);               // Check if the queue is empty.
int cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary, status_code_t *status_code);                // Check if the queue is full.
void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element, status_code_t *status_code);        // Add an element at the end of the queue.
void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary, status_code_t *status_code);                     // Remove an element from the front of the queue.
int cir_que_ary_peek(const cir_que_ary_t *cir_que_ary, status_code_t *status_code);                   // Get the element at the front of the queue.
void cir_que_ary_traverse(cir_que_ary_t *cir_que_ary, void (*fp)(int *), status_code_t *status_code); // Traverse through the queue elements array and call the passed in function
void cir_que_ary_delete(cir_que_ary_t **cir_que_ary, status_code_t *status_code);                     // Free the allocated memory.
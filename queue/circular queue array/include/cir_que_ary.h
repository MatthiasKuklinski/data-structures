#pragma once

typedef struct cir_que_ary
{
    unsigned int capacity, length; // Store the maximum capacity and current length of the queue.
    int front, rear;               // Store the lower and upper bound indice respectively.
    int *elements;                 // Point to the first element of the queue(element at the front of the queue).
} cir_que_ary_t;

cir_que_ary_t *cir_que_ary(const unsigned int capacity);       // Construct the queue structure.
int cir_que_ary_is_empty(const cir_que_ary_t *cir_que_ary);        // Check if the queue is empty.
int cir_que_ary_is_full(const cir_que_ary_t *cir_que_ary);         // Check if the queue is full.
void cir_que_ary_enqueue(cir_que_ary_t *cir_que_ary, int element); // Add an element at the end of the queue.
void cir_que_ary_dequeue(cir_que_ary_t *cir_que_ary);              // Remove an element from the front of the queue.
int cir_que_ary_peek(cir_que_ary_t *cir_que_ary);                  // Get the element at the front of the queue.
void cir_que_ary_delete(cir_que_ary_t **cir_que_ary);              // Free the allocated memory.
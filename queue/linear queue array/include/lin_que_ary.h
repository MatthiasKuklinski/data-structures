#pragma once

#include "lin_que_ary_status.h"

typedef struct lin_que_ary
{
    int capacity, front, rear; // Store the lower(front) and the upper(rear) bound index respectively.
    int *elements;             // Point to the first element of the queue(element at the front of the queue).
} lin_que_ary_t;

lin_que_ary_t *lin_que_ary_alloc(const int capacity, status_t *status);                           // Construct the queue structure.
void lin_que_ary_dealloc(lin_que_ary_t **lin_que_ary, status_t *status);                          // Free the allocated memory.
void lin_que_ary_enqueue(lin_que_ary_t *lin_que_ary, int element, status_t *status);              // Add an element at the end of the queue.
void lin_que_ary_dequeue(lin_que_ary_t *lin_que_ary, status_t *status);                           // Remove an element from the front of the queue.
int lin_que_ary_peek(const lin_que_ary_t *lin_que_ary, status_t *status);                         // Get the element at the front of the queue.
void lin_que_ary_traverse(const lin_que_ary_t *lin_que_ary, void (*fp)(int *), status_t *status); // Traverse through the queue elements array and call the passed in function
unsigned short lin_que_ary_is_empty(const lin_que_ary_t *lin_que_ary, status_t *status);          // Check if the queue is empty.
unsigned short lin_que_ary_is_full(const lin_que_ary_t *lin_que_ary, status_t *status);           // Check if the queue is full.
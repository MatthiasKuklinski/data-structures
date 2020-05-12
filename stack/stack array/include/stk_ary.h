#pragma once

#include <stdlib.h>

#include "stk_ary_status.h"

typedef struct stk_ary
{
    int top;       // Store the index of the top element on the stack.
    int capacity;  // Store the maximum capacity of elements the stack can hold.
    int *elements; // Point to the first element of the stack(element at the bottom of the stack).
} stk_ary_t;

stk_ary_t *stk_ary(const int capacity, status_t *status);                       // Construct the stack structure.
int stk_ary_is_empty(const stk_ary_t *stk_ary, status_t *status);               // Check if the stack is empty.
int stk_ary_is_full(const stk_ary_t *stk_ary, status_t *status);                // Check if the stack is full.
void stk_ary_push(stk_ary_t *stk_ary, const int element, status_t *status);     // Add an element onto the top of the stack.
void stk_ary_pop(stk_ary_t *stk_ary, status_t *status);                         // Remove an element of the top of the stack.
int stk_ary_peek(const stk_ary_t *stk_ary, status_t *status);                   // Get the element on the top of the stack.
void stk_ary_traverse(stk_ary_t *stk_ary, void (*fp)(int *), status_t *status); // Traverse through the stack elements array and call the passed in function
void stk_ary_deallocate(stk_ary_t **stk_ary, status_t *status);                     // Free the allocated memory.
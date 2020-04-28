#pragma once

typedef struct stk_ary
{
    int i;                 // Store the index of the top element on the stack.
    unsigned int capacity; // Store the maximum capacity of elements the stack can hold.
    int *elements;         // Point to the first element of the stack(element at the bottom of the stack).
} stk_ary_t;

stk_ary_t *stk_ary(const unsigned int capacity);                   // Construct the stack structure.
int stk_ary_is_empty(const stk_ary_t *stk_ary);                    // Check if the stack is empty.
int stk_ary_is_full(const stk_ary_t *stk_ary);                     // Check if the stack is full.
void stk_ary_push(stk_ary_t *stk_ary, const unsigned int element); // Add an element onto the top of the stack.
void stk_ary_pop(stk_ary_t *stk_ary);                              // Remove an element of the top of the stack.
int stk_ary_peek(stk_ary_t *stk_ary);                              // Get the element on the top of the stack.
void stk_ary_delete(stk_ary_t **stk_ary);                          // Free the allocated memory.
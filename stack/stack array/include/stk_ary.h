#pragma once

typedef enum status_code
{
    success = 0,
    stk_ary_ptr_is_null = -1,
    insufficient_heap_mem = -2,
    stk_ary_full = -3,
    stk_ary_empty = -4
} status_code_t;

typedef struct stk_ary
{
    int top;       // Store the index of the top element on the stack.
    int capacity;  // Store the maximum capacity of elements the stack can hold.
    int *elements; // Point to the first element of the stack(element at the bottom of the stack).
} stk_ary_t;

stk_ary_t *stk_ary(const int capacity, status_code_t *status_code);                   // Construct the stack structure.
int stk_ary_is_empty(const stk_ary_t *stk_ary, status_code_t *status_code);           // Check if the stack is empty.
int stk_ary_is_full(const stk_ary_t *stk_ary, status_code_t *status_code);            // Check if the stack is full.
void stk_ary_push(stk_ary_t *stk_ary, const int element, status_code_t *status_code); // Add an element onto the top of the stack.
void stk_ary_pop(stk_ary_t *stk_ary, status_code_t *status_code);                     // Remove an element of the top of the stack.
int stk_ary_peek(const stk_ary_t *stk_ary, status_code_t *status_code);                     // Get the element on the top of the stack.
void stk_ary_traverse(stk_ary_t *stk_ary, void (*fp)(int), status_code_t *status_code);                     // Traverse through the stack elements array and call the passed in function
void stk_ary_delete(stk_ary_t **stk_ary, status_code_t *status_code); // Free the allocated memory.
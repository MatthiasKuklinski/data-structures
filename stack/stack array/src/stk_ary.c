#include <stk_ary.h>

#include <stdio.h>
#include <stdlib.h>

stk_ary_t *stk_ary(const int capacity, status_code_t *status_code)
{
    stk_ary_t *stk_ary = NULL;                  // Initialize a null pointer for the stack structure itself.
    if (!(stk_ary = malloc(sizeof(stk_ary_t)))) // Try to allocate sufficient memory on the heap.
    {
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return stk_ary;                       // Stk_ary will be null, since there is no sufficient memory on the heap.
    }

    stk_ary->capacity = capacity; // Set the capacity the stack can hold.

    stk_ary->elements = NULL;                                           // Initialize a null pointer for the elements array.
    if (!(stk_ary->elements = malloc(stk_ary->capacity * sizeof(int)))) // Try to allocate sufficient memory on the heap.
    {
        free(stk_ary);                        // Free the allocated memory for the stack structure itself.
        *status_code = insufficient_heap_mem; // Set the correspoding status code.
        return NULL;
    }

    stk_ary->top = -1; // Set the top index to < 0 (empty).

    *status_code = success; // Set the correspoding status code.
    return stk_ary;
}

int stk_ary_is_empty(const stk_ary_t *stk_ary, status_code_t *status_code)
{
    if (!stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;  // Set the correspoding status code.
    return stk_ary->top < 0; // Check if the stack top index is smaller than 0 (empty) and return the result.
}

int stk_ary_is_full(const stk_ary_t *stk_ary, status_code_t *status_code)
{
    if (!stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;                       // Set the correspoding status code.
    return stk_ary->top == stk_ary->capacity - 1; // Check if the stack top index is of the same size as the capacity -1 and return the result.
}

void stk_ary_push(stk_ary_t *stk_ary, const int element, status_code_t *status_code)
{
    if (!stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (stk_ary_is_full(stk_ary, status_code)) // Check if the stack array has available capacity in order to store one more element.
    {
        *status_code = stk_ary_full; // Set the correspoding status code.
        return;
    }

    stk_ary->elements[++stk_ary->top] = element; // Increment the stack top index and append the requested element afterwards.
    *status_code = success;                      // Set the correspoding status code.
}

void stk_ary_pop(stk_ary_t *stk_ary, status_code_t *status_code)
{
    if (!stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (stk_ary_is_empty(stk_ary, status_code)) // Check if the stack array stores at least one removable element.
    {
        *status_code = stk_ary_empty; // Set the correspoding status code.
        return;
    }

    stk_ary->top--;         // Decrement the stack top index index(do not remove nor overwrite the element, only prevent accessing it via the stack interface).
    *status_code = success; // Set the correspoding status code.
}

int stk_ary_peek(const stk_ary_t *stk_ary, status_code_t *status_code)
{
    if (!stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return -1;
    }

    if (stk_ary_is_empty(stk_ary, status_code)) // Check if the stack array stores at least one removable element.
    {
        *status_code = stk_ary_empty; // Set the correspoding status code.
        return -1;
    }

    *status_code = success;                 // Set the correspoding status code.
    return stk_ary->elements[stk_ary->top]; // Access and return the element at the top of the stack.
}

void stk_ary_traverse(stk_ary_t *stk_ary, void (*fp)(int), status_code_t *status_code)
{
    if (!stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    if (stk_ary_is_empty(stk_ary, status_code)) // Check if the stack array stores at least one removable element.
    {
        *status_code = stk_ary_empty; // Set the correspoding status code.
        return -1;
    }

    for (int i = stk_ary->top; i > -1; --i)
        fp(stk_ary->elements[i]);

    *status_code = success; // Set the correspoding status code.
}

void stk_ary_delete(stk_ary_t **stk_ary, status_code_t *status_code)
{
    if (!*stk_ary) // Check if the stack pointer is defined.
    {
        *status_code = stk_ary_ptr_is_null; // Set the correspoding status code.
        return;
    }

    free((*stk_ary)->elements); // Deallocate the elements array.
    free(*stk_ary);             // Deallocate the stack.
    *stk_ary = NULL;            // Avoid a dangling pointer.
    *status_code = success;     // Set the correspoding status code.
}
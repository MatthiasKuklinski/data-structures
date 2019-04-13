#include <stk_array.h>

#include <stdlib.h>

stack_t *stack(unsigned int capacity)
{
    stack_t *stack = malloc(sizeof(stack_t));             // Allocate memory.
    stack->capacity = capacity;                           // Set capacity.
    stack->top = -1;                                      // Set the top to < 0 (empty).
    stack->array = malloc(stack->capacity * sizeof(int)); // Allocate memory for the related array.

    return stack;
}

void push(stack_t *stack, int value)
{
    stack->array[++stack->top] = value; // Increment top and append the requested value.
}
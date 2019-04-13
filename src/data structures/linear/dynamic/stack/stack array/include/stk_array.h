#pragma once

typedef struct stack
{
    int top;
    unsigned int capacity;
    int *array;
} stack_t;

stack_t *stack(unsigned int capacity);
void push(stack_t *stack, int value);
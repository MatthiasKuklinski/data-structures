#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

que_ary_t *que_ary(unsigned int capacity)
{
    que_ary_t *que_ary = malloc(sizeof(que_ary_t));
    if (!que_ary)
        return NULL;

    que_ary->capacity = capacity;
    que_ary->length = 0;
    que_ary->elements = malloc(que_ary->capacity * sizeof(int));
    if (!(que_ary->elements = malloc(que_ary->capacity * sizeof(int))))
        return NULL;

    return que_ary;
}

void que_ary_delete(que_ary_t **que_ary)
{
    if (!*que_ary)
        return;

    free((*que_ary)->elements); // Deallocate the elements array.
    free(*que_ary);             // Deallocate the stack.
    *que_ary = NULL;            // Set the pointer to NULL to avoid possible undefined behaviour.
}
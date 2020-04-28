#include <que_ary.h>

#include <stdio.h>
#include <stdlib.h>

que_ary_t *que_ary(const unsigned int capacity)
{
    que_ary_t *que_ary = malloc(sizeof(que_ary_t));
    que_ary->capacity = capacity;
    que_ary->length = 0;
    que_ary->front = que_ary->rear = -1;
    que_ary->elements = malloc(que_ary->capacity * sizeof(int));

    return que_ary;
}

int que_ary_is_empty(const que_ary_t *que_ary)
{
    return que_ary->length < 1;
}

int que_ary_is_full(const que_ary_t *que_ary)
{
    return que_ary->rear == que_ary->capacity -1;
}

void que_ary_enqueue(que_ary_t *que_ary, int item)
{
    if (que_ary && !que_ary_is_full(que_ary))
    {
        if (que_ary->front == -1)
            que_ary->front++;

        que_ary->elements[++que_ary->rear] = item;
        que_ary->length++;
    }
}

void que_ary_dequeue(que_ary_t *que_ary)
{
    if (que_ary && !que_ary_is_empty(que_ary))
    {
        que_ary->front++;
        que_ary->length--;

        if (que_ary->front > que_ary->rear)
            que_ary->front = que_ary->rear = -1;
    }
}

void que_ary_delete(que_ary_t **que_ary)
{
    if (!*que_ary)
        return;

    free((*que_ary)->elements); // Deallocate the elements array.
    free(*que_ary);             // Deallocate the queue.
    *que_ary = NULL;            // Avoid a dangling pointer.
}
# Linear Queue (Array-Based)
A queue is a linear collection of data elements, where insertion and deletion of elements takes place at the front and the rear of the queue. A queue implementation follows the FIFO (First In First Out) principle.

## Common area of application
A common area of application can be a buffer (e.g. I/O buffer), where the buffer has a specific capacity of data it can hold. The FIFO (First In First Out) principle ensures that each bit in the buffer is processed in the exact same order it was inserted at. Once the buffer reaches its maximum capacity, elements at the front of the buffer have to be processed (e.g. a flush) in order to allow for new elements to be inserted at the rear of the buffer.

## Interface
A basic implementation of a queue stores two index variables (```rear``` and ```front```) which represent the lower and upper bound respectively. Each time a new element is enqueued, ```rear``` is incremented by one. ```front``` is incremented on the first enqueue and decremented each time an element is dequeued.
The maximum amount of elements the queue can hold is stored in the ```capacity``` variable.
Pointer ```*elements``` points to the first element of the array and therefore allows access to each item by traversing through the queue.

```c
typedef struct lin_que_ary
{
    int capacity, front, rear;
    int *elements;
} lin_que_ary_t;
```

### Constructor
```c
lin_que_ary_t *lin_que_ary_alloc(const int capacity, status_t *status);
```

### Destructor
```c
void lin_que_ary_dealloc(lin_que_ary_t **lin_que_ary, status_t *status);
```

### Operations
`enqueue`: Add an element at the rear of the queue.  
`dequeue`: Remove the element at the front of the queue.  
`peek`: Get the element at the front of the queue.  
`traverse`: Iterate through the queue elements.  
`is_empty`: Check if the queue is empty.  
`is_full`: Check if the queue is full. 

```c
void lin_que_ary_enqueue(lin_que_ary_t *lin_que_ary, int element, status_t *status);
void lin_que_ary_dequeue(lin_que_ary_t *lin_que_ary, status_t *status);
int lin_que_ary_peek(const lin_que_ary_t *lin_que_ary, status_t *status);
void lin_que_ary_traverse(const lin_que_ary_t *lin_que_ary, void (*fp)(int *), status_t *status);
unsigned short lin_que_ary_is_empty(const lin_que_ary_t *lin_que_ary, status_t *status);
unsigned short lin_que_ary_is_full(const lin_que_ary_t *lin_que_ary, status_t *status);
```

## Implementation
### Constructor
Create a null pointer for the queue structure. Try to allocate memory for it. On success, point to the allocated memory, otherwise set the corresponding status code and return null.
Create a null pointer for the queue elements. Try to allocate memory for it. On success, point to the allocated memory, otherwise deallocate the memory for the queue structure and set the corresponding status code and return null.
Set the queue capacity according to the capacity argument.
Set the queue front and rear index to -1 (empty).
Set the corresponding status code and return a pointer to the queue.

```c
lin_que_ary_t *lin_que_ary_alloc(const int capacity, status_t *status)
{
    lin_que_ary_t *lin_que_ary = NULL;
    if (!(lin_que_ary = malloc(sizeof(lin_que_ary_t))))
    {
        *status = insufficient_heap_mem;
        return lin_que_ary;
    }

    lin_que_ary->elements = NULL;
    if (!(lin_que_ary->elements = malloc(capacity * sizeof(int))))
    {
        free(lin_que_ary);
        *status = insufficient_heap_mem;
        return NULL;
    }

    lin_que_ary->capacity = capacity;
    lin_que_ary->front = lin_que_ary->rear = -1;

    *status = success;
    return lin_que_ary;
}
```

### Destructor
Validate the input arguments. On failure, set the corresponding status code and return.
Deallocate the memory for the queue elements.
Deallocate the memory for the queue structure.
Set the queue structure pointer to null, in order to avoid a dangling pointer (defensive programming).
Set the corresponding status code.

```c
void lin_que_ary_dealloc(lin_que_ary_t **lin_que_ary, status_t *status)
{
    if (!*lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    free((*lin_que_ary)->elements);
    free(*lin_que_ary);
    *lin_que_ary = NULL;

    *status = success;
}
```

### Operations
#### enqueue
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the queue is not full. On failure, set the corresponding status code and return.
Check if the queue holds at least one element. If the queue doesn't, increment the queues front index.
Increment the rear index and assign the element to the corresponding memory address.
Set the corresponding status code.

```c
void lin_que_ary_enqueue(lin_que_ary_t *lin_que_ary, int element, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    if (lin_que_ary_is_full(lin_que_ary, status))
    {
        *status = lin_que_ary_full;
        return;
    }

    if (lin_que_ary->front == -1)
        lin_que_ary->front++;

    lin_que_ary->elements[++lin_que_ary->rear] = element;

    *status = success;
}
```

#### dequeue
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the queue is not empty. On failure, set the corresponding status code and return.
Check if the queue holds at least one element. If the queue doesn't, increment the queues front index.
Prevent access to the index by decrementing it.
Check if the lower bound (front) overtook the upper bound (rear). If the lower bound overtook the upper bound, set the front and rear index to -1 (empty), since the queue holds no accessible elements.
Set the corresponding status code.

```c
void lin_que_ary_dequeue(lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    if (lin_que_ary_is_empty(lin_que_ary, status))
    {
        *status = lin_que_ary_empty;
        return;
    }

    lin_que_ary->front++;

    if (lin_que_ary->front > lin_que_ary->rear)
        lin_que_ary->front = lin_que_ary->rear = -1;

    *status = success;
}
```

#### peek
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the queue is not empty. On failure, set the corresponding status code and return.
Set the corresponding status code.
Return the element at the lower bound (front) of the queue.

```c
int lin_que_ary_peek(const lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return -1;
    }

    if (lin_que_ary_is_empty(lin_que_ary, status))
    {
        *status = lin_que_ary_empty;
        return -1;
    }

    *status = success;
    return lin_que_ary->elements[lin_que_ary->front];
}
```

#### traverse
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the queue is not empty. On failure, set the corresponding status code and return.
Iterate through the queue elements and pass each element to the callback function.
Set the corresponding status code.

```c
void lin_que_ary_traverse(const lin_que_ary_t *lin_que_ary, void (*fp)(int *), status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return;
    }

    if (lin_que_ary_is_empty(lin_que_ary, status))
    {
        *status = lin_que_ary_empty;
        return;
    }

    for (int i = lin_que_ary->front; i <= lin_que_ary->rear; i++)
        fp(&lin_que_ary->elements[i]);

    *status = success;
}
```

#### is_empty
Validate the input arguments. On failure, set the corresponding status code and return -1.
Set the corresponding status code.
Return whether the queues rear index is equal to -1 (empty) or greater than -1 (non empty).

```c
unsigned short lin_que_ary_is_empty(const lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return lin_que_ary->rear == -1;
}
```

#### is_full
Validate the input arguments. On failure, set the corresponding status code and return -1.
Set the corresponding status code.
Return whether the queues rear index is equal to the queues capacity -1 (full) or not (not full).

```c
unsigned short lin_que_ary_is_full(const lin_que_ary_t *lin_que_ary, status_t *status)
{
    if (!lin_que_ary)
    {
        *status = lin_que_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return lin_que_ary->rear == lin_que_ary->capacity - 1;
}
```
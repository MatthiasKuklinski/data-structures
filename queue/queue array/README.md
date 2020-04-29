# Queue

A queue is a linear collection of data elements, where insertion and deletion of elements takes place at the front and the rear of the queue. A queue implementation follows the FIFO (First In First Out) prinicple.

## Usage
A common area of application are buffers(e.g. I/O buffer), where the buffer has a specific capacity of data it can hold. Each bit in the buffer is processed in the exact same order it was inserted at te front of the buffer. Once the buffer reaches its maximum capacity, elements at the front/start of the buffer have to be processed/written out(e.g. a flush) in order to allow for new elements to be inserted at the rear/end of the buffer.

## Implementation
### Queue
A queue stores two index variables(```rear``` and ```front```), which are initialized with -1(representing an empty queue) representing the lower and upper bound. Each time a new element is enqueued, ```rear``` gets incremented by one. ```front``` gets incremented on the first enqueue and decremented each time an element is dequeued.
Furthermore ```capacity``` stores information about the maximum capacity of elements the queue can hold. ```length``` returns the current length of the queue. 
Pointer ```*elements``` points to the first element of the array and therefore allows access to each item by traversing through the queue.

### Operations
`is_empty`: Check if the queue is empty.
`is_full`: Check if the queue is full.
`enqueue`: Add an element at the rear of the queue.
`dequeue`: Remove an element at the front of the queue.
`peek`: Get the element at the front of the queue.

### Interface
```c
typedef struct stk_ary
{
    int i;                 // Store the index of the top element on the stack.
    unsigned int capacity; // Store the maximum capacity of elements the stack can hold.
    int *elements;         // Point to the first element of the stack(element at the bottom of the stack).
} stk_ary_t;

stk_ary_t *stk_ary(const unsigned int capacity); // Construct the stack structure.
```

### Implementation
```c
stk_ary_t *stk_ary(const unsigned int capacity)
{
    stk_ary_t *stk_ary = malloc(sizeof(stk_ary_t));              // Allocate memory for the stack itself.
    stk_ary->capacity = capacity;                                // Set capacity.
    stk_ary->i = -1;                                             // Set the index to < 0 (empty).
    stk_ary->elements = malloc(stk_ary->capacity * sizeof(int)); // Allocate memory for the related array in accordance to the capacity.

    return stk_ary;
}
```

### Interface
```c
stk_ary_t *stk_ary(const unsigned int capacity);                   // Construct the stack structure.
int stk_ary_is_empty(stk_ary_t *stk_ary);                          // Check if the stack is empty.
int stk_ary_is_full(stk_ary_t *stk_ary);                           // Check if the stack is full.
void stk_ary_push(stk_ary_t *stk_ary, const unsigned int element); // Add an element onto the top of the stack.
void stk_ary_pop(stk_ary_t *stk_ary);                              // Remove an element of the top of the stack.
int stk_ary_peek(stk_ary_t *stk_ary);                              // Get the element on the top of the stack.
void stk_ary_delete(stk_ary_t **stk_ary);                          // Free the allocated memory.
```

### Implementation
```c
int stk_ary_is_empty(stk_ary_t *stk_ary)
{
    return stk_ary->i < 0; // Check if the stk_ary index is smaller than 0 and return the result.
}
```

```c
int stk_ary_is_full(stk_ary_t *stk_ary)
{
    return stk_ary->i == stk_ary->capacity - 1; // Check if the index is of the same size as the capacity -1 and return the result.
}
```

```c
void stk_ary_push(stk_ary_t *stk_ary, const unsigned int element)
{
    if (stk_ary && !stk_ary_is_full(stk_ary))      // Check if the stack has available capacity to store one more element.
        stk_ary->elements[++stk_ary->i] = element; // Increment the index and append the requested element.
}
```

```c
void stk_ary_pop(stk_ary_t *stk_ary)
{
    if (stk_ary && !stk_ary_is_empty(stk_ary)) // Check if stk_ary is defined or if there are available elements to be removed.
        stk_ary->i--;                          // Decrement the index(element is not removed).
}
```

```c
int stk_ary_peek(stk_ary_t *stk_ary)
{
    return stk_ary->elements[stk_ary->i]; // Access and return the element at the top of the stack.
}
```

```c
void stk_ary_delete(stk_ary_t **stk_ary)
{
    if (!*stk_ary) // Check if stk_ary is defined.
        return;

    free((*stk_ary)->elements); // Deallocate the elements array.
    free(*stk_ary);             // Deallocate the stack.
    *stk_ary = NULL;            // Avoid a dangling pointer.
}
```
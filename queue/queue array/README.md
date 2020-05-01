# Queue

A queue is a linear collection of data elements, where insertion and deletion of elements takes place at the front and the rear of the queue. A queue implementation follows the FIFO (First In First Out) prinicple.

## Usage
A common area of application are buffers(e.g. I/O buffer), where the buffer has a specific capacity of data it can hold. Each bit in the buffer is processed in the exact same order it was inserted at the front of the buffer. Once the buffer reaches its maximum capacity, elements at the front/start of the buffer have to be processed/written out(e.g. a flush) in order to allow for new elements to be inserted at the rear/end of the buffer.

## Implementation
A queue stores two index variables(```rear``` and ```front```), which are initialized with -1(empty queue) representing the lower and upper bound. Each time a new element is enqueued, ```rear``` gets incremented by one. ```front``` gets incremented on the first enqueue and decremented each time an element is dequeued.
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
typedef struct que_ary
{
    unsigned int capacity, length; // Store the maximum capacity and current length of the queue.
    int front, rear;               // Store the lower and upper bound indice respectively.
    int *elements;                 // Point to the first element of the queue(element at the front of the queue).
} que_ary_t;

que_ary_t *que_ary(const unsigned int capacity);       // Construct the queue structure.
int que_ary_is_empty(const que_ary_t *que_ary);        // Check if the queue is empty.
int que_ary_is_full(const que_ary_t *que_ary);         // Check if the queue is full.
void que_ary_enqueue(que_ary_t *que_ary, int element); // Add an element at the end of the queue.
void que_ary_dequeue(que_ary_t *que_ary);              // Remove an element from the front of the queue.
int que_ary_peek(que_ary_t *que_ary);                  // Get the element at the front of the queue.
void que_ary_delete(que_ary_t **que_ary);              // Free the allocated memory.
```

### Implementation
```c
que_ary_t *que_ary(const unsigned int capacity)
{
    que_ary_t *que_ary = malloc(sizeof(que_ary_t));              // Allocate memory for the queue structure itself.
    que_ary->capacity = capacity;                                // Set the maximum capacity the queue can hold.
    que_ary->length = 0;                                         // Initialize the length to 0.
    que_ary->front = que_ary->rear = -1;                         // Set the lower and upper bound indice to -1(represent an empty queue).
    que_ary->elements = malloc(que_ary->capacity * sizeof(int)); // Allocate memory for the related array in accordance to the capacity.

    return que_ary;
}
```

```c
int que_ary_is_empty(const que_ary_t *que_ary)
{
    return que_ary->length < 1; // Check if the queue length is smaller than one and return the result.
}
```

```c
int que_ary_is_full(const que_ary_t *que_ary)
{
    return que_ary->rear == que_ary->capacity - 1; // Check if the upper bound index is of the same size as the capacity substracted by one and return the result.
}
```

```c
void que_ary_enqueue(que_ary_t *que_ary, int element)
{
    if (que_ary && !que_ary_is_full(que_ary)) // Check if the queue is defined and whether it has available capacity in order to store one more element.
    {
        if (que_ary->front == -1) // Check if the queue is enqueued for the first time(doesn't hold any elements).
            que_ary->front++;     // Increment the lower bound.

        que_ary->elements[++que_ary->rear] = element; // Increment the upper bound and store the element afterwards.
        que_ary->length++;                            // Increment the length.
    }
}
```

```c
void que_ary_dequeue(que_ary_t *que_ary)
{
    if (que_ary && !que_ary_is_empty(que_ary)) // Check if the queue is defined and whether it stores at least one element to be removed.
    {
        que_ary->front++;  // Increment the lower bound(do not remove/overwrite the element effectively, but prevent access to it).
        que_ary->length--; // Decrement the length.

        if (que_ary->front > que_ary->rear)      // Check if the lower bound overtook the upper bound(signal an empty queue).
            que_ary->front = que_ary->rear = -1; // Set the lower and upper bound indice to -1(represent an empty queue).
    }
}
```

```c
int que_ary_peek(que_ary_t *que_ary)
{
    return que_ary->elements[que_ary->front]; // Access and return the element at the front of the queue.
}
```

```c
void que_ary_delete(que_ary_t **que_ary)
{
    if (!*que_ary)
        return;

    free((*que_ary)->elements); // Deallocate the elements array.
    free(*que_ary);             // Deallocate the queue.
    *que_ary = NULL;            // Avoid a dangling pointer.
}
```
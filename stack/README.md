# Stack

A stack is a linear collection of data elements, where insertion and deletion of items takes place at the top of the stack. A stack implementation follows the LIFO (Last In First Out) prinicple. 

## Usage
Since a stack enforces sequential rules of access, a common area of application is a history trace(e.g. browser-history), where the last visited website is pushed onto the top of the stack. Each time the back button is pressed, the element(URL) at the top of the stack is removed.
Another common use case for a stack is to reverse a word: pushing each letter onto the stack and popping it of the stack returns the reversed string.

## Implementation
### Stack
The basic implementation of a stack stores an index(```i```), which is incremented each time a new element is pushed onto the top of the stack and decremented each time an element is popped of the top of the stack. In combination with the ```capacity```, the index(```i```) is used to return information whether the stack is full or not. Pointer ```*items``` points to the first element of the array and therefore allows access to each item by traversing through the stack.

#### Interface
```c
typedef struct stk_ary
{
    int i;                 // Store the index of the top element on the stack.
    unsigned int capacity; // Store the maximum capacity of elements the stack can hold.
    int *elements;         // Point to the first element of the stack(element at the bottom of the stack).
} stk_ary_t;

stk_ary_t *stk_ary(const unsigned int capacity); // Construct the stack structure.
```

#### Implementation
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

### Operations
`is_empty`: Check if the stack is empty.  
`is_full`: Check if the stack is full.  
`push`: Add an element onto the top of the stack.  
`pop`: Remove an element of the top of the stack.  
`peek`: Get the element on the top of the stack.

#### Interface
```c
stk_ary_t *stk_ary(const unsigned int capacity);                   // Construct the stack structure.
int stk_ary_is_empty(stk_ary_t *stk_ary);                          // Check if the stack is empty.
int stk_ary_is_full(stk_ary_t *stk_ary);                           // Check if the stack is full.
void stk_ary_push(stk_ary_t *stk_ary, const unsigned int element); // Add an element onto the top of the stack.
void stk_ary_pop(stk_ary_t *stk_ary);                              // Remove an element of the top of the stack.
int stk_ary_peek(stk_ary_t *stk_ary);                              // Get the element on the top of the stack.
void stk_ary_delete(stk_ary_t **stk_ary);                          // Free the allocated memory.
```

#### Implementation
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
    *stk_ary = NULL;            // Point the pointer to NULL(avoid).
}
```
# Stack
A stack is a linear collection of data elements, where insertion and deletion of elements takes place at the top of the stack. A stack implementation follows the LIFO (Last In First Out) prinicple. 

## Common area of application
Since a stack enforces sequential rules of access, a common area of application can be a history trace (e.g. browser-history), where the last visited website is pushed onto the top of the stack as an element (URL). Each time the back button is pressed, the element (URL) at the top of the stack is removed.
A stack can also be used to reverse a word. Each character in the string is pushed onto the stack. Afterwards each character is removed from of the stack. The result is a reversed string.

## Interface
A basic implementation of a stack stores an index (```top```), which is incremented each time a new element is pushed onto the top of the stack and decremented each time an element is popped of the top of the stack. In combination with the ```capacity```, the index (```top```) is used to return information about whether the stack is full or not. Pointer ```*elements``` points to the first element (at the bottom of the stack) of the array and therefore allows access to each item by traversing through the stack.

```c
typedef struct stk_ary
{
    int top, capacity;
    int *elements;
} stk_ary_t;
```

### Constructor
```c
*stk_ary_alloc(const int capacity, status_code_t *status_code)
```

### Destructor
```c
stk_ary_dealloc(stk_ary_t **stk_ary, status_code_t *status_code)
```

### Operations 
`push`: Add an element onto the top of the stack.  
`pop`: Remove the element of the top of the stack.  
`peek`: Get the element on the top of the stack.  
`traverse`: Iterate through the stack elements.  
`is_empty`: Check if the stack is empty.  
`is_full`: Check if the stack is full. 

```c
void stk_ary_push(stk_ary_t *stk_ary, const int element, status_code_t *status_code);
void stk_ary_pop(stk_ary_t *stk_ary, status_code_t *status_code);
int stk_ary_peek(const stk_ary_t *stk_ary, status_code_t *status_code);
void stk_ary_traverse(const stk_ary_t *stk_ary, void (*fp)(int *), status_code_t *status_code);
unsigned short stk_ary_is_empty(const stk_ary_t *stk_ary, status_code_t *status_code);
unsigned short stk_ary_is_full(const stk_ary_t *stk_ary, status_code_t *status_code);
```

## Implementation
### Constructor
Create a null pointer for the stack structure. Try to allocate memory for it. On success, point to the allocted memory, otherwise set the corresponding status code and return null.
Create a null pointer for the stack elements. Try to allocate memory for it. On success, point to the allocted memory, otherwise deallocate the memory for the stack structure and set the corresponding status code and return null.
Set the stack capacity according to the capacity argument.
Set the stack top index to -1 (empty).
Set the corresponding status code and return a pointer to the stack.

```c
stk_ary_t *stk_ary_alloc(const int capacity, status_t *status)
{
    stk_ary_t *stk_ary = NULL;
    if (!(stk_ary = malloc(sizeof(stk_ary_t))))
    {
        *status = insufficient_heap_mem;
        return NULL;
    }

    stk_ary->elements = NULL;
    if (!(stk_ary->elements = malloc(capacity * sizeof(int))))
    {
        free(stk_ary);
        *status = insufficient_heap_mem;
        return NULL;
    }

    stk_ary->capacity = capacity;
    stk_ary->top = -1;

    *status = success;
    return stk_ary;
}
```

### Destructor
Validate the input arguments. On failure, set the corresponding status code and return.
Deallocate the memory for the stack elements.
Deallocate the memory for the stack structure.
Set the stack structure pointer to null, in order to avoid a dangling pointer (defensive programming).
Set the corresponding status code.

```c
void stk_ary_dealloc(stk_ary_t **stk_ary, status_t *status)
{
    if (!*stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    free((*stk_ary)->elements);
    free(*stk_ary);
    *stk_ary = NULL;

    *status = success;
}
```

### Operations
#### push
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the stack is not full. On failure, set the corresponding status code and return.
Increment the top index and assign the element to the corresponding memory address.
Set the corresponding status code.

```c
void stk_ary_push(stk_ary_t *stk_ary, const int element, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    if (stk_ary_is_full(stk_ary, status))
    {
        *status = stk_ary_full;
        return;
    }

    stk_ary->elements[++stk_ary->top] = element;

    *status = success;
}
```

#### pop
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the stack is not empty. On failure, set the corresponding status code and return.
Prevent access to the index by decrementing it.
Set the corresponding status code.

```c
void stk_ary_pop(stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    if (stk_ary_is_empty(stk_ary, status))
    {
        *status = stk_ary_empty;
        return;
    }

    stk_ary->top--;

    *status = success;
}
```

#### peek
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the stack is not empty. On failure, set the corresponding status code and return.
Set the corresponding status code.
Return the element at the top of the stack.

```c
int stk_ary_peek(const stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return -1;
    }

    if (stk_ary_is_empty(stk_ary, status))
    {
        *status = stk_ary_empty;
        return -1;
    }

    *status = success;
    return stk_ary->elements[stk_ary->top];
}
```

#### traverse
Validate the input arguments. On failure, set the corresponding status code and return.
Validate that the stack is not empty. On failure, set the corresponding status code and return.
Iterate through the stack elements and pass each element to the callback function.
Set the corresponding status code.

```c
void stk_ary_traverse(const stk_ary_t *stk_ary, void (*fp)(int *), status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return;
    }

    if (stk_ary_is_empty(stk_ary, status))
    {
        *status = stk_ary_empty;
        return;
    }

    for (int i = stk_ary->top; i > -1; --i)
        fp(&stk_ary->elements[i]);

    *status = success;
}
```

#### is_empty
Validate the input arguments. On failure, set the corresponding status code and return -1.
Set the corresponding status code.
Return whether the stacks top index is smaller than 0 (empty) or greater than 0 (non empty).

```c
unsigned short stk_ary_is_empty(const stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return stk_ary->top < 0;
}
```

#### is_full
Validate the input arguments. On failure, set the corresponding status code and return -1.
Set the corresponding status code.
Return whether the stacks top index is equal to the stacks capacity -1 (full) or not (not full).

```c
unsigned short stk_ary_is_full(const stk_ary_t *stk_ary, status_t *status)
{
    if (!stk_ary)
    {
        *status = stk_ary_ptr_is_null;
        return -1;
    }

    *status = success;
    return stk_ary->top == stk_ary->capacity - 1;
}
```
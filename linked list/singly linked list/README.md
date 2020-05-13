# Singly Linked List
A linked list is a linear collection of data elements (refereed to as list nodes) which together represent a sequence, whose order is not given by their physical placement in memory. Each node stores an element and a reference to the next node. The element can be a reference to another location in memory itself.
The entry point of the list is called the head of the list (head node). The last node in the list is refereed to as the tail of the list (tail node).

## Common area of application
Since a list represents a linear collection of data elements, whose order is not given by their physical placement in memory, insert or delete operations don't require reallocation or reorganization of the entire data structure, since the nodes are not stored contiguously. Accessing any node (except the head node) from the list however, requires traversing through each node of the list, until the requested node is reached. Furthermore a list node comes with a memory overhead, since it doesn't only store the element, but also a reference to the succeeding node.
Therefore a list can be used as an efficient data structure where insert or delete operations are more common than traverse operations and the memory overhead is negligible.

## Interface
### Singly Linked List Node
A basic implementation of a singly linked list node stores an `element` variable, which represents the payload of the node. Additionally the node stores a pointer to it's succeeding node.

```c
typedef struct sll_node
{
    int element;
    struct sll_node *next;
} sll_node_t;
```

#### Constructor
```c
sll_node_t *sll_node(const int element, sll_node_t *next, status_t *status);
```

#### Destructor
```c
void sll_node_dealloc(sll_node_t **sll_node, status_t *status);
```

### Singly Linked List

#### Operations
`enqueue`: Add an element at the rear of the queue.  
`dequeue`: Remove the element at the front of the queue.  
`peek`: Get the element at the front of the queue.  
`traverse`: Iterate through the queue elements.  
`is_empty`: Check if the queue is empty.  
`is_full`: Check if the queue is full. 

```c
void sll_dealloc(sll_node_t **sll_head_node, status_t *status);
void sll_insert(sll_node_t *sll_head_node, const int element, const unsigned int index, status_t *status);
void sll_append(sll_node_t *sll_head_node, const int element, status_t *status);
void sll_prepend(sll_node_t *sll_head_node, const int element, status_t *status);
void sll_pop(sll_node_t **sll_head_node, const unsigned int index, status_t *status);
void sll_pop_first(sll_node_t **sll_head_node, status_t *status);
void sll_pop_last(sll_node_t **sll_head_node, status_t *status);
sll_node_t *sll_get(sll_node_t *sll_head_node, const unsigned int index, status_t *status);
void sll_set(sll_node_t *sll_head_node, const unsigned int index, const int element, status_t *status);
void sll_reverse(sll_node_t **sll_head_node, status_t *status);
void sll_traverse(const sll_node_t *sll_head_node, void (*fp)(sll_node_t *), status_t *status);
int sll_length(sll_node_t *sll_head_node, status_t *status);
```

# Linked List

## About
A linear collection of data elements consisting of a collection of nodes which together represent a sequence, whose order is not given by their physical placement in memory. Instead, each element points to the next.
In its most basic form, each node contains:
- Data
- At least one reference to the next node in the sequence (a pointer)


The 'head' of a list is its first node. The 'tail' of a list may refer either to the rest of the list after the head, or to the last node in the list.

### Singly linked list
- Data field (element)
- Next field (pointer which contains the address of the next node in the memory)


![](https://upload.wikimedia.org/wikipedia/commons/6/6d/Singly-linked-list.svg)


### Doubly linked list
- Data field (element)
- Next field (pointer which contains the address of the next node in the memory)
- Prev field (pointer which contains the address of the previous node in the memory)


![](https://upload.wikimedia.org/wikipedia/commons/5/5e/Doubly-linked-list.svg)

## Advantages
- dynamic size at runtime
- efficient insert and remove operations (data items don't need to be stored contiguously in memory, therefore reallocation is unnecessary and less expensive)
- efficient memory usage (each allocated byte is populated and holds necessary data)


## Disadvantages
- sequential access (each node has to be traversed through)
- higher memory usage (each node contains at least one pointer)
- sufficient reverse traversing (especially single linked list)

## References
[Linked list](https://en.wikipedia.org/w/index.php?title=Linked_list&oldid=883007026)
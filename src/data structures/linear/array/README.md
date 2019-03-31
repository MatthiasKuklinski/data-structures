# Array

## About
In computer science, an array data structure, or simply an array, is a data structure consisting of a collection of elements (values or variables), each identified by at least one array index or key. An array is stored such that the position of each element can be computed from its index tuple by a mathematical formula.


Arrays are among the oldest and most important data structures, and are used by almost every program. They are also used to implement many other data structures, such as lists, strings, hash tables and stacks.


Arrays are useful mostly because the element indices can be computed at run time. Among other things, this feature allows a single iterative statement to process arbitrarily many elements of an array. For that reason, the elements of an array data structure are required to have the same size and should use the same data representation. The set of valid index tuples and the addresses of the elements (and hence the element addressing formula) are usually, but not always, fixed while the array is in use.


## Element access
When data objects are stored in an array, individual objects are selected by an index that is usually a non-negative scalar integer. Indexes are also called subscripts. An index maps the array value to a stored object.

There are three ways in which the elements of an array can be indexed:

- 0 (zero-based indexing): The first element of the array is indexed by subscript of 0.
- 1 (one-based indexing): The first element of the array is indexed by subscript of 1.
- n (n-based indexing): The base index of an array can be freely chosen. Usually programming languages allowing n-based indexing also allow negative index values and other scalar data types like enumerations, or characters may be used as an array index.

Given n is the size of the array and the first element of the array is indexed by subscript of 0, the last element of an array is accessed by (n-1).
Arrays can have multiple dimensions, thus it is not uncommon to access an array using multiple indices.


### One-dimensional arrays
A one-dimensional array (or single dimension array) is a type of linear array. Accessing its elements involves a single subscript which can either represent a row or column index.
```c
int array[0]; // Accessing the element at position 0.
```


### Multidimensional arrays
A multidimensional array is a type of linear array. Accessing its elements involves at least two subscripts which can either represent a row or column index.
```c
int array[0][1]; // Accessing the element at position 1 of the element at position 0.
```


## References
[Array data structure](https://en.wikipedia.org/w/index.php?title=Array_data_structure&oldid=889809412)
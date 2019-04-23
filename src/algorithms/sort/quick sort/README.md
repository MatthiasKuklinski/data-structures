# Quick sort

## About
Quicksort is a divide and conquer algorithm. Quicksort first divides a large array into two smaller sub-arrays: the low elements and the high elements. Quicksort can then recursively sort the sub-arrays.  
  * Pick an element, called a pivot, from the array.  
  * Partitioning: reorder the array so that all elements with values less than the pivot come before the pivot, while all elements with values greater than the pivot come after it (equal values can go either way). After this partitioning, the pivot is in its final position. This is called the partition operation.  
  * Recursively apply the above steps to the sub-array of elements with smaller values and separately to the sub-array of elements with greater values.  


## Performace
| Best-case                  | Average-case               | Worst-case                 | Stable                     | In place                   |
| :------------------------: | :------------------------: | :------------------------: | :------------------------: | :------------------------: |
| O(n log n)                 | O(n log n)                 | O(n<sup>2</sup>)           | No                         | Yes                        |


## References
[Quick sort](https://en.wikipedia.org/w/index.php?title=Quicksort&oldid=892836754)
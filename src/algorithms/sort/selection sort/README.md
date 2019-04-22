# Selection sort

## About
The algorithm divides the input list into two parts: the sublist of items already sorted, which is built up from left to right at the front (left) of the list, and the sublist of items remaining to be sorted that occupy the rest of the list. Initially, the sorted sublist is empty and the unsorted sublist is the entire input list. The algorithm proceeds by finding the smallest (or largest, depending on sorting order) element in the unsorted sublist, exchanging (swapping) it with the leftmost unsorted element (putting it in sorted order), and moving the sublist boundaries one element to the right.


## Performace
| Best-case                  | Average-case               | Worst-case                 | Stable                     | In place                   |
| :------------------------: | :------------------------: | :------------------------: | :------------------------: | :------------------------: |
| O(n<sup>2</sup>)           | O(n<sup>2</sup>)           | O(n<sup>2</sup>)           | Yes                        | Yes                        |


## References
[Selection sort](https://en.wikipedia.org/w/index.php?title=Selection_sort&oldid=892717001)
# CSC 212 Midterm Exam Review

## Programming Portion

You should be able to implement all of the functions declared in the `functions.hpp`, `string.hpp`, and `sorts.hpp` files.

Although there are some functions that may not be solvable recursively, you should be able to solve the vast majority both iteratively, and recursively.

For solutions, consult the various `.cpp` files.

## Comprehension Portion

You should be able to analyze and discuss all algorithms and functions we have implemented in class, along with analyzing some fictitious pseudocode algorithms.

### Recursion

1. What are the required components of recursive programming?
   1. A base case, which handles simple inputs that can be easily solved.
   2. A recursive call to the function itself, where the parameters are made closer to the base case.
2. What happens when you create a recursive function that does not reduce the problem size on each call?
   1. A recursive function that doesn't reduce the size of its problem will recurse infinitely, which results in a stack overflow, since each call requires a separate stack frame.

Provide recursive definitions, recurrence relations, and Big-Oh notation for the following functions:

```algorithm
Definition: func(x) = func(abs(x) - 1) + x; func(0) = 0
Relation: T(n) = T(n - 1) + 1; T(0) = 0
O(n), Omega(1)
function func(int x):
    return (x) ? func(abs(x) - 1) + x : 0;

Definition: func(array, n) = array[-1] + func(array + 1, n - 2) + array[0]; func([n], 1) = func([], 0) = 1
Relation: T(n) = T(n - 2) + 2; T(0) = T(1) = 1
O(n), Omega(1)
function func(int[] array, int n):
    if n <= 1: return
    else:
        swap(array[0], array[n-1])
        func(array + 1, n - 2)
```

### Sorting

1. What does it mean for a sorting algorithm to be stable?
   1. An algorithm that is stable will maintain the relative order of the objects it is sorting.
2. What does it mean for a sorting algorithm to be in-place?
   1. An in-place algorithm is one that can sort the elements given within the memory the original elements were stored, i.e. it requires O(1) space to perform its sorting.
3. What does it mean for a sorting algorithm to be adaptive?
   1. An adaptive algorithm is one that will take advantage of an array that is already partially sorted.
4. If you were given input conditions that the arrays would always be almost completely sorted, what algorithm would you choose?
   1. Insertion sort will be the best algorithm here as it runs in O(kn) where k is the upper bound on the distance each element is from where it should be.
5. Given input constraints that every input array would be smaller then 10 elements, which algorithm would you choose? Does it matter?
   1. I would choose insertion sort, though it doesn't necessarily matter for such a small number of elements, as the differences in runtime are extremely unlikely to make a difference.

Calculate the value for `n` at which you would choose algorithm A over algorithm B to sort a given list, or if you would always choose algorithm B.

```
A: T(n) = 27n; B: T(n) = n!
n >= 5

A: T(n) = 10n log n; B: T(n) = 2^n
n = 1

A: T(n) = 5n + n^2 - 6; B: T(n) = n^3 / 2
n = 1

A: T(n) = n^60; B: T(n) = 100n
Always B
```

### Bubble Sort

1. Provide the upper and lower bounds for best and worst cases for Bubble Sort.
   1. Best: $O(n)$ Worst: $O(n^2)
2. Is Bubble Sort stable? Adaptive? In-Place?
   1. Bubble sort is stable and in-place.
3. Are there any advantages to Bubble Sort?
   1. It is adaptive, and in-place.
4. What is the space-complexity of Bubble Sort?
   1. $O(1)$

### Insertion

1. Provide the upper and lower bounds for the best and worst cases for Insertion Sort.
   1. Best: $O(n)$ Worst: $O(n^2)$
2. Is Insertion Sort stable? Adaptive? In-Place?
   1. Insertion sort is adaptive, stable, and in-place.
3. What are the advantages to Insertion Sort?
   1. It runs in $O(kn)$ for partially sorted arrays, is in-place, and stable.
4. What is the space-complexity of Insertion Sort?
   1. $O(1)$

### Selection Sort

1. Provide the upper and lower bounds for the best and worst cases for Selection Sort.
   1. Best: $O(n^2)$ Worst: $O(n^2)$
2. Is Selection Sort stable? Adaptive? In-Place?
   1. In-place, can be made stable, not adaptive.
3. Are there any advantages to Selection Sort?
   1. Not really.
4. What is the space-complexity of Selection Sort?
   1. $O(1)$

### MergeSort

1. Provide the upper and lower bounds for the best and worst cases for MergeSort.
   1. Best: $O(n \log n)$ Worst: $O(n \log n)
2. Is MergeSort stable? Adaptive? In-Place?
   1. Stable
3. What is the purpose of the `merge` function in most MergeSort implementations? What about the `MergeSort` function?
   1. MergeSort splits up the array into smaller arrays, while merge  puts the arrays back together.
4. What is the space complexity of MergeSort?
   1. $O(n)$

### QuickSort

1. Provide the upper and lower bounds for the best and worst cases for QuickSort.
   1. Best: $O(n \log n)$ Worst: $O(n^2)
2. Is QuickSort stable? Adaptive? In-Place?
   1. In-Place
3. What is the purpose of the `partition` function in quicksort? What about the `quicksort` function?
   1. Partition will place all elements that are larger or smaller than the pivot to either the left or right and then call quicksort on both the new halves.
4. What partitioning scheme did you use in class for your `partition` function?
   1. EX: The Lomuto partitioning scheme, which selects the element in the last position in the array to be the pivot.
5. Find an array that would produce the worst case runtime for this partitioning scheme.
   1. EX: Lomuto, an array in reverse order will produce the worst-case for this partitioning scheme.

### Analysis

Solve the following recurrence relations:

1. `T(0) = 1 ; T(n) = 2T(n - 1) + 1`
2. `T(1) = 1 ; T(n) = 2T(n / 2) + n`
3. `T(0) = 1 ; T(n) = T(n - 1) + n`
4. `T(1) = 1 ; T(n) = T(n / 3) + 1`
5. `T(0) = 1 ; T(n) = T(n - 4) + 1`

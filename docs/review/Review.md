# CSC 212 Midterm Exam Review

## Programming Portion

You should be able to implement all of the functions declared in the `functions.hpp`, `string.hpp`, and `sorts.hpp` files.
Although there are some functions that may not be solvable recursively, you should be able to solve the vast majority both iteratively, and recursively.

## Comprehension Portion

You should be able to analyze and discuss all algorithms and functions we have implemented in class, along with analyzing some fictitious pseudocode algorithms.

### Recursion

1. What are the required components of recursive programming?
2. What happens when you create a recursive function that does not reduce the problem size on each call?

Provide recursive definitions, recurrence relations, and Big-Oh notation for the following functions:

```
function func(int x):
    return (x) ? func(x - 1) + x : 0;

function func(int[] array, int n):
    if n <= 1: return
    else: 
        swap(array[0], array[n-1])
        func(array + 1, n - 2)
```

### Sorting

1. What does it mean for a sorting algorithm to be stable?
2. What does it mean for a sorting algorithm to be in-place?
3. What does it mean for a sorting algorithm to be adaptive?
4. If you were given input conditions that the arrays would always be almost completely sorted, what algorithm would you choose?
5. Given input constraints that every input array would be smaller then 10 elements, which algorithm would you choose? Does it matter?

Calculate the value for `n` at which you would choose algorithm A over algorithm B to sort a given list, or if you would always choose algorithm B.

```
A: T(n) = 27n; B: T(n) = n!
A: T(n) = 10n log n; B: T(n) = 2^n
A: T(n) = 5n + n^2 - 6; B: T(n) = n^3 / 2
A: T(n) = n^60; B: T(n) = 100n
```

### Bubble Sort

1. Provide the upper and lower bounds for best and worst cases for Bubble Sort.
2. Is Bubble Sort stable? Adaptive? In-Place?
3. Are there any advantages to Bubble Sort?
4. What is the space-complexity of Bubble Sort?

### Insertion

1. Provide the upper and lower bounds for the best and worst cases for Insertion Sort.
2. Is Insertion Sort stable? Adaptive? In-Place?
3. What are the advantages to Insertion Sort?
4. What is the space-complexity of Insertion Sort?

### Selection Sort

1. Provide the upper and lower bounds for the best and worst cases for Selection Sort.
2. Is Selection Sort stable? Adaptive? In-Place?
3. Are there any advantages to Selection Sort?
4. What is the space-complexity of Selection Sort?

### MergeSort

1. Provide the upper and lower bounds for the best and worst cases for MergeSort.
2. Is MergeSort stable? Adaptive? In-Place?
3. What is the purpose of the `merge` function in most MergeSort implementations? What about the `MergeSort` function?
4. What is the space complexity of MergeSort?

### QuickSort

1. Provide the upper and lower bounds for the best and worst cases for QuickSort.
2. Is QuickSort stable? Adaptive? In-Place?
3. What is the purpose of the `partition` function in quicksort? What about the `quicksort` function?
4. What partitioning scheme did you use in class for your `partition` function?
5. Find an array that would produce the worst case runtime for this partitioning scheme.

### Analysis

Solve the following recurrence relations:

1. `T(0) = 1 ; T(n) = 2T(n - 1) + 1`
2. `T(1) = 1 ; T(n) = 2T(n / 2) + n`
3. `T(0) = 1 ; T(n) = T(n - 1) + n`
4. `T(1) = 1 ; T(n) = T(n / 3) + 1`
5. `T(0) = 1 ; T(n) = T(n - 4) + 1`

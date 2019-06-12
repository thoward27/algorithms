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

Algorithms: A: T<sub>1</sub>(n) = 27n; B: T<sub>2</sub>(n) = n!

Answer: n = 6. You can set the equations equal to one another and find the n such that T<sub>1</sub>(n-1) > T<sub>2</sub>(n-1) but T<sub>1</sub>(n) < T<sub>2</sub>(n).

1. 27n = n! 
2. 27 = n!/n = (n-1)!
3. Think about the first few factorials:
    1. 2! = 2, 3! = 6, 4! = 24, 5! = 120, 6! = 720
4. Since 4! = 24 \< 27 \< 120 = 5!, we have n-1 = 5, or n = 6.

Algorithms: A: T<sub>1</sub>(n) = 10n log n; B: T<sub>2</sub>(n) = 2^n
n = 1

Answer: n = 8. Here, trial and error is easier than solving algebraically. Since log n is easy to solve for powers of 2, try each one starting from 1.

1. T<sub>1</sub>(1) = 10*1 * log 1 = 10 * 0 = 0; T<sub>2</sub>(1) = 2^1 = 2
    1. T<sub>1</sub>(1) \< T<sub>2</sub>(1)
    2. We might think we are done, but since we have log 1 = 0 in T<sub>1</sub>(1), we can't be certain this is the solution
2. T<sub>1</sub>(2) = 10*2 * log 2 = 20 * 1 = 20; T<sub>2</sub>(2) = 2^2 = 4.
    1. T<sub>1</sub>(2) \> T<sub>2</sub>(2)
3. T<sub>1</sub>(4) = 10*4 * log 4 = 40 * 2 = 80; T<sub>2</sub>(4) = 2^4 = 16.
    1. T<sub>1</sub>(4) \> T<sub>2</sub>(4)
4. T<sub>1</sub>(8) = 10*8 * log 8 = 80 * 3 = 240; T<sub>2</sub>(8) = 2^8 = 256.
    1. T<sub>1</sub>(8) \< T<sub>2</sub>(8)
5. We could then check T<sub>1</sub>(7) and T<sub>2</sub>(7) with a calculator, and see that T<sub>1</sub>(7) \> T<sub>2</sub>(7)
6. Since T<sub>2</sub> continues to increase more quickly than T<sub>1</sub> after n = 8, our solution is n = 8. 

Algorithms: A: T<sub>1</sub>(n) = 5n + n^2 - 6; B: T<sub>2</sub>(n) = n^3 / 2

Answer: n = 4. Again, rather than attempting to solve a cubic polynomial, we can do simple trial and error starting at n = 1

1. T<sub>1</sub>(1) = 5*1 + 1^2 - 6 = 0; T<sub>2</sub>(1) = 1^3 / 2 = 1/2.
    1. T<sub>1</sub>(1) \< T<sub>2</sub>(1).
    2. Again, we have to be careful, because 1^x is 1 for all x.
2. T<sub>1</sub>(2) = 5*2 + 2^2 - 6 = 8; T<sub>2</sub>(2) = 2^3 / 2 = 4.
    1. T<sub>1</sub>(2) \> T<sub>2</sub>(2).
3. T<sub>1</sub>(3) = 5*3 + 3^2 - 6 = 18; T<sub>2</sub>(3) = 3^3 / 2 = 13.5.
    1. T<sub>1</sub>(3) \> T<sub>2</sub>(3).
4. T<sub>1</sub>(4) = 5*4 + 4^2 - 6 = 30; T<sub>2</sub>(4) = 4^3 / 2 = 32.
    1. T<sub>1</sub>(4) \< T<sub>2</sub>(4).
5. Since T<sub>2</sub> continues to increase more quickly than T<sub>1</sub> after n = 4, our solution is n = 4.

Algorithms: A: T<sub>1</sub>(n) = n^60; B: T<sub>2</sub>(n) = 100n

Answer: n = 2. It may seem like the answer is "Always B", since even just 2^60 is much greater than 200, but again, since 1^x is 1 for all x, T<sub>1</sub>(1) = 1 \< T<sub>2</sub>(1) = 100. Thus, since we clearly saw that 2^60 is much greater than 200, n = 2.

### Bubble Sort

1. Provide the upper and lower bounds for best and worst cases for Bubble Sort.
   1. Best: $O(n)$ Worst: $O(n^2)$
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

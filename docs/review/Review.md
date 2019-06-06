# CSC 212 Midterm Exam Review

## Iterative Problem Solving

You should be able to implement all of the functions declared in the `functions.hpp` file, along with:

- 

## Functions on Single Variable

Review Functions:

1. Implement a Binary to Integer function that takes a string representing a binary number and returns its integer equivalent.  
`int bintoint(char * str);`
2. Implement a character to ascii function that takes a character and returns its equivalent ascii code. (This function is to highlight a feature of the C/C++ language and should be a one line solution)  
`int chartoascii(char c);`
3. Implement a character to integer function that takes a character represeneting a number (e.g. '1'), and returns its integer equivalent.  
`int charnumtoint(char c);`
4. Implement a String to Integer function that takes a string representing a decimal number and returns its integer equivalent.  
`int strtoint(char * str);`

## Functions on Arrays

Review Functions:

1. Implement a function that will check if an array is in sorted order.  
`bool issorted(int * arr, int n);`

2. Implement a function that will return a 1 if the array is in increasing order, a -1 if the array is in decreasing order, and a 0 otherwise.  
`int order (int * arr, int n);`

3. Implement a function that reverses a of the elements in an array of integers.  
`void reverse(int * arr, int n);`

4. Implement binary search on an array of integers that returns the index of the key if it is found and a 0 otherwise.  
`int binsearch(int * arr, int n);`

## Recursion

### Recursion: Comprehension Questions

1. What is the primary advantage of recursive thinking?  
2. What problems can be solved recursively?
3. What must every solution have? Why must they have this?
4. Can a function be exclusively recursive (i.e. has no iterative solution)?

#### Recursion: Programming Practice

Review Functions:

1. Implement a recursive sum function that returns the sum of all elements in the array.  
`int recsum(int * arr, int n);`

2. Implement a recursive function that checks whether or not a string is a palindrome (spelled the same forwards and backwards) ignoring spaces.  
`bool plaindrome(char * string, int n);` Hint: keeping track of the length of the string will make this trivial

3. Implement a recursive factorial function that returns the result of num!.  
`int recfact(int num);` (Only test this with small values for num, factorial time is large for a reason)

4. Implement a recursive fibonacci function that returns the nth fibonacci number.  
`int recfib(int n);` (with fib(0) == 0 and fib(1) == 1) 

## Sorting / Bubblesort

### Comprehension Questions

1. What does it mean for a sorting algorithm to be stable?
2. What does it mean for a sorting algorithm to be in-place? 
3. What is the best case (Big-Omega) runtime of Bubblesort?
4. What is the worst case (Big-O) runtime of Bubblesort?
5. Are there any advantages to bubblesort?

### Programming Practice

Implement bubblesort on an array of integers that sorts items into non-increasing order (5, 5, 4, 2, 2, 1).  
`void bubblesort(int * arr, int n);`

## Insertion / Selection Sort

### Comprehension Questions

1. Are Inesertion and/or Selection sort stable algorithms? Are they In-Place algorithms?
2. What does it mean for an array to be partiall-sorted?
3. Find the big-Omega, Big-O, and Big-Theta for Selection and Insertion sort. 

### Programming Practice

Implement Insertion sort on an array of integer that sorts items into strictly increasing order (1, 2, 3, 4, 5).  
`void InsSort(int * arr, int n);`

Implement Selection sort on an array of integer that sorts items into non-decreasing order (1, 2, 2, 4, 5, 5).  
`void SelSort(int * arr, int n);`

## Mergesort

#### Comprehension Questions

1. What is the purpose of the `merge` function in most mergesort implementations? What about the `mergesort` function?
2. What is the average (Big-Theta) runtime of Mergesort?
3. What is the space complexity of mergesort?

#### Programming Practice

Implement Mergesort (make use of a helper `merge` function!) on an array of integer that sorts items into strictly decreasing order (5, 4, 3, 2, 1).  
`void Mergesort(int * arr, int n);`

## QuickSort

#### Comprehension Questions

1. What is the worst-case (Big-O) runtime of Quicksort? What about the average (Big-Theta) runtime of Quicksort? 
2. What is the purpose of the `partition` function in quicksort? What about the `quicksort` function?
3. What partitioning scheme did you use in class for your `partition` function? 
4. Find an array that would produce the worst case runtime for this partitioning scheme.

#### Programming Practice

Implement the partition function for quicksort using the Lumoto partitioning scheme.  
`void partition(int * arr, int n);` 

## Sorting and Analysis Review

#### Comprehension Questions

1. Solve the recurrence relation: `T(0) = 1 ; T(n) = 2T(n - 1) + 1`

2. Solve the recurrence relation: `T(1) = 1 ; T(n) = 2T(n / 2) + n`

3. Solve the recurrence relation: `T(0) = 1 ; T(n) = T(n - 1) + n`

4. Solve the recurrence relation: `T(1) = 1 ; T(n) = T(n / 3) + 1`

5. Solve the recurrence relation: `T(0) = 1 ; T(n) = T(n - 4) + 1`

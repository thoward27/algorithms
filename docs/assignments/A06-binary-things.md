# Assignment 06: For the Love of Binary

For this assignment you will be implementing and analyzing two algorithms: Tree Sort and Binary Search.

## The Algorithms

### Tree Sort

Using a BST to sort an array of elements.

The steps to perform tree sort are:

1. Insert all of the elements in the array into a BST
2. Traverse the tree, placing each element back into the array in sorted order.

Input constraints:

Let \[A = \{x \in \mathbb{Z} | -10,000 \leq x \leq 10,000\}\].

Some pseudocode:

```python
def treesort(A) -> None:
   tree = BST()
   # Insert all of the elements into a BST
   for element in A:
      tree.insert(element)

   # Traverse the tree replacing elements in A
   i = 0
   for element in A.traverse():
      A[i] = element
      i += 1
```

## Binary Search

This algorithm relies on the input array being in sorted order to efficiently find elements.

The steps are:

1. If there are no elements in the array, return -1.
2. If the middle element is the one we are looking for, return that index.
3. If the element at the middle is larger than the one we are searching for, recursively search the left half.
4. Otherwise, recursively search the right half.

Input constraints:

Let $A = \{x \in \mathbb{Z} | x[i-1] \leq x[i] \forall i \geq 1, -1000 \leq x \leq 1000 \}$

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/9gBhRcA_)
   1. Be sure to select your name from the list to link your Github to the class roster!
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
      1. Be sure to use the link for **your copy** of the repository for the assignment
3. Getting things in order
   1. Open your new folder in VS Code
   2. In your folder you should have an updated copies of `functions.test.cpp, functions.hpp, functions.cpp, functions_recursive.cpp, sorts.test.cpp, sorts.hpp, and sorts.cpp`.
   3. Check that you can compile and run the unit tests for Tree Sort
      1. `g++ -std=c++11 source/sorts/sorts.test.cpp source/sorts/sorts.cpp source/Functions/functions.cpp && ./a.out`
   4. Check that you can compile and run the unit tests for Binary Search
      1. Iterative `g++ -std=c++11 source/Functions/functions.test.cpp source/Functions/functions.cpp && ./a.out`
      2. Recursive `g++ -std=c++11 source/Functions/functions.test.cpp source/Functions/functions_recursive.cpp && ./a.out`
   5. At this point you should be failing 3 unit tests, one for tree sort, and one for each implementation of binary search.
4. [60 points] Implement and analyze Tree Sort **Commit and Push your work after each task**
   1. [50 points] Implement Tree Sort in `sorts.cpp`.
   2. [10 points] Analyze the function, providing your pseudocode, and Big-Oh for the best and worst case.
5. Run the following command: `git add . && git commit -m "Tree Sort" && git push`
6. [40 points] Implement and analyze Binary Search **Commit and Push your work after each task**
   1. [15 points] Your iterative implementation should go in `functions.cpp`
   2. [15 points] Your recursive implementation should go in `functions_recursive.cpp`
   3. [10 points] Analyze your functions, providing pseudocode, and Big-Oh notation.
7. Run the following command: `git add . && git commit -m "Binary Search" && git push`

## Submission

To submit this assignment, simply commit and push your work to your assignment repository.
Your last submission before the deadline will be graded.

# Assignment 06: For the Love of Binary

For this assignment you will be implementing and analyzing two algorithms: Tree Sort and Binary Search.

## The Algorithms

### Tree Sort

This algorithm uses a BST to sort an array of elements.

The steps are:

1. Insert all elements into the binary search tree.
2. Traverse the tree, refilling the original array such that it is sorted.

## Binary Search

This algorithm relies on the input array being in sorted order to efficiently find elements.

The steps are:

1. Check if the middle element is the one we are looking for, return the index if so.
2. If the element at the middle is larger than the one we are searching for, recursively search the left half.
3. Otherwise, recursively search the right half.
4. Return -1 if the element is not in the array.

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/jQi18jXV)
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
   3. Check that you can compile and run the unit tests for Tree Sort `g++ -std=c++11 source/Sorts/Sorts.test.cpp source/Linear/Sorts.cpp && ./a.out`
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

# Assignment 05: For the Love of Binary

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
   2. In your folder you should have: `calculator.cpp`, `source/Algorithms/twostack.hpp`, `source/Algorithms/twostack.cpp`, `source/Linear/Stack.test.cpp` and `source/Linear/Stack.cpp`.
   3. Check that you can compile and run your calculator program `g++ -std=c++11 calculator.cpp source/Linear/Stack.cpp && ./a.out`
   4. Check that you can compile and run the Two Stack starter code `g++ -std=c++11 calculator.cpp source/Linear/Stack.cpp && ./a.out`
      1. Ensure that your test cases fail.
4. Implement the `main` function (30 points)
   1. Following the pseudocode in `calculator.cpp`, implement the main function for your calculator.
5. Implement the algorithm (60 points)
   1. Write pseudocode for your algorithm
   2. Commit and push this pseudocode (`git add . && git commit -m "<message>" && git push`)
      1. Check that your pseudocode uploaded, and is visible on the master branch of your assignment.
   3. Implement the Stack datatype, as it is not provided.
   4. Implement your pseudocode in C++
   5. Pass all unit tests
   6. Commit and push your code (`git add . && git commit -m "<message>" && git push`)
      1. Check that all of your working code is uploaded, and visible on the master branch of your assignment.
6. Analyze your work (10 points)
   1. Provide your algorithms' Big-Oh notation as a function of expression length.

## Submission

To submit this assignment, simply commit and push your work to your assignment repository.
Your last submission before the deadline will be graded.

## Grading

For this assignment, 70 points will be awarded for functionality, 10 for your analysis, and 20 for readability.

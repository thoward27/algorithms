# Assignment 03: Hybrid Sorting

For this assignment you will have to create a hybrid sorting algorithm.
A hybrid sorting algorithm is one that combines two different algorithms such as MergeSort + Bubble, or QuickSort + Selection.
When creating a hybrid sorting algorithm, you are exploiting the benefits of both, while avoiding the worst cases.

Continuing the example of MergeSort + Bubble Sort, one approach could be letting MergeSort split the list into smaller chunks, then allowing Bubble Sort to sort those small chunks.
The reason for this, is that MergeSort may have an extremely high constant value, meaning that for low values of `n`, bubble sort may actually be faster!

> Need a refresher on this? See our notes on [functions](docs/notes/functions.html)

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/ztjoUAr2)
   1. Be sure to select your name from the list to link your Github to the class roster!
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <Link to your repository>`)
      1. Be sure to use the link for **your copy** of the repository
3. Getting things in order
   1. Open your new folder in VS Code
   2. Begin by creating a signature and dummy definition for your Hybrid Sorting function.
      1. Your signature should take an array as input, along with the number of elements, and return nothing.
      2. Your dummy definition should just be a blank return statement.
   3. Check your work by compiling and running your code (`g++ -std=c++11 source/sorts.cpp && ./a.out`)
   4. Make sure the code compiled and ran, and that the unit tests for your function failed.
   5. Commit and push these changes (`git add . && git push`)
   6. Check the online copy of your repository to make sure these changes were actually pushed
4. Implement your algorithm (50 points)
   1. Select the algorithms you'd like to combine
   2. Decide when each algorithm should fire (maybe cases depending on the size of n)
   3. Write pseudocode for your algorithm
   4. Commit and push this pseudocode (`git add . && git push`)
   5. Implement your pseudocode in C++
   6. Pass all unit tests
   7. Commit and push your code (`git add . && git push`)
5. Analyze your work (40 points)
   1. Provide your algorithms' Big-Oh, Omega, and Theta notation
   2. Explain and justify your decisions for when certain algorithms are called
      1. Provide theoretical and empirical reasoning for full credit

## Submission

To submit this assignment, simply commit and push your work to your assignment repository.
Your last submission before the deadline will be graded.

## Grading

For this assignment, 50 points will be awarded for functionality, 40 for your analysis, and 10 for readability.

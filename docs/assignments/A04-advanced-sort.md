# Assignment 04: Advanced Sorting

For this assignment you must implement and analyze one advanced sorting algorithm of your choosing.
Your algorithm cannot be the same as the one used in the previous assignment.

You may select any algorithm from the following list:

## Distribution Sorts

- Spreadsort
- Radix Sort
- Flashsort
- Pigeonhole Sort
- Bucket Sort
- Postman Sort

## Comparison Sorts

- In-place MergeSort
- Introsort
- TimSort
- CubeSort
- ShellSort
- CycleSort
- Library Sort
- Patience Sorting
- SmoothSort
- StrandSort
- Block Sort
- Topological Sort
- Curve sort

The student with the fastest sorting algorithm will receive 50 bonus points, second fastest will receive 30, third will receive 20.

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/0-TyqToY)
   1. Be sure to select your name from the list to link your Github to the class roster!
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
      1. Be sure to use the link for **your copy** of the repository for the assignment
3. Getting things in order
   1. Open your new folder in VS Code
   2. Begin by creating a new file `source/Sorts/advanced.cpp`.
      1. Within this file, create the definition for your advanced sorting algorithm: `void sort(int*, int) {}`
   3. Check your work by compiling and running your code (`make advanced`)
   4. Make sure the code compiled and ran, and that the unit tests for your function failed.
   5. Commit and push these changes (`git add . && git commit -m "<message>" && git push`)
   6. Check the online copy of your repository to make sure these changes were actually pushed
4. Implement your algorithm (80 points)
   1. Write pseudocode for your algorithm in the docstring.
   2. Commit and push this pseudocode (`git add . && git commit -m "<message>" && git push`)
   3. Implement your pseudocode in C++
   4. Pass all unit tests
   5. Commit and push your code (`git add . && git commit -m "Done" && git push`)
5. Analyze your work (10 points)
   1. Provide your algorithms' Big-Oh, Omega, and Theta notation

## Grading

| Criteria      | Points |
| ------------- | ------ |
| Functionality | 70     |
| Analysis      | 10     |
| Quality       | 20     |

## Submission

To submit this assignment, simply commit and push your work to your assignment repository.
Your last submission before the deadline will be graded.

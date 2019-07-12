# Assignment 07: Heap Sort

For this assignment you will be using our class-built heap to implement the heap sort algorithm, making all necessary changes to the base class, while still maintaining its original functionality.

## The Algorithm

Given an array $A := \{x \in \mathbb{Z} | -10,000 \leq x \leq 10,000 \}$

```python
def heapsort(A):
   # Create a heap.
   Heap h
   # Push all elements to the heap.
   for x in A:
      h.push(x)
   # Refill the original array with the in-order elements.
   for i in range(0, len(A)):
      A[i] = h.pop()
   return
```

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/BCUpZdDr)
   1. Be sure to select your name from the list to link your Github to the class roster!
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
3. Getting things in order
   1. Open your new folder in VS Code
   2. Begin by creating a new file `source/Sorts/heap.cpp`
      1. Within this file, create the defition for your heap sort algorithm.
   3. Check that you can compile and run the unit tests for heap sort (`make heap`)
   4. Commit and push these changes (`git add . && git commit -m "<message>" && git push`)
   5. Check the online copy of your repository to make sure these changes were actually pushed
4. Implement the Algorithm **Commit and Push your work after each task**
   1. Begin by creating pseudocode for the algorithm in the docstring
   2. Commit and push this pseudocode
   3. Implement your pseudocode in C++
   4. Pass all unit tests
   5. Commit and push your code.
5. Analyze your work
   1. Determine the cost for each line in your algorithm
   2. Present your Best / Worst case analysis at the bottom of your docstring.
6. Submit your work (`git add . && git commit -m "Done" && git push`)

## Grading

| Criteria               | Points |
| ---------------------- | ------ |
| Functional Correctness | 70     |
| Analysis               | 20     |
| Quality                | 10     |

## Submission

Submissions are handled by Github Classroom.
Submissions after the deadline are not graded.

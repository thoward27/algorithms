# Assignment 06: Tree Sort

For this assignment you will be implementing and analyzing Tree Sort.

## The Algorithm

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
   2. Begin by creating a new file `source/Sorts/tree.cpp`
      1. Within this file, create the definition for the sorting algorithm.
   3. Check that you can compile and run the unit tests for Tree Sort (`make tree`)
   4. Ensure that your code compiled, ran, and failed the unit tests.
   5. Commit and push your code
   6. Check the online copy of your repository to make sure your changes were pushed successfully
4. Implement the algorithm **Commit and Push your work after each task**
   1. In the docstring for your function, write pseudocode to solve the problem
   2. Commit and push your pseudocode
   3. Implement the algorithm in C++
   4. Pass all unit tests
   5. Commit and push your work
5. Analyze your work
   1. Proceed line by line, noting runtimes for each action
   2. Document your Best and Worst case analysis at the bottom of your docstring
6. Submit your work
   1. Commit and push all code to your assignment repository.

## Grading

| Criteria      | Points |
| ------------- | ------ |
| Functionality | 70     |
| Analysis      | 20     |
| Quality       | 10     |

## Submission

To submit this assignment, simply commit and push your work to your assignment repository.
Your last submission before the deadline will be graded.

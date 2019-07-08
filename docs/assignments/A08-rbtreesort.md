# Assignment 08: Left-Leaning Red/Black Tree Sort

For this assignment you will be implementing Tree Sort using a Red/Black Tree

## The Algorithm

Given an array $A = \{x \in \mathbb{z} | -100,000 \leq x \leq 100,000 \}$

```python
def treesort(A) -> None:
   tree = RBTree()
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

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/5YjTBf1O)
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
3. Getting things in order
   1. Open your new folder in VS Code
   2. Check that you can compile and run the unit tests for sorting (`make sorts`)
4. Implement LLRB Tree Sort **Commit and Push your work after each task**
   1. Add the signature for `LLRBTreeSort` to `sorts.hpp` (`LLRBTreeSort(int*, int)`)
   2. Add a unit test to `sorts.test.cpp` for `LLRBTreeSort`
   3. Create a docstring for your implementation
   4. In your docstring, detail your pseudocode for your approach
   5. Implement the sorting function
   6. Analyze the function you just wrote, noting the runtimes per line
      1. In your analysis, make direct comparisons to the plain BST Tree Sort you already created.
   7. Present your Big-Oh analysis for the best and worst case at the bottom of your docstring
5. Submit your work (`git add . && git commit -m "Done" && git push`

## Grading

| Criteria               | Points |
| ---------------------- | ------ |
| Functional Correctness | 80     |
| Analysis               | 10     |
| Quality                | 10     |

## Submission

Submissions are handled by Github Classroom.
Submissions after the deadline are not graded.

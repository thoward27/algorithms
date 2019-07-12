# Bonus 04: Left-Leaning Red/Black Tree Sort

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
   2. Begin by creating a new file `source/Sorts/balancedtree.cpp`, populated with a definition for `sort`
   3. Check your work by compiling and running your code (`make balancedtree`)
   4. Commit and push your work.
4. Implement the Algorithm **Commit and Push your work after each task**
   1. Begin by creating pseudocode for your approach in the docstring
   2. Implement this pseudocode in C++
   3. Analyze your work and provide the best / worst-case analysis
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

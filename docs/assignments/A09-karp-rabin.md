# Assignment 09: Karp-Rabin Substring Search

For this assignment you will be implementing an algorithm capable of pattern-matching substrings in a larger body of text.

## The Algorithm

Karp-Rabin (or Rabin-Karp) uses rolling hashing to find substrings within a larger string.

Pseudocode for this algorithm is as follows:

```python
def KarpRabin(text, pattern):
    hash_pattern = hash(pattern)
    for i in range(0, len(text)):
        if hash_pattern == hash(text[i:i + len(pattern)]) and text[i:i + len(pattern)] == pattern:
            return True
    return False
```

Essentially, we hash the pattern we are looking for, then compare that hash to a hash of a small piece of the main text.

For this task, we use a special "rolling hash" function, similar to the one we've seen on the Princeton slides.

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/V5-ecbS2)
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
3. Getting things in order
   1. Open your new folder in VS Code
4. Implement the algorithm **Commit and Push your work after each task**
   1. Locate the header file `karprabin.hpp` under `Algorithms`
   2. In the docstring for your sorting algorithm, detail your pseudocode for accomplishing this task.
   3. Under the provided signature implement the algorithm.
   4. Analyze your work, providing the O(?) runtime.
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

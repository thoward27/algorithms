# Assignment 10: Lexicographic String Sorting

For this assignment you will be implementing an algorithm capable of sorting strings lexicographically.

## The Algorithm

Lexicographic sorting is the process of sorting strings in alphabetic order.

> Hint: We have already constructed a fantastic data structure to accomplish this goal.

## Example

sort(["abz", "abc"], 2) -> ["abc", "abz"]
sort(["ab", "ba", "aa"], 3) -> ["aa", "ab", "ba"]

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/rWxvtRFI)
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
3. Getting things in order
   1. Open your new folder in VS Code
4. Implement the algorithm **Commit and Push your work after each task**
   1. Locate the header file `lexicographic.hpp` under `Algorithms`
   2. In the docstring for your sorting algorithm, detail your pseudocode for accomplishing this task.
   3. Under the signature `sort(String* arr[], int n)` implement a lexicographic sorting algorithm.
   4. Analyze your work, providing the O(?) runtime.
5. Submit your work (`git add . && git commit -m "Done" && git push`

## Grading

| Criteria               | Points |
| ---------------------- | ------ |
| Functional Correctness | 80     |
| Analysis               | 10     |
| Quality                | 10     |

## Bonus

For this assignment, you may accrue an additional 25 bonus points by implementing the `Burstsort` algorithm, which is a slightly more advanced implementation of lexicographic sorting.

### Resources

- [The paper that introduced burtsort](https://people.eng.unimelb.edu.au/jzobel/fulltext/acmjea04.pdf)
- [Wikipedia Entry](https://en.wikipedia.org/wiki/Burstsort)

## Submission

Submissions are handled by Github Classroom.
Submissions after the deadline are not graded.

# Assignment 10: A* Search

For this assignment you will be implementing an algorithm capable of more efficiently finding paths through a more complicated maze.

## The Algorithm

A* Search uses a heuristic to try and take "better" steps through a maze.

Typically, the metric used is a simple Euclidean Distance.

Pseudocode for this algorithm is as follows:

```python
def asearch(maze, start, finish):
    frontier = PriorityQueue()
    frontier.put(start, 0)
    came_from = {}
    cost_so_far = {}
    came_from[start] = None
    cost_so_far[start] = 0

    while not frontier.empty():
    current = frontier.get()

    if current == goal:
        break

    for next in maze.neighbors(current):
        new_cost = cost_so_far[current] + maze.cost(current, next)
        if next not in cost_so_far or new_cost < cost_so_far[next]:
            cost_so_far[next] = new_cost
            priority = new_cost + heuristic(goal, next)
            frontier.put(next, priority)
            came_from[next] = current
```

### Resources

- [Computerfile](https://www.youtube.com/watch?v=ySN5Wnu88nE)
- [Red Blob Games](https://www.redblobgames.com/pathfinding/a-star/introduction.html)

## Instructions

This assignment will be hosted on Github Classroom.

1. Register for the assignment on our Github Classroom using [this link](https://classroom.github.com/a/xa30-340)
2. Clone the repository to your machine
   1. Open a terminal
   2. Navigate to your algorithms folder
   3. Go to the parent directory (`cd ..`)
   4. Clone the repository to this location (`git clone <your repository link here>`)
3. Getting things in order
   1. Open your new folder in VS Code
4. Implement the algorithm **Commit and Push your work after each task**
   1. Locate the header file `a-star.hpp` under `Algorithms`
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

# Lab 05: Recursive Backtracking

Today you will be implementing two recursive algorithms. The neat thing about recursion is that you can solve problems with a relatively small amount of well thought out code.

> For this lab you will form groups of at least 2 and no more than 5 members.

## 1. A Quick Review of Recursion

In its simplest form, recursion is just the act of a function calling itself within its own body. Recursion essentially breaks the problem apart into smaller, more easily solvable pieces, which can lead to some very elegant and important algorithms. When a recursive function is called by a function other than itself it begins execution, just like any other function. However, when the program reaches the line in which the function calls itself a new "instance" of the function is created, hopefully with a slightly different set of parameters (otherwise it may recurse forever!). This new instance will likely reach a point where it calls itself again, creating yet another new instance with, again, slightly different parameters; this process repeats until the *base case* is reached.

At first, this may seem like an infinite loop of sorts, but if the function is implemented correctly, the input size should get reduced on each call, as the function works towards solving the problem. Eventually the function will reduce its parameters enough to handle the input non-recursively, and then return to whatever instance of the function last called it. From there each previous function will return (perhaps after doing some processing) until the original call returns and the recursive function has completed. Unfortunately, if the function is implemented without a base case, or continually recurses without reaching one, the program will crash with a stack overflow error.

### Example: Greatest Common Divisor

The Euclidean algorithm is a computationally efficient way to find the greatest common divisor between any two numbers.
The greatest common divisor of _a_ and _b_ is the largest number that will divide evenly into both _a_ and _b_.
For example, _GCD(81,96)_ is _3_ because _3_ is the largest number that will divide _81_ and _96_ with no remainder.  The algorithm can be formulated as follows:

```
GCD for any a, b:
    if b is larger than a:
        swap a and b
        
    if a is equal to b:
        a is the GCD of a and b
    otherwise apply GCD(a-b, b)
```
Here is the wikipedia on GCD in a recursive context. Use it as a resource if needed https://en.wikipedia.org/wiki/Recursion_(computer_science)#Greatest_common_divisor

From this you can see that recursion is fundamental to the problem, as the GCD algorithm we have just defined invokes itself for certain inputs.  Your job is to implement the GCD algorithm and time your function as you did in the previous question.

> You will **report** the actual running time of calling your function with the following pairs of values: (100,612), (1098,8721), (10872,17238), (1000000000,100000000), (184729384, 2273652).  Include your intuition behind the running time of this function (constant? linear? logarithmic? quadratic? ...).

### Running the Code

You can compile and run your program using the command below:
```bash
$ g++ -g -Wall -std=c++11 gcd.cpp -o gcd && ./gcd
```
> The **&&** here symbolizes "do what's on the left of me, then if that's successful, do what's on the right" -- Learning bash can make development a much easier process!


## 2. Backtracking

One of the most useful implementations of recursion is in an algorithm utilizing backtracking. A backtracking algorithm solves problems in much the same way that you would solve a cornmaze. When you want to escape a cornmaze, you try one path until either it leads you out of the maze or you hit a dead end and declare this path a failure. Once this path is considered a failure, you *backtrack*, abandoning this path and returning to the last fork in the maze and try another path. Eventually you will either escape the maze or you will have tried all possible paths and will declare it unsolvable. 

In a very similar manner, a backtracking algorithm incrementally builds candidate solutions (you walk along paths one step at a time) to solve problems (escape the maze), and abandons candidates once it determines that it cannot possibly lead to a valid solution (you hit a dead end which is not the exit). It will then test another candidate solution until all candidates have been exhausted or the problem has been solved and satisfies the required criteria.

### N-Queens

For the remainder of the lab, you will be working with your teams to solve the N-Queens puzzle. The N-Queens puzzle is the problem of placing N chess queens on an NxN chessboard in such a way that no two queens can attack each other. This problem is an excellent example of a backtracking algorithm. 

> You can play with an 8x8 board [here](http://www.hbmeyer.de/backtrack/achtdamen/eight.htm).

### The Algorithm

> **You can find starter code for this problem (named queens.cpp) in the lab-05 folder**

> A visualization of a possible algorithm is [here](https://www.cs.usfca.edu/~galles/visualization/RecQueens.html).

The general algorithm to solve this problem goes as such:

Before calling the recursive algorithm, a grid of NxN booleans needs to be created.  Initially all cells are marked as `False`, i.e. they are empty.  Your recursive function will mark a cell as `True` every time a queen is placed in that cell.

Your initial call will place the first queen in the leftmost column (column 0), the queens will be placed 
in column order of left to right. The inside of the recursive solve function will look like this:

    1. If current column being looked at = N, then all queens have been placed, return true. 
    (this is your base case)
    2. If your base case isn't satisfied, do the following:
        1. Try placing the queen in all the rows in the current column.
        2. For each row, check if the queen is safe in its current position using isSafe(). If isSafe returns true, 
        change the 0 at the current position to a 1 and call the recursive function on the next column.
        3. Check whether the recursive function call returns true
            * If the above call returns true, then the solution has been found because all subsequent recursions
        returned true. In this case just return true.
        4. If the recursive function call doesn't return true, this is an invalid candidate solution and it is time to 
        backtrack. Change the current queen from a 1 to a 0 because it doesn't lead to a correct solution and continue 
        the search for safe rows for the current queen by returning to step 2 and searching the rest of the rows.
    3. If all rows have been tried by the else statement and none returned true, return false, there is no solution

## 3. Submission

Each group will submit 3 files named `gcd.cpp`, `gcd.txt` and `queens.cpp` on Gradescope. Please ensure your files contain the following:

1. `gcd.cpp` should contain the source code for your implementation of the Euclidean Algorithm.
2. `gcd.txt` should contain your report of the results of running `gcd.cpp` on the given inputs.
3. `queens.cpp` should contain the source code for your implementation of the N-Queens Algorithm.

If you are unable to complete the entire lab, submit what you have for each of the above files. If you were not able to start `queens.cpp`, submit the starter code as is.

> Make sure you add **all group members** to your submission on Gradescope

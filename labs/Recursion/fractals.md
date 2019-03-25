# Lab 06: Lab + Recursion(6) = Lab + (Lab + Recursion(5))

## Introduction

Recursion is the practice of breaking a complicated problem down into small, trivially solvable pieces, and then merging those pieces together to solve the full problem completely. 
Today you will be implementing a few recursive algorithms. 
The neat thing about recursion is that you can solve problems with a relatively small amount of well thought out code.

## A Quick Review of Recursion

In its simplest form, recursion is simply when a function calls itself within its own body. 
When a recursive function calls itself, a new stack frame is pushed onto the call stack with a slightly different set of parameters (if the parameters do not change it may recurse forever!). 
Calling itself allows the function to start again from the first line using the new parameters. 
The function call associated with this new stack frame will likely reach a point where it calls itself again, creating yet another stack frame with, again, with slightly different parameters.  This process repeats until the base case is reached.

At first, this may seem like an infinite loop of sorts, but if the function is implemented correctly, the input should be modified at each call such that the parameters get closer to triggering the base case. 
In the base case, some non-recursive code is executed, and the function is able to return to whichever stack frame came before it, picking up where it left off. 
One by one, each call to the recursive function will complete, having done some processing on the input, and return its own result. 
If the function is implemented without a base case, or continually recurses without reaching one, the program will instead crash with a stack overflow error.

### How to think about recursive function calls
<img src="https://i.imgur.com/Z5eeHrE.png" height="500px">

In the above diagram, each box is a call to the recursive function `foo`. 
In the base case, simple, often times even trivial, steps are taken for some special case of the input. 
After returning from the base case, each call to `foo` may *use* the result returned to it and return to its caller.

**Note:** Each deeper level of recursion is solving a smaller problem, so when you think of a recursive algorithm, you will often ask yourself three questions: "How can I make this input smaller?", "What is the base case I am working towards?" and "How do I use solutions to the smaller problem to solve the bigger problem?"

## 1. Sum of Numbers

Before you begin implementing recursive algorithms for yourself, you'll be guided through each step of a recursive implementation of the sum from 1 to n. 
Along the way, you will see which part of the algorithm corresponds to which concept, and hopefully you will get a better understanding of how to think about a recursive algorithm.

First, open the file `sum.cpp` that came with this lab (or copy it in if you're not using git). 
All you have is a small `main` and an empty function `sum` which presently returns 0. 
Enter each of the following lines after reading the description for each, starting at line `4`.

```c++
if (n == 0) {
    return 0;
}
```

For most recursive algorithms, the best place to start is the base case, and since it's so important (and allows you to end your function early with a `return`) it will often be at the top. 
The base case should be a small sub-problem which can be solved easily. 
In this case, `sum(0)` should sum no numbers from 1 to n, so it is defined to be 0, which will be a useful value when we consider the recursive step. 
Thus, you should note there are two important things going on here: we are *checking for the base case* with `n == 0`, and we are *solving the base case* by returning 0.

```c++
unsigned long sub_sum = sum(n - 1);
```

To reach this line, the base case must be false `(n != 0)`, and so we must now recurse. 
We have already solved the question asking "what is the base case?" so now we address "how can the input size be reduced?". 
Observe that the sum of all numbers from 1 to n uses the sum of all numbers from 1 to n-1 in the result, so we can get that sum by calling `sum(n - 1)` and storing it in a variable. 
Now we should have the solution to a smaller problem, which we can use in the solution to the whole problem.

> Note: Often times instead of storing the value of the recursive call in a variable we will use it directly, either in some other computation to be stored in a variable or right in the return statement itself.
 
 ```c++
 unsigned long total = n + sub_sum;
 ```
 
Finally, we address the third question: "how can the solution to the smaller problem be used to solve the whole problem?". 
In this case it is fairly trivial, in that since we're summing the numbers from 1 to n, and we have the sum from 1 to n-1, we can just add n to the sum from 1 to n-1 to obtain our solution. 
However, in many algorithms this question is not so trivially answered, and sometimes this part, which is sometimes called the *combination step*, requires a whole separate algorithm to solve. 
This what is meant by the "use" part of "use and return" in the diagram at the beginning of the lab.

> Note: In some recursive problems, such as fibonacci, there will be more than one sub-problem needing to be solved, requiring multiple recursive calls, typically with different inputs. 
In such cases, the combination step requires combining the solutions to *all* the sub-problems to solve the whole problem. 
On the other hand, sometimes there is no combination step required, despite there being recursive calls. 
This is often the case with recursive functions with side-effects.

```c++
return total;
```

The final problem to address is that `sum` is still returning 0, so we will now have it return `total`. 
Keep in mind that if some function other than `sum` is being returned to, then `total` represents the final solution: the sum from 1 to the original input n. 
However, if it is returning to another call to `sum`, then `total` represents the sum from 1 to n-1 from the perspective of the call it is returning to.

At this point you can compile and run `sum.cpp`. 
Since `sum` is called on 10 and on 100, you should get 55 and 5050 respectively. 
For the case of 10, you can see that the algorithm will give you the following

sum(10) = 10 + sum(9) = 10 + 9 + sum(8) = ... = 10 + 9 + ... + 2 + 1 + sum(0) = 55.

You should now take a moment to consider what the time complexity (big O) of this function is. 
Despite not having analyzed recursive functions before, you should still be able to come up with an answer and a good reason for it based on what you have seen in this section.
Write your answer as a comment above the declaration of `sum()`. 

## 2. The Natural Numbers

The set of all integers greater than 0 (i.e., {1,2,3,4,5,...}) is commonly referred to the set of natural numbers. 
Write a recursive algorithm that takes a positive integer input `n` and prints out all of the natural numbers from 1 to n. 
The function signature for this problem should be as follows:

```C++
void print_nums(unsigned int n);
```

You may print all the numbers on one line separated by spaces, or each number on its own line, but these are not very elegant for large values of `n`. 
Start printing your output on a new line after every 10 numbers. Your expected output will then look similar to this:

```
1 2 3 4 5 6 7 8 9 10 
11 12 13 14 15 16 17 18 19 20 
21 22 23 24 25 26 27 28 29 30 
31 32 33 34 35 36 37 38 39 40 
41 42 43 44 45 
```
 
## 3. Number of Digits

When working with and processing large numbers, it is at times useful to be able to determine how many digits long the number is. With access to a graphing calculator, (or a math library), a quick way to compute this would be to take the floor of log<sub>10</sub>(n) and add 1. For example, log<sub>10</sub>(382) is roughly 2.582, the floor of which is 2, and adding 1 then yields 3 which is the length of n. 
This is a handy trick, but if there is no access to a log function then this problem may alternatively be solved recursively.

Write a recursive algorithm that takes an integer n and returns its length, using the following function signature:

```C++
unsigned int num_len(unsigned long int num);
```

## Drawing Fractals with Python

At this point in the lab you will do something a bit different than usual, as you may have been able to tell from the title of this section. 
Specifically, you will use the Python library called Matplotlib to draw fractals. 
Before becoming too alarmed, you don't need any previous knowledge of Matplotlib for this lab, and only minimal Python knowledge is required, which surely at least one person at your table has.

### Setting Up

We recommend working through this section outside of cs50 IDE so that visualizing your work is easier. 

#### Checking for Existing Installs

To check for existing python installations, open up your terminal and execeute `python --version`. 
If you see 3.x you are to use `python` to execute everything that follows. 
Otherwise, try to run `python3 --version`. 
If this command works, you are to use `python3` to execute everything that follows. 

If neither of these commands worked, you must install python. 

#### Installing Python

There are multiple ways to install python, the best way will depend on your system. 

##### Linux

To install python on Linux, run `[apt-get or equivalent] install python3`

##### Windows / Mac

Go to [python.org](https://www.python.org), mouse over "Downloads" and select your operating system, click "Latest Python 3 Release...", scroll to the bottom of the page and select the most appropriate download link. 
**When installing Python, make sure it's added to your system path.**

#### Installing matplotlib

Once you have Python installed, go to your terminal (on Windows it's PowerShell, on Mac it should be just "Terminal", which you can search for with Finder) and type `[python or python3] -m pip install matplotlib`. 
It should proceed to install Matplotlib along with any libraries necessary for it to run. 
You should now be ready to proceed.

### Drawing Fractals

#### Rectangles
First, lets look at one simple fractal solution we've provided `rec_fun`. 
This function begins by checking if `h` is zero, if this is true, it returns nothing, completing it's task.
Otherwise, it draws its shape, using [`plt.plot`](https://matplotlib.org/api/_as_gen/matplotlib.pyplot.plot.html).
Finally, it calls itself four seperate times with new coordinates for each call, along with a reduced `h`. 
As you are now well aware, it is this reduction in `h` which gradually moves the function towards it's own base case.
We can see that, in this function, we reduce the length at each call as well, meaning that this function begins by drawing the largest shape, then progressively smaller ones. 

<img src="rect_fun.png" width="750px">

#### Sierpinski Triangle
Now, implement `sierpinski_triangle` (your code will share some similarities to the `rec_fun` function).
Begin by looking at the figure below, examine the shape you are trying to draw. 

<img src="https://aperiodical.com/wp-content/uploads/2015/12/siermathgb3.png" width="750px">

> Hint: The tip of the bottom left triangle should be halfway along the left line of the outer triangle, same with the bottom right and the right line. 

#### Snowflake
Finally, implement `snowflake`.
For this function, you will need `x1 = cos(radians(60))*length/2` and `y1 = sin(radians(60))*length/2`, they represent the diagonal parts of the snowflake.  Ask the TAs for help if needed. 
Don't forget to also use `-x1, -y1` to handle the negative portion of the diagonals.

<img src="snowflake_1.png" height="400px">
<img src="snowflake_2.png" height="400px">
<img src="snowflake_3.png" height="400px">

## Submission

Submit all of your source code, including `fractals.py`, `sum.cpp` and any cpp files created to solve the other problems (e.g. Number of Digits).

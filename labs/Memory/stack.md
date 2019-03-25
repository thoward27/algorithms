# Lab 03: Stacking that knowledge

> In computer science, a call stack is a stack data structure that stores information about the active subroutines of a computer program.
This kind of stack is also known as an execution stack, program stack, control stack, run-time stack, or machine stack, and is often shortened to just "the stack".
Although maintenance of the call stack is important for the proper functioning of most software, the details are normally hidden and automatic in high-level programming languages.
- [Wikipedia](https://en.wikipedia.org/wiki/Call_stack)

# Introduction

Today, we are going to examine the stack quite closely.
We are going to peel back the woodwork and take a look into how exactly it functions in relation to a very simple program.
It's your job to understand exactly how the stack functions by the time you leave lab today.
Along with the stack, we are going to examine command line arguments, and dabble a bit in recursion (don't panic, it'll be okay).

**Important Note:** As before, you will perform this lab in groups based on your table, but it **will require** the use of CS50 IDE.

# Instructions

1. Read the entirety of the lab before beginning.
2. Answer the questions as you go, each question may require changes to code, these changes should be done in sequence.
3. Ask questions, that's what the TAs are for.

# What is the Call Stack?

The Call Stack, or more commonly just *The Stack*, can be thought of as a deck of notecards.
Whenever a function begins, it creates a new card to be put on top of the stack of existing cards (hence the name).
On each of these cards, the function allocates a small space for every variable it will need, along with any parameters it is given, and a space for whatever the function will return.

For a short visualization of how the stack works, please step through [PythonTutor](https://goo.gl/zekNw3).
The Python Tutor is a great resource if you're having trouble visualizing exactly what's happening in your code, and it's free!
Make good use of it.

# Exercises

Time to get that knowledge of the stack into shape!
The rest of the lab requires carefully stepping through code, making small changes, and implementing some small recursive functions.

## Part 1

Begin by compiling and running the starter code with no additional flags (no output, or debugging quite yet).

```
$ g++ lab-03.cpp
$ ./a.out
```

> If you wanted to perform the above two commands on one line, you could use the `&&` operator between the two commands, which signifies that if the portion on the left executes correctly, the portion on the right should be executed as well.

Now, compile and run the code with a single command line argument.

> Hint: This is equivalent to asking you to append any string to the end of the previous command.

#### Question 1: Examine what was printed out each time, is anything different? If so, what?
#### Question 2: Look at the function `bar`. Without using the CS50 IDE Debugger, can you suggest a better (more descriptive) name for this function? (Don't worry if you can't quite yet, we will be examining this function quite closely a few parts from now)

Quit the debugger, either by pressing "Play", or by entering CTRL-C in the terminal.

## Part 2

It is now time to start stepping through some code.
Recompile the starter code with debugging.
Once you've recompiled the code, set a breakpoint for the line `int n = foo(argc);`, and run the debugger with no command line arguments.
Using the "Step Into" button, step into `foo`.
Use "Step Over" until a return statement is highlighted.

#### Question 3: What return statement is highlighted?
#### Question 4: How many stack frames are in the "Call Stack" section of the debugger?
#### Question 5: What values for `n` would force additional stack frames to be used?

Restart the debugger.

This time, run the debugger with two command line arguments, stopping at the same original breakpoint.
Step into the function `foo`.

#### Question 6: What return statement **should** fire with your new value of `n`?

Before advancing the debugger, change the value of `n` in the `foo` stack frame to 0.

> You can tell what stack frame you are in by selecting any stack frame in the Call Stack, CS50 should highlight in green whatever stack frame is selected.
Make sure to have `foo` selected when you modify `n`.

Step **into** the return statement that should fire with your new value of `n`.

#### Question 7: How many stack frames are currently in the Call Stack?

Take a moment to walk back through the stack, select each frame, and examine the values of the variables.
When you're done, continue with the lab.

Step over the current line, at this point the final line of `foo` should be highlighted.
Step out of `foo`.
Modify the value of `n`, set it equal to 5.
Step into `multiply`.

#### Question 8: What are the values of `x, y` within the `multiply` function?

Continue hitting "Step Into" until `y == 0`.

#### Question 9: How many stack frames are there now in the call stack? (Include `main`).
#### Question 10: What is the value of `x`?

"Step Out" of the function until you arrive back at `main`.
Step over the current line.

#### Question 11: What are the current values of `n, x, y`, and why?

Quit your debugger.

## Part 3

Set a breakpoint for the line `print(argv)` and debug your code with a single command line argument.

Step all the way into the `bar` function.

In the Call Stack, select the `print` function, and expand `argv` completely.
Double click the most nested value, and type 120.
Once it updates, it should show `120 'x'`.
Now enter a new Watch Expression for `bar(argv[0][0])`.

#### Question 12: What is the new value of `bar`?

Select the `bar` stack frame.

#### Question 13: Has anything inside of the stack frame changed? Why do you think that is?

Step over the current line, the first return statement should be highlighted.
Continue stepping into bar, watching the variables, until you believe the next return statement will not create a new stack frame.

#### Question 14: How many stack frames are there on the call stack?
#### Question 15: Did our modification of the previous cards in the call stack actually make any difference in the final execution of the function?

Quit the debugger.

## Part 4

Set your breakpoint for the line `int x = 10`.
Debug the program with a single command line argument.

Step over until the call to `multiply`, change the value of `y` to 2, and press "Step Into".

#### Question 16: What function did you step into?
#### Question 17: Write out the fully expanded return statement from the first call to the last.

> Hint: Try to write out the full return statement as a chain of mathematical operations.

Step out and over until the line: `y = factorial(5)`, then step into the `factorial` function.

#### Question 18: Write out the fully expanded return statement from the first call to the last.
#### Question 19: How many stack frames are required to complete this function?
#### Question 20: How many stack frames are required to compute `bar(1000)`?

## Part 5

Now it's time for you to write some functions that take advantage of the stack to solve problems.
As you've just seen, you can expand a function's return statement across stack frames to simplify problems substantially, this tactic is called recursion.
We know the term "recursion" instills fear in the minds of many a young developer, but **do not fear**, it isn't really all that complicated.
The whole idea is simply to utilize the ordering of stack frames to simplify problems until they become easily solvable.
To see an example, just look at your answers for the `multiply` and `factorial` functions!
As you've already noted, when you fully expand the return statement up the stack, you can clearly see the desired answer.

To begin, first write a function to find the [Greatest Common Divisor](https://en.wikipedia.org/wiki/Greatest_common_divisor) between two integers.

Psuedo-code follows:

```
gcd(a, b) = a if b = 0
gcd(a, b) = gcd(a - b, b) if a > b
gcd(a, b) = gcd(a, b - a) if a <= b
```

#### Question 21: Paste the source code for your `gcd` function into your answers file.

Once you've written a recursive solution to the `gcd` function, you may proceed to try `print_reversed`.

`print_reversed` should take a single integer, such as 12345, and print it out to the terminal in reversed order, ie 54321.

To do this, you must rely on recursion, and your own ingenuity.

#### Question 22: Paste the source code for your `print_reversed` function into your answers file.


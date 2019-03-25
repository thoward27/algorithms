# Lab 02: The Great Algorithm Race

## Introduction

Different algorithm implementations often take different lengths of time to complete, even if they solve the same problem. This lab will explore the impact using different algorithms can have; it will be completed in teams (based on the table you're working at, with **no more than six students at one table**). Please do all of your scratch work on your table's whiteboard.

The goal of the lab is to get a hands-on look at algorithm complexity by benchmarking three different algorithms for different input sizes, and printing a table of the results to the console. If you have more than 20 minutes remaining by the time you get to the optional section, you should attempt it.

**As always, make sure you read through this entire lab file.** All of the information here will be useful and many of your questions are likely answered somewhere in this file.

## Instructions

There are two primary goals in this lab:
1. Design algorithms to solve three different (but related) problems
2. Benchmark implementations of these algorithms on different input sizes and report on the results

Note that the first goal is **not** to write code, but to come up with strict, step-by-step procedures (algorithms) by which you can solve the problems described in this lab. The purpose of this is to separate the process of solving a problem from the process of creating code that compiles, runs, and works correctly. Preemptively jumping into code can result in a "try it until it works" mindset, which can get in the way of solving the problem at hand. Plus, if you can come up with an algorithm that solves a certain problem, and you are confident in the correctness of your algorithm, turning it into code will be a much easier task.

That being said, you should first discuss the problem, how you will try to solve it with your teammates, and write out the algorithm your team decides on in plain english or pseudocode. Then, you should evaluate the performance of your algorithm on various different test cases to ensure your logic is correct. If it doesn't, adjust your algorithm so that it passes all of your test cases.

Also, be aware that "various" test cases does not necessarily mean "random" test cases. You should try to come up with test cases that will cause your algorithm to fail, since your algorithm should be able to work correctly for *all* possible tests within the scope of the problem. Since you obviously can't try all of them, you will need to determine what kinds of input there are, and which of those your algorithm does/doesn't work correctly on. These are sometimes called "edge cases", as they can act like a bound on the functionality of the algorithm.

**Only when you feel satisfied with the correctness of your algorithm** should you implement it in the starter code *and* ensure that it works correctly there, too.

Once you have implemented all three algorithms you can use the other functions in the starter code to time them against one another and report on the results. Make sure to use the same input variables for each of the three functions.

## The Starter Code

The starter code for this lab is available in the file `lab-02.cpp` in this lab's folder (top of the screen on github.com). This code contains three functions you will use: `gen_rand_list`, `gen_rand_int` and `delete_list`, and three you will implement: `num_in_array`, `sum2_in_array`, and `sum3_in_array`. 

> `num_in_array`: Determine whether or not a given number `num` is in a list of numbers `arr`

> `sum2_in_array`: Determine whether or not there are two numbers `x1` and `x2` in a list of numbers `arr` such that `x1 + x2` is equal to a given number `num`

> `sum3_in_array`: Determine whether or not there are three numbers `x1`, `x2`, and `x3` in a list of numbers `arr` such that `x1 + x2 + x3` is equal to a given number `num`

The three functions you will implement need not actually be called directly, as the starter code contains a way to call each function from a function array, but you may use each function explicitly instead if you wish. They each take an integer array, its length, and a number `num` as parameters, and return `1` if the condition is met, `0` if it is not met, and `-1` if it takes too long (taken care of by the commented-out code in each function). To generate randomized arrays for the algorithms to work with you can use `gen_rand_list`, which takes the length of the array as a parameter and returns a pointer to a randomized integer array. These arrays are allocated on the heap, so use either `delete_list` or the `delete` keyword to free the memory when you're done with them. 

## Compiling

Ensure that your terminal is in the same directory as the `.cpp` files and then compile your program using the command:   

```bash
g++ -g -std=c++11 name_of_file.cpp -o name_of_file
```

>Replace `name_of_file` with the name of the file you are trying to compile

Also notice the -std=c++11 flag. This is needed because this lab's code uses some features that are only available in C++11, such as the `<chrono>` library and the `auto` specifier.
 
The program should compile without errors.

This program takes no arguments, so you will run it with the command `./name_of_file`

> Make sure your program runs without errors before proceeding. You may want to write some testing code within main to ensure your algorithms are working properly.

## Benchmarking

Measuring the time an algorithm or a section of code takes to run is called benchmarking. It times the code just like you would do in real life. It looks at the time when the code starts, runs the code, then looks at the time it ends. This is how you do it in C++:

```C++
#include <iostream>
#include <chrono>

int main() {
    // Get the starting Time
    auto start = std::chrono::steady_clock::now();
    /*
        The part of your code you want to time
    */
    // Get the ending time
    auto end = std::chrono::steady_clock::now();
    
    // This finds the time your code took to run by subtracting the end
    // and start times. It assigns it to the variable  t  as a double
    // Now you can use std::cout to print  t  to the console.
    double t = std::chrono::duration<double> (end - start).count();
    return 0;
}
```

> Note that for this lab's starter code, each function you implement will stop running if it runs for longer than fifteen seconds (via the code in each function that needs to be uncommented), and will return `-1` instead of the actual answer. In the case where the algorithm is running for too long, `N/A` should be used as a placeholder in the output since the algorithm did not actually complete.

## Printing Running Times

For successful completion of this lab, you must print to the console a table of running times for each of the algorithms, given different input sizes, using the technique described in the previous section. The input sizes you should use for this lab are 10, 100, 1000, and 10000. These should be printed across the top of the table, and the algorithms should be printed along the left side (you may simply use "A1, A2 and A3" in place of "num_in_array, sum2_in_array, and sum3_in_array" respectively). To ensure that you print the columns out evenly, you may use `std::cout.precision(x)` to set the number of digits after the decimal to be printed, and `std::cout << std::fixed` to print the results in regular decimal format instead of scientific. The output to your program should look something like this:

```
    10         100        1000       10000      
A1  0.0000284  0.0037321  0.5383260  N/A
A2  0.0000117  0.0001362  0.0017957  0.1353368
A3  0.0000039  0.0000063  0.0000117  0.0001200
```

There are no restrictions regarding how you solve this problem, but since printing this table is not a simple task, you may want to employ the same technique you used to create and implement the three algorithms from before. That is, you will likely want to devise an algorithm to print out the data on the board, stepping through each line and justifying to yourself that you will get the output you want, and then implement it. Since the type of input you will receive (i.e. the time each algorithm takes to run) is very well specified, minimal input type testing should be required.

Some suggestions to help your algorithm/implementation:

+ Separate data collection from table printing
+ Use the `gen_rand_list` function for your input array
+ Use the `gen_rand_int` function for the `num` argument in each algorithm. You will need to decide an appropriate range (`min` and `max` parameters of `gen_rand_int`)
+ Use the function array containing the three algorithms to reduce repeated code (there is an example in the starter code)

## Getting More Accurate Data (Optional)

The data acquired in the previous section may give you a good idea as to how the algorithms perform relative to one another on different input sizes, but they're not very useful in describing how long you will expect an algorithm to take on a certain input size, since the input data is random. To see this, consider the case where the algorithm you expect to be the slowest is run on a random array of size 10000, but finds its result in the first 5 or 10 numbers. This will result in a fast runtime that doesn't accurately portray the algorithm's runtime in general, which is often undesirable when reporting on runtimes. Thus, you have a couple of options to solve this problem:

If you are only interested in how the algorithms performs on the inputs of each size that will take it the longest to run (the worst-case) then you will need to give the algorithms input arrays/`num` values which will cause the algorithm to run for as long as possible, and report those times instead. This will result in much more consistent times for each algorithm on each input size.

Alternatively, if you are interested in how the algorithms perform on data of a certain size in general (average-case)*, you may time each of your algorithm on 10 different random arrays of each input size, and report the average of each set of 10 runtimes. Statistically speaking, this is guaranteed to be a more accurate representation of the actual runtimes of the algorithms.

> Side Note 1 (Hardware): These runtimes will be more accurate for the system on which they were tested, but not all systems in general, as there are other variables to be taken into account such as system hardware and the environment in which the program is run.

> Side Note 2 (Generalization): To truly capture the average runtime for the algorithm, even on a given system, the types of input would have to cover all possible types of input. In this lab, however, every array has the property that its range of values is +/- the size of the array (provided `gen_rand_list` is used). Thus, we are examining the average time for some restrictions on the possible types of data. This of course can be useful to, but it is something to be aware of. 

Your task for this section will be to create two copies of your completed starter code, named `lab-02-wc.cpp` and `lab-02-avg.cpp` in which you will implement the worst-case and average-case improvement techniques specified above. You will need to think about what types of input will cause the worst-case scenario. Run each of your improved programs and report the new tables in `lab-02.txt`, making sure they are labeled by the technique used.

You should consider the differences between your two new tables and the table you created previously, but you do not need to include it in your submission.

## Submission

You will submit 2 text files named `lab-02.cpp` and `lab-02.txt` on Gradescope. Please ensure your files contain the following:

1. `lab-02.cpp` should contain your entire source code
2. `lab-02.txt` should contain the table (running times) generated by your program

If you attempted/completed the optional section, you should also include the `lab-02-wc.cpp` and `lab-02-avg.cpp` files, and your `lab-02.txt` file should also contain the two additional tables.

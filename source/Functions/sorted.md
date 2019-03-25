# Lab 04: Basic Sorting Algorithms with Different Input Types
```
What does a sorting algorithm say when it's broken?

Out of order!
```
## Introduction

To become more familiar with basic sorting algorithms and input types, this week you will be testing some algorithms you write yourselves. More specifically, you will be implementing the Insertion and Selection Sort algorithms you learned about in class, and benchmarking them against the standard C++ library's sorting algorithm. 

You will also get some exposure to two-dimensional arrays and pointers, but we don't expect you to fully understand them yet.

**Be sure to read this lab's instructions extra carefully**, as you may be unfamiliar with some of the concepts.

Other things to note about this lab:
1. Be sure to call each of your sorting algorithms on **the same list** for every input type. That is, the content of the arrays passed into each of your algorithms should be the same.
2. Each sorting algorithm will sort **in place**, so you must be sure to avoid passing in an already sorted array. In order to avoid sorting an already sorted array, use the `copy_array` function contained in the starter code.
3. Make sure *all* arrays allocated using the `new` operator are deleted after you are finished with them, using the `delete` operator. (This includes all the arrays returned by the `gen_list` functions and `copy_array()`)
4. (**Important**) You **may not** use the slides or any online resources to guide your implementation, instead you should come up with the algorithms with your group based on your understanding of how insertion and selection sort work.

## Inputs

The performance of an algorithm can depend greatly on the type of input it receives. In fact, most professional sorting algorithms are *hybrid* algorithms, which use different routines depending on the size of the input. As you've seen, even algorithms that grow in complexity faster than others can be more effective on small input sizes. Along with input size, as a programmer, you should also consider what state the input will be in on arrival; i.e. is there a chance it is already sorted? Partially sorted?

Generally, these different scenarios will be referred to as **best case**, **average case**, and **worst case**. To explore this topic further, today you will examine what happens given a variety of inputs:

+ Random Unsorted Lists
+ Already Sorted Lists
+ Reverse Sorted Lists
+ Partially Sorted Lists

Each of the above list types is exactly what you would expect (reverse sorted lists are lists in reverse order, for example) except for partially sorted. A partially sorted list has a definition which is a bit more complicated, but for the purpose of this lab a partially sorted list is one which requires **at most** `n` swaps to sort, where `n` is the length of the list. In other words, the number of *inversions* in the array is at most `n`.

> Don't worry about trying to create input arrays falling into these categories yourself; there are functions that randomly generate arrays with each of the above properties provided for you in `lab-04.cpp`.

## Starter Code

If you take a look into the starter code for the lab, you will find over 200 lines have already been written! To make this a bit less intimidating, here is a rough breakdown of the code:

#### Sorting Functions

The functions used for sorting in this lab are as follows:

```C++
void swap(int *a, int *b) {...}

void in_sort(int *arr, int len) {...}

void sel_sort(int *arr, int len) {...}

void cpp_sort(int *arr, int len) {...}
```

`swap()` swaps two elements of an array in-place. This is accomplished by passing in *pointers* to the elements that will have their values swapped. Passing data into a function this way is called *passing by reference*. You may do this in your sorting functions in one of two ways:

```C++
// Given an array named arr and indices i and j...
swap(&(arr[i]), &(arr[j]))
// or
swap(arr + i, arr + j)  
```

The reasons the above lines work will be made clear in a later lab, when pointers are discussed in more detail.

`in_sort()` and `sel_sort()` are where the insertion and selection sort algorithms will need to be implemented, respectively. Again, we see a pointer in the form of `*arr`. This is another form in which you may see an array, and so you may use `arr` in your functions as if it was an array. You may also pass any integer array into `in_sort()` or `sel_sort()`, whether it's one you make yourself or one returned by one of the provided generator functions.

`cpp_sort()` uses the sorting algorithm provided by C++, and is thus already implemented. You won't need to use it yourself, as all the code that needs it has **already been implemented**.

#### Input Generation Functions

The functions for creating arrays of different types are as follows:

```C++
int *gen_list_unsorted(int size) {...}

int *gen_list_sorted(int size) {...}

int *gen_list_reversed(int size) {...}

int *gen_list_partial_sorted(int size) {...}
```

Each of the above functions will create an array with the quality specified in its name (e.g. `gen_list_reversed()` creates and returns a reverse sorted array). It is returned in the same form as `arr` in the sorting functions, and so may be easily passed into such a function. Here, `size` is the length of the array to be generated, but it also specifies the bounds for the random values in the array, from `-size` to `size`.

These functions are already used in `main()` to fill the array `lists` with the input arrays, so you don't need to worry about using these functions yourself. However, you may find it useful to use one or more of these functions when testing your sort implementations.

#### Other Functions

There are now just three remaining functions, two of which are already implemented:

```C++
int *copy_array(int *arr, int len) {...}

void test_sorts() {...}

void print_table(char names[][30], double times[][4]) {...}
```

`copy_array()` **will be crucial** in your implementation, as you will always want to sort copies of your randomly generated arrays, instead of trying to sort a single array three times (the sorts are in-place, so the input array will be modified by the functions). It takes the same parameters as the sorting functions you will implement, and returns an array in the same way as the list generating functions.

`test_sorts()` is an empty function that's called at the beginning of `main()`, and serves as a good place to test your implementations as you work on them. You don't need to use it, but it may be convenient as it helps to keep `main()` a little less messy.

`print_table()` is the largest function in the starter code and the one you least need to worry about. It primarily consists of (probably overcomplicated) formatting magic that makes a nice table for your benchmarked data. It's already called in `main()`, so all you need to do is put the runtimes in the `times` array.

#### The Main Function

There are a few different things happening in `main()`, so here are the most important details:

`lists` is an array of four arrays, one for each input type. Thus if you want one of the input arrays out of lists, you can get it by using `lists[i]` where i is 0 for the unsorted list, 1 for the sorted list, 2 for the reversed list and 3 for the partially sorted list.

`times` is a 2D array used for storing the runtimes of each algorithm on each input type. The first index tells you which algorithm you're using and the second index tells you which input type you are using. For example, `times[1][2]` should contain the time it takes `sel_sort()` to run on a reversed array. You may use it in the exact same way as it is used in collecting the runtimes for `cpp_sort()`, which is already done. 

`input_size` is the number of elements in each array. You may adjust this value to see a table of runtimes on different array sizes.

## Instructions

  1. Discuss a plan for implementing insertion sort with your group. Once again, this must be driven by your own knowledge of the two sorting algorithms, **not** (pseudo)code found online or in the lecture slides.
  2. Implement insertion sort based on your plan.
  3. Test to make sure the code compiles and insertion sort works correctly. If it does not, revise your insertion sort implementation plan and then implement your changes.
  4. Discuss a plan for implementing selection sort.
  5. Implement selection sort based on your plan.
  6. Perform the same testing process on selection sort as insertion sort.
  7. Write the code that benchmarks the three algorithms on the different types of data.
  8. Answer the questions in the next section.
  
## Questions

> **Question 1:** On which type(s) of input did insertion sort perform best? On which type(s) did it perform worst?

> **Question 2:** What was the overall difference between insertion sort's best-case input and its worst-case input? (no need for numbers on this question, just describe the difference the two input types made).

> **Question 3:** On which type(s) of input did selection sort perform best? On which type(s) did it perform worst?

> **Question 4:** What was the overall difference between selection sort's best-case input and its worst-case input?

> **Question 5:** Would insertion or selection sort ever be good sorting algorithms to use in a more general program? Explain your answer.

> **Question 6:** Generate multiple tables by changing the value of `input_size` (e.g. 50, 500, 5000, 10000).  What are your overall conclusions regarding the performance of these three algorithms, considering different input sizes and different input types?

## Submission

Each group will submit 2 files named `lab-04.cpp` and `lab-04.txt` on Gradescope. Please ensure your files contain the following:

1. `lab-04.cpp` should contain your entire source code
2. `lab-04.txt` should contain your answers to the questions above and the formatted benchmarking data. 

If you are unable to complete the entire lab, submit your `lab-04.cpp`, and submit the answers of questions pertaining to the sections you completed along with a summary of the difficulties you encountered during this lab in your `lab-04.txt`.

> Make sure you add all group members to your submission on Gradescope

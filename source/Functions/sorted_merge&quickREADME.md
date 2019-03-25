# Lab 6: MergeSort & Quicksort

This week you will be working with two of the most commonly used sorting algorithms, Mergesort and Quicksort. While both algorithms are impressive, they each also have their own limitations, strengths and weaknesses. Today you will implement your own mergesort algorithm and explore its limitations.

**Only mergesort is required for this lab.**

Since quicksort has not yet been covered in lecture, you will not be required to submit an implementation of quicksort for this lab. However, it is highly recommended that you go back and implement it after it is covered in lecture.

**Additionally, please not the following important rules:**
+ As with previous labs, you will be working in teams of 2 to 5 students.
+ **You must devise your algorithms solely from the contents of this lab.** That is to say, **do not copy any code!** Whether it be from the lecture slides or from an outside source, no merge or mergesort code copying is allowed.

## Mergesort

Mergesort is a divide and conquer algorithm that was invented by John von Neumann in 1945 [[*ref*](https://en.wikipedia.org/wiki/Merge_sort)]. It divides input array in two halves, calls itself for the two halves and then merges the two sorted halves. Here is a [visualization of MergeSort](https://www.cs.usfca.edu/~galles/visualization/ComparisonSort.html) to help understand the algorithm. As you can see, the idea behind mergesort is to break down a large array into smaller sub-arrays which can each be more quickly and easily sorted. Once these small arrays are sorted, they are merged into one another and sorted again as this is done, hence the name _mergesort_. The algortihm is a classic use of recursion; breaking down large, complex problems into very small, simple problems.

Here is the visualization from wikipedia which does a good job of showing the basic Merge Sort process:

![image](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

Here is another visual which shows the _divide_ aspect of teh algorithm on the left hand side, and the _conquer_ aspect of the algortihm on the righthand side 

![Example Pic](/lab-06/mergesort.png "Mergesort")

To begin, download the starter code, which includes the test cases, and the lab6.cpp file.

## 1. Implementing Merge

Merge algorithms are a family of algorithms that take multiple sorted lists as input and produce a single list as output, containing all the elements of the inputs lists in sorted order. [[*ref*](https://en.wikipedia.org/wiki/Merge_algorithm)]. Today you will be merging two lists together in linear time, and in linear space or less. Your goal will be to transform the whole array `A` to be sorted in non-decreasing order.

The function header you will be using is:

```c++
void merge(int* A, int n, int mid);
```

Where:

* `A` is an array of integers, of length `n`, where `A` from `0` to `mid-1` is sorted in non-decreasing order, and `A` from `mid` to `n-1` is also sorted in non-decreasing order. The whole array is not necessarily sorted in non-decreasing order. **In other words, `A` represents two sorted lists which are concatenated at `mid`**

* `n` is the length of array `A`
* `mid`, while not necessarily the midpoint, is the index of the element in `A` where the second sorted section begins

Here is an example of an array `A`:

![Example Pic](/lab-06/array.png?raw=true "Example Array")

Loose pseudocode for the algorithm is as follows:

1. Allocate Memory Dynamically to array B, size of n
2. Copy A to B
3. Merge Back into A
4. Deallocate Memory (B)


## 2. Testing out Merge

Once you feel that you're ready to test your `merge` function, recompile your code using the statement below.

```bash
$ g++ -std=c++11 -g lab6.cpp -o lab6
```

You may then use the `lab6` file to test your `merge` function by running the line below, with `INPUT_SIZE` replaced with a positive integer. If your function works correctly, the program will print out a success message for each of three trials, along with an overall success message. Otherwise, it will print at least one trial failure message, along with an overall failure message.

```bash
$ ./lab6 merge INPUT_SIZE
```

> Note: if at any point in the lab you would like to write your own tests, you may use the word "custom" in place of "merge." This will run the unimplemented-by-default function `custom_test()`, passing in the specified INPUT_SIZE as an argument.


## 3. Implementing Mergesort

Now that you have merge implemented, it should be fairly easy to implement the full MergeSort. **You must have a correct implementation of `merge()` in order to complete Mergesort**

The function header is as follows:

```c++
void MergeSort(int* A, int n);
```

Where:

* `A` is an array of potentially unsorted integers
* `n` is the length of array `A`

The goal is to sort A in non-decreasing order. This algorithm is recursive, so your function should also be recursive.

## 4. Testing Mergesort

Once you feel that you're ready to test your `mergesort` function, recompile your code again using the statement below.

```bash
$ g++ -std=c++11 -g lab6.cpp -o lab6
```

Just as with the `merge` function, you may use the `lab6` file to test your `mergesort` function by running the line below, with `INPUT_SIZE` replaced with a positive integer. Again, if your function works correctly, the program will print out a success message for each of three trials, along with an overall success message. Otherwise, it will print at least one trial failure message, along with an overall failure message.

```bash
$ ./lab6 mergesort INPUT_SIZE
```

#### Questions

> Question 1: What is the asymptotic complexity (Big O) of mergesort?

> Question 2: Which type of input might merge sort perform poorly on?

**Everything after this point is optional and does not need to be submitted for the lab.** You may skip to the submission section if you have completed everything above. Once again, it is highly recommended that you work through the rest of this lab on your own time after quicksort has been covered in lecture. 

## Quicksort

Quicksort is a systematic element placement sorting algorithm developed by British scientist Tony Hoare in 1959 [[*ref*](https://en.wikipedia.org/wiki/Quicksort)] It sorts arrays by choosing one element and swaps the array such that all elements greater than the chosen element go to one side of it and all elements less than or equal to it go to its other side. This means that this element (called the pivot) is sorted, and quicksort now calls itself on the sub arrays to the left and right of the pivot.  There are different ways to implement this algorithm, based around how you choose your pivot. For the purposes of this lab it is recommended that you use the Lomuto partition method and always make your pivot the last element, as it is a bit easier to understand and implement. However, if you wish to pick the first element as your pivot, here is a visualization of what that algorithm could look like [[*ref*](https://visualgo.net/en/sorting)]

Here is a picture showing the steps of Lomuto quicksort:

![Example Pic](/lab-06/lomuto.png?raw=true "Lomuto Partition")

## 5. Implementing Quicksort

Similarly to merge sort, you will need to implement two functions to fully implement quicksort, one that partitions an array into two sub-arrays separated by a pivot, and a recursive function that utilizes the partitioning function to sort the entire array. The signatures for these two functions are as follows:

```c++
int partition(int* A, int lo, int hi);
```

```c++
void quicksort(int* A, int lo, int hi);
```

Where:

* `A` is an array of potentially unsorted integers
* `lo` is the index of the first element in the given array/sub-array
* `hi` is the index of the last element in the given array/sub-array
* `partition()` returns the index of the pivot element after partitioning

Pseudocode for the partition function (using the Lomuto partition) is as follows:

1. Choose the last element as the pivot.
2. Swap each element that is less than the pivot with the first element in the array that is greater than the pivot.
3. Swap the pivot with the first element that is greater than the pivot. The new location is the pivot index to be returned.

You may refer to the image in the previous section for a visualization of the pivot.

## 6. Testing Quicksort

Once you feel that you're ready to test your `quicksort` function, recompile your code once more using the statement below.

```bash
g++ -std=c++11 -g lab6.cpp -o lab6
```

Unsurprisingly, you can test your `quicksort` implementation in the exact same manner as `merge` and `mergesort` using the line below. This will behave in the exact same way as if `mergesort` had been given as an argument, but will test your `quicksort` algorithm instead.

```bash
./lab6 quicksort INPUT_SIZE
```

#### Questions

> Question 3: What is the asymptotic complexity of quicksort?

> Question 4: Which type of input might quicksort perform poorly on?

> Question 5: Which algorithm is better for general use? Explain your reasoning.

## 8. Submission

Your submission for this lab will include the `lab6.cpp` file containing your implementations of `merge()` and `mergesort()` along with a `lab6.txt` file containing your answers to the questions above.

* If your group was not able to successfully implement merge and mergesort, you should submit the `lab6.cpp` file containing everything you were able to implement. Ideally, the source code file you submit should be able to compile. 
* If your group did not answer both questions 1 and 2, submit the questions that you did answer.
* If your group ran out of time before reaching the questions section, upload a blank `lab6.txt` file.

**Make sure to add the people you worked with as collaborators in your Gradescope submission.** 

# Sorting

## Table of Contents

1. [Introduction to Sorting](#introduction-to-sorting)
2. [Bubble Sort](#bubble-sort)
3. [Insertion Sort](#insertion-sort)
4. [Selection Sort](#selection-sort)
5. [Merge Sort](#merge-sort)
6. [Quicksort](#quicksort)
7. [Resources](#resources)

## Introduction to Sorting

### What is Sorting

Chances are you are already familiar with the concept of sorting used in a non-technical sense. When you want to arrange some items by some quality of the items such that they are ordered, sorting is the process you carry out to accomplish your goal. Here are a couple of examples:

You may sort books (the items) by author (the quality) in alphabetical order.

You may sort people (the items) by height (the quality) in increasing order.

![Sorting Coins](http://i.imgur.com/t9hQLMA.gif)

> Here coins are sorted by denomination. In this case the quality is categorical, so we have many items with the same values sorted into four different categories.

Humans tend not to have much difficulty with sorting for small numbers of items, but when the number of items is large, the items are more abstract, the *quality* is more abstract, or sorting needs to be performed very frequently, we turn to computers for help.

### Sorting as a Concept in Algorithms

People process information very differently than computers, and in many cases we are able to sort things with relative ease, but if asked to describe *how* we went about sorting some cards or books, many of us may not be able to give precise instructions to follow if we want someone else to sort exactly as we did. Since following precise instructions is what computers do best, we have to think about sorting from an algorithmic standpoint.

It turns out there are many ways to sort an array of elements (i.e. items) algorithmically, which we call *sorting algorithms*. Each sorting algorithm performs differently but ultimately accomplishes the same task, putting an array into some order based on one or more qualities of its data. The sorting algorithms we cover in this course are known as *comparison based* sorting algorithms, meaning that items are rearranged by comparing the values (i.e. the quality) of the elements and deciding whether to swap the elements based on these comparisons. Sorting algorithms that are not comparison based also exist and have their own interesting properties, but they are beyond the scope of this course.

### Sorting Algorithm Applications

The primary sorting algorithms are useful to programmers is because data is often much easier to work with when it's ordered. Think about binary search, which can only be applied if the elements of an array are in order, which is equivalent to saying the array is sorted. Considering just how often searches need to be performed (search engines, databases, etc.), having data be sorted is immensely important. Nobody wants Google to have to look at every page on the internet just to perform a single search.

Furthermore, sometimes data needs to be sorted by multiple qualities. A perfect real-world example is sorting a deck of cards, as one will often first sort by suit, and within each suit sort by card value. On the other hand, in data analysis/visualization, one might want a table of data which can be sorted by one or more rows, in which case a re-sort of the data could be requested at any time.

## Bubble Sort

### Description

Bubble sort is a naïve sorting algorithm which gets its name from the visualized algorithm looking like larger elements are "bubbling" towards the end of the array (assuming increasing order). As far as sorting algorithms go, it is too slow to be considered usable in most applications, however it is one of the simpler sorting algorithms and thus a good place to start with them. Performing bubble sort basically consists of repeatedly scanning through the elements of an array, swapping adjacent elements that are out of order along the way, until the array is sorted.

![Bubble Sort in Action](https://upload.wikimedia.org/wikipedia/commons/5/54/Sorting_bubblesort_anim.gif)

> Bubble Sort in Action

### Pseudocode

Pseudocode for the Bubble Sort algorithm is as follows:

```
while array is not sorted:
    for each element in the array (except the last):
        if the current element is greater than the next element:
            swap the current and next element
```

### Optimizations

Bubble Sort can actually be modified from the algorithm given by the pseudocode to perform slightly better. If we observe that at the end of each iteration the largest unsorted element is put into its sorted position (take a moment to justify this to yourself) we can stop our inner loop one position earlier each iteration, effectively cutting the total number of iterations in half. If our array has *n* elements then on the first iteration we scan through all *n* elements, on the second iteration we scan through the first *n - 1* elements, and then the first *n - 2* elements on the third iteration, and so on.

As it turns out, we can actually do even better than the previous optimization. Often times on a single iteration, multiple elements will be put into their correct positions at the end of the array. In fact, at any single iteration every element after the last swap is sorted, so the next iteration need only be performed on the elements up to the position of that last swap. You just need to keep track of where the last swap happens at each iteration.

Despite these operations, bubble sort is still a poor choice of a sorting algorithm in most applications (an exception may be when an array is partially sorted and similarly valued elements are near one another).

## Insertion Sort

### Description

Insertion sort is the first of two generally mediocre sorting algorithms that are still considered better than bubble sort. The principle behind insertion sort is that it takes each element of the array, from left to right, and swaps it with previous elements in the array until it is sorted with respect to its adjacent elements. Since each element is sorted with respect to its adjacent elements at each iteration, not only is the entire array sorted by the end, but at the end of any given iteration *i* the array is sorted from positions 0 to *i*.

![Insertion Sort in Action](https://upload.wikimedia.org/wikipedia/commons/4/42/Insertion_sort.gif)

> Insertion Sort in Action (apologies for the dissatisfying ending)

### Pseudocode

Pseudocode for the Insertion Sort algorithm is as follows (with *n* the number of elements in the array):

```
for each i from 0 to n:
    for each j from i to 0:
        if the element at j-1 is greater than the element at j:
            swap the elements at j-1 and at j
        otherwise break
```

Note that *j* is decrementing at each iteration of the inner loop, and that *break* means to stop the innermost loop prematurely.

## Selection Sort

### Description

Selection sort is the other generally mediocre sorting algorithm that's still considered better than bubble sort. Selection sort takes a more direct approach to sorting an array, repeatedly searching for the lowest-valued unsorted element and swapping it to each position of the array in order. This algorithm is similar to insertion sort in that at the end of any given iteration *i* the array is sorted from positions 0 to *i* (which is perhaps more obvious for this algorithm).

![Selection Sort in Action](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)

> Selection Sort in Action

### Pseudocode

```
for each i from 0 to n:
    set the current minimum index to i
    for each j from i + 1 to n:
        if the element at j is less than the element at the current minimum index:
            set the current minimum index to j
    swap the elements at i and the current minimum index
```

Note that the *current minimum index* is not referring to a small index, but to the index of the smallest value seen so far. Additionally, by the time the inner for loop ends, the current minimum index is the index of the actual minimum (unsorted) value.

## Merge Sort

### Description

Now that we have discussed some sub-par sorting algorithms, we may begin to look at algorithms that are actually used in practice, such as *merge sort*. In general, merge sort outperforms insertion sort, selection sort, and bubble sort by a landslide, but the implementation is slightly more complex. The merge sort algorithm actually relies on a separate algorithm to work properly, the *merge* algorithm.

The merge algorithm simply takes two sorted arrays (or in application, two sorted *subarrays*) and sorts them together into a single sorted array. Since the subarrays are already sorted, they can be sorted together into a single array easily, although this does require the use of an *auxiliary array* of the same size as the full array (or the sum of the sizes of the two subarrays). This algorithm performs the bulk of the computations in merge sort.

Once you have the merge algorithm, the merge sort algorithm itself is actually quite simple, and relies on a technique called *divide and conquer*. The principle of divide and conquer is that a problem can be solved by dividing it into several smaller sub-problems, and continuing to divide sub-problems into even smaller sub-problems until the problems are trivially solvable. Often times divide and conquer algorithms also involve a *combine step*, where solutions to smaller sub-problems must be unified into a solution to the larger problem at hand. For merge sort in particular, the array is divided into two halves, merge sort is called on each half, and then merge is called on the array (which can be done since the calls to the merge sort function sort the two halves into two sorted subarrays). The base case for this recursive algorithm is the trivially solvable case where there is only one element, as a single element array is sorted by definition. 

![Merge Sort in Action](https://codepumpkin.com/wp-content/uploads/2017/10/MergeSort_Avg_case.gif)

> Merge Sort in Action. The division of the array into smaller and smaller subarrays is handled by the merge sort function itself, and the merging of the elements in the subarrays back up to the full array is handled by the merge function.

### Pseudocode

**Merge**

```
make a copy of the array
set j to 0 and k to the middle index
for each i from 0 to n:
    if j has reached or passed the middle index:
        set the array at i to the copy at k and increment k
    otherwise, if k has reached or passed the end of the array:
        set the array at i to the copy at j and increment j
    otherwise, if the array at j is less than the array at k
        set the array at i to the copy at j and increment j
    otherwise
        set the array at i to the copy at k and increment k 
```

Note that the elements can be copied at the beginning and sorted from the copied array to the input array, or the elements can be sorted from the input array to the new array and copied back to the input array at the end, the result is the same.

**Merge Sort**

```
if the number of elements is greater than 1:
    call mergesort on the first half of the array
    call mergesort on the second half of the array
    merge the array
```

Believe it or not, this is all the merge sort function itself has to do.

### Optimizations

Just as with bubble sort, there ways in which merge sort can be improved to be even faster and more efficient. Remember how we said that *in general* merge sort outperforms insertion sort, selection sort and bubble sort? Well it turns out that for small arrays (with a max size between 7 and 10, up to programmer's discretion) actually tends to be faster than merge sort. Thus, with a good implementation of insertion sort, one can choose to call insertion sort on subarrays smaller than a certain value in their implementation of merge sort, instead of dividing down to the trivial case of one element.

Another small modification that can be made to merge sort to improve its performance is to check if the array is already sorted before merging. While this would be an expensive operation for general arrays, since we know the array is made of two sorted subarrays, determining whether the whole array is sorted is as simple as comparing the last element of the first subarray with the first element of the second subarray. If those two elements are sorted with respect each other, the whole array is sorted, and the call to merge can be skipped. Note that because this is a recursive algorithm, this case could occur in many different calls to merge sort, not just the initial call.

## Quicksort

### Description

Quicksort is a sorting algorithm that performs similarly to merge sort, and is also the final sorting algorithm we will discuss this semester. Like merge sort, quicksort is a (generally) recursive divide-and conquer algorithm which, unlike merge sort, does *not* include a combine step. Instead, quicksort uses a different helper function called a *partitioning algorithm*, which seeks to take a single element in an unsorted array (called a *pivot*) and move around the elements such that all elements less than the pivot come before it and all elements greater than the pivot come after it.

Using a partitioning algorithm on an array gives two major benefits:

1. The element that is chosen as the pivot is guaranteed to be in the right position once partitioning is complete.
2. The subarrays to the left and right of the pivot can be sorted recursively.

Based on the second benefit above, we can implement a sorting algorithm very similar to merge sort using a partitioning algorithm, which is exactly what Quicksort is. Quicksort partitions an array and calls itself on the subarrays to the left and right of the pivot, with the same base case as merge sort. Now, at this point you may not be entirely convinced that this algorithm does successfully sort an array, but consider the following:

Each time partition is called it puts one element in the correct position, guaranteed, and due to recursion, a large amount of the elements get a chance to be the pivot. As for the elements that are never the pivot, those are the elements that reach the base case and are trivially sorted, and thanks to all the work done by partition, each such element must be greater than the element to its left, and less than the element to its right, and so must be sorted with respect to them.

Although it is conceptually more complex, quicksort has proven to be one of the fastest and most efficient sorting algorithms, and is often the sorting algorithm of choice in libraries that provide one.

![Quicksort in Action](https://upload.wikimedia.org/wikipedia/commons/6/6a/Sorting_quicksort_anim.gif)

> Quicksort in Action. This version of quicksort uses the Hoare partition scheme and chooses the last element of the (sub)array as the pivot.

### Pseudocode

**Partition**

```
set i to lo + 1 and j to hi
while true:
    increment i until array at i is greater than array at lo
    decrement j until array at j is less than array at lo
    break if j <= i
    swap the elements at i and at j
swap the elements at lo and at j
return j
```

Note that you should always be careful when using "while true," as you need to have one or more break statements such that one will always occur at some point, otherwise you will get an infinite loop. Also, this particular partitioning algorithm is known as the *Hoare partition scheme*, but more on that later.

**Quicksort**

```
if lo is less than hi:
    partition the array and set p to the partition index
    call quicksort on the array with lo as lo and p - 1 as hi
    call quicksort on the array with p + 1 as lo and hi as hi
```

### Optimizations

Thus far the sorting algorithm optimizations that have come up have been relatively light, adding bells and whistles (figuratively, of course) to make each one a bit better. However, quicksort changes the whole game thanks to one tiny detail: there are a *lot* of different partitioning algorithms.

Before taking a look into a couple of them, it's also important to know that there are also different ways to choose the pivot element, and the one we've chosen for our pseudocode is actually the worst. Choosing the first or last element as the pivot is typically a poor choice, since in the case of a sorted or reverse sorted array there is only one subarray on which to recur after each call to partition; the divide and conquer technique greatly benefits from sub-problems that are roughly the same size (which 0 and n - 1 generally are not).

There are two choices for a pivot that have been shown to work better than the first or last element: the middle element of the array or the median (middle in value) of the first, middle and last elements. We won't analyze specifically how these are better, other than solving the problem mentioned in the last paragraph, but good implementations of quicksort will typically use either the middle element or the median-of-three as the pivot element.

Finally, we have the different partitioning algorithms. The explanations and benefits of other partitioning algorithms are beyond the scope of this course, but they make use of a few particular improvements. Here are a few:

+ Lomuto partitioning (or the Lomuto partition scheme) actually performs worse than Hoare's partitioning, which is what we used in our pseudocode, however it is simpler to implement. Instead of scanning two indices from either side of the array, you scan one index from left to right and keep an index that tracks where the next element greater than the pivot is. When the scanning index reaches an element that is less than the pivot, that element swaps with the one at the kept index, which moves forward to the next element that is greater than the pivot.
+ Dijkstra's 3-way partitioning and Bentley-McIlroy's 3-way partitioning each return two different partition indices, and thus partitions the array into three subarrays, one with elements less than the pivot, one with elements *equal to* the pivot and one with elements greater than the pivot.
+ Dual-pivot partitioning goes one step further and actually uses two different pivots to partition an array.

## Resources

[Satisfying animation of multiple sorting algorithms](https://www.youtube.com/watch?v=kPRA0W1kECg)

[Really cool interactive website for visualizing sorting algorithms](http://sorting.at/)

[More information on partitioning algorithms](https://algs4.cs.princeton.edu/lectures/23DemoPartitioning.pdf)
# Singly Linked Lists

## Motivation

Arrays are pretty awesome, right? They let you perform operations on sequences of data, and are essential to working with C-style strings...but have you even tried to insert elements into an array, or remove elements from one? Unless you're particularly clever, you have to create an entirely new array and copy all of the elements from the old array into the new array, including any newly inserted elements and excluding any elements to be removed, every single time! Now that's *not* awesome.

Introducing, Data Structures! The hip, new\* pieces of computer science technology that allow collections of data to be stored in various different way, allowing for more efficient operations on sequential data (including insertion and deletion)! The first data structure we would like to introduce is known as the *singly linked list*.

> \*Not actually all that new.

## Description

![A Singly Linked List](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2013/03/Linkedlist.png)

> A Singly Linked List with four elements/nodes.

The singly linked list is the first and most basic of a variety of linked list flavors (think vanilla ice cream: a classic flavor that's not particularly fancy). Like arrays, linked lists allow you to store a collection of data, such as *int*s or *char*s, but the interesting distinguishing feature of linked lists is how they store their data. A linked list uses a "chain" of *nodes* to hold data, where each node contains a single element and the location(s) of some other node(s). In C++, every linked list class will be accompanied by a node class, which contains an element of some data type and one or two pointers to another node (depending on the type of linked list).

The singly linked list has the most basic structure of all linked lists, which is shown in the image at the beginning of this section. The nodes of a single linked list each contain one pointer, which should always point to the next node in the list. The pointer in the last node of a singly linked list should always be the null pointer. Other than its *data* and *next* values, all a node needs is a constructor and a destructor, the latter of which is typically empty. In C++, a node also needs a *friend* statement to give the linked list class permission to access its private data members, such as

```c++
friend class SLL;
```

The singly linked list class is where all the real work happens. For private data members, a pointer to the first node in the list, known as the *head* of the list, is all that is necessary. For extra convenience a singly linked list class can make use of two optional private data members: a pointer to the last element in the list, known as the *tail*, and the length of the list.

The real important part of the singly linked list class is the methods that it implements. A singly linked list class can insert an element at front (the start of the list) in constant time, and at the back (the end of the list) in either constant time if using a tail pointer or in linear time otherwise. Inserting an element anywhere into a singly linked list, however, always takes linear time in the average case. As for removal, elements can be removed from the front of the list in constant time, but removing elements anywhere else in the list is also linear time on average, and removing the last element of a singly linked list is always the worst-case scenario.

A variety of different methods with different time complexities can be implemented for singly linked lists, but it is of the utmost importance that no matter what methods are implemented, the singly linked list always keep its defining properties:

+ The *head* pointer points to the first element/node.
+ The last node points to NULL.
+ Every element of the list is accessible and no nodes are lost.

Due to the versatility of linked lists, they can actually be used to implement data structures tailored to more specific purposes, which will be discussed in the future.
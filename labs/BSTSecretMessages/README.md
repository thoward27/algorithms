# Lab 09: Secret Messages with Binary Search Trees

In this lab you will implement methods for a class called BSTree. BSTree is a simplified version of a binary search tree with a twist: given proper input, an instance of the class will be able to print out a secret message. The goal of this lab is to give you a deeper understanding of the tree structures you've seen in class, particularly binary search trees and their methods. You should also gain a better understanding of classes in C++ as well as function overloading, which can be very useful when working with classes.
#### Starter Code

For this lab you will be given the _BST.cpp_, _BST.hpp_, and _main.cpp_ starter files, along with the text files containing the data to be read into the trees.

#### Filling the Tree

Data which can be used to fill the tree can be found in any of the messageX.txt files in the lab folder.
The format of the messageX.txt files is as follows:

```txt
v1 ch1
v2 ch2
v3 ch3
...
```
where vX is a value used to insert the data into the tree and chX is the associated character, which will also be contained in the node.

In order to insert these values into the tree you will have to parse the file, inserting the data from each line into a new node using the function

```c++
  void BSTree::insert(unsigned int idx, char ch)
```

Here is a visual of what a BST would look like for the first couple of insertions:
![BST.insert](/lab-09/BSTinsert.png "insertion visual")

The input you will be working with will be much larger than just six nodes, but this should give you an idea of how the tree should be constructed. Notice that for any given node every node in its right subtree has a larger value than its own, and every node in its left subtree has a smaller value.

#### Searching for Secrets

Once you feel confident that your insert function is working properly it is time to start the search function.
The search function uses the following signature:

```c++
  bool BSTree::search(unsigned int k)
```
It searches the tree for the key k. At _each node it visits_, it should print the associated character to the console. Once it finds k, it should stop searching and printing values. Make sure that your function prints out the character stored in the node at every recursive iteration.

#### Overloading Functions and Private Helpers

When working on your implementation, you may find it advantageous to create helper functions that are able to solve certain problems recursively, such as inserting a node. You are then provided with the option to give the helper function the same name as the function it is helping. When you have multiple definitions of the same function name in C++, this is called _function overloading_. This allows you to define two functions with the same name which can perform differently given different arguments. This has many applications and can be particularly useful when you are working with multiple classes which have similar methods inherent to themselves. Such as how the string class in C++ as well as your LinkedList class both had an _append_ method. In fact, many of you have actually already worked with overloading functions, perhaps without even realizing it, when you wrote class constructors in assignment 4,

```c++
Node(double X, double Y, double Z, char Chain);
Node();
```
While both _Node_ constructors create Node objects, they perform differently based on whether you pass them arguements or not.

In this assignment however, you would use function overloading for a slightly different purpose. A recursive method of the BSTree class will always start at the _root_ of the tree to perform its function, and thus it requires a pointer to the root of the BST as a parameter to the function. If you wanted to call such a private function inside of main, you would need to get access to the _root_ pointer from the BSTree class. This presents a problem as _main_ cannot actually access the _root_ of a BSTree, since the _root_ pointer is private. While you could do this using public _getter_ functions to return the _root_ and then pass it to the function, this is not clean, nor is it intuitive for someone else working with this class. Instead what you will likely want to do is implement a public version of the search/insert/clear functions which when called from _main_ will call their private, recursive counterparts. (These functions should also check whether the BSTree is empty before calling the private functions).

```c++
//looks good in main: 
myTree.insert(3544, 'y');
//looks bad in main: 
myTree.insert(3554, 'y', myTree.getRoot());
```

#### Objective

Your objective for this lab will be to do the following:

1. Implement an insertion method for the BSTree class
2. Implement a search method (aka method for printing a secret message) for the BSTree class
3. Write a main function which runs your program on given input including reading from the file
4. Test your program on the sample input

#### Compiling

As in previous labs, it's advisable that you compile your program with the C++11 standard and the -g flag, i.e.

```bash
  g++ -std=c++11 -g main.cpp bst.cpp -o main
```

If the tree was constructed properly and the search function is implemented correctly, then you should get some message when you give your function the following inputs

```bash
  ./main filename N dest
```
where filename is your messageX.txt file, N is the number of lines in the text file, and dest is the value to search for within the tree.

**Note that the filenames each contain two numbers: the first corresponds to number of lines (or nodes) and the second corresponds to the value of the node to search for.**

For the visual example above, if the tree was read from a file called "test.txt" then your main should produce the following output given the following:

```bash
./main test.txt 6 8270
you
```

An example of testing your implementation on an actual input file is as follows:

```bash
./main message_1817_9310.txt 1817 9310
```

#### Questions

> What is the runtime of the search function for any key K?

> What was the output of your program for message_1817_9310.txt?

> For message_2590_9693.txt?

> For message_9350_7955.txt?

#### Submission

You will submit your main.cpp, bst.cpp, and bst.hpp files to Gradescope along with a lab9.txt file containg answers to the questions at the end of the lab.

If you do no finish the lab within the allotted time, submit your incomplete main.cpp, bst.cpp, and bst.hpp files along with an empty lab9.txt file

__Remember to put the names of any group members you worked with on your submission__


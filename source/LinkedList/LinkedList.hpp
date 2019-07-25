#pragma once
#include <iostream>

/** Node Class
 * These are the building blocks of the linked list.
 */
class Node {
 private:
  int data;
  Node* next;
  Node* prev;

 public:
  Node(int d) : data(d) { next = prev = nullptr; }
  ~Node() {}

  friend class LinkedList;
};

/** Doubly Linked List
 * A class that manages nodes to store data
 * non-contiguously in memory.
 */
class LinkedList {
 private:
  Node* head;
  Node* tail;
  unsigned int len;

 public:
  LinkedList();
  ~LinkedList();

  /** at(int index)
   * Returns the element at the given index.
   * Negative numbers return from the end of the list.
   * Throws Out of Bounds exception if index not in list.
   * 
   * Inputs: 
   * @param index: index to get the value of 
   * 
   * Outputs:
   * The value of list[index]
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.at(0) == 1
   * 
   * Runtime:
   * O(n) //dependant on type of LinkedList
   */
  int at(int index);

  /** length()
   * Returns the length of linked list.
   * 
   * Outputs:
   * The value of data member len
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.length() == 1
   * 
   * Runtime:
   * O(1)
   */
  unsigned int length();

  /** push(int data, [int index])
   * Pushes a node containing the given data to the list.
   * 
   * Inputs:
   * @param data: integer to be added to the list
   * @param index: index to insert data at
   * 
   * Side Effects:
   * Adds data to either the front, back, or at the given index within the list
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.push_front(5)
   * test.push(3, 1)
   * 
   * Runtime:
   * O(n) for push(), O(1) for others
   */
  void push_front(int data);
  void push_back(int data);
  void push(int data, int index);

  /** pop([int index])
   * Removes and returns the data behind the given index.
   * 
   * Outputs:
   * The value at either the front,back or at the given index
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.pop_back() == 1
   * 
   * Runtime:
   * O(n) for pop(), O(1) for others
   */
  int pop_front();
  int pop_back();
  int pop(int index);

  /** set(int index, int data)
   * Overwrite the node at index to contain the new data.
   * Negative numbers set from the end of the list.
   * Throws Out of Bounds exception if index not in list.
   * 
   * Inputs:
   * @param index: index to change value of
   * @param data: integer to replace current value at List[index]
   * 
   * Outputs:
   * Changes the value of list[index] to data
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.set(0, 5)
   * 
   * Runtime:
   * O(n)
   */
  int set(int index, int data);

  /** clear()
   * Clears the entire list.
   * 
   * Side Effects:
   * Removes all nodes from the list
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.clear()
   * 
   * Runtime:
   * O(n)
   */
  void clear();

  /** remove(int data)
   * Removes the first item from the list with value data.
   * 
   * Inputs:
   * @param data: value to be removed
   * 
   * Side Effects:
   * Removes the first node with a value equal to data
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.push_back(2)
   * test.remove(12)
   * 
   * Runtime:
   * O(n)
   */
  void remove(int data);

  /** index(data)
   * Returns the index of the given data in the linked list,
   * -1 if that data is not present.
   * 
   * Inputs:
   * @param data: value to be searched for
   * 
   * Outputs:
   * The first index at which data was found or -1 if it was not found
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.index(1) == 0
   * test.index(2) == -1
   * 
   * Runtime:
   * O(n)
   */
  int index(int data);

  /** reverse()
   * Reverses the order of the list in-place.
   * 
   * Side Effects:
   * Reverses the elements in the List
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.push_back(2)
   * test.push_back(3)
   * test.reverse() // [3,2,1]
   * 
   * Runtime:
   * O(n)
   */
  void reverse();

  /** print()
   * Prints the contents of the list to the ostream.
   * 
   * Side Effects:
   * Prints all elements of the list to cout
   * 
   * Examples:
   * Linkedlist test;
   * test.push_back(1)
   * test.print()
   * 
   * Runtime:
   * O(n)
   */
  void print(std::ostream& oss = std::cout);
};

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
  ~Node(){}

  friend class DLL;
};

/** Doubly Linked List
 * A class that manages nodes to store data
 * non-contiguously in memory.
 */
class DLL {
 private:
  Node* head;
  Node* tail;
  unsigned int len;

 public:
  DLL();
  ~DLL();

  /** at(int index)
   * Returns the element at the given index.
   * Negative numbers return from the end of the list.
   * Throws Out of Bounds exception if index not in list.
   */
  int at(int index);

  /** length()
   * Returns the length of linked list.
   */
  unsigned int length();

  /** push(int data, [int index])
   * Pushes a node containing the given data to the list.
   */
  void push_front(int data);
  void push_back(int data);
  void push(int data, int index);

  /** pop([int index])
   * Removes and returns the data behind the given index.
   */
  int pop_front();
  int pop_back();
  int pop(int index);

  /** set(int index, int data)
   * Overwrite the node at index to contain the new data.
   * Negative numbers set from the end of the list.
   * Throws Out of Bounds exception if index not in list.
   */
  int set(int index, int data);

  /** clear()
   * Clears the entire list.
   */
  void clear();

  /** remove(int data)
   * Removes the first item from the list with value data.
   */
  void remove(int data);

  /** index(data)
   * Returns the index of the given data in the linked list,
   * -1 if that data is not present.
   */
  int index(int data);

  /** reverse()
   * Reverses the order of the list in-place.
   */
  void reverse();

  /** print()
   * Prints the contents of the list to the ostream.
   */
  void print(std::ostream& oss = std::cout);
};

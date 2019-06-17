#pragma once
#include "../doctest.h"

/** Node Class
 * These are the building blocks of the linked list.
 */
class Node {
 private:
  int data;
  Node* next;

 public:
  Node(int d) : data(d) { next = nullptr; }
  ~Node() {}

  friend class SLL;
};

/** Singly Linked List
 * A class that manages nodes to store data
 * non-contiguously in memory.
 */
class SLL {
 private:
  Node* head;
  // Node* tail;
  unsigned int len;

 public:
  SLL();
  ~SLL();

  /** at(int index)
   * Returns the element at the given index.
   * Negative numbers return from the end of the list.
   * Throws Out of Bounds exception if index not in list.
   */
  int at(int);

  /** length()
   * Returns the length of linked list.
   */
  unsigned int length();

  /** prepend(int data)
   * Prepends a new node with the given integer data.
   */
  void prepend(int);

  /** append(int data)
   * Appends a new node with the given integer data.
   */
  void append(int);

  /** insert(int data, int index)
   * Inserts the given data at the given index.
   */
  void insert(int, int);

  /** pop([int index])
   * Removes and returns the data behind the given index.
   */
  int pop_front();
  int pop_back();
  int pop(int);

  /** set(int data, int index)
   * Overwrite the node at index to contain the new data.
   */
  int set(int, int);

  /** clear()
   * Clears the entire list.
   */
  void clear();

  /** remove(int data)
   * Removes the first item from the list with value data.
   */
  void remove(int);

  /** unique()
   * Returns the count of unique elements in the list.
   */
  void unique();

  /** reverse()
   * Reverses the order of the list in-place.
   */
  void reverse();
};

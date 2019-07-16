#pragma once
#include <iostream>
#include "../String/String.hpp"
#include <string>

/** A modified version of the linkedlist class available in the LinkedList Library */

/** Node Class
 * These are the building blocks of the linked list.
 */
class Node {
 private:
  String* key;
  int val;
  Node* next;
  Node* prev;

 public:
  Node();
  Node(const String& k, int v);
  ~Node();

  friend class List;
};

/** Doubly Linked List
 * A class that manages nodes to store data
 * non-contiguously in memory.
 */
class List {
 private:
  Node* head;
  Node* tail;
  unsigned int len;

 public:
  List();
  ~List();

  /** length()
   * Returns the length of linked list.
   */
  unsigned int length();

  /** push(int data, [int index])
   * Pushes a node containing the given data to the list.
   */
  void push_back(const String& key, int val);

  /** clear()
   * Clears the entire list.
   */
  void clear();

  /** remove(int data)
   * Removes the first item from the list with value data.
   */
  void remove(String& data);

  /** index(data)
   * Returns the index of the given data in the linked list,
   * -1 if that data is not present.
   */
  int index(String& d);

  /** at(ind)
   * returns the val member at the given index
   */
  int at(int ind);

  /** print()
   * Prints the contents of the list to the ostream.
   */
  void print(std::ostream& oss = std::cout);
};

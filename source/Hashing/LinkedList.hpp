#pragma once
#include <iostream>
#include <string>
#include "../String/String.hpp"

/** A modified version of the linkedlist class available in the LinkedList
 * Library */

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
  Node() : key(new String()), val(0) { next = prev = nullptr; }
  Node(const String& k, int v) : key(new String(k.cstr())), val(v) {
    next = prev = nullptr;
  }
  ~Node() { delete key; };

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
  List() : head(nullptr), len(0) {}
  ~List() { clear(); }

  /** length()
   * Returns the length of linked list.
   */
  unsigned int length() { return len; }

  /** push(int data, [int index])
   * Pushes a node containing the given data to the list.
   */
  void push_back(const String& key, int val) {
    Node* n = new Node(key, val);
    if (!head) {
      head = n;
    } else {
      Node* iter = head;
      while (iter->next)
        iter = iter->next;

      iter->next = n;
    }
    ++len;
    return;
  }

  /** clear()
   * Clears the entire list.
   */
  void clear() {
    Node* to_remove;
    while (head) {
      to_remove = head;
      head = head->next;
      delete to_remove;
    }
    len = 0;
  }

  /** remove(int data)
   * Removes the first item from the list with value data.
   */
  void remove(String& data) {
    if (!head)
      throw "Nothing to remove";
    else if (head->key->compare(data)) {
      Node* temp = head;
      head = head->next;
      --len;
      delete temp;
    } else {
      for (Node* iter = head; iter->next; iter = iter->next) {
        if (iter->next->key->compare(data) == 1) {
          Node* to_remove = iter->next;
          iter->next = to_remove->next;
          delete to_remove;
          --len;
          break;
        }
      }
    }
  }

  /** index(data)
   * Returns the index of the given data in the linked list,
   * -1 if that data is not present.
   */
  int index(String& d) {
    int i = 0;
    for (Node* iter = head; iter; iter = iter->next, ++i) {
      if (iter->key->compare(d) == 1)
        return i;
    }
    return -1;
  }

  /** at(ind)
   * returns the val member at the given index
   */
  int at(int ind) {
    Node* iter = head;
    for (int i = 0; i < ind; ++i) {
      iter = iter->next;
    }
    return iter->val;
  }

  /** print()
   * Prints the contents of the list to the ostream.
   */
  void print(std::ostream& oss = std::cout) {
    std::cout << "Length " << len << std::endl;
    Node* temp = head;
    while (temp) {
      oss << temp->val << ", ";
      temp->key->print();
      std::cout << std::endl;
      temp = temp->next;
    }
    oss << std::endl;
    return;
  }
};

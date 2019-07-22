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

 public:
  Node() : key(new String()), val(0) { next = nullptr; }
  Node(const String& k, int v) : key(new String(k.cstr())), val(v) {
    next = nullptr;
  }
  ~Node() { delete key; };

  friend class List;
  friend class HashTable;
};

/** Doubly Linked List
 * A class that manages nodes to store data
 * non-contiguously in memory.
 */
class List {
 private:
  Node* head;
  unsigned int len;

 public:
  List() : head(nullptr), len(0) {}
  ~List() { clear(); }

  /** length()
   * Returns the length of linked list.
   */
  unsigned int length() { return len; }

  /** empty()
   * Returns whether or not the string is empty.
   */
  bool empty() const { return len == 0; }

  /** peak()
   * Returns the node at the front of the list.
   */
  Node* top() const {
    if (!head)
      throw std::underflow_error("Empty list.");
    return head;
  }

  /** pop()
   * Removes an element from the front of the list.
   */
  void pop() {
    if (!head)
      throw std::underflow_error("Empty list.");
    Node* temp = head;
    head = head->next;
    delete temp;
    len--;
  }

  /** push(String key, int val)
   * Pushes a node containing the given data to the list.
   */
  void push(const String& key, int val) {
    Node* n = new Node(key, val);
    if (!head)
      head = n;
    else {
      n->next = head;
      head = n;
    }
    len++;
  }

  /** update(String key, int val)
   * Updates the given key with the given value.
   */
  void update(const String& key, int val) {
    Node* temp = head;
    while (temp && !temp->key->compare(key))
      temp = temp->next;
    if (temp)
      temp->val = val;
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

  /** remove(String key)
   * Removes the first item from the list with the given key.
   */
  void remove(String& key) {
    if (!head)
      throw "Nothing to remove";
    else if (head->key->compare(key)) {
      Node* temp = head;
      head = head->next;
      --len;
      delete temp;
    } else {
      for (Node* iter = head; iter->next; iter = iter->next) {
        if (iter->next->key->compare(key) == 1) {
          Node* to_remove = iter->next;
          iter->next = to_remove->next;
          delete to_remove;
          --len;
          break;
        }
      }
    }
  }

  /** index(String key)
   * Returns the index of the given data in the linked list,
   * -1 if that data is not present.
   */
  int index(const String& key) {
    int i = 0;
    for (Node* iter = head; iter; iter = iter->next, ++i) {
      if (iter->key->compare(key) == 1)
        return i;
    }
    return -1;
  }

  /** get(String key)
   * Gets the value associated with the given key.
   */
  int get(const String& key) const {
    for (Node* iter = head; iter; iter = iter->next)
      if (iter->key->compare(key))
        return iter->val;

    throw std::runtime_error("Key not found.");
  }

  /** at(int index)
   * returns the val member at the given index
   */
  int at(unsigned int idx) {
    Node* iter = head;
    for (unsigned int i = 0; iter && i < idx; ++i) {
      iter = iter->next;
    }
    return (iter) ? iter->val : throw std::out_of_range("Index out of bounds");
  }

  /** print()
   * Prints the contents of the list to the ostream.
   */
  void print(std::ostream& oss = std::cout) {
    Node* temp = head;
    oss << "{";
    while (temp) {
      temp->key->print();
      oss << ": " << temp->val << ", ";
      temp = temp->next;
    }
    oss << "}";
    return;
  }
};

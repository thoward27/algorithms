#pragma once

#include "../LinkedList/LinkedList.hpp"

/** Stack
 * A container class that stores data using a LIFO
 * (last in, first out) scheme.
 */
class Stack {
 private:
  LinkedList* list;

 public:
  Stack();
  ~Stack();

  /** size()
   * Returns the size of the stack.
   * 
   * Outputs:
   * The size of the stack
   * 
   * Examples:
   * Stack test;
   * test.push(1)
   * test.size() == 1
   * 
   * Runtime:
   * O(1)
   */
  unsigned int size();

  /** push(int data)
   * Pushes a node containing the given data to the top of the stack.
   * 
   * Inputs:
   * @param data: integer to be added to the queue
   * 
   * Side Effects:
   * Adds the value data to the front of the stack
   * 
   * Examples:
   * Stack test;
   * test.push(1)
   * 
   * Runtime:
   * O(1)
   */
  void push(int data);

  /** pop()
   * Removes and returns the data at the top of the stack.
   * 
   * Outputs:
   * The value currently at the top of the stack and removes it from the stack
   * 
   * Examples:
   * Stack test;
   * test.push(1)
   * test.pop() == 1
   * 
   * Runtime:
   * O(1)
   */
  int pop();

  /** top()
   * Returns the data at the top of the stack without changing the stack.
   * 
   * Outputs:
   * The value currently at the top of the stack
   * 
   * Examples:
   * Stack test;
   * test.push(1)
   * test.top() == 1
   * 
   * Runtime:
   * O(1)
   */
  int top();

  /** empty()
   * Returns whether or not the stack is empty.
   * 
   * Outputs:
   * True if the backing List is empty
   * False otherwise
   * 
   * Examples:
   * Stack test;
   * test.empty() == 1
   * test.push(1)
   * test.empty() == 0
   * 
   * Runtime:
   * O(1)
   * 
   */
  bool empty();

  /** clear()
   * Clears the entire stack.
   * 
   * Side Effects:
   * Removes all elements from the stack
   * 
   * Examples:
   * Stack test;
   * test.push(1)
   * test.clear() 
   * 
   * Runtime:
   * O(n)
   */
  void clear();
};
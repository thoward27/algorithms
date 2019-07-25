#pragma once

#include "../LinkedList/LinkedList.hpp"

/** Queue
 * A container class that stores data using a FIFO
 * (first in, first out) scheme.
 */
class Queue {
 private:
  LinkedList* list;

 public:
  Queue();
  ~Queue();

  /** size()
   * Returns the size of the queue.
   * 
   * Outputs:
   * The size of the queue
   * 
   * Examples:
   * Queue test;
   * test.push(1)
   * test.size() == 1
   * 
   * Runtime:
   * O(1)
   */
  unsigned int size();

  /** push(int data)
   * Pushes a node containing the given data to the back of the queue.
   * 
   * Inputs:
   * @param data: integer to add to the queue
   * 
   * Side Effects:
   * Adds data to the end of the queue
   * 
   * Examples:
   * Queue test;
   * test.push(1)
   * 
   * Runtime:
   * O(1)
   */
  void push(int data);

  /** pop()
   * Removes and returns the data at the front of the queue.
   * 
   * Outputs:
   * The value of the leftmost value in the queue and removes it from the queue
   * 
   * Examples:
   * Queue test;
   * test.push(1)
   * test.push(2)
   * test.pop() == 1
   * 
   * Runtime:
   * O(1)
   */
  int pop();

  /** front()
   * Returns the data at the front of the queue without changing the queue.
   * 
   * Outputs:
   * The value of the leftmost value in the queue 
   * 
   * Examples:
   * Queue test;
   * test.push(1)
   * test.push(2)
   * test.front() == 1
   * 
   * Runtime:
   * O(1)
   */
  int front();

  /** back()
   * Returns the data at the back of the queue without changing the queue.
   * 
   * Outputs:
   * The value of the rightmost value in the queue 
   * 
   * Examples:
   * Queue test;
   * test.push(1)
   * test.push(2)
   * test.back() == 2
   * 
   * Runtime:
   * O(1)
   */
  int back();

  /** empty()
   * Returns whether or not the queue is empty.
   * 
   * Outputs:
   * True if the backing list is empty
   * False otherwise
   * 
   * Examples:
   * Queue test
   * test.empty() == 1
   * test.push(1)
   * test.empty() == 0
   * 
   * Runtime:
   * O(1)
   */
  bool empty();

  /** clear()
   * Clears the entire queue.
   * 
   * Side Effects:
   * Removes all elements from the queue
   * 
   * Examples:
   * Queue test;
   * test.push(1)
   * test.push(2)
   * test.clear()
   * 
   * Runtime:
   * O(n) // same as LinkedList
   */
  void clear();
};
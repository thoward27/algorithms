#pragma once

/** Queue
 * A container class that stores data using a FIFO
 * (first in, first out) scheme.
 */
class Queue {
 private:
 public:
  Queue();
  ~Queue();

  /** size()
   * Returns the size of the queue.
   */
  unsigned int size();

  /** push(int data)
   * Pushes a node containing the given data to the back of the queue.
   */
  void push(int data);

  /** pop()
   * Removes and returns the data at the front of the queue.
   */
  int pop();

  /** front()
   * Returns the data at the front of the queue without changing the queue.
   */
  int front();

  /** back()
   * Returns the data at the back of the queue without changing the queue.
   */
  int back();

  /** empty()
   * Returns whether or not the queue is empty.
   */
  bool empty();

  /** clear()
   * Clears the entire stack.
   */
  void clear();
};
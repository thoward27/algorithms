#pragma once

#include "../LinkedList/LinkedList.hpp"

/** Dequeue Class
 * A Double ended queue class
 * Supports functionality of a Stack and Queue simultaneously
 */
class Deque {
 private:
  LinkedList* list;

 public:
  Deque();
  ~Deque();

  /** size();
   * Returns an unsigned integer representing the
   * number of nodes in the Dequeue
   * 
   * Outputs:
   * The size of the dequeue 
   * 
   * Examples:
   * Dequeue test;
   * test.pushleft(1)
   * test.size() == 1
   * 
   * Runtime:
   * O(1)
   */
  unsigned int size();

  /** pushleft(int data);
   * Adds a node to the front of the dequeue (stack functionality)
   * 
   * Inputs:
   * @param data: integer to add to the left of the dequeue
   * 
   * Side Effects:
   * Adds data to the left of the dequeue
   * 
   * Examples:
   * Dequeue test;
   * test.pushleft(1)
   * 
   * Runtime:
   * O(1)
   */
  void pushleft(int data);

  /** popleft();
   * Returns the value of the first node in the dequeue
   * and removes that node from the dequeue (stack functionality)
   * 
   * Outputs:
   * The value of the leftmost value in the dequeue and removes it from the dequeue
   * 
   * Examples:
   * Dequeue test;
   * test.pushleft(1)
   * test.pushleft(2)
   * test.popleft() == 2
   * 
   * Runtime:
   * O(1)
   */
  int popleft();

  /** pushright(int data);
   * Adds a node to the end of the dequeue (queue functionality)
   * 
   * Inputs:
   * @param data: integer to add to the right of the dequeue
   * 
   * Side Effects:
   * Adds data to the right of the dequeue
   * 
   * Examples:
   * Dequeue test;
   * test.pushright(1)
   * 
   * Runtime:
   * O(1)
   */
  void pushright(int data);

  /** popright();
   * Returns the value of the first node in the dequeue
   * and removes that node from the dequeue (queue functionality)
   * 
   * Outputs:
   * The value of the rightmost value in the dequeue and removes it from the dequeue
   * 
   * Examples:
   * Dequeue test;
   * test.pushleft(1)
   * test.pushleft(2)
   * test.popright() == 1
   * 
   * Runtime:
   * O(1)
   */
  int popright();

  /** front();
   * Returns the value of the first node in the dequeue without
   * changing the dequeue
   * 
   * Outputs:
   * The value of the leftmost value in the queue 
   * 
   * Examples:
   * Dequeue test;
   * test.pushleft(1)
   * test.pushleft(2)
   * test.front() == 2
   * 
   * Runtime:
   * O(1)
   */
  int front();

  /** back();
   * Returns the value of the last node in the dequeue without
   * changing the dequeue
   * 
   * Outputs:
   * The value of the rightmost value in the queue 
   * 
   * Examples:
   * Queue test;
   * test.pushleft(1)
   * test.pushleft(2)
   * test.back() == 1
   * 
   * Runtime:
   * O(1)
   */
  int back();

  /** empty();
   * Returns true if the dequeue is empty,
   *         false otherwise
   * 
   * Outputs:
   * True if the backing list is empty
   * False otherwise
   * 
   * Examples:
   * Dequeue test
   * test.empty() == 1
   * test.pushleft(1)
   * test.empty() == 0
   * 
   * Runtime:
   * O(1)
   */
  bool empty();

  /** clear();
   * Removes all nodes from the dequeue without destructing it
   * 
   * Side Effects:
   * Removes all elements from the dequeue
   * 
   * Examples:
   * Dequeue test;
   * test.pushleft(1)
   * test.pushleft(2)
   * test.clear()
   * 
   * Runtime:
   * O(n) // same as Linkedlist
   */
  void clear();
};
#pragma once

#include "../LinkedList/LinkedList.hpp"

/** Dequeue Class
 * A Double ended queue class
 * Supports functionality of a Stack and Queue simultaneously
 */
class Dequeue {
 private:
  LinkedList* list;

 public:
  Dequeue();
  ~Dequeue();

  /** size();
   * Returns an unsigned integer representing the
   * number of nodes in the Dequeue
   */
  unsigned int size();

  /** push(int data);
   * Adds a node to the front of the dequeue (stack functionality)
   */
  void pushleft(int data);

  /** pop();
   * Returns the value of the first node in the dequeue
   * and removes that node from the dequeue (stack functionality)
   */
  int popleft();

  /** pushright(int data);
   * Adds a node to the end of the dequeue (queue functionality)
   */
  void pushright(int data);

  /** popright();
   * Returns the value of the first node in the dequeue
   * and removes that node from the dequeue (queue functionality)
   */
  int popright();

  /** front();
   * Returns the value of the first node in the dequeue without
   * changing the dequeue
   */
  int front();

  /** back();
   * Returns the value of the last node in the dequeue without
   * changing the dequeue
   */
  int back();

  /** empty();
   * Returns true if the dequeue is empty,
   *         false otherwise
   */
  bool empty();

  /** clear();
   * Removes all nodes from the dequeue without destructing it
   */
  void clear();
};
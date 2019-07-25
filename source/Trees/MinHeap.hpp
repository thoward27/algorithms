#pragma once
#include <iostream>

/** Min Heap
 * A class that stores data in a heap structure, with the smallest
 * element at the root, providing efficient push and min operations
 */
class MinHeap {
 private:
  int* array;
  unsigned int capacity;
  int size;

  /** swim()
   * Restores the heap order property after an element is pushed. Assumes the
   * new element has been pushed at the end of the heap array (right-most node
   * in the bottom level of the tree), and swaps it upwards the tree until it's
   * greater than its parent.
   * 
   * Side Effects:
   * Restores order in the heap by moving an element up the heap
   * 
   * Runtime:
   * O(?)
   */
  void swim();

  /** sink(int i)
   * Restores the heap order property after element removal. Assumes the element
   * at the end of the heap array has been swapped with the root, and the size
   * has been decremented (effectively removing the last element in the heap
   * array). It then swaps the element at the root down the tree until both
   * children are greater than it.
   * 
   * Inputs:
   * @param i: integer to sink down the heap
   * 
   * Side Effects:
   * Restores order in the heap by moving i down the heap
   * 
   * Runtime:
   * O(?)
   */
  void sink(int i);

  /** search(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * returning true if the data is found and false if i is greater than or
   * equal to size or data is less than the MinHeap's value at i.
   * 
   * Inputs:
   * @param i: root of the subtree
   * @param data: integer to search the heap for
   * 
   * Outputs:
   * True if data is found in the subtree rooted at i
   * False otherwise
   * 
   * Runtime:
   * O(?)
   */
  bool search(int i, int data);

  /** erase(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * calling remove on i if data is found in the tree.
   * Does nothing if data is not found in the subtree.
   * 
   * Inputs:
   * @param i: root of the subtree
   * @param data: integer to search the heap for
   * 
   * Side Effects:
   * Removes the element data from the subtree rooted at i
   * 
   * Runtime:
   * O(?)
   */
  void erase(int i, int data);

 public:
  explicit MinHeap(unsigned int cap = 16);
  ~MinHeap();

  /** push(int data)
   * Inserts data into the MinHeap such that the heap order property is
   * preserved.
   * Assumes duplicate elements will not be pushed.
   * 
   * Inputs:
   * @param data: integer to search the heap for
   * 
   * Side Effects:
   * Pushes data onto the heap and restores order
   * 
   * Runtime:
   * O(?)
   */
  void push(int data);

  /** count()
   * Returns the number of elements in the MinHeap.
   * 
   * Outputs:
   * The count of all the elements in the heap
   * 
   * Runtime:
   * O(1)
   */
  int count();

  /** pop()
   * Removes and returns the minimum element in the MinHeap, preserving the
   * heap order property.
   * Throws an error if the heap is empty.
   * 
   * Outputs:
   * The value of the minimum value in the heap and removes it from the heap
   * 
   * Runtime:
   * O(?)
   */
  int pop();

  /** peek()
   * Returns the minimum element in the MinHeap without modifying its contents.
   * Throws an error if the heap is empty.
   * 
   * Outputs:
   * The value of the minimum value in the heap
   * 
   * Runtime:
   * O(?)
   */
  int peek();

  /** search(int data)
   * Searches the MinHeap for the given data, returning true if the data is
   * found and false otherwise.
   * 
   * Inputs:
   * @param data: integer to search the heap for
   * 
   * Side Effects:
   * Pushes data onto the heap and restores order
   * 
   * Runtime:
   * O(?)
   */
  bool search(int data);

  /** remove(int i)
   * Removes the element at index i in the MinHeap tree (indexed left-to-right,
   * top-to-bottom) and returns its value.
   * Throws an error if the heap is empty or the index is out of bounds.
   * 
   * Inputs:
   * @param i: index to remove from the heap
   * 
   * Outputs:
   * The value at index i and removes it from the heap
   * 
   * Runtime:
   * O(?)
   */
  int remove(int i);

  /** erase(int data)
   * Searches the MinHeap for the given data, and deletes it if it's found,
   * preserving the heap order property.
   * Does nothing if data is not found.
   * 
   * Inputs:
   * @param data: integer to remove from the heap 
   * 
   * Side Effects:
   * Removes data from the heap if it is in the heap
   * 
   * Runtime:
   * O(?)
   */
  void erase(int data);

  /** print()
   * Prints the contents of the MinHeap tree to the ostream from left-to-right,
   * top-to-bottom.
   * 
   * Side Effects:
   * Prints the content of the heap to the given stream
   */
  void print(std::ostream& oss = std::cout);
};

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
   * Restores the heap order property after element pushion. Assumes the new
   * element has been pushed at the end of the heap array (right-most node in
   * the bottom level of the tree), and swaps it up the tree until it's greater
   * than its parent.
   */
  void swim();

  /** sink(int i)
   * Restores the heap order property after element removal. Assumes the element
   * at the end of the heap array has been swapped with the root, and the size
   * has been decremented (effectively removing the last element in the heap
   * array). It then swaps the element at the root down the tree until both
   * children are greater than it.
   */
  void sink(int i);

  /** search(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * returning true if the data is found and false if i is greater than or
   * equal to size or data is less than the MinHeap's value at i.
   */
  bool search(int i, int data);

  /** erase(int i, int data)
   * Recursively searches for data in the MinHeap's subtree rooted at i,
   * calling remove on i if data is found in the tree.
   * Does nothing if data is not found in the subtree.
   */
  void erase(int i, int data);

 public:
  MinHeap(unsigned int cap);
  ~MinHeap();

  /** push(int data)
   * Inserts data into the MinHeap such that the heap order property is
   * preserved.
   * Assumes duplicate elements will not be pushed.
   * Throws an error if the heap is full.
   */
  void push(int data);

  /** count()
   * Returns the number of elements in the MinHeap.
   */
  int count();

  /** pop()
   * Removes and returns the minimum element in the MinHeap, preserving the
   * heap order property.
   * Throws an error if the heap is empty.
   */
  int pop();

  /** peek()
   * Returns the minimum element in the MinHeap without modifying its contents.
   * Throws an error if the heap is empty.
   */
  int peek();

  /** search(int data)
   * Searches the MinHeap for the given data, returning true if the data is
   * found and false otherwise.
   */
  bool search(int data);

  /** remove(int i)
   * Removes the element at index i in the MinHeap tree (indexed left-to-right,
   * top-to-bottom) and returns its value.
   * Throws an error if the heap is empty or the index is out of bounds.
   */
  int remove(int i);

  /** erase(int data)
   * Searches the MinHeap for the given data, and deletes it if it's found,
   * preserving the heap order property.
   * Does nothing if data is not found.
   */
  void erase(int data);

  /** print()
   * Prints the contents of the MinHeap tree to the ostream from left-to-right,
   * top-to-bottom.
   */
  void print(std::ostream& oss = std::cout);
};

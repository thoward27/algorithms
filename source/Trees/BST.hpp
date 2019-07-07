#pragma once
#include <iostream>
#include "Node.hpp"

/** Binary Search Tree
 * A class that stores data in a binary tree structure, providing
 * efficient insert, search, and remove operations (in the average case)
 */
class BST {
 private:
  Node* root;

  /** insert(int data, Node* n)
   * Recursively places data at the correct position in the subtree
   * rooted at n, preserving the BST properties.
   * Returns the Node containing data at the call that creates the node,
   * and returns n at every other call.
   * Does nothing if the data is already in the subtree.
   */
  Node* insert(int data, Node* n);

  /** search(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, returning
   * true if the data is found and false otherwise.
   */
  bool search(int data, Node* n);

  /** remove(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, removing it
   * if it exists and preserving the BST properties.
   * Returns...
   *   nullptr if data was not found or n was a leaf.
   *   the pointer to the child if n has only one child.
   *   the pointer to the right child (successor) if n has two children.
   */
  Node* remove(int data, Node* n);

  /** height(Node* n)
   * Recursively determines the height of the subtree rooted at n.
   */
  int height(Node* n);

  /** clear(Node* n)
   * Recursively deletes the entire subtree rooted at n.
   */
  void clear(Node* n);

  /** preorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a pre-order traversal.
   */
  void preorder(Node* n, std::ostream& oss, bool dups);

  /** inorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using an in-order traversal.
   */
  void inorder(Node* n, std::ostream& oss, bool dups);

  /** postorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a post-order traversal.
   */
  void postorder(Node* n, std::ostream& oss, bool dups);

 public:
  BST();
  ~BST();

  /** insert(int data)
   * Inserts the given data into the tree.
   * Does nothing if the data is already in the tree.
   */
  void insert(int data);

  /** is_empty()
   * Returns true if the tree is empty and false otherwise
   */
  bool is_empty();

  /** search(int data)
   * Searches the tree for the given data, returning true if the data
   * is found and false otherwise.
   */
  bool search(int data);

  /** remove(int data)
   * Removes the given data from the tree, provided it exists.
   */
  void remove(int data);

  /** height()
   * Determines and returns the height of the tree.
   * Returns -1 if the tree is empty.
   */
  int height();

  /** clear()
   * Removes every element from the tree.
   */
  void clear();

  /** preorder()
   * Prints the contents of the tree to the ostream using a pre-order
   * traversal.
   */
  void preorder(std::ostream& oss = std::cout, bool dups = false);

  /** inorder()
   * Prints the contents of the tree to the ostream using an in-order
   * traversal.
   */
  void inorder(std::ostream& oss = std::cout, bool dups = false);

  /** postorder()
   * Prints the contents of the tree to the ostream using a post-order
   * traversal.
   */
  void postorder(std::ostream& oss = std::cout, bool dups = false);
};

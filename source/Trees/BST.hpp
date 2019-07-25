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
   * 
   * Inputs:
   * @param data: integer to be added to the tree
   * @param n: Node to root the subtree
   * 
   * Outputs:
   * A pointer to a node for use in recursion
   * 
   * Side Effects:
   * Inserts the value data into its appropriate place within the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1, root)
   * 
   * Runtime:
   * O(log n)
   */
  static Node* insert(int data, Node* n);

  /** search(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, returning
   * true if the data is found and false otherwise.
   * 
   * Inputs:
   * @param data: integer to be searched for
   * @param n: Node to root the subtree
   * 
   * Outputs:
   * True if the value of data is in the tree
   * False otherwise
   * 
   * Examples:
   * BST test;
   * test.insert(1, root)
   * test.search(1, root) == 1
   * test.search(2, root) == 0
   * 
   * Runtime:
   * O(log n)
   */
  static bool search(int data, Node* n);

  /** remove(int data, Node* n)
   * Recursively searches for data in the subtree rooted at n, removing it
   * if it exists and preserving the BST properties.
   * Returns...
   *   nullptr if data was not found or n was a leaf.
   *   the pointer to the child if n has only one child.
   *   the pointer to the right child (successor) if n has two children.
   * 
   * Inputs:
   * @param data: integer to be removed from the tree
   * @param n: Node to root the subtree
   * 
   * Outputs:
   * A pointer to a node for use in recursion
   * 
   * Side Effects:
   * Removes the value data from the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1, root)
   * test.remove(1, root)
   * test.search(1, root) == 0
   * 
   * Runtime:
   * O(log n)
   */
  static Node* remove(int data, Node* n);

  /** height(Node* n)
   * Recursively determines the height of the subtree rooted at n.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * 1
   * Outputs:
   * The height of the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1, root)
   * test.height(root) == 1
   * 
   * Runtime:
   * O(?)
   */
  static int height(Node* n);

  /** clear(Node* n)
   * Recursively deletes the entire subtree rooted at n.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * 
   * Side Effects:
   * Removes all nodes from the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1, root)
   * test.clear(root)
   * test.search(1, root) == 0
   * 
   * Runtime:
   * O(?)
   */
  static void clear(Node* n);

  /** preorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a pre-order traversal.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   * @param dups: A flag for whether or not to print duplicates
   * 
   * Side Effects:
   * Prints a preorder traversal of the tree to the given stream
   * 
   * Runtime:
   * O(?)
   */
  static void preorder(Node* n, std::ostream& oss, bool dups);

  /** inorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using an in-order traversal.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   * @param dups: A flag for whether or not to print duplicates
   * 
   * Side Effects:
   * Prints an inorder traversal of the tree to the given stream
   * 
   * Runtime:
   * O(?)
   */
  static void inorder(Node* n, std::ostream& oss, bool dups);

  /** postorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a post-order traversal.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   * @param dups: A flag for whether or not to print duplicates
   * 
   * Side Effects:
   * Prints a postorder traversal of the tree to the given stream
   * 
   * Runtime:
   * O(?)
   */
  static void postorder(Node* n, std::ostream& oss, bool dups);

 public:
  BST();
  ~BST();

  /** insert(int data)
   * Inserts the given data into the tree.
   * Does nothing if the data is already in the tree.
   * 
   Inputs:
   * @param data: integer to be added to the tree
   * 
   * Side Effects:
   * Inserts the value data into its appropriate place within the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1)
   * 
   * Runtime:
   * O(log n)
   */
  void insert(int data);

  /** is_empty()
   * Returns true if the tree is empty and false otherwise
   * 
   * Outputs:
   * True if the tree is empty
   * False otherwise
   * 
   * Examples:
   * BST test;
   * test.is_empty() == 1
   * test.insert(1)
   * test.is_empty() == 0
   * 
   * Runtime:
   * O(1)
   */
  bool is_empty();

  /** search(int data)
   * Searches the tree for the given data, returning true if the data
   * is found and false otherwise.
   * 
   * Inputs:
   * @param data: integer to be added to the tree
   * 
   * Outputs:
   * True if the value of data appears in the tree
   * False otherwise
   * 
   * Examples:
   * BST test;
   * test.insert(1, root)
   * test.search(1) == 1
   * 
   * Runtime:
   * O(log n)
   */
  bool search(int data);

  /** remove(int data)
   * Removes the given data from the tree, provided it exists.
   * 
   * Inputs:
   * @param data: integer to be added to the tree
   * 
   * Side Effects:
   * Removes the value data from the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1)
   * test.remove(1)
   * test.search(1) == 0
   * 
   * Runtime:
   * O(log n)
   */
  void remove(int data);

  /** height()
   * Determines and returns the height of the tree.
   * Returns -1 if the tree is empty.
   * 
   * Outputs:
   * The height of the tree as an integer
   * 
   * Examples:
   * BST test;
   * test.insert(1)
   * test.height() == 1
   * 
   * Runtime:
   * O(?)
   */
  int height();

  /** clear()
   * Removes every element from the tree.
   * 
   * Side Effects:
   * Removes every node from the tree
   * 
   * Examples:
   * BST test;
   * test.insert(1)
   * test.clear()
   * test.search(1) == 0
   * 
   * Runtime:
   * O(n)
   */
  void clear();

  /** preorder()
   * Prints the contents of the tree to the ostream using a pre-order
   * traversal.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   * @param dups: A flag for whether or not to print duplicates
   *
   * Side Effects:
   * Prints a preorder traversal of the tree to the given stream
   * 
   * Runtime:
   * O(?)
   */
  void preorder(std::ostream& oss = std::cout, bool dups = false);

  /** inorder()
   * Prints the contents of the tree to the ostream using an in-order
   * traversal.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   * @param dups: A flag for whether or not to print duplicates
   * 
   * Side Effects:
   * Prints an inorder traversal of the tree to the given stream
   * 
   * Runtime:
   * O(?)
   */
  void inorder(std::ostream& oss = std::cout, bool dups = false);

  /** postorder()
   * Prints the contents of the tree to the ostream using a post-order
   * traversal.
   * 
   * Inputs:
   * @param n: Node to root the subtree
   * @param oss: Stream to print to
   * @param dups: A flag for whether or not to print duplicates
   * 
   * Side Effects:
   * Prints a postorder traversal of the tree to the given stream
   * 
   * Runtime:
   * O(?)
   */
  void postorder(std::ostream& oss = std::cout, bool dups = false);
};

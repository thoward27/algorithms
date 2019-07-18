#pragma once
#include <iostream>
#include "Node.hpp"

/** Red-Black Tree
 * Go to the link below for details about certain methods (e.g. rotateRight):
 * https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf
 */
class RBTree {
 private:
  Node* root;

  /** insert(int data, Node* n)
   * Recursively places data at the correct position in the subtree
   * rooted at n, preserving the RBTree properties.
   * Returns the Node containing data at the call that creates the node,
   * and returns n at every other call.
   * Does nothing if the data is already in the subtree.
   */
  Node* insert(int data, Node* n);

  /** rotateRight(Node* node)
   * Performs the "rotate right" operation on node, as described in the link
   * above.
   * Returns the node at the same position after rotation (node->left)
   */
  Node* rotateRight(Node* node);

  /** rotateLeft(Node* node)
   * Performs the "rotate left" operation on node, as described in the link
   * above.
   * Returns the node at the same position after rotation (node->right)
   */
  Node* rotateLeft(Node* node);

  /** flipColors(Node* node)
   * Flips the colors of node and its children.
   */
  void flipColors(Node* node);

  /** fix(Node* node)
   * Combines rotateRight, rotateLeft, and flipColors to restore RBTree
   * properties, as described in the link above.
   * Returns the node at the same position in the tree after fixing.
   */
  Node* fix(Node* temp);

  /** moveRedLeft(Node* temp)
   * Performs the "move red left" operation on temp, as described in the link
   * above.
   * Returns the node at the same position in the tree after alteration.
   */
  Node* moveRedLeft(Node* temp);

  /** moveRedRight(Node* temp)
   * Performs the "move red right" operation on temp, as described in the link
   * above.
   * Returns the node at the same position in the tree after alteration.
   */
  Node* moveRedRight(Node* temp);

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

  /** removeMax(Node* temp)
   * Removes the node with the largest key from the subtree rooted at temp.
   * Returns nullptr if temp was removed and temp otherwise.
   */
  Node* removeMax(Node* temp);

  /** removeMin(Node* temp)
   * Removes the node with the smallest key from the subtree rooted at temp.
   * Returns nullptr if temp was removed and temp otherwise.
   */
  Node* removeMin(Node* temp);

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
  void preorder(Node* n, std::ostream& oss);

  /** inorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using an in-order traversal.
   */
  void inorder(Node* n, std::ostream& oss);

  /** postorder()
   * Recursively prints the contents of the subtree rooted at n to the
   * ostream using a post-order traversal.
   */
  void postorder(Node* n, std::ostream& oss);

  /** isRed(Node* n)
   * Checks if n is red. A null pointer is defined to not be red.
   */
  bool isRed(Node* n);

  /** min(Node* subtree)
   * Finds the value of the minimum key in the subtree rooted at subtree and
   * returns it.
   */
  int min(Node* subtree);

  /** max(Node* subtree)
   * Finds the value of the maximum key in the subtree rooted at subtree and
   * returns it.
   */
  int max(Node* subtree);

 public:
  /** Constructors */
  RBTree() { root = nullptr; };

  /** Destructors */
  ~RBTree();

  /** insert(int data)
   * Inserts the given data into the tree.
   * Does nothing if the data is already in the tree.
   */
  void insert(int data);

  /** is_empty()
   * Returns true if the tree is empty and false otherwise
   */
  bool is_empty() { return !root; };

  /** search(int data)
   * Searches the tree for the given data, returning true if the data
   * is found and false otherwise.
   */
  bool search(int data) { return search(data, root); }

  /** min()
   * Finds the minimum key in the tree and returns it.
   */
  int min() { return min(root); }

  /** max()
   * Finds the maximum key in the tree and returns it.
   */
  int max() { return max(root); }

  /** remove(int data)
   * Removes the given data from the tree, provided it exists.
   */
  void remove(int data) { root = remove(data, root); }

  /** removeMin()
   * Removes the minimum key from the tree
   */
  void removeMin();

  /** removeMax()
   * Removes the maximum key from the tree
   */
  void removeMax();

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
  void preorder(std::ostream& oss = std::cout);

  /** inorder()
   * Prints the contents of the tree to the ostream using an in-order
   * traversal.
   */
  void inorder(std::ostream& oss = std::cout);

  /** postorder()
   * Prints the contents of the tree to the ostream using a post-order
   * traversal.
   */
  void postorder(std::ostream& oss = std::cout);
};

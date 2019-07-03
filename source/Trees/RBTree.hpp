#pragma once
#include <iostream>

/** Red-Black Node Class */
class Node {
 private:
  // A 1 is a red link and a 0 is a black link
  int data;
  bool color;
  Node* left;
  Node* right;

 public:
  ~Node() {}

  Node(int data = 0, bool color = true) : data(data), color(color) {
    left = right = nullptr;
  }

  friend class RBTree;
};

/** Red-Black Tree Class */
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
  Node* rotateRight(Node* node);
  Node* rotateLeft(Node* node);
  void flipColors(Node* node);
  Node* fix(Node* temp);
  Node* moveRedLeft(Node* temp);
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

  Node* deleteMax(Node* temp);
  Node* deleteMin(Node* temp);

  int min(Node* subtree, bool first);

 public:
  RBTree() { root = nullptr; };
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

  /** remove(int data)
   * Removes the given data from the tree, provided it exists.
   */
  void remove(int data) { remove(data, root); }

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

  void deleteMax();

  void deleteMin();
};

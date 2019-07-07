#pragma once

/** Node Class
 * These are the building blocks of the binary search tree.
 */
class Node {
 private:
  int data;

  Node* left;
  Node* right;

  int count;

  bool color;

 public:
  Node(int d, bool c = 1) : data(d), count(1), color(c) {
    left = right = nullptr;
  }
  ~Node() {}

  friend class BST;
  friend class RBTree;
};

#include "BST.hpp"

BST::BST() {
  root = nullptr;
}

BST::~BST() {}

Node* BST::insert(int data, Node* n) {
  if (!n) {
    return new Node(data);
  } else if (data < n->data) {
    n->left = insert(data, n->left);
  } else if (data > n->data) {
    n->right = insert(data, n->right);
  }
  return n;
}

void BST::insert(int data) {
  root = insert(data, root);
}

bool BST::is_empty() {
  return !root;
}

bool BST::search(int data, Node* n) {
  if (!n)
    return false;
  else if (data == n->data)
    return true;
  else if (data < n->data)
    return search(data, n->left);
  else
    return search(data, n->right);
}

bool BST::search(int data) {
  return search(data, root);
}

Node* BST::remove(int data, Node* n) {}

void BST::remove(int data) {}

int max(int a, int b) {
  return (a > b) ? a : b;
}
int BST::height(Node* n) {
  return (!n) ? -1 : 1 + max(height(n->left), height(n->right));
  if (!n)
    return -1;
  return 1 + max(height(n->left), height(n->right));
}

int BST::height() {
  return height(root);
}

void BST::clear(Node* n) {}

void BST::clear() {}

void BST::preorder(Node* n, std::ostream& oss) {}

void BST::preorder(std::ostream& oss) {}

void BST::inorder(Node* n, std::ostream& oss) {}

void BST::inorder(std::ostream& oss) {}

void BST::postorder(Node* n, std::ostream& oss) {}

void BST::postorder(std::ostream& oss) {}

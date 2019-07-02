#include "BST.hpp"

BST::BST() {
  root = nullptr;
}

BST::~BST() {
  clear(root);
}

Node* BST::insert(int data, Node* n) {
  if (!n) {
    return new Node(data);
  } else if (data < n->data) {
    n->left = insert(data, n->left);
  } else if (data > n->data) {
    n->right = insert(data, n->right);
  } else if (data == n->data) {
    n->count += 1;
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

Node* BST::remove(int data, Node* n) {
  if (!n) {
    return nullptr;

  } else if (data < n->data) {
    // Recurse down the left subtree.
    n->left = remove(data, n->left);

  } else if (data > n->data) {
    // Recurse down the right subtree.
    n->right = remove(data, n->right);

  } else if (!n->left && !n->right) {
    // Remove a leaf.
    delete n;
    n = nullptr;

  } else if (!n->left != !n->right) {
    // Remove a node with a single child.
    Node* rm = n;
    n = (n->left) ? n->left : n->right;
    delete rm;

  } else {
    // Remove a node with two children.
    Node* successor = n->right;
    while (successor->left) {
      successor = successor->left;
    }
    n->data = successor->data;
    n->right = remove(n->data, n->right);
  }
  return n;
}

void BST::remove(int data) {
  root = remove(data, root);
}

inline int max(int a, int b) {
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

void BST::clear(Node* n) {
  if (!n)
    return;
  clear(n->left);
  clear(n->right);
  delete n;
}

void BST::clear() {
  clear(root);
  root = nullptr;
}

void BST::preorder(Node* n, std::ostream& oss, bool dups) {
  if (!n)
    return;

  for (int i = 0; i < n->count; ++i) {
    oss << n->data << ", ";
    if (!dups)
      break;
  }

  preorder(n->left, oss, dups);
  preorder(n->right, oss, dups);
}

void BST::preorder(std::ostream& oss, bool dups) {
  preorder(root, oss, dups);
  oss << std::endl;
}

void BST::inorder(Node* n, std::ostream& oss, bool dups) {
  if (!n)
    return;
  inorder(n->left, oss, dups);

  for (int i = 0; i < n->count; ++i) {
    oss << n->data << ", ";
    if (!dups)
      break;
  }

  inorder(n->right, oss, dups);
}

void BST::inorder(std::ostream& oss, bool dups) {
  inorder(root, oss, dups);
  oss << std::endl;
}

void BST::postorder(Node* n, std::ostream& oss, bool dups) {
  if (!n)
    return;
  postorder(n->left, oss, dups);
  postorder(n->right, oss, dups);
  for (int i = 0; i < n->count; ++i) {
    oss << n->data << ", ";
    if (!dups)
      break;
  }
}

void BST::postorder(std::ostream& oss, bool dups) {
  postorder(root, oss, dups);
  oss << '\n';
}
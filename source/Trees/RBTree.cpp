#include "RBTree.hpp"

/** Author's Note
 * A large portion of this implementation is derived from Java source code
 * present in Robert Sedgewick's slides on Left-Leaning Red Black Trees,
 * (Avaialable here: https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf)
 * that has been translated into C++ and tweaked for the purposes of this
 * course/
 */

/** Destructor */
RBTree::~RBTree() {
  clear();
  root = nullptr;
}

/** RotateRight()
 * A method to rotate nodes in a RB tree in order to maintain balance
 */
Node* RBTree::rotateRight(Node* node) {
  Node* temp = node->left;
  node->left = temp->right;
  temp->right = node;
  temp->color = temp->right->color;
  temp->right->color = 1;
  return temp;
}

/** RotateLeft()
 * A method to rotate nodes in a RB tree in order to maintain balance
 */
Node* RBTree::rotateLeft(Node* node) {
  Node* temp = node->right;
  node->right = temp->left;
  temp->left = node;
  temp->color = temp->left->color;
  temp->left->color = 1;
  return temp;
}

/** FlipColors()
 * A method to flip the colors of a nodes links in order to maintain balance
 */
void RBTree::flipColors(Node* node) {
  node->color = !node->color;
  node->left->color = !node->left->color;
  node->right->color = !node->right->color;
}

/** Insert()
 * A method to insert keys into the trees
 */
Node* RBTree::insert(int data, Node* temp) {
  if (!temp) {
    return new Node(data, 1);
  }

  // recurse to bottom
  if (data < temp->data) {
    temp->left = insert(data, temp->left);
  } else if (data > temp->data) {
    temp->right = insert(data, temp->right);
  }

  return fix(temp);
}

void RBTree::insert(int data) {
  root = root ? insert(data, root) : new Node(data, 0);
}

/** Search()
 * A method to search a RBTree for a given key
 */
bool RBTree::search(int data, Node* n) {
  if (!n)
    return false;
  else if (data == n->data)
    return true;
  else if (data < n->data)
    return search(data, n->left);
  else
    return search(data, n->right);
}

/** Fix()
 * A method to fix the tree
 */
Node* RBTree::fix(Node* temp) {
  if (temp->right && temp->right->color) {
    temp = rotateLeft(temp);
  }

  if (temp->left && temp->left->color && temp->left->left &&
      temp->left->left->color) {
    temp = rotateRight(temp);
  }

  if (temp->left && temp->right && temp->left->color && temp->right->color) {
    flipColors(temp);
  }

  return temp;
}

/** moveRedLeft()
 * A method to aid in deleting a key
 */
Node* RBTree::moveRedLeft(Node* temp) {
  flipColors(temp);
  if (temp->right->left && temp->right->left->color) {
    temp->right = rotateRight(temp->right);
    temp = rotateLeft(temp);
    flipColors(temp);
  }
  return temp;
}

/** moveRedRight()
 * A method to aid in deleting a key
 */
Node* RBTree::moveRedRight(Node* temp) {
  flipColors(temp);
  if (temp->left->left && temp->left->left->color) {
    temp = rotateRight(temp);
    flipColors(temp);
  }
  return temp;
}

/** Delete the tree form the root */
void RBTree::deleteMax() {
  root = deleteMax(root);
  root->color = 0;
}

/** DeleteMax()
 * A method to aid in deleteing a key
 */
Node* RBTree::deleteMax(Node* temp) {
  if (temp->left && temp->left->color) {
    temp = rotateRight(temp);
  }

  if (temp->right == nullptr) {
    // delete temp;
    return nullptr;
  }

  if (temp->right && !temp->right->color && temp->right->left != nullptr &&
      !temp->right->left->color) {
    temp = moveRedRight(temp);
  }

  temp->left = deleteMax(temp->left);
  return fix(temp);
}

/** Delete the tree form the root */
void RBTree::deleteMin() {
  root = deleteMin(root, 1);
  // TODO: nullptr->color
  root->color = 0;
}

/** DeleteMax()
 * A method to aid in deleteing a key
 */
Node* RBTree::deleteMin(Node* temp, bool first = 1) {
  if (first) {
    deleteMin(temp->right, 0);
    return fix(temp);
  }

  if (temp->left == nullptr) {
    // delete temp;
    return nullptr;
  }

  if (temp->left && !temp->left->color && temp->left->left &&
      !temp->left->left->color) {
    temp = moveRedLeft(temp);
  }

  temp->left = deleteMin(temp->left, 0);
  return fix(temp);
}

/** Min()
 * A method to find the successor to a node, aids in deletion
 */
int RBTree::min(Node* subtree, bool first = 1) {
  if (first) {
    if (subtree->right != nullptr)
      return min(subtree->right, 0);
    else
      return subtree->left->data;
  }
  if (subtree->left == nullptr) {
    return subtree->data;
  }
  return min(subtree->left, 0);
}

/** Deletekey()
 * Delete a key in the tree with the given key
 */
Node* RBTree::remove(int data, Node* temp) {
  int comparison;
  if (temp->data == data) {
    comparison = 0;
  } else if (temp->data < data) {
    comparison = 1;
  } else {
    comparison = -1;
  }

  if (comparison < 0) {
    if (temp->left && !temp->left->color && temp->left->left &&
        !temp->left->left->color) {
      temp = moveRedLeft(temp);
    }
    temp->left = remove(data, temp->left);
  }

  else {
    if (temp->left != nullptr && temp->left->color) {
      temp = rotateRight(temp);
    }
    if (comparison == 0 && temp->right == nullptr) {
      // maybe delete here
      return nullptr;
    }

    if (temp->right != nullptr && !temp->right->color &&
        temp->right->left != nullptr && !temp->right->left->color) {
      temp = moveRedRight(temp);
    }

    if (comparison == 0) {
      temp->right->data = min(temp->right);
      temp->right = deleteMin(temp->right);
    } else {
      temp->right = remove(data, temp->right);
    }
  }
  return fix(temp);
}

void RBTree::preorder(std::ostream& oss) {
  preorder(root, oss);
  oss << std::endl;
}

void RBTree::preorder(Node* n, std::ostream& oss) {
  if (!n)
    return;
  oss << n->data << ", ";

  preorder(n->left, oss);
  preorder(n->right, oss);
}

void RBTree::inorder(Node* n, std::ostream& oss) {
  if (!n)
    return;
  inorder(n->left, oss);

  oss << n->data << ", ";

  inorder(n->right, oss);
}

void RBTree::inorder(std::ostream& oss) {
  inorder(root, oss);
  oss << std::endl;
}

void RBTree::clear() {
  clear(root);
}

void RBTree::clear(Node* n) {
  if (!n)
    return;
  clear(n->left);
  clear(n->right);
  delete n;
}

void RBTree::postorder(Node* n, std::ostream& oss) {
  if (!n)
    return;
  postorder(n->left, oss);
  postorder(n->right, oss);
  oss << n->data << ", ";
}

void RBTree::postorder(std::ostream& oss) {
  postorder(root, oss);
  oss << std::endl;
}

int RBTree::height() {
  return height(root);
}

int RBTree::height(Node* n) {
  if (n == nullptr)
    return -1;
  else {
    int leftsub = height(n->left);
    int rightsub = height(n->right);
    return ((leftsub < rightsub) ? rightsub : leftsub) + 1;
  }
}
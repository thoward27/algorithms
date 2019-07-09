#include "RBTree.hpp"

/** Author's Note
 * A large portion of this implementation is derived from Java source code
 * present in Robert Sedgewick's slides on Left-Leaning Red Black Trees,
 * (Avaialable here: https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf)
 * that has been translated into C++ and tweaked for the purposes of this
 * course/
 * These sources were also taken into account:
 * https://algs4.cs.princeton.edu/code/edu/princeton/cs/algs4/RedBlackBST.java.html
 * https://www.cs.princeton.edu/~rs/talks/LLRB/LLRB.pdf
 */

/** Destructor */
RBTree::~RBTree() {
  clear(root);
}

/** rotateRight()
 * A method to rotate nodes in an RBTree in order to maintain balance
 */
Node* RBTree::rotateRight(Node* node) {
  Node* temp = node->left;
  node->left = temp->right;
  temp->right = node;
  temp->color = temp->right->color;
  temp->right->color = 1;
  return temp;
}

/** rotateLeft()
 * A method to rotate nodes in an RBTree in order to maintain balance
 */
Node* RBTree::rotateLeft(Node* node) {
  Node* temp = node->right;
  node->right = temp->left;
  temp->left = node;
  temp->color = temp->left->color;
  temp->left->color = 1;
  return temp;
}

/** flipColors()
 * A method to flip the colors of a node's links in order to maintain balance
 */
void RBTree::flipColors(Node* node) {
  node->color = !node->color;
  node->left->color = !node->left->color;
  node->right->color = !node->right->color;
}

/** insert()
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

/** search()
 * A method to search an RBTree for a given key
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

/** fix()
 * A method to fix the tree
 */
Node* RBTree::fix(Node* temp) {
  if (isRed(temp->right)) {
    temp = rotateLeft(temp);
  }

  if (isRed(temp->left) && isRed(temp->left->left) ) {
    temp = rotateRight(temp);
  }

  if (isRed(temp->left) && isRed(temp->right) ) {
    flipColors(temp);
  }

  return temp;
}

/** moveRedLeft()
 * A method to aid in deleting a key
 */
Node* RBTree::moveRedLeft(Node* temp) {
  flipColors(temp);
  if (isRed(temp->right->left)) {
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

void RBTree::removeMax() {
  root = removeMax(root);
  if (root) root->color = 0;
}

Node* RBTree::removeMax(Node* temp) {
  if (isRed(temp->left)) {
    temp = rotateRight(temp);
  }

  if (!temp->right) {
    delete temp;
    return nullptr;
  }

  if (!isRed(temp->right) && !isRed(temp->right->left)) {
    temp = moveRedRight(temp);
  }

  temp->right = removeMax(temp->right);

  return fix(temp);
}

/** Delete the tree's min key from the root */
void RBTree::removeMin() {
  root = removeMin(root);
  if (root) root->color = 0;
}

/** removeMin()
 * A method to aid in deleting a key
 */
Node* RBTree::removeMin(Node* temp) {
  if(temp->left == nullptr) {
    delete temp;
    return nullptr;
  }

  if(!isRed(temp->left) && !isRed(temp->left->left) ) {
    temp = moveRedLeft(temp);
  }

  temp->left = removeMin(temp->left);

  return fix(temp);
}

/** max()
 * A method to find the maximum key.
 */
int RBTree::max(Node* subtree) {
  if (subtree->right == nullptr) return subtree->data;
  else return max(subtree->right);
}


/** min()
 * A method to find the successor to a node (minimum key). Aids in deletion.
 */
int RBTree::min(Node* subtree) {
  if (subtree->left == nullptr) return subtree->data;
  else return min(subtree->left);
}

/** remove()
 * Remove a key with the given data from the tree
 */
Node* RBTree::remove(int data, Node* temp) {
  if (data < temp->data) {
    if (!isRed(temp->left) && !isRed(temp->left->left) ) temp = moveRedLeft(temp);
    temp->left = remove(data, temp->left);
  }

  else {
    if(isRed(temp->left)) temp = rotateRight(temp);

    if(data == temp->data && (temp->right == nullptr)) {
        delete temp;
        return nullptr;
    }

    if(!isRed(temp->right) && !isRed(temp->right->left)) temp = moveRedRight(temp);

    if(data == temp->data) {
      temp->data = min(temp->right);
      temp->right = removeMin(temp->right);
    }
    else {
      temp->right = remove(data, temp->right);
    }
  }

  return fix(temp);
}

/** clear(Node* n)
 * Clear the subtree rooted at n
 */
void RBTree::clear(Node* n) {
  if (!n) return;
  clear(n->left);
  clear(n->right);
  delete n;
}

/** clear()
 * Clear the whole tree
 */
void RBTree::clear() {
  clear(root);
  root = nullptr;
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

/** height()
 * Find the height of the tree
 */
int RBTree::height(Node* n) {
  if (n == nullptr)
    return -1;
  else {
    int leftsub = height(n->left);
    int rightsub = height(n->right);
    return ((leftsub < rightsub) ? rightsub : leftsub) + 1;
  }
}

/** isRed()
 * Checks if a node is red. A null pointer is defined to not be red.
 */
bool RBTree::isRed(Node* n) {
  if(n == nullptr) return false;
  return n->color;
}
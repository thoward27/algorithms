#include "RBTree.hpp"
/** Author's Note
 * A large portion of this implementation is derived from Java source code
 * present in Robert Sedgewick's slides on Left-Leaning Red Black Trees,
 * (Avaialable here: https://www.cs.princeton.edu/~rs/talks/LLRB/RedBlack.pdf)
 * that has been translated into C++ and tweaked for the purposes of this course/
 */

/** Node Definitions */

/** Default Constructor */
RBNode::RBNode() {
    color = 0;
    key = 0;
    left = nullptr;
    right = nullptr;
}


/** Destructor */
RBNode::~RBNode() {
    //Nothing allocated dynamically, nothing to deallocate
}


/** Initialized Constructor */
RBNode::RBNode(int inkey,
               bool incolor,  
               RBNode * inleft, 
               RBNode * inright) {

    key = inkey;
    color = incolor;
    left = inleft;
    right = inright;
}



/** Tree Definitions */

/** Default Constructor */
RBTree::RBTree(){
    root = nullptr;
}


/** Destructor */
RBTree::~RBTree() {
    //do somfin
}


/** RotateRight()
 * A method to rotate nodes in a RB tree in order to maintain balance
 */
RBNode * RBTree::rotateRight(RBNode * node) {
    RBNode * temp = node->left;
    node->left = temp->right;
    temp->right = node;
    temp->color = temp->right->color;
    temp->right->color = 1;
    if(node == root) root = temp;
    return temp;
}


/** RotateLeft()
 * A method to rotate nodes in a RB tree in order to maintain balance
 */
RBNode * RBTree::rotateLeft(RBNode * node) {
    RBNode * temp = node->right;
    node->right = temp->left;
    temp->left = node;
    temp->color = temp->left->color;
    temp->left->color = 1;
    if(node == root) root = temp;
    return temp;
}


/** FlipColors()
 * A method to flip the colors of a nodes links in order to maintain balance
 */
void RBTree::flipColors(RBNode * node) {
    node->color = !node->color;
    node->left->color = !node->left->color;
    node->right->color = !node->right->color;
}


/** Insert()
 * A method to insert keys into the trees 
 */
RBNode * RBTree::insert(int keyvalue, RBNode * temp) {
    //if at bottom insert node
    if(!root) {
        RBNode * insertnode = new RBNode(keyvalue, 0);
        root = insertnode;
        return insertnode;
    }

    if(!temp) {
        RBNode * insertnode = new RBNode(keyvalue, 1);
        temp = insertnode;
        return insertnode;
    }

    //recurse to bottom
    if(keyvalue < temp->key) {
        temp->left = insert(keyvalue, temp->left);
    }
    else if(keyvalue > temp->key) {
        temp->right = insert(keyvalue, temp->right);
    }

    temp = fix(temp);
    
    return temp;
}


/** Search()
 * A method to search a RBTree for a given key
 */
bool RBTree::search(int deskey) {
    RBNode * trav = root;
    for( ; trav != nullptr ; ) {
        if(trav->key == deskey) {
            return true;
        }
        else if(trav->key > deskey) {
            trav = trav->left;
        }
        else if(trav->key < deskey) {
            trav = trav->right;
        }
    }
    return false;
}


/** Fix()
 * A method to fix the tree
 */
RBNode * RBTree::fix(RBNode * temp) {
    if(temp->right != nullptr && temp->right->color) {
        temp = rotateLeft(temp);
    }
    
    if(temp->left != nullptr && temp->left->color) {
        temp = rotateRight(temp);
    }

    if(temp->left && temp->right) {
        if(temp->left->color && temp->right->color) {
            flipColors(temp);
        }
    }

    return temp;
}


/** moveRedLeft()
 * A method to aid in deleting a key
 */
RBNode * RBTree::moveRedLeft(RBNode * temp) {
    flipColors(temp);
    if(temp->right->left != nullptr && temp->right->left->color) {
        temp->right = rotateRight(temp->right);
        temp = rotateLeft(temp);
        flipColors(temp);
    }
    return temp;
}


/** moveRedRight()
 * A method to aid in deleting a key
 */
RBNode * RBTree::moveRedRight(RBNode * temp) {
    flipColors(temp);
    if(temp->left->left != nullptr && temp->left->left->color) {
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
RBNode * RBTree::deleteMax(RBNode * temp) {
    if(temp->left != nullptr && temp->left->color) {
        temp = rotateRight(temp);
    }

    if(temp->right == nullptr) {
        delete temp;
        return nullptr;
    }

    if(temp->right != nullptr && temp->right->color) {
        temp = moveRedRight(temp->left);
    }
    return fix(temp);
}


/** Delete the tree form the root */
void RBTree::deleteMin() {
    root = deleteMin(root);
    root->color = 0;
}


/** DeleteMax()
 * A method to aid in deleteing a key
 */
RBNode * RBTree::deleteMin(RBNode * temp) {
    if(temp->left == nullptr) {
        delete temp;
        return nullptr;
    }

    if(temp->left != nullptr && temp->left->color && 
       temp->left->left != nullptr && temp->left->left->color) {
        temp = moveRedLeft(temp);
    }

    temp->left = deleteMin(temp->left);
    return fix(temp);
}


/** Min()
 * A method to find the successor to a node, aids in deletion
 */
int RBTree::min(RBNode * subtree, bool first = 1) {
    if(first) return min(subtree->right, 0);
    if(subtree->left == nullptr) return subtree->key;
    return min(subtree->left);
}


/** Deletekey() 
 * Delete a key in the tree with the given key
 */
RBNode * RBTree::deletekey(RBNode * temp, int delkey) {
   
    int comparison;
    if(temp->key == delkey) {
        comparison = 0;
    }
    else if(temp->key < delkey) {
        comparison = 1;
    }
    else {
        comparison = -1;
    }

    if(comparison < 0) {
        if(temp->left != nullptr && temp->left->color && 
           temp->left->left != nullptr && temp->left->left->color) {
            temp = moveRedLeft(temp);
        }
        temp->left = deletekey(temp->left, delkey);
    }
    
    else {
        if(temp->left && temp->left->color) temp = rotateRight(temp);

        if(comparison == 0 && temp->right == nullptr) {
            return nullptr;
        }

        if(temp->right != nullptr && temp->right->color && 
           temp->right->left != nullptr && temp->right->left->color) {
            temp = moveRedRight(temp);
        }

        if(comparison == 0) {
            temp->key = min(temp->right);
            temp->right = deleteMin(temp->right);
        }
        else {
            temp->right = deletekey(temp->right, delkey);
        }
    }
    return fix(temp);
}


/** getRoot()
 * Getter for root data member
 */
RBNode * RBTree::getRoot() {
    return root;
}
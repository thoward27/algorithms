#pragma once
#include <iostream>


/** Red-Black Node Class */
class RBNode {
    private:
        //A 1 is a red link and a 0 is a black link
        bool color;
        int key;
        RBNode * left;
        RBNode * right;

    public:
        RBNode();
        ~RBNode();

        RBNode(int inkey        = 0, 
               bool incolor     = false,
               RBNode * inleft  = nullptr, 
               RBNode * inright = nullptr);
        
        friend class RBTree;
};


/** Red-Black Tree Class */
class RBTree {
    private:
        RBNode * root;

        RBNode * rotateRight(RBNode * node);
        RBNode * rotateLeft(RBNode * node);
        void flipColors(RBNode * node);

    public:
        RBTree();
        ~RBTree();
        RBNode * insert(int keyvalue, RBNode * temp);
        bool search(int deskey);
        RBNode * fix(RBNode * temp);
        
        RBNode * moveRedLeft(RBNode * temp);
        RBNode * moveRedRight(RBNode * temp);
        
        void deleteMax();
        RBNode * deleteMax(RBNode * temp);

        void deleteMin();
        RBNode * deleteMin(RBNode * temp);
        int min(RBNode * subtree, bool first);
        RBNode * deletekey(RBNode * temp, int delkey);
        RBNode * getRoot();

};

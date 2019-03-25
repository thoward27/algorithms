#include "mancala.hpp"

#include <iostream>

/*
*  Pit Constructor
*/
Pit::Pit(int idx, int pieces) {
    index = idx;
    num_pieces = pieces;
    next = NULL;
}

/*
* Pit Destructor
*/
Pit::~Pit() {
    // No dynamic memory, nothing to deconstruct
}

/*
* MancalaSolver Constructor
*/
MancalaSolver::MancalaSolver() {
    head = NULL;
    curr = NULL;
    n_elem = 0;
}

/*
* MancalaSolver Destructor
*/
MancalaSolver::~MancalaSolver() {
    Pit* nptr = head;
    for (int i = 0; i < n_elem; i++) {
        head = head->next;
        delete nptr;
        nptr = head;
    }
}

/*
* The removeByIndex function receives a pit index and attempts
* to remove a pit with that index, returning the number of pieces
* that were in the removed pit. Return -1 if no pit is found.
*/
int MancalaSolver::removeByIndex(unsigned int idx) {
    // TODO: Implement removeByIndex
}

/*
* The append function receives an integer and inserts it at the
* end of the list
*/
void MancalaSolver::append(int idx, int pieces) {
    // TODO: Implement append
}

/*
* The solve function receives a starting index and solves Mancala
* Solitaire for this board, returning the index of the winning pit.
* After this function completes, the
*/
int MancalaSolver::solve(int idx) {
    // TODO: Implement solve
}

/*
* Returns the size of the linked list
*/
unsigned int MancalaSolver::getSize() {
    // TODO: Implement getSize
}

/*
* Prints the contents of the linked list in index:data format,
* along with the head and tail with their respective data
*
* Note: if the pointers from one Pit to another are not properly
* handled this method may fail or have unexpected results.
*/
void MancalaSolver::print() {
    Pit *n = head;
    for (int i = 0; i < n_elem; i++) {
        std::cout << n->index << ':' << n->num_pieces << std::endl;
        n = n->next;
    }
    if (head != NULL) std::cout << "Head:" << head->index << std::endl;
}
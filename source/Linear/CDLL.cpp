#include "LinkedList.hpp"

LinkedList::LinkedList() {}

LinkedList::~LinkedList() {}

unsigned int LinkedList::length() {}

void LinkedList::push_front(int d) {}

int LinkedList::pop_front() {}

int LinkedList::index(int data) {}

void LinkedList::push_back(int d) {}

int LinkedList::pop_back() {}

int LinkedList::at(int idx) {}

int LinkedList::set(int idx, int d) {}

void LinkedList::push(int d, int idx) {}

int LinkedList::pop(int idx) {}

void LinkedList::clear() {}

void LinkedList::remove(int d) {}

void LinkedList::reverse() {}

void LinkedList::print(std::ostream& oss) {
  Node* temp = head;
  while (temp) {
    oss << temp->data << ", ";
    temp = temp->next;
  }
  oss << std::endl;
  return;
}
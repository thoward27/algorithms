#include "Stack.hpp"

Stack::Stack() {
  list = new LinkedList();
}

Stack::~Stack() {
  delete list;
}

unsigned int Stack::size() {
  return list->length();
}

void Stack::push(int data) {
  list->push_front(data);
}

int Stack::pop() {
  return list->pop_front();
}

int Stack::top() {
  return list->at(0);
}

bool Stack::empty() {
  return list->length() == 0;
}

void Stack::clear() {
  list->clear();
}
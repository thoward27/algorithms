#include "Dequeue.hpp"

/** Constructor */
Dequeue::Dequeue() {
  list = new LinkedList();
  // Construction handled by LinkedList class
}

/** Destructor */
Dequeue::~Dequeue() {
  list->clear();
}

/** size() */
unsigned int Dequeue::size() {
  return list->length();
}

/** pushleft() */
void Dequeue::pushleft(int data) {
  list->push_front(data);
}

/** popleft() */
int Dequeue::popleft() {
  return list->pop_front();
}

/** pushright() */
void Dequeue::pushright(int data) {
  list->push_back(data);
}

/** popright() */
int Dequeue::popright() {
  return list->pop_back();
}

/** front() */
int Dequeue::front() {
  return list->at(0);
}

/** back() */
int Dequeue::back() {
  return list->at(list->length() - 1);
}

/** empty() */
bool Dequeue::empty() {
  return (list->length()) ? false : true;
}

/** clear() */
void Dequeue::clear() {
  list->clear();
}
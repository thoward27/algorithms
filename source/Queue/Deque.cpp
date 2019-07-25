#include "Deque.hpp"

/** Constructor */
Deque::Deque() {
  list = new LinkedList();
  // Construction handled by LinkedList class
}

/** Destructor */
Deque::~Deque() {
  delete list;
}

/** size() */
unsigned int Deque::size() {
  return list->length();
}

/** pushleft() */
void Deque::pushleft(int data) {
  list->push_front(data);
}

/** popleft() */
int Deque::popleft() {
  return list->pop_front();
}

/** pushright() */
void Deque::pushright(int data) {
  list->push_back(data);
}

/** popright() */
int Deque::popright() {
  return list->pop_back();
}

/** front() */
int Deque::front() {
  return list->at(0);
}

/** back() */
int Deque::back() {
  return list->at(list->length() - 1);
}

/** empty() */
bool Deque::empty() {
  return (list->length()) ? false : true;
}

/** clear() */
void Deque::clear() {
  list->clear();
}
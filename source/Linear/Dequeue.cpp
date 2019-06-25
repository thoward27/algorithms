#include "Dequeue.hpp"

/** Constructor */
Dequeue::Dequeue() {
  // Construction handled by LinkedList class
}

/** Destructor */
Dequeue::~Dequeue() {
  queue.clear();
}

/** size() */
unsigned int Dequeue::size() {
  return queue.length();
}

/** pushleft() */
void Dequeue::pushleft(int data) {
  queue.push_front(data);
}

/** popleft() */
int Dequeue::popleft() {
  return queue.pop_front();
}

/** pushright() */
void Dequeue::pushright(int data) {
  queue.push_back(data);
}

/** popright() */
int Dequeue::popright() {
  return queue.pop_back();
}

/** front() */
int Dequeue::front() {
  return queue.at(0);
}

/** back() */
int Dequeue::back() {
  return queue.at(queue.length() - 1);
}

/** empty() */
bool Dequeue::empty() {
  return (queue.length()) ? false : true;
}

/** clear() */
void Dequeue::clear() {
  queue.clear();
}
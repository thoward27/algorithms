#include "queue.hpp"

Queue::Queue() {
  head = nullptr;
  len = 0;
}

Queue::~Queue() {
  clear();
}

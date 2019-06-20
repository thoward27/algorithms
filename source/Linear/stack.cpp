#include "stack.hpp"

Stack::Stack() {
  head = nullptr;
  len = 0;
}

Stack::~Stack() {
  clear();
}

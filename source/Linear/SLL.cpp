#include "LinkedList.hpp"

LinkedList::LinkedList() {
  head = nullptr;
  len = 0;
}

LinkedList::~LinkedList() {
  clear();
}

unsigned int LinkedList::length() {
  return len;
}

void LinkedList::push_front(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = n;
  } else {
    n->next = head;
    head = n;
  }
  ++len;
}

int LinkedList::pop_front() {
  Node* to_remove = head;
  int rval = head->data;
  if (len == 1) {
    head = nullptr;
  } else {
    head = to_remove->next;
  }
  delete to_remove;
  --len;
  return rval;
}

int LinkedList::index(int data) {
  Node* temp = head;
  int i = 0;
  while (temp) {
    if (temp->data == data)
      return i;
    i += 1;
    temp = temp->next;
  }
  return -1;
}

void LinkedList::push_back(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = n;
  } else {
    Node* iter = head;
    while (iter->next) {
      iter = iter->next;
    }
    iter->next = n;
  }
  ++len;
}

int LinkedList::pop_back() {
  Node* to_remove;
  if (len == 1) {
    to_remove = head;
    head = nullptr;
  } else {
    Node* iter = head;
    while (iter->next->next) {
      iter = iter->next;
    }
    to_remove = iter->next;
    iter->next = nullptr;
  }
  int rval = to_remove->data;
  delete to_remove;
  --len;
  return rval;
}

int LinkedList::at(int idx) {
  // Handle negative indexes by making it positive.
  idx = (idx < 0) ? len + idx : idx;

  // Check for out of bounds.
  if (idx < 0 || (unsigned int)idx >= len)
    throw "Bad index";

  // Iterate to the element.
  Node* iter = head;
  for (int i = 0; i < idx; ++i) {
    iter = iter->next;
  }

  // Return it's data.
  return iter->data;
}

int LinkedList::set(int idx, int data) {
  // Handle negative indexes by making it positive.
  idx = (idx < 0) ? len + idx : idx;

  // Check for out of bounds.
  if (idx < 0 || (unsigned int)idx >= len)
    throw "Bad index";

  Node* iter = head;
  while (--idx >= 0) {
    iter = iter->next;
  }
  int old = iter->data;
  iter->data = data;
  return old;
}

void LinkedList::push(int d, int idx) {
  if (!idx) {
    push_front(d);
  } else if ((unsigned int)idx == len) {
    push_back(d);
  } else {
    Node* n = new Node(d);
    Node* iter = head;
    while (--idx > 0) {
      iter = iter->next;
    }
    n->next = iter->next;
    iter->next = n;
    ++len;
  }
}

int LinkedList::pop(int idx) {
  if (!idx) {
    return pop_front();
  } else if ((unsigned int)idx == len - 1) {
    return pop_back();
  } else {
    Node* iter = head;
    while (--idx > 0) {
      iter = iter->next;
    }
    Node* to_remove = iter->next;
    iter->next = to_remove->next;
    int ret = to_remove->data;
    delete to_remove;
    --len;
    return ret;
  }
}

void LinkedList::clear() {
  Node* to_remove;
  while (head) {
    to_remove = head;
    head = head->next;
    delete to_remove;
  }
  len = 0;
}

void LinkedList::remove(int d) {
  if (head && head->data == d)
    pop_front();
  else {
    Node* iter = head;
    while (iter->next) {
      if (iter->next->data == d) {
        Node* to_remove = iter->next;
        iter->next = to_remove->next;
        delete to_remove;
        --len;
        break;
      } else {
        iter = iter->next;
      }
    }
  }
}

void LinkedList::reverse() {
  if (len <= 1)
    return;
  Node* prev = nullptr;
  Node* curr = head;
  Node* next;
  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head = prev;
}

void LinkedList::print(std::ostream& oss) {
  Node* temp = head;
  while (temp) {
    oss << temp->data << ", ";
    temp = temp->next;
  }
  oss << std::endl;
  return;
}
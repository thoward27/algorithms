#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "SLL.hpp"

SLL::SLL() {
  head = nullptr;
  len = 0;
}

SLL::~SLL() {
  clear();
}


int SLL::front() {
  return head->data;
}

int SLL::length() {
  return len;
}


void SLL::push_front(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = n;
  } else {
    n->next = head;
    head = n;
  }
  ++len;
}

int SLL::pop_front() {
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

void SLL::push_back(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = n;
  } else {
    Node *iter = head;
    while (iter->next) {
      iter = iter->next;
    }
    iter->next = n;
  }
  ++len;
}

int SLL::pop_back() {
  Node* to_remove;
  if (len == 1) {
    to_remove = head;
    head = nullptr;
  } else {
    Node *iter = head;
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

int SLL::at(int idx) {
  Node* iter = head;
  while (--idx >= 0) {
    iter = iter->next;
  }
  return iter->data;
}

int SLL::set(int d, int idx) {
  Node* iter = head;
  while (--idx >= 0) {
    iter = iter->next;
  }
  int old = iter->data;
  iter->data = d;
  return old;
}

void SLL::insert(int d, int idx) {
  if (!idx) {
    push_front(d);
  } else if (idx == len) {
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

void SLL::erase(int idx) {
  if (!idx) {
    pop_front();
  } else if (idx == len - 1) {
    pop_back();
  } else {
    Node* iter = head;
    while (--idx > 0) {
      iter = iter->next;
    }
    Node* to_remove = iter->next;
    iter->next = to_remove->next;
    delete to_remove;
    --len;
  }
}

void SLL::clear() {
  Node* to_remove;
  while (--len >= 0) {
    to_remove = head;
    head = head->next;
    delete to_remove;
  }
  len = 0;
}


void SLL::remove(int d) {
  while (head && head->data == d) {
    pop_front();
  }
  if (!len) return;
  Node* to_remove;
  Node* iter = head;
  while (iter->next) {
    if (iter->next->data == d) {
      to_remove = iter->next;
      iter->next = to_remove->next;
      delete to_remove;
      --len;
    } else {
      iter = iter->next;
    }
  }
}

void SLL::unique() {
  Node* iter = head;
  int i = 0;
  int data;
  while (iter && iter->next) {
    if (iter->data > 0) {
      data = set(iter->data - 1, i);
    } else {
      data = set(iter->data + 1, i);
    }
    remove(data);
    set(data, i);
    ++i;
    iter = iter->next;
  }
}

void SLL::reverse() {
  if (len <= 1) return;
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

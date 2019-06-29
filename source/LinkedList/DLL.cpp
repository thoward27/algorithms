#include "LinkedList.hpp"

LinkedList::LinkedList() {
  head = tail = nullptr;
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
    head = tail = n;
  } else {
    n->next = head;
    head->prev = n;
    head = n;
  }
  ++len;
}

int LinkedList::pop_front() {
  if (!head)
    throw "Nothing to pop";
  Node* to_remove = head;
  int rval = head->data;
  if (len == 1) {
    head = tail = nullptr;
  } else {
    head->next->prev = nullptr;
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
  if (!tail) {
    head = tail = n;
  } else {
    n->prev = tail;
    tail->next = n;
    tail = n;
  }
  ++len;
}

int LinkedList::pop_back() {
  if (!head)
    throw "Nothing to pop";
  Node* to_remove = tail;
  int rval = tail->data;
  if (len == 1) {
    head = tail = nullptr;
  } else {
    tail->prev->next = nullptr;
    tail = to_remove->prev;
  }
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

  // Iterate to the element from the head or tail, whichever is closer.
  Node* iter;
  if ((unsigned int)idx < len / 2) {
    iter = head;
    while (--idx >= 0) {
      iter = iter->next;
    }
  } else {
    iter = tail;
    while (++idx < (int)len) {
      iter = iter->prev;
    }
  }

  // Return its data.
  return iter->data;
}

int LinkedList::set(int idx, int d) {
  // Handle negative indexes by making it positive.
  idx = (idx < 0) ? len + idx : idx;

  // Check for out of bounds.
  if (idx < 0 || (unsigned int)idx >= len)
    throw "Bad index";

  Node* iter;
  if ((unsigned int)idx < len / 2) {
    iter = head;
    while (--idx >= 0) {
      iter = iter->next;
    }
  } else {
    iter = tail;
    while (++idx < (int)len) {
      iter = iter->prev;
    }
  }

  int old = iter->data;
  iter->data = d;
  return old;
}

void LinkedList::push(int d, int idx) {
  if (!idx) {
    push_front(d);
  } else if ((unsigned int)idx == len) {
    push_back(d);
  } else {
    Node* n = new Node(d);
    Node* iter;
    if ((unsigned)idx < len / 2) {
      iter = head;
      while (--idx > 0) {
        iter = iter->next;
      }
    } else {
      iter = tail;
      while (++idx <= (int)len) {
        iter = iter->prev;
      }
    }
    n->next = iter->next;
    n->prev = iter;
    iter->next = n;
    n->next->prev = n;
    ++len;
  }
}

int LinkedList::pop(int idx) {
  if (!idx) {
    return pop_front();
  } else if ((unsigned int)idx == len - 1) {
    return pop_back();
  } else {
    Node* iter;
    if ((unsigned)idx < len / 2) {
      iter = head;
      while (--idx > 0) {
        iter = iter->next;
      }
    } else {
      iter = tail;
      while (++idx <= (int)len) {
        iter = iter->prev;
      }
    }
    Node* to_remove = iter->next;
    iter->next = to_remove->next;
    iter->next->prev = iter;
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
  tail = nullptr;
  len = 0;
}

void LinkedList::remove(int d) {
  if (head && head->data == d) {
    pop_front();
  } else {
    Node* iter = head;
    while (iter->next) {
      if (iter->next->data == d) {
        Node* to_remove = iter->next;
        iter->next = to_remove->next;
        iter->next->prev = iter;
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
    curr->prev = next;
    prev = curr;
    curr = next;
  }
  tail = head;
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
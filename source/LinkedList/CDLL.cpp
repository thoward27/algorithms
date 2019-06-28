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
    n->next = n;
    n->prev = n;
  } else {
    n->next = head;
    n->prev = head->prev;
    n->prev->next = n;
    head->prev = n;
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
    head->next->prev = head->prev;
    head->prev->next = head->next;
    head = to_remove->next;
  }
  delete to_remove;
  --len;
  return rval;
}

int LinkedList::index(int data) {
  if (!len)
    return -1;
  Node* temp = head;
  int i = 0;
  do {
    if (temp->data == data)
      return i;
    i += 1;
    temp = temp->next;
  } while (temp != head);
  return -1;
}

void LinkedList::push_back(int d) {
  Node* n = new Node(d);
  if (!head) {
    head = n;
    n->prev = n;
    n->next = n;
  } else {
    n->next = head;
    n->prev = head->prev;
    n->prev->next = n;
    head->prev = n;
  }
  ++len;
}

int LinkedList::pop_back() {
  Node* to_remove = head->prev;
  int rval = to_remove->data;
  if (len == 1) {
    head = nullptr;
  } else {
    head->prev = to_remove->prev;
    to_remove->prev->next = head;
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
  Node* iter = head;
  if ((unsigned int)idx <= len / 2) {
    while (--idx >= 0) {
      iter = iter->next;
    }
  } else {
    iter = iter->prev;
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

  Node* iter = head;
  if ((unsigned int)idx <= len / 2) {
    while (--idx >= 0) {
      iter = iter->next;
    }
  } else {
    iter = iter->prev;
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
    Node* iter = head;
    if ((unsigned int)idx < len / 2) {
      while (--idx > 0) {
        iter = iter->next;
      }
    } else {
      iter = iter->prev;
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
    Node* iter = head;
    if ((unsigned int)idx < len / 2) {
      while (--idx > 0) {
        iter = iter->next;
      }
    } else {
      iter = iter->prev;
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
  ++len;
  while (--len) {
    to_remove = head;
    head = head->next;
    delete to_remove;
  }
  head = nullptr;
}

void LinkedList::remove(int d) {
  if (len > 0 && head->data == d) {
    pop_front();
  } else if (!len) {
    return;
  } else {
    Node* iter = head;
    do {
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
    } while (iter != head);
  }
}

void LinkedList::reverse() {
  if (len <= 1)
    return;
  Node* prev = head->prev;
  Node* curr = head;
  Node* next;
  do {
    next = curr->next;
    curr->next = prev;
    curr->prev = next;
    prev = curr;
    curr = next;
  } while (curr != head);
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
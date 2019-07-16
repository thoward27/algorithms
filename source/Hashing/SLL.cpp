#include "LinkedList.hpp"

Node::Node() {
  key = new String();
  val = 0;
  next = prev = nullptr;
}

Node::Node(const String &k, int v) {
  key = new String(k.cstr());
  val = v;
  next = prev = nullptr;
}

Node::~Node() {
  delete key;
}

List::List() {
  head = nullptr;
  len = 0;
}

List::~List() {
  clear();
}

unsigned int List::length() {
  return len;
}



int List::index(String& d) {
  int i = 0;
  for (Node* iter = head; iter; iter = iter->next, ++i) {
    if (iter->key->compare(d) == 1)
      return i;
  }
  return -1;
}

void List::push_back(const String& key, int val) {
  Node* n = new Node(key, val);
  if (!head) {
    head = n;
  } else {
    Node* iter = head;
    while (iter->next)
      iter = iter->next;

    iter->next = n;
  }
  ++len;
  return;
}

void List::clear() {
  Node* to_remove;
  while (head) {
    to_remove = head;
    head = head->next;
    delete to_remove;
  }
  len = 0;
}

void List::remove(String& d) {
  if (!head)
    throw "Nothing to remove";
  else if (head->key->compare(d)) {
    Node* temp = head;
    head = head->next;
    --len;
    delete temp;
  }
  else {
    for (Node* iter = head; iter->next; iter = iter->next) {
      if (iter->next->key->compare(d) == 1) {
        Node* to_remove = iter->next;
        iter->next = to_remove->next;
        delete to_remove;
        --len;
        break;
      }
    }
  }
}

int List::at(int ind) {
  Node* iter = head;
  for(int i = 0 ; i < ind ; ++i) {
    iter = iter->next;
  }
  return iter->val;
}

void List::print(std::ostream& oss) {
  std::cout << "Length " << len << std::endl;
  Node* temp = head;
  while (temp) {
    oss << temp->val << ", "; 
    temp->key->print(); 
    std::cout << std::endl;
    temp = temp->next;
  }
  oss << std::endl;
  return;
}
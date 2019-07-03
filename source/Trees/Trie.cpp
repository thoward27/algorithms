#include "Trie.hpp"

Trie::Trie() {
  root = new Node(0, false);
  size = 0;
}

Trie::~Trie() {
  clear();
}

void Trie::insert(const char* word, int val) {
  int i = 0;
  int idx;
  Node* n = root;
  while (word[i]) {
    idx = word[i] - 'a';
    if (n->children[idx]) {
      n = n->children[idx];
    } else {
      Node* next = new Node(0, false);
      n->children[idx] = next;
      n = n->children[idx];
    }
    ++i;
  }
  n->end_of_word = true;
  n->value = val;
  ++size;
}

int Trie::count() {
  return size;
}

bool Trie::search(const char* word) {
  int i = 0;
  int idx;
  Node* n = root;
  while (word[i]) {
    idx = word[i] - 'a';
    if (!(n->children[idx]))
      return false;
    n = n->children[idx];
    ++i;
  }
  if (n->end_of_word)
    return true;
  else
    return false;
}

int Trie::get(const char* word) {
  int i = 0;
  int idx;
  Node* n = root;
  while (word[i]) {
    idx = word[i] - 'a';
    if (!(n->children[idx]))
      throw "Key not found.";
    n = n->children[idx];
    ++i;
  }
  if (n->end_of_word)
    return n->value;
  else
    throw "Key not found.";
}

// TODO: Fix erroneous implementation
void Trie::remove(const char* word) {
  if (!*word) throw "Attempted to remove empty string";
  int i = 0;
  int idx;
  Node* n = root;
  Node* prev = nullptr;
  Node* next;
  do {
    idx = word[i] - 'a';
    if (!(n->children[idx]))
      throw "Key not found.";
    next = n->children[idx];
    n->children[idx] = prev;
    prev = n;
    n = next;
  } while (word[++i]);

  if (!(prev->end_of_word)) {
    throw "Key not found.";
  }

  if (n) {
    prev->end_of_word = false;
  } else {
    bool suffix = true;
    do {
      n = prev;
      prev = n->children[word[--i] - 'a'];
      for (int j = 0; j < 26; ++j) {
        if (n->children[j]) {
          suffix = false;
          break;
        }
      }
      delete n;
    } while (suffix);
  }
}

void Trie::clear() {

}

void Trie::print(std::ostream& oss) {

}
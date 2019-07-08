#include "Trie.hpp"

Trie::Trie() {
  root = new Node(0, false);
  size = 0;
  max_height = 0;
}

Trie::~Trie() {
  clear(root);
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
  if (i > max_height) {
    max_height = i;
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

void Trie::clear(Node* n) {
  for (int i = 0; i < 26; ++i) {
    if (n->children[i]) {
      clear(n->children[i]);
    }
  }
  delete n;
}

void Trie::clear() {
  clear(root);
  root = new Node(0, false);
  size = 0;
  max_height = 0;
}

void Trie::print(std::ostream& oss, Node* n, char* letters, int level) {
  if (n->end_of_word) {
    letters[level] = '\0';
    oss << letters << ' ' << n->value << std::endl;
  }

  for (int i = 0; i < 26; ++i) {
    if (n->children[i]) {
      letters[level] = 'a' + i;
      print(oss, n->children[i], letters, level + 1);
    }
  }
}

void Trie::print(std::ostream& oss) {
  char* letters = new char[max_height + 1];
  print(oss, root, letters, 0);
  delete [] letters;
}
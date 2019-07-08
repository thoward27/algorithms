#include "Trie.hpp"

Trie::Trie() {
  root = new Node(0, false);
  size = 0;
  height_upper_bound = 0;
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
  if (i > height_upper_bound) {
    height_upper_bound = i;
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

Node* Trie::remove(const char *word, Node *n) {
  if (!word[0]) {
    if (!n->end_of_word) throw "Key not found.";
    n->end_of_word = false;
    --size;
  } else {
    if (!n) throw "Key not found.";
    int idx = word[0] - 'a';
    n->children[idx] = remove(word + 1, n->children[idx]);
  }
  if (!n->end_of_word) {
    bool deletable = true;
    for (int i = 0; i < 26; ++i) {
      if (n->children[i]) {
        deletable = false;
        break;
      }
    }
    if (deletable) {
      delete n;
      return nullptr;
    }
  }
  return n;
}

void Trie::remove(const char* word) {
  root = remove(word, root);
  if (!root) root = new Node(0, false);
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
  height_upper_bound = 0;
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
  char* letters = new char[height_upper_bound + 1];
  print(oss, root, letters, 0);
  delete [] letters;
}
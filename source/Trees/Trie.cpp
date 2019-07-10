#include "Trie.hpp"

Trie::Trie() {
  root = new Node(0, false);
  size = 0;
}

Trie::~Trie() {
  clear(root);
}

int Trie::count() {
  return size;
}

void Trie::put(const char* word, int val) {
  int idx;
  Node* n = root;
  for (int i = 0; word[i]; ++i) {
    idx = word[i] - 'a';
    if (n->children[idx]) {
      n = n->children[idx];
    } else {
      Node* next = new Node(0, false);
      n->children[idx] = next;
      n = n->children[idx];
    }
  }
  n->end_of_word = true;
  n->value = val;
  ++size;
}

bool Trie::search(const char* word) {
  Node* n = root;
  for (int i = 0; word[i]; ++i) {
    if (!(n->children[word[i] - 'a']))
      return false;
    else
      n = n->children[word[i] - 'a'];
  }
  if (n->end_of_word)
    return true;
  else
    return false;
}

int Trie::get(const char* word) {
  Node* n = root;
  for (int i = 0; word[i]; ++i) {
    if (n->children[word[i] - 'a'])
      n = n->children[word[i] - 'a'];
    else
      throw "Key not found.";
  }
  if (n->end_of_word)
    return n->value;
  else
    throw "Key not found.";
}

Node* Trie::remove(const char* word, Node* n) {
  if (!word[0]) {
    if (!n->end_of_word)
      throw "Key not found.";
    n->end_of_word = false;
    --size;
  } else {
    if (!n)
      throw "Key not found.";
    int idx = word[0] - 'a';
    n->children[idx] = remove(word + 1, n->children[idx]);
  }
  if (!n->end_of_word) {
    if (!n->any()) {
      delete n;
      return nullptr;
    }
  }
  return n;
}

void Trie::remove(const char* word) {
  root = remove(word, root);
  if (!root)
    root = new Node(0, false);
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
}

void Trie::print(std::ostream& oss, Node* n, String& letters) {
  if (n->end_of_word) {
    oss << letters << ' ' << n->value << std::endl;
  }

  for (int i = 0; i < 26; ++i) {
    if (n->children[i]) {
      letters.append('a' + i);
      print(oss, n->children[i], letters);
      letters.clear();
    }
  }
}

void Trie::print(std::ostream& oss) {
  String letters;
  print(oss, root, letters);
}
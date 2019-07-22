#include "Hashtable.hpp"

int HashTable::hash(const String& key) {
  int hash = 0;
  for (unsigned int i = 0; i < key.size(); ++i) {
    hash = (hash * 7) + key.at(i);
  }
  return hash % m;
}

unsigned int HashTable::elements() const {
  return n;
}

void HashTable::grow() {
  List* newtable = new List[m * 2];
  for (unsigned int i = 0; i < m; ++i) {
    Node* n = table[i].top();
    newtable[hash(*(n->key))].push(*(n->key), n->val);
    table[i].pop();
  }
  delete[] table;
  table = newtable;
  m *= 2;
}

void HashTable::shrink() {
  unsigned int old_m = m;
  m = m/2 + 1; // May need to divide by m later, so ensure m > 0
  List* newtable = new List[m];
  for (unsigned int i = 0; i < old_m; ++i) {
    while (!table[i].empty()) {
      Node *node = table[i].top();
      newtable[hash(*(node->key))].push(*(node->key), node->val);
      table[i].pop();
    }
  }
  delete[] table;
  table = newtable;
}

void HashTable::insert(const String& key, int data) {
  int h = hash(key);
  if (table[h].index(key) == -1) {
    table[h].push(key, data);
    n++;
  } else {
    table[h].update(key, data);
  }

  if (n / m >= 8)
    grow();
}

void HashTable::remove(String& key) {
  table[hash(key)].remove(key);
  --n;

  if (n / m <= 2)
    shrink();
}

bool HashTable::search(String& key) {
  if (table[hash(key)].index(key) >= 0)
    return true;
  else
    return false;
}

int HashTable::get(String& key) {
  return table[hash(key)].get(key);
}

bool HashTable::is_empty() {
  for (unsigned int i = 0; i < m; ++i) {
    if (table[i].length() != 0)
      return false;
  }
  return true;
}

void HashTable::print(std::ostream& oss) {
  for (unsigned int i = 0; i < m; ++i) {
    oss << "Row: " << i << " => ";
    table[i].print(oss);
    oss << std::endl;
  }
}
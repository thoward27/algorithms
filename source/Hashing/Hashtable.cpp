#include "Hashtable.hpp"

HashTable::HashTable() {
    size = 5;
    table = new List[size];
}

HashTable::HashTable(int indices) {
    size = indices;
    table = new List[indices];
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hash(const String& key) {
    int hash = 0;
    for (int i = 0; i < key.size(); ++i) {
        int ascii = key.at(i) - '0';
        hash = (hash * 7) + ascii;
    }

    return hash % size;
}

unsigned int HashTable::Size() {
    return size;
}

void HashTable::insert(const String& key, int data) {
    if (table[hash(key)].length() > 8) {
        List* newTable = new List[size * 2];
        int oldsize = size;
        size *= 2;
        for (int i = 0; i < oldsize; ++i) {
            Node* iter = table[i].head;
            while (iter) {
                int val = iter->val;
                String* k = iter->key;
                newTable[hash(*k)].push_back(key, val);
                iter = iter->next;
            }
        }
        delete[] table;
        table = newTable;
    }
    table[hash(key)].push_back(key, data);
}

void HashTable::remove(String& key) {
    table[hash(key)].remove(key);
}

bool HashTable::search(String& key) {
    if (table[hash(key)].index(key) >= 0) return true;
    else return false;
}

int HashTable::get(String& key) {
    return table[hash(key)].at(table[hash(key)].index(key));
}

bool HashTable::is_empty() {
    for (int i = 0; i < size; ++i) {
        if (table[i].length() != 0) return false;
    }
    return true;
}

void HashTable::print(std::ostream& oss) {
    for (int i = 0; i < size; ++i) {
        table[i].print(oss);
    }
}
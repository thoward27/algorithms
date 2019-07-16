#include "Hashtable.hpp"

/** Default constructor */
HashTable::HashTable() {
    size = 5;
    table = new List[size];
}


/** Destructor */
HashTable::~HashTable() {
    delete[] table;
}


/** Hash function
 * Calculates and returns the hash value of the given data
 * This version is rather simple and mods values by the size of the table
 */
int HashTable::hash(const String& key) {
    unsigned total = 0;
    for(unsigned i = 0; i < key.size() ; ++i) {
        total += key.at(i);
    }
    return (total % size);
}


/** Initialized Constructor */
HashTable::HashTable(int indices) {
    size = indices;
    table = new List[size];
}


/** Size Method
 * A Method to return the number of chains in the table
 */
unsigned int HashTable::Size() {
    return size;
}


/** Insert Method
 * Insert a value into the hashtable by cacluating its hash and 
 * adding it to the linked list at the index
 */
void HashTable::insert(const String& key, int data) {
    //do table doubling
    table[hash(key)].push_back(key, data);
}


/** Remove method
 * Remove a value from the hashtable using the linked list deletion method
 */
void HashTable::remove(String& key) {
    table[hash(key)].remove(key);
}

/** Search Method
 * Search a Hashtable for the given value 
 * return true if the value is found in the table
 * return false otherwise
 */
bool HashTable::search(String& key) {
    if(table[hash(key)].index(key) == -1) return false;
    return true;
}

/** Get Method
 * A method to get the value associated with the given key
 */
int HashTable::get(String& key) {
    int tableind = table[hash(key)].index(key);
    if(tableind < 0) {
        throw "";
    }
    return table[hash(key)].at(tableind);
}

/** Is Empty Method
 * Returns true if the hashtable has no keys in it
 */
bool HashTable::is_empty() {
    for(unsigned int i = 0 ; i < size ; ++i) {
        if(table[i].length()) return false;
    }
    return true;
}

void HashTable::print() {
    for(unsigned int i = 0 ; i < size ; ++i) {
        table[i].print();
    }
}  
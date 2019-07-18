#pragma once
#include <iostream>
#include "../String/String.hpp"
#include "LinkedList.hpp"

class HashTable {
 private:
  unsigned int m;
  unsigned int n;
  List* table;

  /** hash(String key)
   * Calculates the simple modular hash of a string being:
   * (sum of ascii values for each character) % (size data member)
   */
  int hash(const String& key);

  /** grow()
   * Doubles the size of the table.
   */
  void grow();

  /** shrink()
   * Halves the size of the table.
   */
  void shrink();

 public:
  HashTable() : m(5), n(0) { table = new List[m]; }
  ~HashTable() { delete[] table; }

  HashTable(int m) : m(m), n(0) { table = new List[m]; }

  /** size()
   * Returns the number of rows in the table.
   */
  unsigned int size() const { return m; }

  /** elements()
   * Returns the number of elements in the table.
   */
  unsigned int elements() const;

  /** insert(String key, int data)
   * Insert the value of data into the chain at index hash(key)
   */
  void insert(const String& key, int data);

  /** remove(String key)
   * Removes the first instance of the given key from the chain located at
   * hash(key)
   */
  void remove(String& key);

  /** search(String key)
   * Returns true if it found an instance of the key at index hash(key) false
   * otherwise
   */
  bool search(String& key);

  /** get(String key)
   * Returns the integer value associated with the given key from the key/value
   * pair
   */
  int get(String& key);

  /** is_empty()
   * Returns true if all chains are of length 0 indicating them being empty,
   * returns false otherwise
   */
  bool is_empty();

  /** print()
   * Calls the Linked List print() method on each of its chains
   */
  void print(std::ostream& oss = std::cout);
};
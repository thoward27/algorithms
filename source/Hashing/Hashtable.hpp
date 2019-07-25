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
   *
   * Inputs:
   * @param key: A string to calculate the hash of
   *
   * Outputs:
   * The calculated hash value of key, used for indexing within the table
   *
   * Examples:
   * hash("Hello World") == 5 //this value is arbitrary the actual hash
   *                            for "Hello World" will likely not be 5
   *
   * Runtime:
   * O(?)
   */
  int hash(const String& key);

  /** grow()
   * Doubles the size of the table.
   *
   * Side Effects:
   * Doubles the number of chains in the hash table, used when table
   * becomes too loaded
   *
   * Runtime:
   * O(?)
   */
  void grow();

  /** shrink()
   * Halves the size of the table.
   *
   * Side Effects:
   * Halves the number of chains in the hash table, used when table
   * becomes becomes less loaded
   *
   * Runtime:
   * O(?)
   */
  void shrink();

 public:
  HashTable() : m(5), n(0) { table = new List[m]; }
  ~HashTable() { delete[] table; }

  explicit HashTable(int m) : m(m), n(0) { table = new List[m]; }

  /** size()
   * Returns the number of rows in the table.
   *
   * Outputs:
   * The value of internal data member m : the number of chains in the table
   *
   * Examples:
   * Hashtable test(10)
   * test.size() == 10
   *
   * Runtime:
   * O(1)
   */
  unsigned int size() const { return m; }

  /** elements()
   * Returns the number of elements in the table.
   *
   * Outputs:
   * The sum of the lengths of each chain in the table
   *
   * Examples:
   * Hashtable test(10)
   * test.insert("Hello", 1)
   * test.insert("World", 2)
   * test.elements() == 2
   *
   * Runtime:
   * O(1)
   */
  unsigned int elements() const;

  /** insert(String key, int data)
   * Insert the value of data into the chain at index hash(key)
   *
   * Inputs:
   * @param key: A string to calculate the hash for
   * @param data: Value to assign to that key
   *
   * Side Effects:
   * Inserts data at hashtable[hash(key)]
   *
   * Examples:
   * Hashtable test(10)
   * test.insert("Hello", 1)
   *
   * Runtime:
   * O(1)
   */
  void insert(const String& key, int data);

  /** remove(String key)
   * Removes the first instance of the given key from the chain located at
   * hash(key)
   *
   * Inputs:
   * @param key: A string to calculate the hash for
   *
   * Side Effects:
   * Removes the first occurrence of key in table[hash(key)]
   *
   * Examples:
   * Hashtable test(10)
   * test.insert("Hello", 1)
   * test.remove("Hello")
   *
   * Runtime:
   * O(1) //dependant on backing Linked List implementation
   */
  void remove(String& key);

  /** search(String key)
   * Returns true if it found an instance of the key at index hash(key) false
   * otherwise
   *
   * Inputs:
   * @param key: key to search for
   *
   * Outputs:
   * True if key found in the chain at table[hash(key)]
   * False otherwise
   *
   * Examples:
   * Hashtable test(10)
   * test.insert("Hello", 1)
   * test.search("Hello") == 1
   * test.search("World") == 0
   *
   * Runtime:
   * O(n)
   */
  bool search(String& key);

  /** get(String key)
   * Returns the integer value associated with the given key from the key/value
   * pair
   *
   * Inputs:
   * @param key: key to look for value of
   *
   * Outputs:
   * Value associated with key within the chain at table[hash(key)]
   *
   * Examples:
   * Hashtable test(10)
   * test.insert("Hello", 12)
   * test.get("Hello") == 12
   *
   * Runtime:
   * O(n)
   */
  int get(String& key);

  /** is_empty()
   * Returns true if all chains are of length 0 indicating them being empty,
   * returns false otherwise
   *
   * Outputs:
   * True when all chains are of length 0
   * False otherwise
   *
   * Examples:
   * Hashtable test(10)
   * test.is_empty() == 1
   * test.insert("hello", 1)
   * test.is_empty() == 0
   *
   * Runtime:
   * O(1) // dependant on Linked List implementation
   */
  bool is_empty();

  /** print()
   * Calls the Linked List print() method on each of its chains
   *
   * Side Effects:
   * Prints the contents of each chain to cout
   *
   * Runtime:
   * O(n)
   */
  void print(std::ostream& oss = std::cout);
};
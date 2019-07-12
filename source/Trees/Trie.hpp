#pragma once
#include <iostream>

#include "../String/String.hpp"

/** Node Class
 * These are the building blocks of the trie.
 */
class Node {
 private:
  const static unsigned short R = 26;
  Node* children[R] = {nullptr};
  int value;
  bool end_of_word;

 public:
  Node(int d, bool eow) : value(d), end_of_word(eow) {}
  ~Node() {}

  friend class Trie;
};

/** Trie (Prefix Tree)
 * A class that stores strings and associated ints as a tree of letter nodes,
 * where each path down the tree contains the letters of a string or substring.
 * The value associated with the string is stored in the node representing the
 * last letter of the string.
 * If the value of a Node is null the string is not in the tree.
 * Allows for efficient put and search/data access methods.
 * Assumes all words are lowercase.
 */
class Trie {
 private:
  Node* root;
  int size;

  /** remove(const char* word, Node* n)
   * Recursively searches the Trie for word, and then deletes every node used
   * exclusively by that word (i.e. all nodes with end_of_word false and all
   * null pointers in children array coming out of recursion).
   * Returns null if n was deleted, and n otherwise
   */
  Node* remove(const char* word, Node* n);

  /** clear(Node* n)
   * Recursively deletes all of the nodes in the subtree rooted at n, and then
   * deletes n.
   */
  void clear(Node* n);

  /** print(std::ostream& oss, Node* n, char* letters, int level)
   * Recursively traverses the Trie with a depth-first search, printing each
   * word to the ostream in alphabetical order. All the letters from the root
   * to n are stored in the variable "letters", and the current level in the
   * Trie is stored in the variable "level".
   */
  void print(std::ostream& oss, Node* n, String& letters);

 public:
  Trie();
  ~Trie();

  /** put(char* word)
   * Inserts word with the associated val into the Trie.
   * If the word is already in the tree, its value is replaced with val.
   * Increases height_upper_bound to word length if
   * word length > height_upper_bound.
   */
  void put(const char* word, int val);

  /** count()
   * Returns the number of word in the Trie.
   */
  int count();

  /** search(char* word)
   * Searches for word in the Trie, returning true if found and false otherwise.
   */
  bool search(const char* word);

  /** get(char* word)
   * Searches for word in the Trie and returns its value.
   * Throws an error if word is not found.
   */
  int get(const char* word);

  /** remove(char* word)
   * Searches for word in the tree and remove it if found.
   * Throws an error if word is not found.
   */
  void remove(const char* word);

  /** clear()
   * Removes all words from the Trie.
   * Sets height_upper_bound back to zero.
   */
  void clear();

  /** print()
   * Prints the Trie's key-value (string-int) pairs to the ostream in
   * alphabetical order.
   * The key and value of each pair are separated by a space, and each pair is
   * separated by the newline character.
   * Size of letters array for call to recursive print should be
   * height_upper_bound
   */
  void print(std::ostream& oss = std::cout);
};

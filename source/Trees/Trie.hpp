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
  ~Node() = default;

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
   * 
   * Inputs:
   * @param word: 
   * @param n: node to root the subtree at
   * 
   * Outputs:
   * A node pointer to aid in recursion
   * 
   * Side Effects:
   * Removes every node used exclusively by the word param
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  Node* remove(const char* word, Node* n);

  /** clear(Node* n)
   * Recursively deletes all of the nodes in the subtree rooted at n, and then
   * deletes n.
   * 
   * Inputs:
   * @param n: node to root the subtree at
   * 
   * Side Effects:
   * Removes every node in the Trie
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  static void clear(Node* n);

  /** print(std::ostream& oss, Node* n, char* letters, int level)
   * Recursively traverses the Trie with a depth-first search, printing each
   * word to the ostream in alphabetical order. All the letters from the root
   * to n are stored in the variable "letters", and the current level in the
   * Trie is stored in the variable "level".
   * 
   * Inputs:
   * @param oss: Stream to print to
   * @param n: node to root the subtree at
   * @param letters: String to write the letters to
   * 
   * Side Effects:
   * Prints the contents of the Trie to the provided stream
   * and adds the letters to letters
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  static void print(std::ostream& oss, Node* n, String& letters);

 public:
  Trie();
  ~Trie();

  /** put(char* word)
   * Inserts word with the associated val into the Trie.
   * If the word is already in the tree, its value is replaced with val.
   * Increases height_upper_bound to word length if
   * word length > height_upper_bound.
   * 
   * Inputs:
   * @param word: word to insert 
   * @param val: value to associate with word
   * 
   * Side Effects:
   * Puts the word with its associated value in the Trie
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  void put(const char* word, int val);

  /** count()
   * Returns the number of words in the Trie.
   * 
   * Outputs:
   * The number of words in the tree
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  int count();

  /** search(char* word)
   * Searches for word in the Trie, returning true if found and false otherwise.
   * 
   * Inputs:
   * @param word: word to search the Trie for
   * 
   * Outputs:
   * True if the word is found in the Trie
   * False otherwise
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  bool search(const char* word);

  /** get(char* word)
   * Searches for word in the Trie and returns its value.
   * Throws an error if word is not found.
   * 
   * Inputs:
   * @param word: word ot get the associated value of
   * 
   * Outputs:
   * The value associated with the given word 
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  int get(const char* word);

  /** remove(char* word)
   * Searches for word in the tree and remove it if found.
   * Throws an error if word is not found.
   * 
   * Inputs:
   * @param word: word to remove from the Trie
   * 
   * Side Effects:
   * Removes the given word from the Trie
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  void remove(const char* word);

  /** clear()
   * Removes all words from the Trie.
   * Sets height_upper_bound back to zero.
   * 
   * Side Effects:
   * Removes every node in the Trie
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  void clear();

  /** print()
   * Prints the Trie's key-value (string-int) pairs to the ostream in
   * alphabetical order.
   * The key and value of each pair are separated by a space, and each pair is
   * separated by the newline character.
   * Size of letters array for call to recursive print should be
   * height_upper_bound
   * 
   * Inputs:
   * @param oss: stream to print to 
   * 
   * Side Effects:
   * Prints the contents of the Trie to the given stream
   * 
   * Examples:
   * 
   * Runtime:
   * O(?)
   */
  void print(std::ostream& oss = std::cout);
};

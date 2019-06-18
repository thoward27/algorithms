#pragma once

class String {
 private:
  char* array;
  unsigned int _capacity;

 public:
  /** Constructors */
  String();
  String(char*);
  String(char);

  /** Destructors */
  ~String();

  /** at(int position)
   * Returns the character at the given position, throws an exception if the
   * position is out of bounds.
   * O(?)
   */
  char at(int) const;

  /** empty()
   * Returns whether or not the string is empty.
   * O(?)
   */
  bool empty() const;

  /** size()
   * Returns the number of characters in the string.
   */
  unsigned int size() const;

  /** capacity()
   * Returns the number of characters that the string can hold.
   * O(?)
   */
  unsigned int capacity() const;

  /** reserve(int extra)
   * Reserves extra amount of characters, extending the capacity of the string.
   * O(?)
   */
  void reserve(unsigned int);

  /** insert(char c, int index)
   * Inserts the given character `c` into the string at the given index.
   * If the index is out of bounds the character should appended / prepended.
   * O(?)
   */
  void insert(char, int);

  /** erase(char)
   * Erases all copies of the given character from the string.
   * O(?)
   */
  void erase(char);

  /** remove(int index)
   * Removes the character at the given index.
   * O(?)
   */
  void remove(int);

  /** append(char)
   * Appends the given character to the string.
   * O(?)
   */
  void append(char);

  /** prepend(char)
   * Prepends the given character to the string.
   * O(?)
   */
  void prepend(char);

  /** compare(char* or String)
   * Returns whether or not the string is equal with the one given.
   * O(?)
   */
  bool compare(char*) const;
  bool compare(String&) const;

  /** concate(char* or String)
   * Concatenates the string with the given character array, or string.
   * O(?)
   */
  void concatenate(char*);
  void concatenate(String&);

  /** find(char* or char or String)
   * Returns the index of the first occurrence of the character array, char, or
   * string given. Should return length if not found.
   * O(?)
   */
  unsigned int find(char*, int start = 0) const;
  unsigned int find(char, int start = 0) const;
  unsigned int find(String&, int start = 0) const;

  /** reverse()
   * Reverses the string in-place.
   * O(?)
   */
  void reverse();

  /** shift(int)
   * Shifts all characters ASCII values in the array upwards or downwards by the
   * amount given. This method should also prevent characters from becoming
   * null, or exceeding the ASCII range.
   * O(?)
   */
  void shift(int);

  /** toInt()
   * Returns the string as an integer, if it can be represented as one.
   * Otherwise throws an exception
   * O(?)
   */
  int toInt() const;

  /** substr(start, end)
   * Returns the string contained between [start, end).
   * O(?)
   */
  String substr(int, int) const;
};

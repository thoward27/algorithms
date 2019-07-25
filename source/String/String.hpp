#pragma once
#include <iostream>

class String {
 private:
  char* array;
  unsigned int _capacity;
  unsigned int _size;

 public:
  /** Constructors
   * Construct Strings from various starting points
   * 
   * Inputs:
   * @param char: a character to create a string from
   * @param char*: c-style string to create a string from
   * 
   * Outputs:
   * A String from given parameters
   * 
   * Examples:
   * String test()
   * String test('c')
   * String test("Hello")
   * 
   * Runtime:
   * O(n)
   */
  String();
  String(char*);
  String(char);

  /** Destructors
   * Destructs the string
   * 
   * Side Effects:
   * Frees any dynamically allocated memory
   * 
   * Runtime:
   * O(1)
   */
  ~String();

  /** at(int position)
   * Returns the character at the given position, throws an exception if the
   * position is out of bounds.
   * 
   * Inputs:
   * @param position: index to retrieve character of
   * 
   * Outputs:
   * The character at String[position]
   * 
   * Examples:
   * String test("Hello")
   * test.at(1) == 'e'
   * 
   * Runtime:
   * O(1)
   */
  char at(int) const;

  /** empty()
   * Returns whether or not the string is empty.
   * 
   * Outputs:
   * The character at String[position]
   * 
   * Examples:
   * String test()
   * test.empty == 1
   * 
   * Runtime:
   * O(1)
   */
  bool empty() const;

  /** size()
   * Returns the number of characters in the string.
   * 
   * Outputs:
   * The size of the array
   * 
   * Examples:
   * String test("Hello")
   * test.size() == 5
   * 
   * Runtime:
   * O(1)
   */
  unsigned int size() const;

  /** capacity()
   * Returns the number of characters that the string can hold.
   * 
   * Outputs:
   * The total number of available character slots
   * 
   * Examples:
   * String test("Hello")
   * test.capacity() == 5
   * 
   * Runtime:
   * O(1)
   */
  unsigned int capacity() const;

  /** reserve(int extra)
   * Reserves extra amount of characters, extending the capacity of the string.
   * 
   * Inputs:
   * @param int: number of additional character slots to add
   * 
   * Side Effects:
   * Adds the value of int param to available character slots
   * 
   * Examples:
   * String test("Hello")
   * test.capacity() == 5
   * test.reserve(5)
   * test.capacity() == 10
   * 
   * Runtime:
   * O(n)
   */
  void reserve(unsigned int);

  /** insert(char c, int index)
   * Inserts the given character `c` into the string at the given index.
   * If the index is out of bounds the character should appended / prepended.
   * 
   * Inputs:
   * @param char: character to insert into the string
   * @param int: the index to add the char param at
   * 
   * Outputs:
   * Adds the char param to the string at index 
   * 
   * Examples:
   * String test("Hello")
   * test.insert('c', 3)  == "Hellco"
   * 
   * Runtime:
   * O(n)
   */
  void insert(char, int);

  /** erase(char)
   * Erases all copies of the given character from the string.
   * 
   * Inputs:
   * @param char: character to remove from the string
   * 
   * Side Effects:
   * Removes all occurences of the char param from the string 
   * 
   * Examples:
   * String test("Hello")
   * test.erase('l')  == "Heo"
   * 
   * Runtime:
   * O(n)
   */
  void erase(char);

  /** clear()
   * Clears the contents of the string.
   * 
   * Outputs:
   * Clears all characters from the string
   * 
   * Examples:
   * String test("Hello")
   * test.clear() == ""
   * 
   * Runtime:
   * O(n)
   */
  void clear();

  /** remove(int index)
   * Removes the character at the given index.
   * 
   * Inputs:
   * @param int: index to remove
   * 
   * Side Effects:
   * Removes the character at string[int]
   * 
   * Examples:
   * String test("Hello")
   * test.remove(1)  == "Hllo"
   * 
   * Runtime:
   * O(n)
   */
  void remove(int);

  /** pop_back
   * Pops the last character off.
   * 
   * Outputs:
   * The last character from the string
   * 
   * Examples:
   * String test("World")
   * test.pop()  == "Worl"
   * 
   * Runtime:
   * O(1)
   */
  char pop_back();

  /** append(char)
   * Appends the given character to the string.
   * 
   * Inputs:
   * @param char: character to append to the string
   * 
   * Side Effects:
   * Appends the char param to the end of the string
   * 
   * Examples:
   * String test("Hello")
   * test.append('l')  == "Hellol"
   * 
   * Runtime:
   * O(1)
   */
  void append(char);

  /** prepend(char)
   * Prepends the given character to the string.
   * 
   * Inputs:
   * @param char: character to prepend to the string
   * 
   * Outputs:
   * Prepends the char param to the beginning of the string
   * 
   * Examples:
   * String test("Hello")
   * test.prepend('l')  == "lHello"
   * 
   * Runtime:
   * O(1)
   */
  void prepend(char);

  /** compare(char* or String)
   * Returns whether or not the string is equal with the one given.
   * 
   * Inputs:
   * @param char*: c-style string to compare to
   * @param String: String to compare to
   * 
   * Outputs:
   * True if the two strings are equivalent
   * False otherwise
   * 
   * Examples:
   * String test("Hello")
   * test.compare("Hello") == 1
   * test.compare("Helo") == 0
   * 
   * Runtime:
   * O(n)
   */
  bool compare(char*) const;
  bool compare(const String&) const;

  /** concatenate(char* or String)
   * Concatenates the string with the given character array, or string.
   * 
   * Inputs:
   * @param char*: c-style string to concatenate
   * @param String: String to concatenate
   * 
   * Side Effects:
   * Adds the contents of the string param to the end of the string
   * 
   * Examples:
   * String test("Hello")
   * test.concatenate(" World") == "Hello World"
   * 
   * Runtime:
   * O(n)
   */
  void concatenate(char*);
  void concatenate(String&);

  /** find(char* or char or String)
   * Returns the index of the first occurrence of the character array, char, or
   * string given. Should return length if not found.
   * 
   * Inputs:
   * @param char*: c-style string to search for
   * @param char: char to search for
   * @param String: String to search for
   * @param start: index to start searching from
   * 
   * Outputs:
   * The index of the first occurence of the given substring or character
   * False otherwise
   * 
   * Examples:
   * String test("Hello")
   * test.find("ell") == 1
   * 
   * Runtime:
   * O(n^2)
   */
  unsigned int find(char*, int start = 0) const;
  unsigned int find(char, int start = 0) const;
  unsigned int find(String&, int start = 0) const;

  /** reverse()
   * Reverses the string in-place.
   * 
   * Side Effects:
   * Reverses the string in place
   * 
   * Examples:
   * String test("Hello")
   * test.reverse() == "olleH"
   * 
   * Runtime:
   * O(n)
   */
  void reverse();

  /** shift(int)
   * Shifts all characters ASCII values in the array upwards or downwards by the
   * amount given. This method should also prevent characters from becoming
   * null, or exceeding the ASCII range.
   * 
   * Inputs:
   * @param int: value to be added to ASCII code of each character
   * 
   * Side Effects:
   * Adds the int param to each character to shift all characters int number 
   * of characters forward in the ASCII table
   * 
   * Examples:
   * String test("Hello")
   * test.shift(1) == "Ifmmp"
   * 
   * Runtime:
   * O(n)
   * 
   */
  void shift(int);

  /** toInt()
   * Returns the string as an integer, if it can be represented as one.
   * Otherwise throws an exception
   * 
   * Outputs:
   * The integer value represented by the string if it is possible
   * 
   * Examples:
   * String test("Hello")
   * Strin integer("1234")
   * test.toInt()  Throws exception
   * integer.toInt() == 1234
   * 
   * Runtime:
   * O(n)
   */
  int toInt() const;

  /** substr(start, end)
   * Returns the string contained between [start, end).
   * 
   * Inputs:
   * @param int: index to start substring from
   * @param int: index to end substring at
   * 
   * Outputs:
   * Creates a new substring from int param one to int param two
   * 
   * Examples:
   * String test("Hello")
   * test.substr(1,4) == "ello"
   * 
   * Runtime:
   * O(n)
   */
  String substr(int, int) const;

  /** print(output stream)
   * Prints the contents of the string to the given output.
   * 
   * Inputs:
   * @param oss: stream to print data to
   * 
   * Side Effects:
   * Prints the contents of the string to the given stream
   * 
   * Runtime:
   * O(?)
   */
  void print(std::ostream& oss = std::cout) const;

  /** cstr()
   * Returns a c-style string.
   * 
   * Outputs:
   * The c-style string equivalent of the String object
   * 
   * Examples: 
   * String test("Hello")
   * test.cstr() == ['H','e','l','l','o','\0']
   * 
   * Runtime:
   * O(1)
   */
  char* cstr() const { return this->array; };

  friend std::ostream& operator<<(std::ostream& oss, const String& str);
};

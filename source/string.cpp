#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "string.hpp"

// Inclusions go here:
// #include <iostream>

String::String() {
  // Allocate space.
  array = new char[1];

  // Add the null.
  array[0] = '\0';

  // Adjust private variables.
  _capacity = 0;
}

String::String(char c) {
  // Allocate space.
  array = new char[2];

  // Add the character and the null.
  array[0] = c;
  array[1] = '\0';

  // Adjust private variables.
  _capacity = 1;
}

String::String(char* str) {
  // Get the length of the incoming string.
  int length = 0;
  while (str[length])
    ++length;

  // Allocate space for the string plus a null.
  array = new char[length + 1];

  // Fill our array up, including the null.
  for (int i = 0; i <= length; ++i)
    array[i] = str[i];

  // Adjust private variables.
  _capacity = length;
}

String::~String() {
  delete[] array;
}

char String::at(int index) const {
  // If our index is negative, or beyond the size of our array, we cannot return
  // anything.
  return (index < 0 || index >= this->size()) ? throw "Index" : array[index];
}

unsigned int String::size() const {
  int length = 0;
  while (array[length])
    ++length;
  return length;
}

bool String::empty() const {
  return this->size() == 0;
}

unsigned int String::capacity() const {
  return this->_capacity;
}

void String::reserve(unsigned int n) {
  if (!n)
    return;

  // Make a new array.
  char* _array = new char[_capacity + n + 1]();

  // Fill it up.
  int length = this->size();
  for (int i = 0; i <= length; ++i)
    _array[i] = array[i];

  // Remove old memory.
  delete[] array;

  // Save new memory.
  array = _array;

  // Adjust private variables.
  _capacity += n;
  return;
}

void String::insert(char c, int index) {
  // Prepend and append as easy cases.
  if (index < 0)
    prepend(c);
  else if (index >= size())
    append(c);
  else {
    // Increase capacity, if needed.
    if (this->size() == this->_capacity) {
      this->reserve(this->size() * 2);
    }
    // Move all elements after index over.
    for (int i = this->size() + 1; i >= index; --i)
      array[i] = array[i - 1];
    // Insert our new character.
    array[index] = c;
  }
  return;
}

void String::erase(char c) {
  // Create a new array.
  char* _array = new char[_capacity + 1];

  // Copy all non-erased characters to the new array.
  int length = size();
  for (int i = 0, j = 0; i <= length; ++i) {
    if (array[i] != c)
      _array[j++] = array[i];
  }

  // Remove the old array.
  delete[] array;
  array = _array;
  return;
}

void String::remove(int index) {
  // Copy all characters to the left, overwriting index.
  int length = this->size();
  for (int i = index; i < length; ++i)
    array[i] = array[i + 1];
  return;
}

void String::append(char c) {
  int length = size();
  if (length == this->capacity()) {
    this->reserve(length * 2);
  }
  array[length] = c;
  array[length + 1] = 0;
  return;
}

void String::prepend(char c) {
  int length = size();
  if (length == this->capacity()) {
    this->reserve(length * 2);
  }
  for (int i = length + 1; i >= 0; --i)
    array[i] = array[i - 1];
  array[0] = c;
  return;
}

bool String::compare(char* str) const {
  int length = size();
  // Compare all the way up to the null.
  for (int i = 0; i <= length; ++i) {
    if (str[i] != array[i])
      return false;
  }
  return true;
}

bool String::compare(String& str) const {
  return this->compare(str.array);
}

void String::concatenate(char* str) {
  // Get our lengths.
  int strlen = 0, length = size();
  while (str[strlen])
    ++strlen;
  // Reserve the space/
  if (length + strlen > this->_capacity) {
    this->reserve(strlen);
  }
  // Copy things over.
  for (int i = length, j = 0; i <= length + strlen; ++i, ++j) {
    this->array[i] = str[j];
  }
  return;
}

void String::concatenate(String& str) {
  this->concatenate(str.array);
  return;
}

bool exact_match(char* a, char* b) {
  return (!b[0]) ? true : a[0] == b[0] && exact_match(a + 1, b + 1);
}
unsigned int String::find(char* str, int start) const {
  unsigned int i = start, length = size();
  for (i, length; i < length; ++i) {
    if (exact_match(this->array + i, str))
      return i;
  }
  return i;
}

unsigned int String::find(char c, int start) const {
  unsigned int i = start, length = size();
  for (i, length; i < length; ++i)
    if (array[i] == c)
      return i;
  return i;
}

unsigned int String::find(String& str, int start) const {
  return this->find(str.array, start);
}

void String::reverse() {
  int length = size() - 1;
  for (int i = 0; i < length / 2; ++i) {
    array[i] ^= array[length - i];
    array[length - i] ^= array[i];
    array[i] ^= array[length - i];
  }
  return;
}

void String::shift(int n) {
  int length = size();
  for (int i = 0; i < length; ++i) {
    array[i] = array[i] + n % 255;
    if (!array[i])
      ++array[i];
  }
  return;
}

int chartoint(char c) {
  return ('0' <= c && c <= '9') ? c - 48 : throw "bad input";
}
int String::toInt() const {
  int len = size();
  int out = 0;

  for (int i = 0; i < len; ++i) {
    out += chartoint(array[len - i - 1]) * pow(10, i);
  }

  return out;
}

String String::substr(int start, int end) const {
  String ret;
  for (int i = start; i < end; ++i)
    ret.append(array[i]);
  return ret;
}
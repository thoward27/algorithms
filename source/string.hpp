#ifndef __STRING__
#define __STRING__

#include "doctest/doctest/doctest.h"

class String {
 private:
  char* array;

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
  bool compare(String) const;

  /** concate(char* or String)
   * Concatenates the string with the given character array, or string.
   * O(?)
   */
  void concatenate(char*);
  void concatenate(String);

  /** find(char* or char or String)
   * Returns the index of the first occurrence of the character array, char, or
   * string given. Should return length if not found.
   * O(?)
   */
  unsigned int find(char*, int start = 0) const;
  unsigned int find(char, int start = 0) const;
  unsigned int find(String, int start = 0) const;

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

TEST_CASE("Append") {
  String s;
  for (int i = 0; i < 10; ++i)
    s.append('a' + i);
  for (int i = 0; i < 10; ++i)
    CHECK_EQ(s.at(i), 'a' + i);
}

TEST_CASE("At") {
  SUBCASE("Empty strings") {
    String s;
    CHECK_THROWS(s.at(0));
  }
  SUBCASE("Non-Empty strings") {
    String s((char*)"Testing");
    CHECK_EQ(s.at(0), 'T');
    CHECK_EQ(s.at(1), 'e');
    CHECK_EQ(s.at(5), 'n');
    CHECK_EQ(s.at(6), 'g');
    CHECK_THROWS(s.at(-1));
    CHECK_THROWS(s.at(7));
  }
}

TEST_CASE("Capacity") {
  SUBCASE("Empty string") {
    String s;
    CHECK_EQ(s.capacity(), 0);
  }
  SUBCASE("Non-empty string") {
    String s((char*)"123456789");
    CHECK_EQ(s.capacity(), 9);
  }
}

TEST_CASE("Compare") {
  SUBCASE("Character arrays") {
    String s((char*)"abcd");
    CHECK(s.compare((char*)"abcd"));
    CHECK_FALSE(s.compare((char*)"1234"));
  }
  SUBCASE("Strings") {
    String a((char*)"abcd");
    String b((char*)"abcd");
    String c((char*)"bcde");
    CHECK(a.compare(b));
    CHECK(b.compare(a));
    CHECK_FALSE(a.compare(c));
    CHECK_FALSE(c.compare(a));
  }
}

TEST_CASE("Concatenate") {
  SUBCASE("Character arrays") {
    SUBCASE("Empty Strings") {
      String s;
      s.concatenate((char*)"abcd");
      CHECK_EQ(s.at(0), 'a');
      CHECK_EQ(s.at(3), 'd');
    }
    SUBCASE("Non-empty strings") {
      String s((char*)"test");
      s.concatenate((char*)"ing");
      CHECK_EQ(s.at(0), 't');
      CHECK_EQ(s.at(6), 'g');
    }
  }
  SUBCASE("Strings") {
    SUBCASE("Empty strings") {
      String a;
      String b((char*)"testing");
      a.concatenate(b);
      CHECK_EQ(a.at(0), 't');
      CHECK_EQ(a.at(3), 't');
    }
    SUBCASE("Non-empty strings") {
      String a((char*)"test");
      String b((char*)"ing");
      a.concatenate(b);
      CHECK_EQ(a.at(0), 't');
      CHECK_EQ(a.at(6), 'g');
    }
  }
}

TEST_CASE("Empty") {
  SUBCASE("Empty strings") {
    String s;
    CHECK(s.empty());
  }
  SUBCASE("Non-empty strings") {
    String s((char*)"testing");
    CHECK_FALSE(s.empty());
  }
}

TEST_CASE("Erase") {
  String s((char*)"Testing, 1, 2, 3. TTT");
  s.erase('t');
  CHECK_EQ(s.at(3), 'i');
  s.erase('T');
  CHECK_EQ(s.at(0), 'e');
  CHECK_EQ(s.at(13), '.');
  CHECK_THROWS(s.at(15));
}

TEST_CASE("Find") {
  SUBCASE("Character arrays") {
    String s((char*)"abcba");
    CHECK_EQ(s.find((char*)"bc"), 1);
    CHECK_EQ(s.find((char*)"ab"), 0);
    CHECK_EQ(s.find((char*)"ab", 1), 5);
  }
  SUBCASE("Character") {
    String s((char*)"ababcbcb");
    CHECK_EQ(s.find('a'), 0);
    CHECK_EQ(s.find('a', 1), 2);
    CHECK_EQ(s.find('c', 4), 4);
  }
  SUBCASE("String") {
    String a((char*)"test");
    String b((char*)"testing the tester");
    CHECK_EQ(b.find(a), 0);
    CHECK_EQ(b.find(a, 1), 12);
    CHECK_EQ(a.find(b), 4);
  }
}

TEST_CASE("Insert") {
  String s;
  s.insert(0, 'a');
  CHECK_EQ(s.at(0), 'a');
  s.insert(-1, 'b');
  CHECK_EQ(s.at(0), 'b');
  s.insert(10, 'c');
  CHECK_EQ(s.at(2), 'c');
  s.insert('d', 1);
  CHECK_EQ(s.at(1), 'd');
}

TEST_CASE("Prepend") {
  String s;
  s.prepend('a');
  CHECK_EQ(s.at(0), 'a');
  s.prepend('b');
  CHECK_EQ(s.at(0), 'b');
  s.prepend('c');
  CHECK_EQ(s.at(0), 'c');
}

TEST_CASE("Remove") {
  String s((char*)"Testing: 1, 2, 3");
  s.remove(0);
  CHECK_EQ(s.at(0), 'e');
  s.remove(1);
  CHECK_EQ(s.at(0), 'e');
  CHECK_EQ(s.at(1), 's');
}

TEST_CASE("Reserve") {
  String s((char*)"abc");
  CHECK_EQ(s.capacity(), 3);
  s.reserve(10);
  CHECK_EQ(s.capacity(), 13);
}

TEST_CASE("Reverse") {
  String s((char*)"abc");
  s.reverse();
  CHECK_EQ(s.at(0), 'c');
}

TEST_CASE("Shift") {
  String s((char*)"aaa");
  s.shift(2);
  CHECK_EQ(s.at(0), 'c');
}

TEST_CASE("Size") {
  String s((char*)"12345");
  CHECK_EQ(s.size(), 5);
}

TEST_CASE("Substr") {
  String s((char*)"abcdef");
  CHECK(s.substr(1, 3).compare(String((char*)"bc")));
}

TEST_CASE("To Int") {
  SUBCASE("Valid") {
    String s((char*)"123");
    CHECK_EQ(s.toInt(), 123);
  }
  SUBCASE("Invalid") {
    String s((char*)"123b");
    CHECK_THROWS(s.toInt());
  }
}

#endif
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "String.hpp"

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
  CHECK_EQ(s.at(13), '3');
  CHECK_THROWS(s.at(16));
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
  s.insert('a', 0);
  CHECK_EQ(s.at(0), 'a');
  s.insert('b', -1);
  CHECK_EQ(s.at(0), 'b');
  s.insert('c', 10);
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
  CHECK_EQ(s.at(1), 't');
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
  CHECK(s.substr(1, 3).compare((char*)"bc"));
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

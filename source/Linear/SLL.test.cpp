#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "SLL.hpp"

TEST_CASE("Constructor") {
  SLL list;
  CHECK(list.length() == 0);
}

TEST_CASE("at") {
  SLL list;
  for (int i = 0; i < 10; ++i) {
    list.push_front(i);
  }
  SUBCASE("Positive indexes") {
    REQUIRE_EQ(list.at(0), 9);
    REQUIRE_EQ(list.at(2), 7);
    REQUIRE_EQ(list.at(9), 0);

    REQUIRE_THROWS(list.at(10));
  }
  SUBCASE("Negative indexes") {
    REQUIRE_EQ(list.at(-1), 0);
    REQUIRE_EQ(list.at(-3), 2);
    REQUIRE_EQ(list.at(-10), 9);

    REQUIRE_THROWS(list.at(-11));
  }
}

TEST_CASE("push") {
  SUBCASE("to front") {
    SLL list;
    list.push_front(5);
    REQUIRE(list.length() == 1);
    REQUIRE(list.at(0) == 5);
    list.push_front(10);
    REQUIRE(list.length() == 2);
    REQUIRE(list.at(0) == 10);
  }
  SUBCASE("to back") {
    SLL list;
    list.push_back(5);
    list.push_back(10);
    REQUIRE(list.length() == 2);
    REQUIRE(list.at(0) == 5);
  }
  SUBCASE("to index") {
    SLL list;
    list.push(10, 0);
    list.push(1, 1);
    list.push(2, 1);
    REQUIRE(list.length() == 3);
    REQUIRE(list.at(1) == 2);
  }
}

TEST_CASE("pop") {
  SUBCASE("front") {
    SLL list;
    for (int i = 0; i < 10; ++i)
      list.push_back(i);
    for (int i = 0; i < 10; ++i)
      REQUIRE_EQ(list.pop_front(), i);
    REQUIRE_EQ(list.length(), 0);
  }
  SUBCASE("back") {
    SLL list;
    for (int i = 0; i < 10; ++i)
      list.push_front(i);
    for (int i = 0; i < 10; ++i)
      REQUIRE_EQ(list.pop_back(), i);
    REQUIRE_EQ(list.length(), 0);
  }
  SUBCASE("index") {
    SLL list;
    for (int i = 0; i < 10; ++i)
      list.push_front(i);
    REQUIRE_EQ(list.pop(0), 9);
    REQUIRE_EQ(list.pop(4), 4);
    REQUIRE_EQ(list.pop(4), 3);
  }
}

TEST_CASE("set") {
  SLL list;
  for (int i = 0; i < 5; ++i)
    list.push_front(i);
  SUBCASE("Positive indexes") {
    list.set(0, 11);
    REQUIRE_EQ(list.at(0), 11);
    REQUIRE_EQ(list.length(), 5);
    list.set(4, 12);
    REQUIRE_EQ(list.at(4), 12);
    REQUIRE_EQ(list.length(), 5);

    REQUIRE_THROWS(list.set(5, 0));
  }
  SUBCASE("Negative indexes") {
    list.set(-1, 13);
    REQUIRE_EQ(list.at(-1), 13);
    REQUIRE_EQ(list.length(), 5);
    list.set(-2, 14);
    REQUIRE_EQ(list.at(-2), 14);
    REQUIRE_EQ(list.length(), 5);

    REQUIRE_THROWS(list.set(-6, 0));
  }
}

TEST_CASE("clear") {
  SLL list;
  for (int i = 0; i < 5; ++i) {
    list.push_front(i);
  }
  list.clear();
  CHECK_EQ(list.length(), 0);
  REQUIRE_THROWS(list.at(0));
  list.push_front(10);
  CHECK_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 10);
}

TEST_CASE("remove") {
  SLL list;
  for (int i = 0; i < 10; ++i)
    list.push_back(i);
  list.remove(6);
  REQUIRE_EQ(list.length(), 9);
  CHECK_EQ(list.at(5), 5);
  CHECK_EQ(list.at(6), 7);

  for (int i = 0; i < 5; ++i)
    list.push_back(6);
  list.remove(6);
  REQUIRE_EQ(list.at(9), 6);
  list.remove(6);
  REQUIRE_EQ(list.at(9), 6);
}

TEST_CASE("index") {
  SLL list;
  for (int i = 0; i < 10; ++i)
    list.push_back(i);
  for (int i = 0; i < 10; ++i)
    REQUIRE_EQ(list.index(i), i);
}

TEST_CASE("Testing reverse...") {
  SLL list;
  list.reverse();
  list.push_front(50);
  list.reverse();
  REQUIRE_EQ(list.length(), 1);
  REQUIRE_EQ(list.at(0), 50);

  for (int i = 0; i < 10; ++i) {
    list.push_front(i);
  }
  list.reverse();
  REQUIRE_EQ(list.length(), 11);
  for (int i = 0; i < 10; ++i) {
    REQUIRE_EQ(list.at(i + 1), i);
  }
}
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
    list.print();
    REQUIRE_EQ(list.pop(4), 4);
  }
}

TEST_CASE("set") {
  SLL list;
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  int val1 = list.set(6, 0);
  CHECK_EQ(list.length(), 3);
  CHECK_EQ(list.at(0), 6);
  CHECK_EQ(val1, 3);
  int val2 = list.set(7, 1);
  CHECK_EQ(list.at(1), 7);
  CHECK_EQ(val2, 2);
  int val3 = list.set(8, 2);
  CHECK_EQ(list.at(2), 8);
  CHECK_EQ(val3, 1);
  int val4 = list.set(9, 0);
  CHECK_EQ(list.at(0), 9);
  CHECK_EQ(val4, 6);
}

TEST_CASE("clear") {
  SLL list;
  for (int i = 0; i < 5; ++i) {
    list.push_front(i);
  }
  list.clear();
  CHECK_EQ(list.length(), 0);
  list.push_front(10);
  CHECK_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 10);
}

TEST_CASE("remove") {
  SLL list1;
  for (int i = 0; i < 10; ++i) {
    list1.push_front(9 - i);
  }
  list1.remove(6);
  CHECK_EQ(list1.length(), 9);
  CHECK_EQ(list1.at(5), 5);
  CHECK_EQ(list1.at(6), 7);

  SLL list2;
  for (int i = 0; i < 10; ++i) {
    list2.push_front(i % 3);
  }
  list2.remove(1);
  CHECK_EQ(list2.length(), 7);
  for (int i = 0; i < 7; ++i) {
    CHECK_EQ(list2.at(i), (i % 2) * 2);
  }

  SLL list3;
  list3.push_front(10);
  list3.remove(10);
  CHECK_EQ(list3.length(), 0);
}

TEST_CASE("Testing unique...") {
  SLL list1;
  for (int i = 0; i < 5; ++i) {
    list1.push_front(4 - i);
  }
  list1.unique();
  for (int i = 0; i < 5; ++i) {
    CHECK_EQ(list1.at(i), i);
  }

  SLL list2;
  for (int i = 0; i < 10; ++i) {
    list2.push_front(i % 3);
  }
  list2.unique();
  CHECK_EQ(list2.length(), 3);
  CHECK_EQ(list2.at(0), 0);
  CHECK_EQ(list2.at(1), 2);
  CHECK_EQ(list2.at(2), 1);

  SLL list3;
  for (int i = 0; i < 10; ++i) {
    list3.push_front(i / 3);
  }
  list3.unique();
  CHECK_EQ(list3.length(), 4);
  CHECK_EQ(list3.at(0), 3);
  CHECK_EQ(list3.at(1), 2);
  CHECK_EQ(list3.at(2), 1);
  CHECK_EQ(list3.at(3), 0);
}

TEST_CASE("Testing reverse...") {
  SLL list1;
  list1.reverse();
  list1.push_front(50);
  list1.reverse();
  CHECK_EQ(list1.length(), 1);
  CHECK_EQ(list1.at(0), 50);

  SLL list2;
  for (int i = 0; i < 10; ++i) {
    list2.push_front(i);
  }
  list2.reverse();
  CHECK_EQ(list2.length(), 10);
  for (int i = 0; i < 10; ++i) {
    CHECK_EQ(list2.at(i), i);
  }
}
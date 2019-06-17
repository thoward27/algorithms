#include "../doctest.h"

#include "SLL.hpp"

TEST_CASE("Testing constructor (trivial) and length accessor (trivial)...") {
  SLL list;
  CHECK(list.length() == 0);
}

TEST_CASE("Testing pop_front...") {
  SLL list;
  list.append(5);
  list.append(10);
  int val1 = list.pop_front();
  CHECK_EQ(val1, 10);
  CHECK_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 5);
  int val2 = list.pop_front();
  CHECK_EQ(val2, 5);
  CHECK_EQ(list.length(), 0);
}

TEST_CASE("Testing append...") {
  SLL list;
  list.append(5);
  CHECK_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 5);
  list.append(10);
  CHECK_EQ(list.length(), 2);
  CHECK_EQ(list.at(0), 5);
}

TEST_CASE("Testing pop_back...") {
  SLL list;
  list.append(5);
  list.append(10);
  int val1 = list.pop_back();
  CHECK_EQ(val1, 5);
  CHECK_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 10);
  int val2 = list.pop_back();
  CHECK_EQ(val2, 10);
  CHECK_EQ(list.length(), 0);
}

TEST_CASE("Testing general element accessor (at)...") {
  SLL list1;
  for (int i = 0; i < 10; ++i) {
    list1.append(i);
  }
  CHECK_EQ(list1.at(0), 9);
  CHECK_EQ(list1.at(9), 0);
  CHECK_EQ(list1.at(4), 5);

  SLL list2;
  for (int i = 9; i >= 0; --i) {
    list2.append(i);
  }
  CHECK_EQ(list2.at(0), 0);
  CHECK_EQ(list2.at(9), 9);
  CHECK_EQ(list2.at(4), 4);
}

TEST_CASE("Testing set...") {
  SLL list;
  list.append(1);
  list.append(2);
  list.append(3);
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

TEST_CASE("Testing insert...") {
  SLL list;
  list.insert(5, 0);
  REQUIRE_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 5);
  list.insert(15, 1);
  CHECK_EQ(list.length(), 2);
  CHECK_EQ(list.at(0), 5);
  CHECK_EQ(list.at(1), 15);
  list.insert(10, 1);
  CHECK_EQ(list.length(), 3);
  CHECK_EQ(list.at(1), 10);
  CHECK_EQ(list.at(2), 15);
}

TEST_CASE("Testing erase...") {
  SLL list;
  for (int i = 0; i < 5; ++i) {
    list.append(5 - i);
  }
  list.erase(2);
  CHECK_EQ(list.length(), 4);
  CHECK_EQ(list.at(2), 4);
  list.erase(0);
  CHECK_EQ(list.length(), 3);
  CHECK_EQ(list.at(0), 2);
  list.erase(2);
  CHECK_EQ(list.length(), 2);
  CHECK_EQ(list.at(0), 2);
  CHECK_EQ(list.at(1), 4);
}

TEST_CASE("Testing clear...") {
  SLL list;
  for (int i = 0; i < 5; ++i) {
    list.append(i);
  }
  list.clear();
  CHECK_EQ(list.length(), 0);
  list.append(10);
  CHECK_EQ(list.length(), 1);
  CHECK_EQ(list.at(0), 10);
}

TEST_CASE("Testing remove...") {
  SLL list1;
  for (int i = 0; i < 10; ++i) {
    list1.append(9 - i);
  }
  list1.remove(6);
  CHECK_EQ(list1.length(), 9);
  CHECK_EQ(list1.at(5), 5);
  CHECK_EQ(list1.at(6), 7);

  SLL list2;
  for (int i = 0; i < 10; ++i) {
    list2.append(i % 3);
  }
  list2.remove(1);
  CHECK_EQ(list2.length(), 7);
  for (int i = 0; i < 7; ++i) {
    CHECK_EQ(list2.at(i), (i % 2) * 2);
  }

  SLL list3;
  list3.append(10);
  list3.remove(10);
  CHECK_EQ(list3.length(), 0);
}

TEST_CASE("Testing unique...") {
  SLL list1;
  for (int i = 0; i < 5; ++i) {
    list1.append(4 - i);
  }
  list1.unique();
  for (int i = 0; i < 5; ++i) {
    CHECK_EQ(list1.at(i), i);
  }

  SLL list2;
  for (int i = 0; i < 10; ++i) {
    list2.append(i % 3);
  }
  list2.unique();
  CHECK_EQ(list2.length(), 3);
  CHECK_EQ(list2.at(0), 0);
  CHECK_EQ(list2.at(1), 2);
  CHECK_EQ(list2.at(2), 1);

  SLL list3;
  for (int i = 0; i < 10; ++i) {
    list3.append(i / 3);
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
  list1.append(50);
  list1.reverse();
  CHECK_EQ(list1.length(), 1);
  CHECK_EQ(list1.at(0), 50);

  SLL list2;
  for (int i = 0; i < 10; ++i) {
    list2.append(i);
  }
  list2.reverse();
  CHECK_EQ(list2.length(), 10);
  for (int i = 0; i < 10; ++i) {
    CHECK_EQ(list2.at(i), i);
  }
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <iostream>
#include "MinHeap.hpp"

TEST_CASE("constructor") {
  MinHeap heap(1);
  CHECK_FALSE(heap.count());
  CHECK_THROWS(heap.peek());
}

TEST_CASE("push") {
  MinHeap heap(4);
  heap.push(10);
  REQUIRE_EQ(heap.count(), 1);
  REQUIRE_EQ(heap.peek(), 10);

  heap.push(20);
  heap.push(5);
  REQUIRE_EQ(heap.count(), 3);
  REQUIRE_EQ(heap.peek(), 5);

  heap.push(1);
  REQUIRE_EQ(heap.peek(), 1);

  heap.push(100);
  REQUIRE_EQ(heap.peek(), 1);
  REQUIRE_EQ(heap.count(), 5);
}

TEST_CASE("pop") {
  MinHeap heap(10);
  REQUIRE_THROWS(heap.pop());

  for (int i = 0; i < 10; ++i) {
    heap.push(i);
  }
  int min;
  for (int i = 0; i < 9; ++i) {
    min = heap.pop();
    REQUIRE_EQ(min, i);
    REQUIRE_EQ(heap.peek(), i + 1);
  }
  min = heap.pop();
  REQUIRE_EQ(min, 9);
  REQUIRE_FALSE(heap.count());
}

TEST_CASE("search") {
  SUBCASE("empty and single node") {
    MinHeap heap(5);
    REQUIRE_FALSE(heap.search(0));
    REQUIRE_FALSE(heap.search(10));
    heap.push(10);
    REQUIRE_FALSE(heap.search(0));
    REQUIRE(heap.search(10));
  }
  SUBCASE("multiple nodes") {
    MinHeap heap(10);
    int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    REQUIRE(heap.search(1));
    REQUIRE(heap.search(2));
    REQUIRE(heap.search(8));
    REQUIRE(heap.search(9));
    REQUIRE_FALSE(heap.search(0));
    REQUIRE_FALSE(heap.search(10));
    REQUIRE_FALSE(heap.search(6));
  }
}

TEST_CASE("remove") {
  int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
  SUBCASE("empty and out of bounds") {
    MinHeap heap(5);
    REQUIRE_THROWS(heap.remove(0));
    heap.push(1);
    heap.push(2);
    REQUIRE_THROWS(heap.remove(2));
    REQUIRE_THROWS(heap.remove(-1));
  }
  SUBCASE("last and leaf nodes") {
    MinHeap heap(10);
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    heap.remove(7);
    REQUIRE_FALSE(heap.search(9));
    REQUIRE(heap.search(4));
    heap.remove(4);
    REQUIRE_FALSE(heap.search(3));
    REQUIRE(heap.search(2));
    REQUIRE(heap.search(7));
  }
  SUBCASE("internal node") {
    MinHeap heap(10);
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    heap.remove(2);
    REQUIRE_FALSE(heap.search(5));
    REQUIRE(heap.search(7));
    REQUIRE(heap.search(9));
  }
  SUBCASE("root") {
    MinHeap heap(10);
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    heap.remove(0);
    REQUIRE_FALSE(heap.search(1));
    REQUIRE_EQ(heap.peek(), 2);
    REQUIRE(heap.search(3));
    REQUIRE(heap.search(9));
  }
}

TEST_CASE("erase") {
  int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
  SUBCASE("empty and non-present element") {
    MinHeap heap(5);
    REQUIRE_FALSE(heap.count());
    heap.push(1);
    heap.erase(-1);
    REQUIRE_EQ(heap.count(), 1);
  }
  SUBCASE("last and leaf nodes") {
    MinHeap heap(10);
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    heap.erase(9);
    REQUIRE_FALSE(heap.search(9));
    REQUIRE(heap.search(4));
    heap.erase(3);
    REQUIRE_FALSE(heap.search(3));
    REQUIRE(heap.search(2));
    REQUIRE(heap.search(7));
  }
  SUBCASE("internal node") {
    MinHeap heap(10);
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    heap.erase(5);
    REQUIRE_FALSE(heap.search(5));
    REQUIRE(heap.search(7));
    REQUIRE(heap.search(9));
  }
  SUBCASE("root") {
    MinHeap heap(10);
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    heap.erase(1);
    REQUIRE_FALSE(heap.search(1));
    REQUIRE_EQ(heap.peek(), 2);
    REQUIRE(heap.search(3));
    REQUIRE(heap.search(9));
  }
}

TEST_CASE("print") {
  SUBCASE("empty") {
    MinHeap heap(2);
    std::ostringstream oss;
    heap.print(oss);
    REQUIRE_EQ(oss.str(), "\n");
  }
  SUBCASE("multiple values") {
    MinHeap heap(10);
    int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < 8; ++i) {
      heap.push(nums[i]);
    }
    std::ostringstream oss;
    heap.print(oss);
    REQUIRE_EQ(oss.str(), "1, 2, 5, 4, 3, 8, 7, 9, \n");
  }
}
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Queue.hpp"

TEST_CASE("Constructor") {
  Queue queue;
  CHECK(queue.size() == 0);
}

TEST_CASE("push") {
  Queue queue;
  queue.push(5);
  REQUIRE(queue.size() == 1);
  REQUIRE(queue.front() == 5);
  REQUIRE(queue.back() == 5);
  queue.push(10);
  REQUIRE(queue.size() == 2);
  REQUIRE(queue.front() == 5);
  REQUIRE(queue.back() == 10);
}

TEST_CASE("front and back") {
  Queue queue;
  REQUIRE_THROWS(queue.front());
  REQUIRE_THROWS(queue.back());
  queue.push(10);
  queue.push(5);
  REQUIRE(queue.front() == 10);
  REQUIRE(queue.back() == 5);
}

TEST_CASE("pop") {
  Queue queue;
  REQUIRE_THROWS(queue.pop());
  for (int i = 0; i < 10; ++i)
    queue.push(i);
  for (int i = 0; i < 10; ++i)
    REQUIRE_EQ(queue.pop(), i);
  REQUIRE_EQ(queue.size(), 0);
}

TEST_CASE("empty") {
  Queue queue;
  REQUIRE_FALSE(!queue.empty());
  queue.push(5);
  REQUIRE_FALSE(queue.empty());
  queue.pop();
  REQUIRE_FALSE(!queue.empty());
}

TEST_CASE("clear") {
  Queue queue;
  for (int i = 0; i < 5; ++i) {
    queue.push(i);
  }
  queue.clear();
  CHECK_EQ(queue.size(), 0);
  queue.push(10);
  CHECK_EQ(queue.size(), 1);
  CHECK_EQ(queue.front(), 10);
}
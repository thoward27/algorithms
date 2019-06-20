#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Stack.hpp"

TEST_CASE("Constructor") {
  Stack stack;
  CHECK(stack.size() == 0);
}

TEST_CASE("push") {
  Stack stack;
  stack.push(5);
  REQUIRE(stack.size() == 1);
  REQUIRE(stack.top() == 5);
  stack.push(10);
  REQUIRE(stack.size() == 2);
  REQUIRE(stack.top() == 10);
}

TEST_CASE("top") {
  Stack stack;
  REQUIRE_THROWS(stack.top());
  stack.push(10);
  REQUIRE(stack.top() == 10);
  stack.push(20);
  REQUIRE(stack.top() == 20);
}

TEST_CASE("pop") {
  Stack stack;
  REQUIRE_THROWS(stack.pop());
  for (int i = 0; i < 10; ++i)
    stack.push(i);
  for (int i = 9; i >= 0; --i)
    REQUIRE_EQ(stack.pop(), i);
  REQUIRE_EQ(stack.size(), 0);
}

TEST_CASE("empty") {
  Stack stack;
  REQUIRE_FALSE(!stack.empty());
  stack.push(5);
  REQUIRE_FALSE(stack.empty());
  stack.pop();
  REQUIRE_FALSE(!stack.empty());
}

TEST_CASE("clear") {
  Stack stack;
  for (int i = 0; i < 5; ++i) {
    stack.push(i);
  }
  stack.clear();
  CHECK_EQ(stack.size(), 0);
  stack.push(10);
  CHECK_EQ(stack.size(), 1);
  CHECK_EQ(stack.top(), 10);
}
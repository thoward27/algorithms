#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Dequeue.hpp"

TEST_CASE("Constructor") {
  Dequeue test;
  CHECK(test.size() == 0);
}

TEST_CASE("Size Method") {
  Dequeue test;
  for (int i = 0; i < 100; ++i) {
    test.pushleft(i);
    REQUIRE(test.size() == i + 1);
  }
}

TEST_CASE("Push Methods") {
  Dequeue test;
  SUBCASE("Pushleft Method") {
    for (int i = 0; i < 10; ++i) {
      test.pushleft(i);
      REQUIRE(test.size() == i + 1);
    }
    CHECK(test.front() == 9);
  }
  SUBCASE("Pushright Method") {
    for (int i = 0; i < 15; ++i) {
      test.pushright(i);
      REQUIRE(test.size() == i + 1);
    }
    CHECK(test.back() == 14);
  }
}

TEST_CASE("Pop Methods") {
  Dequeue test;
  SUBCASE("Popleft Method") {
    for (int i = 0; i < 10; ++i) {
      test.pushleft(i);
    }

    for (int i = 0; i < 10; ++i) {
      CHECK(test.popleft() == (9 - i));
      CHECK(test.size() == (9 - i));
    }
    CHECK(test.empty());
  }
  SUBCASE("Popright Method") {
    for (int i = 0; i < 10; ++i) {
      test.pushleft(i);
    }

    for (int i = 0; i < 10; ++i) {
      CHECK(test.popright() == i);
      CHECK(test.size() == (9 - i));
    }
    CHECK(test.empty());
  }
}

TEST_CASE("Front Method") {
  Dequeue test;
  Dequeue test2;
  for (int i = 0; i < 10; ++i) {
    test.pushright(i);
    test2.pushleft(i);
  }
  REQUIRE(test.front() == 0);
  REQUIRE(test2.front() == 9);

  for (int i = 0; i < 10; ++i) {
    CHECK(test2.front() == (9 - i));
    test2.popleft();
  }
}

TEST_CASE("Back Method") {
  Dequeue test;
  Dequeue test2;
  for (int i = 0; i < 10; ++i) {
    test.pushright(i);
    test2.pushleft(i);
  }
  REQUIRE(test.back() == 9);
  REQUIRE(test2.back() == 0);

  for (int i = 0; i < 10; ++i) {
    CHECK(test.back() == (9 - i));
    test.popright();
  }
}

TEST_CASE("Empty Method") {
  Dequeue test;
  test.pushleft(1);
  CHECK(!test.empty());
  test.popleft();
  CHECK(test.empty());
}

TEST_CASE("Clear Method") {
  Dequeue test;
  for (int i = 0; i < 10; ++i) {
    test.pushleft(i);
  }
  REQUIRE(test.size() == 10);
  test.clear();
  CHECK(test.size() == 0);
}
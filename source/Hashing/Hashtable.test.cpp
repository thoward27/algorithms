#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <sstream>
#include "../doctest.h"

#include "Hashtable.hpp"

TEST_CASE("Default Constructor") {
  HashTable test;
  REQUIRE(test.size() == 5);
}

TEST_CASE("Initialized Constructor") {
  HashTable test(7);
  REQUIRE(test.size() == 7);
}

TEST_CASE("Is_Empty") {
  HashTable test;
  REQUIRE(test.is_empty());

  test.insert(String((char*)"Test"), 10);
  REQUIRE_FALSE(test.is_empty());
}

TEST_CASE("Insert") {
  HashTable test;
  SUBCASE("Trivial Case") {
    REQUIRE(test.is_empty());
    test.insert(String((char*)"Hello"), 10);
    REQUIRE_FALSE(test.is_empty());
    REQUIRE_EQ(test.elements(), 1);
  }
  SUBCASE("Duplicate Inserts") {
    for (int i = 0; i < 5; ++i)
      test.insert(String((char*)"ABC"), i);
    REQUIRE_EQ(test.elements(), 1);
  }
  SUBCASE("Unique Inserts") {
    for (int i = 0; i < 40; ++i)
      test.insert(String('a' + i), i);
    REQUIRE_EQ(test.elements(), 40);
    REQUIRE_EQ(test.size(), 10);
  }
}

TEST_CASE("Remove") {
  HashTable test;
  SUBCASE("Trivial Case") {
    String hello_str((char*)"Hello");
    test.insert(hello_str, 1);
    REQUIRE_FALSE(test.is_empty());
    REQUIRE(test.search(hello_str));

    test.remove(hello_str);
    REQUIRE_FALSE(test.search(hello_str));
    REQUIRE(test.is_empty() == 1);
  }

  SUBCASE("Multiple Insertions") {
    for (int i = 0; i < 10; ++i) {
      String str('a' + i);
      test.insert(str, i + 1);
    }
    REQUIRE_FALSE(test.is_empty());
    String test_str((char*)"test");
    REQUIRE_FALSE(test.search(test_str));
    for (int i = 0; i < 10; ++i) {
      String str('a' + i);
      test.remove(str);
      REQUIRE_FALSE(test.search(str));
    }
  }
}

TEST_CASE("Get") {
  HashTable test;
  SUBCASE("Trivial Case") {
    String hello_str((char*)"Hello");
    test.insert(hello_str, 1);
    REQUIRE_FALSE(test.is_empty());
    REQUIRE(test.get(hello_str));
  }

  SUBCASE("Similar Insertions") {
    String world_str1((char*)"World");
    String world_str2((char*)"world");
    test.insert(world_str1, 5);
    test.insert(world_str2, 10);
    REQUIRE_EQ(test.get(world_str1), 5);
    REQUIRE_EQ(test.get(world_str2), 10);
  }

  SUBCASE("Multiple Insertions") {
    for (int i = 0; i < 10; ++i) {
      String str('a' + i);
      test.insert(str, i + 1);
    }
    REQUIRE_FALSE(test.is_empty());
    for (int i = 0; i < 10; ++i) {
      String str('a' + i);
      REQUIRE_EQ(test.get(str), i + 1);
    }
  }

  SUBCASE("Random Insertions") {
    char cstrings[8][20] = {
        "asddaweg", "asdqrqsda", "weqasdZasd", "qeasDQWEasdz",
        "Daqwesd",  "QecByasd",  "Jkusasdqwe", "Liiqdsaqe",
    };
    int nums[8] = {132, 14314, 76874, 5141, 141234, 7636, 1241236, 1523};
    for (int i = 0; i < 8; ++i) {
      String str(cstrings[i]);
      test.insert(str, nums[i]);
    }
    for (int i = 0; i < 8; ++i) {
      String str(cstrings[i]);
      REQUIRE_EQ(test.get(str), nums[i]);
    }
  }
}

TEST_CASE("Print") {
  HashTable test;
  for (int i = 0; i < 10; ++i) {
    String str('a' + i);
    test.insert(str, i + 1);
  }

  // std::ostringstream oss;
  // test.print(oss);
  // String answer((
  //     char*)"Length 2\n2, b\n7, g\n\nLength 2\n3, c\n8, h\n\nLength 2\n4, "
  //           "d\n9, "
  //           "i\n\nLength 2\n5, e\n10, j\n\nLength 2\n1, a\n6, f\n");
  // char* ans = answer.cstr();
  // REQUIRE_EQ(oss.str(), ans);
}

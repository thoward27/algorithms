#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Trie.hpp"
#include <iostream>

void populate(Trie& trie) {
  trie.insert("insert", 1);
  trie.insert("search", 2);
  trie.insert("inert", 4);
  trie.insert("sea", 8);
  trie.insert("inserted", 16);
}

TEST_CASE("constructor") {
  Trie trie;
  CHECK_FALSE(trie.count());
}

TEST_CASE("insert and search") {
  Trie trie;
  populate(trie);
  REQUIRE_EQ(trie.count(), 5);
  REQUIRE(trie.search("insert"));
  REQUIRE(trie.search("sea"));
  REQUIRE(trie.search("inserted"));
  REQUIRE_FALSE(trie.search("ins"));
  REQUIRE_FALSE(trie.search("i"));
  REQUIRE_FALSE(trie.search("searched"));
}

TEST_CASE("get") {
  Trie trie;
  populate(trie);
  REQUIRE_EQ(trie.get("insert"), 1);
  REQUIRE_EQ(trie.get("inert"), 4);
  REQUIRE_EQ(trie.get("sea"), 8);
  REQUIRE_EQ(trie.get("inserted"), 16);
  REQUIRE_THROWS(trie.get("searched"));
  REQUIRE_THROWS(trie.get("i"));
}

TEST_CASE("remove") {
  Trie trie;
  populate(trie);
  REQUIRE_THROWS(trie.remove("searched"));
  REQUIRE_THROWS(trie.remove("i"));
  trie.remove("inert");
  REQUIRE_FALSE(trie.search("inert"));
  REQUIRE(trie.search("insert"));
  trie.remove("search");
  REQUIRE_FALSE(trie.search("search"));
  REQUIRE(trie.search("sea"));
  trie.remove("insert");
  REQUIRE_FALSE(trie.search("insert"));
  REQUIRE(trie.search("inserted"));
  SUBCASE("remove last word and retain usability") {
    trie.remove("inserted");
    trie.remove("sea");
    REQUIRE_FALSE(trie.count());
    trie.insert("remove", 128);
  }
}

TEST_CASE("clear") {
  Trie trie;
  trie.clear();
  REQUIRE_FALSE(trie.count());
  populate(trie);
  trie.clear();
  REQUIRE_FALSE(trie.count());
  REQUIRE_FALSE(trie.search("sea"));
  trie.insert("clear", 32);
  trie.insert("search", 2);
  REQUIRE(trie.search("clear"));
  REQUIRE(trie.search("search"));
}

TEST_CASE("print") {
  Trie trie;
  populate(trie);
  std::ostringstream oss;
  trie.print(oss);
  REQUIRE_EQ(oss.str(), "inert 4\n"
                        "insert 1\n"
                        "inserted 16\n"
                        "sea 8\n"
                        "search 2\n");
}
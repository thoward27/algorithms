#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <iostream>
#include "Trie.hpp"

void populate(Trie& trie) {
  trie.put("put", 1);
  trie.put("search", 2);
  trie.put("inert", 4);
  trie.put("sea", 8);
  trie.put("puted", 16);
}

TEST_CASE("constructor") {
  Trie trie;
  CHECK_FALSE(trie.count());
}

TEST_CASE("put and search") {
  Trie trie;
  populate(trie);
  REQUIRE_EQ(trie.count(), 5);
  REQUIRE(trie.search("put"));
  REQUIRE(trie.search("sea"));
  REQUIRE(trie.search("puted"));
  REQUIRE_FALSE(trie.search("ins"));
  REQUIRE_FALSE(trie.search("i"));
  REQUIRE_FALSE(trie.search("searched"));
}

TEST_CASE("get") {
  Trie trie;
  populate(trie);
  REQUIRE_EQ(trie.get("put"), 1);
  REQUIRE_EQ(trie.get("inert"), 4);
  REQUIRE_EQ(trie.get("sea"), 8);
  REQUIRE_EQ(trie.get("puted"), 16);
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
  REQUIRE(trie.search("put"));
  trie.remove("search");
  REQUIRE_FALSE(trie.search("search"));
  REQUIRE(trie.search("sea"));
  trie.remove("put");
  REQUIRE_FALSE(trie.search("put"));
  REQUIRE(trie.search("puted"));
  SUBCASE("remove last word and retain usability") {
    trie.remove("puted");
    trie.remove("sea");
    REQUIRE_FALSE(trie.count());
    trie.put("remove", 128);
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
  trie.put("clear", 32);
  trie.put("search", 2);
  REQUIRE(trie.search("clear"));
  REQUIRE(trie.search("search"));
}

TEST_CASE("print") {
  Trie trie;
  populate(trie);
  std::ostringstream oss;
  trie.print(oss);
  REQUIRE_EQ(oss.str(),
             "inert 4\n"
             "put 1\n"
             "puted 16\n"
             "sea 8\n"
             "search 2\n");
}
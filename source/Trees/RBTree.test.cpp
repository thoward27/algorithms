#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "RBTree.hpp"

TEST_CASE("Constructor") {
  RBTree tree;
  REQUIRE(tree.is_empty());
}

TEST_CASE("Insert Method") {
  RBTree tree;
  SUBCASE("To Root") {
    tree.insert(3);
    REQUIRE_FALSE(tree.is_empty());
    REQUIRE(tree.search(3));
  }
  SUBCASE("Rotating") {
    for (int i = 0; i < 3; ++i)
      tree.insert(i);
    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "1, 0, 2, \n");
  }
  SUBCASE("Beyond Root: Linear Insertions") {
    for (int i = 0; i < 10; ++i) {
      tree.insert(i);
      REQUIRE(tree.search(i) == 1);
    }
  }
  SUBCASE("Beyond Root: Large Linear Insertions") {
    for (int i = 0; i < 100; ++i) {
      tree.insert(i);
      REQUIRE(tree.search(i) == 1);
    }
  }
  SUBCASE("Beyond Root: Reverse Linear Insertions") {
    for (int i = 10; i > 0; --i) {
      tree.insert(i);
      REQUIRE(tree.search(i) == 1);
    }
  }
  SUBCASE("Beyond Root: Random Insertions") {
    tree.insert(5);
    tree.insert(2);
    tree.insert(6);
    tree.insert(4);
    tree.insert(3);
    tree.insert(7);
    tree.insert(0);
    REQUIRE(tree.search(3) == 1);
    REQUIRE(tree.search(0) == 1);
    REQUIRE(tree.search(5) == 1);
    REQUIRE(tree.search(6) == 1);
    REQUIRE(tree.search(4) == 1);
  }

  SUBCASE("Beyond Root: Random Insertions 2") {
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);
    tree.insert(9);
    tree.insert(0);
    tree.insert(3);
    tree.insert(7);
    REQUIRE(tree.search(3) == 1);
    REQUIRE(tree.search(0) == 1);
    REQUIRE(tree.search(5) == 1);
    REQUIRE(tree.search(1) == 1);
    REQUIRE(tree.search(4) == 1);
  }
}

TEST_CASE("Delete Method") {
  RBTree tree;
  for (int i = 0; i < 10; ++i) {
    tree.insert(i);
  }
  tree.remove(2);
  REQUIRE(tree.search(2) == 0);
  REQUIRE(tree.search(0) == 1);
  REQUIRE(tree.search(4) == 1);
}
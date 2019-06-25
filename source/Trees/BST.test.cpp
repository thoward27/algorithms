#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "BST.hpp"
#include <iostream>

TEST_CASE("Constructor") {
  BST tree;
  CHECK(tree.is_empty());
}

TEST_CASE("insert") {
  BST tree;
  tree.insert(10);
  REQUIRE_FALSE(tree.is_empty());
  CHECK_EQ(tree.height(), 0);
  tree.insert(20);
  REQUIRE_FALSE(tree.is_empty());
}

TEST_CASE("search") {
  SUBCASE("empty and single node") {
    BST tree;
    REQUIRE_FALSE(tree.search(0));
    REQUIRE_FALSE(tree.search(10));
    tree.insert(10);
    REQUIRE_FALSE(tree.search(0));
    REQUIRE(tree.search(10));
  }
  SUBCASE("multiple nodes") {
    BST tree2;
    int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < 8; ++i) {
      tree2.insert(nums[i]);
    }
    REQUIRE(tree2.search(4));
    REQUIRE(tree2.search(8));
    REQUIRE(tree2.search(1));
    REQUIRE(tree2.search(7));
    REQUIRE_FALSE(tree2.search(10));
    REQUIRE_FALSE(tree2.search(6));
  }
}

TEST_CASE("height") {
  BST tree;
  REQUIRE_EQ(tree.height(), -1);
  tree.insert(10);
  REQUIRE_EQ(tree.height(), 0);
  tree.insert(20);
  REQUIRE_EQ(tree.height(), 1);
  tree.insert(5);
  REQUIRE_EQ(tree.height(), 1);
  tree.insert(7);
  REQUIRE_EQ(tree.height(), 2);
  tree.insert(8);
  REQUIRE_EQ(tree.height(), 3);
  tree.insert(25);
  tree.insert(30);
  tree.insert(35);
  REQUIRE_EQ(tree.height(), 4);
}

TEST_CASE("remove") {
  BST tree;
  int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
  for (int i = 0; i < 8; ++i) {
    tree.insert(nums[i]);
  }
  tree.remove(1);
  REQUIRE_FALSE(tree.search(1));
  REQUIRE(tree.search(2));
  tree.remove(5);
  REQUIRE_FALSE(tree.search(5));
  REQUIRE(tree.search(7));
  tree.remove(4);
  REQUIRE_FALSE(tree.search(4));
  REQUIRE(tree.search(8));
  REQUIRE(tree.search(2));
  REQUIRE(tree.search(7));
}

TEST_CASE("clear") {
  BST tree;
  tree.clear();
  REQUIRE(tree.is_empty());
  int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
  for (int i = 0; i < 8; ++i) {
    tree.insert(nums[i]);
  }
  CHECK_FALSE(tree.is_empty());
  tree.clear();
  REQUIRE(tree.is_empty());
}

TEST_CASE("preorder") {
  SUBCASE("empty") {
    BST tree;
    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "\n");
  }
  SUBCASE("multiple nodes") {
    BST tree;
    int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < 8; ++i) {
      tree.insert(nums[i]);
    }
    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "4, 2, 1, 3, 8, 5, 7, 9, \n");
  }
}

TEST_CASE("inorder") {
  SUBCASE("empty") {
    BST tree;
    std::ostringstream oss;
    tree.inorder(oss);
    REQUIRE_EQ(oss.str(), "\n");
  }
  SUBCASE("multiple nodes") {
    BST tree;
    int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < 8; ++i) {
      tree.insert(nums[i]);
    }
    std::ostringstream oss;
    tree.inorder(oss);
    REQUIRE_EQ(oss.str(), "1, 2, 3, 4, 5, 7, 8, 9, \n");
  }
}

TEST_CASE("postorder") {
  SUBCASE("empty") {
    BST tree;
    std::ostringstream oss;
    tree.postorder(oss);
    REQUIRE_EQ(oss.str(), "\n");
  }
  SUBCASE("multiple nodes") {
    BST tree;
    int nums[8] = {4, 2, 8, 1, 3, 5, 7, 9};
    for (int i = 0; i < 8; ++i) {
      tree.insert(nums[i]);
    }
    std::ostringstream oss;
    tree.postorder(oss);
    REQUIRE_EQ(oss.str(), "1, 3, 2, 7, 5, 9, 8, 4, \n");
  }
}
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
    for (int i = 0; i < 3; ++i) {
        tree.insert(i);
    }

    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "1, 0, 2, \n");
  }

  SUBCASE("Inorder Traversal: Linear Insertions") {
    for (int i = 0; i < 10; ++i) {
        tree.insert(i);
    }

    std::ostringstream oss;
    std::ostringstream oss2;
    tree.inorder(oss);
    tree.remove(6);
    tree.inorder(oss2);
    REQUIRE_EQ(oss.str(), "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \n");
    REQUIRE_EQ(oss2.str(), "0, 1, 2, 3, 4, 5, 7, 8, 9, \n");
  }

  SUBCASE("Inorder Traversal: Random Insertions") {
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(8);
    tree.insert(5);
    tree.insert(0);
    tree.insert(9);
    tree.insert(3);
    tree.insert(7);
    std::ostringstream oss;
    tree.inorder(oss);
    REQUIRE_EQ(oss.str(), "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \n");
  }

  SUBCASE("Inorder Traversal: Random Insertions 2") {
    tree.insert(2);
    tree.insert(8);
    tree.insert(7);
    tree.insert(6);
    tree.insert(4);
    tree.insert(1);
    tree.insert(9);
    tree.insert(0);
    tree.insert(5);
    tree.insert(3);
    std::ostringstream oss;
    tree.inorder(oss);
    REQUIRE_EQ(oss.str(), "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \n");
  }

  SUBCASE("Inorder Traversal: Random Insertions 3") {
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(8);
    tree.insert(0);
    tree.insert(3);
    tree.insert(2);
    tree.insert(9);
    tree.insert(1);
    std::ostringstream oss;
    tree.inorder(oss);
    REQUIRE_EQ(oss.str(), "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \n");
  }

  SUBCASE("Postorder Traversal: Linear Insertions") {
    for (int i = 0; i < 10; ++i) {
        tree.insert(i);
    }

    std::ostringstream oss;
    std::ostringstream oss2;
    tree.postorder(oss);
    tree.remove(6);
    tree.postorder(oss2);
    REQUIRE_EQ(oss.str(), "0, 2, 1, 4, 6, 5, 8, 9, 7, 3, \n");
    REQUIRE_EQ(oss2.str(), "0, 2, 1, 4, 5, 8, 9, 7, 3, \n");
  }

  SUBCASE("Postorder Traversal: Random Insertions") {
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(8);
    tree.insert(5);
    tree.insert(0);
    tree.insert(9);
    tree.insert(3);
    tree.insert(7);
    std::ostringstream oss;
    tree.postorder(oss);
    REQUIRE_EQ(oss.str(), "0, 2, 3, 1, 5, 7, 6, 9, 8, 4, \n");
  }

  SUBCASE("Postorder Traversal: Random Insertions 2") {
    tree.insert(2);
    tree.insert(8);
    tree.insert(7);
    tree.insert(6);
    tree.insert(4);
    tree.insert(1);
    tree.insert(9);
    tree.insert(0);
    tree.insert(5);
    tree.insert(3);
    std::ostringstream oss;
    tree.postorder(oss);
    REQUIRE_EQ(oss.str(), "0, 2, 3, 1, 5, 6, 8, 9, 7, 4, \n");
  }

  SUBCASE("Postorder Traversal: Random Insertions 3") {
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(8);
    tree.insert(0);
    tree.insert(3);
    tree.insert(2);
    tree.insert(9);
    tree.insert(1);
    std::ostringstream oss;
    tree.postorder(oss);
    REQUIRE_EQ(oss.str(), "0, 2, 1, 4, 3, 6, 8, 9, 7, 5, \n");
  }

  SUBCASE("Preorder Traversal: Linear Insertions") {
    for (int i = 0; i < 10; ++i) {
        tree.insert(i);
    }

    std::ostringstream oss;
    std::ostringstream oss2;
    tree.preorder(oss);
    tree.remove(6);
    tree.preorder(oss2);
    REQUIRE_EQ(oss.str(), "3, 1, 0, 2, 7, 5, 4, 6, 9, 8, \n");
    REQUIRE_EQ(oss2.str(), "3, 1, 0, 2, 7, 5, 4, 9, 8, \n");
  }

  SUBCASE("Preorder Traversal: Random Insertions") {
    tree.insert(4);
    tree.insert(2);
    tree.insert(6);
    tree.insert(1);
    tree.insert(8);
    tree.insert(5);
    tree.insert(0);
    tree.insert(9);
    tree.insert(3);
    tree.insert(7);
    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "4, 1, 0, 3, 2, 8, 6, 5, 7, 9, \n");
  }

  SUBCASE("Preorder Traversal: Random Insertions 2") {
    tree.insert(2);
    tree.insert(8);
    tree.insert(7);
    tree.insert(6);
    tree.insert(4);
    tree.insert(1);
    tree.insert(9);
    tree.insert(0);
    tree.insert(5);
    tree.insert(3);
    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "4, 1, 0, 3, 2, 7, 6, 5, 9, 8, \n");
  }

  SUBCASE("Preorder Traversal: Random Insertions 3") {
    tree.insert(6);
    tree.insert(4);
    tree.insert(5);
    tree.insert(7);
    tree.insert(8);
    tree.insert(0);
    tree.insert(3);
    tree.insert(2);
    tree.insert(9);
    tree.insert(1);
    std::ostringstream oss;
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "5, 3, 1, 0, 2, 4, 7, 6, 9, 8, \n");
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

  SUBCASE("Height of Large Tree: Linear Insertions") {
    for (int i = 0 ; i < 256 ; ++i) {
        tree.insert(i);
    }
    REQUIRE(tree.height() == 8);
  }

  SUBCASE("Height of Large Tree: Reverse Linear Insertions") {
    for (int i = 255 ; i >= 0 ; --i) {
        tree.insert(i);
    }
    REQUIRE(tree.height() == 8);
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
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
    tree.inorder(oss);
    REQUIRE_EQ(oss.str(), "0, 1, 2, 3, 4, 5, 6, 7, 8, 9, \n");
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
    tree.postorder(oss);
    REQUIRE_EQ(oss.str(), "0, 2, 1, 4, 6, 5, 8, 9, 7, 3, \n");
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
    tree.preorder(oss);
    REQUIRE_EQ(oss.str(), "3, 1, 0, 2, 7, 5, 4, 6, 9, 8, \n");
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

TEST_CASE("max") {
  RBTree tree;
  SUBCASE("Max is Root: 1 Node") {
    tree.insert(10);
    REQUIRE_EQ(tree.max(), 10);
  }

  SUBCASE("Max is Root: 2 Nodes") {
    tree.insert(10);
    tree.insert(20);
    REQUIRE_EQ(tree.max(), 20);
  }

  SUBCASE("Max is Internal") {
    for (int i = 0; i < 10; ++i)
      tree.insert(i);
    REQUIRE_EQ(tree.max(), 9);
  }

  SUBCASE("Max is Leaf") {
    for (int i = 0; i < 11; ++i)
      tree.insert(i);
    REQUIRE_EQ(tree.max(), 10);
  }
}

TEST_CASE("min") {
  RBTree tree;
  SUBCASE("Min is Root") {
    tree.insert(10);
    REQUIRE_EQ(tree.min(), 10);
  }

  SUBCASE("Min is Leaf") {
    for (int i = 1; i < 10; ++i)
      tree.insert(i);
    REQUIRE_EQ(tree.min(), 1);
  }
}

TEST_CASE("removeMax") {
  RBTree tree;
  std::ostringstream oss;
  SUBCASE("Max is Root: 1 Node") {
    tree.insert(10);
    tree.removeMax();
    REQUIRE_FALSE(tree.search(10));
  }

  SUBCASE("Max is Root: 2 Nodes") {
    tree.insert(10);
    tree.insert(20);
    tree.removeMax();
    REQUIRE_FALSE(tree.search(20));
  }

  SUBCASE("Max is Internal") {
    for (int i = 0; i < 10; ++i)
      tree.insert(i);
    tree.removeMax();
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "3, 1, 0, 2, 7, 5, 4, 6, 8, \n");
    REQUIRE_FALSE(tree.search(9));
  }

  SUBCASE("Max is Leaf at Bottom") {
    for (int i = 0; i < 11; ++i)
      tree.insert(i);
    tree.removeMax();
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "3, 1, 0, 2, 7, 5, 4, 6, 9, 8, \n");
    REQUIRE_FALSE(tree.search(10));
  }

  SUBCASE("Max is Leaf above Bottom") {
    for (int i = 0; i < 13; ++i)
      tree.insert(i);
    tree.removeMax();
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "7, 3, 1, 0, 2, 5, 4, 6, 9, 8, 11, 10, \n");
    REQUIRE_FALSE(tree.search(12));
  }
}

TEST_CASE("removeMin") {
  RBTree tree;
  std::ostringstream oss;
  SUBCASE("Min is Root") {
    tree.insert(10);
    tree.removeMin();
    REQUIRE_FALSE(tree.search(10));
  }

  SUBCASE("Min is Leaf at Bottom") {
    for (int i = 1; i < 10; ++i)
      tree.insert(i);
    tree.removeMin();
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "6, 4, 3, 2, 5, 8, 7, 9, \n");
    REQUIRE_FALSE(tree.search(1));
  }

  SUBCASE("Min is Leaf above Bottom") {
    for (int i = 0; i < 10; ++i)
      tree.insert(i);
    tree.removeMin();
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "5, 3, 2, 1, 4, 7, 6, 9, 8, \n");
    REQUIRE_FALSE(tree.search(0));
  }

  SUBCASE("Min in Complete Tree") {
    for (int i = 1; i < 8; ++i)
      tree.insert(i);
    tree.removeMin();
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "6, 4, 3, 2, 5, 7, \n");
    REQUIRE_FALSE(tree.search(1));
  }
}

TEST_CASE("Delete Method") {
  RBTree tree;
  for (int i = 0; i < 10; ++i) {
    tree.insert(i);
  }
  SUBCASE("Leaf Node") {
    tree.remove(2);
    REQUIRE(tree.search(2) == 0);
    REQUIRE(tree.search(0) == 1);
    REQUIRE(tree.search(4) == 1);
  }
  
  SUBCASE("Internal Node: 7") {
    tree.remove(7);
    std::ostringstream oss;
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "3, 1, 0, 2, 8, 5, 4, 6, 9, \n");
    REQUIRE(tree.search(7) == 0);
  }

  SUBCASE("Internal Node: 9") {
    tree.remove(9);
    std::ostringstream oss;
    tree.preorder(oss);
    CHECK_EQ(oss.str(), "3, 1, 0, 2, 7, 5, 4, 6, 8, \n");
    REQUIRE(tree.search(9) == 0);
  }
  
  SUBCASE("Internal Node: 1") {
    tree.remove(1);
    std::ostringstream oss;
    tree.preorder(oss);
    //This order may be off
    CHECK_EQ(oss.str(), "5, 3, 2, 0, 4, 7, 6, 9, 8, \n");
    REQUIRE(tree.search(1) == 0);
  }
}

TEST_CASE("Clear") {
  RBTree tree;
  SUBCASE("Clear empty tree doesn't break it") {
    tree.clear();
    tree.insert(1);
    REQUIRE(tree.search(1));
  }

  SUBCASE("Just the root") {
    tree.insert(1);
    tree.clear();
    REQUIRE_FALSE(tree.search(1));
  }

  SUBCASE("Nontrivial tree") {
    for (int i = 1; i <= 10; ++i)
      tree.insert(i);
    tree.clear();
    for (int i = 1; i <= 10; ++i) {
      REQUIRE_FALSE(tree.search(i));
    }
  }
}
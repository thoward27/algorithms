#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "RBTree.hpp"

TEST_CASE("Constructor") {
    RBTree test;
    CHECK(test.getRoot() == nullptr);
}

TEST_CASE("Get Root Method") {
    RBTree test;
    SUBCASE("No Root"){
        REQUIRE(test.getRoot() == nullptr);
    }

    SUBCASE("Initial Root") {
        test.insert(1, test.getRoot());
        REQUIRE(test.getRoot() != nullptr);
    }
}

TEST_CASE("Insert Method") {
    RBTree test;
    SUBCASE("To Root") {
        test.insert(3, test.getRoot());
        REQUIRE(test.getRoot() != nullptr);
        REQUIRE(test.search(3) == 1);
    }
    SUBCASE("Beyond Root: Linear Insertions") {
        for(int i = 0 ; i < 10 ; ++i) {
            test.insert(i, test.getRoot());
            REQUIRE(test.search(i) == 1);
        }
    }
    SUBCASE("Beyond Root: Large Linear Insertions") {
        for(int i = 0 ; i < 100 ; ++i) {
            test.insert(i, test.getRoot());
            REQUIRE(test.search(i) == 1);
        }
    }
    SUBCASE("Beyond Root: Reverse Linear Insertions") {
        for(int i = 10 ; i > 0 ; --i) {
            test.insert(i, test.getRoot());
            REQUIRE(test.search(i) == 1);
        }
        
    }
    SUBCASE("Beyond Root: Random Insertions") {
        test.insert(5, test.getRoot()); 
        test.insert(2, test.getRoot()); 
        test.insert(6, test.getRoot()); 
        test.insert(4, test.getRoot()); 
        test.insert(3, test.getRoot()); 
        test.insert(7, test.getRoot()); 
        test.insert(0, test.getRoot()); 
        REQUIRE(test.search(3) == 1);
        REQUIRE(test.search(0) == 1);
        REQUIRE(test.search(5) == 1);
        REQUIRE(test.search(6) == 1);
        REQUIRE(test.search(4) == 1);
    }

    SUBCASE("Beyond Root: Random Insertions 2") {
        test.insert(1, test.getRoot()); 
        test.insert(4, test.getRoot()); 
        test.insert(2, test.getRoot()); 
        test.insert(5, test.getRoot()); 
        test.insert(9, test.getRoot()); 
        test.insert(0, test.getRoot()); 
        test.insert(3, test.getRoot()); 
        test.insert(7, test.getRoot()); 
        REQUIRE(test.search(3) == 1);
        REQUIRE(test.search(0) == 1);
        REQUIRE(test.search(5) == 1);
        REQUIRE(test.search(1) == 1);
        REQUIRE(test.search(4) == 1);
    }
}

TEST_CASE("Delete Method") {
    RBTree test;
    for(int i = 0 ; i < 10 ; ++i) {
        test.insert(i, test.getRoot());
    }
    test.deletekey(test.getRoot(), 2);
    REQUIRE(test.search(2) == 0);
    REQUIRE(test.search(0) == 1);
    REQUIRE(test.search(4) == 1);
}
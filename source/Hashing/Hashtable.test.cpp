#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "Hashtable.hpp"

TEST_CASE("Default Constructor") {
    HashTable test;
    REQUIRE(test.Size() == 5);
}


TEST_CASE("Initialized Constructor") {
    HashTable test(7);
    REQUIRE(test.Size() == 7);
}


TEST_CASE("Is_Empty") {
    HashTable test;
    REQUIRE(test.is_empty() == 1);
}


TEST_CASE("Insert") {
    HashTable test;
    SUBCASE("Trivial Case") {
        String str1("Hello");
        String str2("test");
        test.insert(str1, 1);
        REQUIRE(test.is_empty() == 0);
        REQUIRE(test.search(str2) == 0);
        REQUIRE(test.search(str1) == 1);
    }
    
    SUBCASE("Multiple Insertions") {
        for (int i = 0; i < 10; ++i) {
            String str('a' + i);
            test.insert(str, i + 1);
        }
        REQUIRE_FALSE(test.is_empty());
        String test_str("test");
        REQUIRE_FALSE(test.search(test_str));
        for (int i = 0; i < 10; ++i) {
            String str('a' + i);
            REQUIRE(test.search(str));
        }
    }
}

TEST_CASE("Remove") {
    HashTable test;
    SUBCASE("Trivial Case") {
        String hello_str("Hello");
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
        String test_str("test");
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
        String hello_str("Hello");
        test.insert(hello_str, 1);
        REQUIRE_FALSE(test.is_empty());
        REQUIRE(test.get(hello_str));
    }

    SUBCASE("Similar Insertions") {
        String world_str1("World");
        String world_str2("world");
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
        char cstrings[8][20] = { "asddaweg", "asdqrqsda", "weqasdZasd",
                                 "qeasDQWEasdz", "Daqwesd", "QecByasd",
                                 "Jkusasdqwe", "Liiqdsaqe", };
        int nums[8] = { 132, 14314, 76874, 5141, 141234, 7636, 1241236, 1523 };
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
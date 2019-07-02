#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "twostack.hpp"

TEST_CASE("Two Stack") {
  SUBCASE("Valid Expressions") {
    REQUIRE_EQ(twostack((char*)"(1 + 1)"), 2.0);
    REQUIRE_EQ(twostack((char*)"(1 - 1)"), 0.0);
    REQUIRE_EQ(twostack((char*)"(1 * 1)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(1 / 1)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(1 ^ 1)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(5 + (2 + (4 + 6)))"), 17.0);
    REQUIRE_EQ(twostack((char*)"((5 - 2) - 1)"), 2.0);
    REQUIRE_EQ(twostack((char*)"((5 / 2) / 2)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(2 ^ (2 ^ 2))"), 16.0);
    REQUIRE_EQ(twostack((char*)"(5 + (10 - (3 ^ (4 / 2))))"), 6);
    REQUIRE_EQ(twostack((char*)"(2 ^ (3 - (5 / 5)))"), 4.0);
    REQUIRE_EQ(twostack((char*)"(20 + (30 - (50 / 50)))"), 49.0);
  }
  SUBCASE("Negative Numbers") {
    REQUIRE_EQ(twostack((char*)"(1 + -1)"), 0.0);
    REQUIRE_EQ(twostack((char*)"(-1 + -1)"), -2.0);
    REQUIRE_EQ(twostack((char*)"(-10 + -15)"), -25.0);
    REQUIRE_EQ(twostack((char*)"(-10 - -15)"), 5.0);
    REQUIRE_EQ(twostack((char*)"(-10 / -10)"), 1.0);
    REQUIRE_EQ(twostack((char*)"(-1 * 5)"), -5.0);
  }
  SUBCASE("Invalid Expressions") {
    REQUIRE_THROWS(twostack((char*)"1 + 1"));
    REQUIRE_THROWS(twostack((char*)"(1 + 1"));
    REQUIRE_THROWS(twostack((char*)""));
  }
}

TEST_CASE("Modulo") {
  REQUIRE_EQ(twostack((char*)"(5 % 5)"), 0.0);
  REQUIRE_EQ(twostack((char*)"(5 % 4)"), 1.0);
}
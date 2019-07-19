#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "karprabin.hpp"

TEST_CASE("Trivial") {
  REQUIRE(karp_rabin(String((char*)"Test"), String((char*)"Test")));
  REQUIRE_FALSE(karp_rabin(String((char*)"A"), String((char*)"B")));
}
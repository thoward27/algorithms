#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include <string>
#include "karprabin.hpp"

TEST_CASE("Trivial") {
  REQUIRE(karp_rabin(String((char*)"Test"), String((char*)"Test")));
  REQUIRE_FALSE(karp_rabin(String((char*)"A"), String((char*)"B")));
}

TEST_CASE("Trivial 2") {
  String s1 = (char*)"eqfsdasdfqwregaczxqrasdwasdczxcgadzxc";
  String s2 = (char*)"a";
  String s3 = (char*)"Abccedadea";
  String s4 = (char*)"B";
  REQUIRE(karp_rabin(s1,s2));
  REQUIRE_FALSE(karp_rabin(s3,s4));
}

TEST_CASE("Trivial 3") {
  REQUIRE(karp_rabin(String((char*)"eqfsdasdfqwregaczxqrasdwasdczxcgadzxc"), String((char*)"asd")));
  REQUIRE_FALSE(karp_rabin(String((char*)"zxcadadsavzxvgasdfqwe"), String((char*)"B")));
}

TEST_CASE("Large String + Easy Pattern") {
  String s1 =(char*)"HelloWorld";
  String s2 = (char*)"dbuhasdmzoxlcnoiawrjpjpfaiholuhosadhp;uigdholihHelloWorlduhafohoijvciahsdolighqlhfgbkjuaygsdujhasfylhaiosdhiusgfhihjOAIUHDOPAIHSOD";
  REQUIRE(karp_rabin(s2, s1));
}

TEST_CASE("Large String + Large Pattern") {
  String s1 = (char*)"HelloWorld,IAmAComputerProgram,AndThisIsAKarpRabinAlgorithm";
  String s2 = (char*)"dbuhasdmzoxlcnoiawrjpjpfaiholuhosadhp;uigdholihHelloWorld,IAmAComputerProgram,AndThisIsAKarpRabinAlgorithmuhafohoijvciahsdolighqlhfgbkjuaygsdujhasfylhaiosdhiusgfhihjOAIUHDOPAIHSOD";
  REQUIRE(karp_rabin(s2, s1));
}

TEST_CASE("Large String + Large Pattern + Case Sensitivity") {
  String s1 = (char*)"HelloWorld,IAmAComputerProgram,AndThisIsAKarpRabinAlgorithm";
  String s2 = (char*)"dbuhasdmzoxlcnoiawrjpjpfaiholuhosadhp;uigdholihHelloWorld,IAmAComputerProgram,AndThisIsAKarpRabinAlgorithmuhafohoijvciahsdolighqlhfgbkjuaygsdujhasfylhaiosdhiusgfhihjOAIUHDOPAIHSOD";
  REQUIRE(karp_rabin(s2, s1));
}

TEST_CASE("Pattern Larger Than String") {
  String s1 = (char*)"HelloWorld,IAmAComputerProgram,AndThisIsAKarpRabinAlgorithm";
  String s2 = (char*)"dhHelloWorld,IAmAComputerPaiosdhiusgfhihjOAIUHDOPAIHSOD";
  REQUIRE_FALSE(karp_rabin(s2, s1));
}

TEST_CASE("Patterns Not In String") {
  String s1 = (char*)"HelloIAmAComputerProgram,AndThisIsAKarpRabinAlgorithm";
  String s2 = (char*)"HelloWerProgram,AndThisIsAKarpRabinAlgorithm";
  String s3 = (char*)"HelloWerPrsAKarpRabinAlgorithm";
  String s4 = (char*)"HelloWerPrsAithm";
  String s5 = (char*)"dhHelloWorld,IAmAComputerPaiosdhiusgfhihjOAIUHDOPAIHSOD";
  REQUIRE_FALSE(karp_rabin(s5, s1));
  REQUIRE_FALSE(karp_rabin(s5, s2));
  REQUIRE_FALSE(karp_rabin(s5, s3));
  REQUIRE_FALSE(karp_rabin(s5, s4));
}
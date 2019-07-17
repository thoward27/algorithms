#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "lexicographic.hpp"

TEST_CASE("Sorting Strings") {
  String* s1 = new String((char*)"abc");
  String* s2 = new String((char*)"bcd");
  String* s3 = new String((char*)"acde");
  String* arr[] = {s1, s2, s3};
  sort(arr, 3);
  CHECK(arr[0]->compare(*s1));
  CHECK(arr[1]->compare(*s3));
  CHECK(arr[2]->compare(*s2));
  delete s1;
  delete s2;
  delete s3;
}
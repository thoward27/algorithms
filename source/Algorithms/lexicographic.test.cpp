#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "lexicographic.hpp"

TEST_CASE("Single Characters: Sorted") {
  SUBCASE("abc") {
    String s1((char*)"a");
    String s2((char*)"b");
    String s3((char*)"c");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"b"));
    CHECK(arr[2]->compare((char*)"c"));
  }
  SUBCASE("xyz") {
    String s1((char*)"x");
    String s2((char*)"y");
    String s3((char*)"z");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"x"));
    CHECK(arr[1]->compare((char*)"y"));
    CHECK(arr[2]->compare((char*)"z"));
  }
  SUBCASE("Alphabet") {
    String s1((char*)"a");
    String s2((char*)"b");
    String s3((char*)"c");
    String s4((char*)"d");
    String s5((char*)"e");
    String s6((char*)"f");
    String s7((char*)"g");
    String s8((char*)"h");
    String s9((char*)"i");
    String s10((char*)"j");
    String s11((char*)"k");
    String s12((char*)"l");
    String s13((char*)"m");
    String s14((char*)"n");
    String s15((char*)"o");
    String s16((char*)"p");
    String s17((char*)"q");
    String s18((char*)"r");
    String s19((char*)"s");
    String s20((char*)"t");
    String s21((char*)"u");
    String s22((char*)"v");
    String s23((char*)"w");
    String s24((char*)"x");
    String s25((char*)"y");
    String s26((char*)"z");
    String* arr[] = {&s1,  &s2,  &s3,  &s4,  &s5,  &s6,  &s7,  &s8,  &s9,
                     &s10, &s11, &s12, &s13, &s14, &s15, &s16, &s17, &s18,
                     &s19, &s20, &s21, &s22, &s23, &s24, &s25, &s26};
    sort(arr, 26);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"b"));
    CHECK(arr[2]->compare((char*)"c"));
    CHECK(arr[3]->compare((char*)"d"));
    CHECK(arr[4]->compare((char*)"e"));
    CHECK(arr[5]->compare((char*)"f"));
    CHECK(arr[6]->compare((char*)"g"));
    CHECK(arr[7]->compare((char*)"h"));
    CHECK(arr[8]->compare((char*)"i"));
    CHECK(arr[9]->compare((char*)"j"));
    CHECK(arr[10]->compare((char*)"k"));
    CHECK(arr[11]->compare((char*)"l"));
    CHECK(arr[12]->compare((char*)"m"));
    CHECK(arr[13]->compare((char*)"n"));
    CHECK(arr[14]->compare((char*)"o"));
    CHECK(arr[15]->compare((char*)"p"));
    CHECK(arr[16]->compare((char*)"q"));
    CHECK(arr[17]->compare((char*)"r"));
    CHECK(arr[18]->compare((char*)"s"));
    CHECK(arr[19]->compare((char*)"t"));
    CHECK(arr[20]->compare((char*)"u"));
    CHECK(arr[21]->compare((char*)"v"));
    CHECK(arr[22]->compare((char*)"w"));
    CHECK(arr[23]->compare((char*)"x"));
    CHECK(arr[24]->compare((char*)"y"));
    CHECK(arr[25]->compare((char*)"z"));
  }
}

TEST_CASE("Single Characters: Unsorted") {
  SUBCASE("1") {
    String s1((char*)"b");
    String s2((char*)"c");
    String s3((char*)"a");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"b"));
    CHECK(arr[2]->compare((char*)"c"));
  }
  SUBCASE("2") {
    String s1((char*)"z");
    String s2((char*)"x");
    String s3((char*)"y");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"x"));
    CHECK(arr[1]->compare((char*)"y"));
    CHECK(arr[2]->compare((char*)"z"));
  }
  SUBCASE("Scrambled Alphabet") {
    String s1((char*)"b");
    String s2((char*)"c");
    String s3((char*)"v");
    String s4((char*)"d");
    String s5((char*)"h");
    String s6((char*)"i");
    String s7((char*)"e");
    String s8((char*)"g");
    String s9((char*)"f");
    String s10((char*)"j");
    String s11((char*)"m");
    String s12((char*)"l");
    String s13((char*)"k");
    String s14((char*)"n");
    String s15((char*)"z");
    String s16((char*)"q");
    String s17((char*)"p");
    String s18((char*)"t");
    String s19((char*)"r");
    String s20((char*)"s");
    String s21((char*)"u");
    String s22((char*)"a");
    String s23((char*)"x");
    String s24((char*)"y");
    String s25((char*)"w");
    String s26((char*)"o");
    String* arr[] = {&s1, &s2, &s3, &s4, &s5, &s6, &s7, &s8, &s9,
                     &s10, &s11, &s12, &s13, &s14, &s15, &s16, &s17, &s18,
                     &s19, &s20, &s21, &s22, &s23, &s24, &s25, &s26};
    sort(arr, 26);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"b"));
    CHECK(arr[2]->compare((char*)"c"));
    CHECK(arr[3]->compare((char*)"d"));
    CHECK(arr[4]->compare((char*)"e"));
    CHECK(arr[5]->compare((char*)"f"));
    CHECK(arr[6]->compare((char*)"g"));
    CHECK(arr[7]->compare((char*)"h"));
    CHECK(arr[8]->compare((char*)"i"));
    CHECK(arr[9]->compare((char*)"j"));
    CHECK(arr[10]->compare((char*)"k"));
    CHECK(arr[11]->compare((char*)"l"));
    CHECK(arr[12]->compare((char*)"m"));
    CHECK(arr[13]->compare((char*)"n"));
    CHECK(arr[14]->compare((char*)"o"));
    CHECK(arr[15]->compare((char*)"p"));
    CHECK(arr[16]->compare((char*)"q"));
    CHECK(arr[17]->compare((char*)"r"));
    CHECK(arr[18]->compare((char*)"s"));
    CHECK(arr[19]->compare((char*)"t"));
    CHECK(arr[20]->compare((char*)"u"));
    CHECK(arr[21]->compare((char*)"v"));
    CHECK(arr[22]->compare((char*)"w"));
    CHECK(arr[23]->compare((char*)"x"));
    CHECK(arr[24]->compare((char*)"y"));
    CHECK(arr[25]->compare((char*)"z"));
  }
}

TEST_CASE("Strings: Sorted") {
  SUBCASE("Random 1") {
    String s1((char*)"lmno");
    String s2((char*)"pqrs");
    String s3((char*)"tuvw");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"lmno"));
    CHECK(arr[1]->compare((char*)"pqrs"));
    CHECK(arr[2]->compare((char*)"tuvw"));
  }
  SUBCASE("Different Length Strings") {
    String s1((char*)"a");
    String s2((char*)"ab");
    String s3((char*)"abc");
    String s4((char*)"abcd");
    String s5((char*)"abcde");
    String* arr[] = {&s1, &s2, &s3, &s4, &s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"ab"));
    CHECK(arr[2]->compare((char*)"abc"));
    CHECK(arr[3]->compare((char*)"abcd"));
    CHECK(arr[4]->compare((char*)"abcde"));
  }
}

TEST_CASE("Strings: Unsorted") {
  SUBCASE("1") {
    String s1((char*)"abc");
    String s2((char*)"bcd");
    String s3((char*)"acde");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"abc"));
    CHECK(arr[1]->compare((char*)"acde"));
    CHECK(arr[2]->compare((char*)"bcd"));
  }
  SUBCASE("2") {
    String s1((char*)"tuvw");
    String s2((char*)"lmno");
    String s3((char*)"pqrs");
    String* arr[] = {&s1, &s2, &s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"lmno"));
    CHECK(arr[1]->compare((char*)"pqrs"));
    CHECK(arr[2]->compare((char*)"tuvw"));
  }
  SUBCASE("Random Test 1") {
    String s1((char*)"fread");
    String s2((char*)"feadd");
    String s3((char*)"draef");
    String s4((char*)"drsda");
    String s5((char*)"ddeq");
    String* arr[] = {&s1, &s2, &s3, &s4, &s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"ddeq"));
    CHECK(arr[1]->compare((char*)"draef"));
    CHECK(arr[2]->compare((char*)"drsda"));
    CHECK(arr[3]->compare((char*)"feadd"));
    CHECK(arr[4]->compare((char*)"fread"));
  }
  SUBCASE("Random Test 2") {
    String s1((char*)"dasdweq");
    String s2((char*)"asdqwead");
    String s3((char*)"zxcawe");
    String s4((char*)"vasdzx");
    String s5((char*)"daqwe");
    String* arr[] = {&s1, &s2, &s3, &s4, &s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"asdqwead"));
    CHECK(arr[1]->compare((char*)"daqwe"));
    CHECK(arr[2]->compare((char*)"dasdweq"));
    CHECK(arr[3]->compare((char*)"vasdzx"));
    CHECK(arr[4]->compare((char*)"zxcawe"));
  }
  SUBCASE("Random Test 3") {
    String s1((char*)"hnams");
    String s2((char*)"ham");
    String s3((char*)"hjus");
    String s4((char*)"hrtasd");
    String s5((char*)"husda");
    String* arr[] = {&s1, &s2, &s3, &s4, &s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"ham"));
    CHECK(arr[1]->compare((char*)"hjus"));
    CHECK(arr[2]->compare((char*)"hnams"));
    CHECK(arr[3]->compare((char*)"hrtasd"));
    CHECK(arr[4]->compare((char*)"husda"));
  }
  SUBCASE("Random Test 4") {
    String s1((char*)"jushyg");
    String s2((char*)"jhays");
    String s3((char*)"jasbsd");
    String s4((char*)"jlzmx");
    String s5((char*)"jmnhhasd");
    String* arr[] = {&s1, &s2, &s3, &s4, &s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"jasbsd"));
    CHECK(arr[1]->compare((char*)"jhays"));
    CHECK(arr[2]->compare((char*)"jlzmx"));
    CHECK(arr[3]->compare((char*)"jmnhhasd"));
    CHECK(arr[4]->compare((char*)"jushyg"));
  }
}

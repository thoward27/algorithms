#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "lexicographic.hpp"

TEST_CASE("Single Characters: Sorted") {
  SUBCASE("abc") {
    String* s1 = new String((char*)"a");
    String* s2 = new String((char*)"b");
    String* s3 = new String((char*)"c");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"b"));
    CHECK(arr[2]->compare((char*)"c"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("xyz") {
    String* s1 = new String((char*)"x");
    String* s2 = new String((char*)"y");
    String* s3 = new String((char*)"z");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"x"));
    CHECK(arr[1]->compare((char*)"y"));
    CHECK(arr[2]->compare((char*)"z"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("Alphabet") {
    String* s1 = new String((char*)"a");
    String* s2 = new String((char*)"b");
    String* s3 = new String((char*)"c");
    String* s4 = new String((char*)"d");
    String* s5 = new String((char*)"e");
    String* s6 = new String((char*)"f");
    String* s7 = new String((char*)"g");
    String* s8 = new String((char*)"h");
    String* s9 = new String((char*)"i");
    String* s10 = new String((char*)"j");
    String* s11 = new String((char*)"k");
    String* s12 = new String((char*)"l");
    String* s13 = new String((char*)"m");
    String* s14 = new String((char*)"n");
    String* s15 = new String((char*)"o");
    String* s16 = new String((char*)"p");
    String* s17 = new String((char*)"q");
    String* s18 = new String((char*)"r");
    String* s19 = new String((char*)"s");
    String* s20 = new String((char*)"t");
    String* s21 = new String((char*)"u");
    String* s22 = new String((char*)"v");
    String* s23 = new String((char*)"w");
    String* s24 = new String((char*)"x");
    String* s25 = new String((char*)"y");
    String* s26 = new String((char*)"z");
    String* arr[] = {s1,  s2,  s3,  s4,  s5,  s6,  s7,  s8,  s9,
                     s10, s11, s12, s13, s14, s15, s16, s17, s18,
                     s19, s20, s21, s22, s23, s24, s25, s26};
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
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
    delete s8;
    delete s9;
    delete s10;
    delete s11;
    delete s12;
    delete s13;
    delete s14;
    delete s15;
    delete s16;
    delete s17;
    delete s18;
    delete s19;
    delete s20;
    delete s21;
    delete s22;
    delete s23;
    delete s24;
    delete s25;
    delete s26;
  }
}

TEST_CASE("Single Characters: Unsorted") {
  SUBCASE("1") {
    String* s1 = new String((char*)"b");
    String* s2 = new String((char*)"c");
    String* s3 = new String((char*)"a");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"b"));
    CHECK(arr[2]->compare((char*)"c"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("2") {
    String* s1 = new String((char*)"z");
    String* s2 = new String((char*)"x");
    String* s3 = new String((char*)"y");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"x"));
    CHECK(arr[1]->compare((char*)"y"));
    CHECK(arr[2]->compare((char*)"z"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("Scrambled Alphabet") {
    String* s1 = new String((char*)"b");
    String* s2 = new String((char*)"c");
    String* s3 = new String((char*)"v");
    String* s4 = new String((char*)"d");
    String* s5 = new String((char*)"h");
    String* s6 = new String((char*)"i");
    String* s7 = new String((char*)"e");
    String* s8 = new String((char*)"g");
    String* s9 = new String((char*)"f");
    String* s10 = new String((char*)"j");
    String* s11 = new String((char*)"m");
    String* s12 = new String((char*)"l");
    String* s13 = new String((char*)"k");
    String* s14 = new String((char*)"n");
    String* s15 = new String((char*)"z");
    String* s16 = new String((char*)"q");
    String* s17 = new String((char*)"p");
    String* s18 = new String((char*)"t");
    String* s19 = new String((char*)"r");
    String* s20 = new String((char*)"s");
    String* s21 = new String((char*)"u");
    String* s22 = new String((char*)"a");
    String* s23 = new String((char*)"x");
    String* s24 = new String((char*)"y");
    String* s25 = new String((char*)"w");
    String* s26 = new String((char*)"o");
    String* arr[] = {s1,  s2,  s3,  s4,  s5,  s6,  s7,  s8,  s9,
                     s10, s11, s12, s13, s14, s15, s16, s17, s18,
                     s19, s20, s21, s22, s23, s24, s25, s26};
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
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
    delete s6;
    delete s7;
    delete s8;
    delete s9;
    delete s10;
    delete s11;
    delete s12;
    delete s13;
    delete s14;
    delete s15;
    delete s16;
    delete s17;
    delete s18;
    delete s19;
    delete s20;
    delete s21;
    delete s22;
    delete s23;
    delete s24;
    delete s25;
    delete s26;
  }
}

TEST_CASE("Strings: Sorted") {
  SUBCASE("Random 1") {
    String* s1 = new String((char*)"lmno");
    String* s2 = new String((char*)"pqrs");
    String* s3 = new String((char*)"tuvw");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"lmno"));
    CHECK(arr[1]->compare((char*)"pqrs"));
    CHECK(arr[2]->compare((char*)"tuvw"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("Different Length Strings") {
    String* s1 = new String((char*)"a");
    String* s2 = new String((char*)"ab");
    String* s3 = new String((char*)"abc");
    String* s4 = new String((char*)"abcd");
    String* s5 = new String((char*)"abcde");
    String* arr[] = {s1, s2, s3, s4, s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"a"));
    CHECK(arr[1]->compare((char*)"ab"));
    CHECK(arr[2]->compare((char*)"abc"));
    CHECK(arr[3]->compare((char*)"abcd"));
    CHECK(arr[4]->compare((char*)"abcde"));
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
  }
}

TEST_CASE("Strings: Unsorted") {
  SUBCASE("1") {
    String* s1 = new String((char*)"abc");
    String* s2 = new String((char*)"bcd");
    String* s3 = new String((char*)"acde");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"abc"));
    CHECK(arr[1]->compare((char*)"acde"));
    CHECK(arr[2]->compare((char*)"bcd"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("2") {
    String* s1 = new String((char*)"tuvw");
    String* s2 = new String((char*)"lmno");
    String* s3 = new String((char*)"pqrs");
    String* arr[] = {s1, s2, s3};
    sort(arr, 3);
    CHECK(arr[0]->compare((char*)"lmno"));
    CHECK(arr[1]->compare((char*)"pqrs"));
    CHECK(arr[2]->compare((char*)"tuvw"));
    delete s1;
    delete s2;
    delete s3;
  }
  SUBCASE("Random Test 1") {
    String* s1 = new String((char*)"fread");
    String* s2 = new String((char*)"feadd");
    String* s3 = new String((char*)"draef");
    String* s4 = new String((char*)"drsda");
    String* s5 = new String((char*)"ddeq");
    String* arr[] = {s1, s2, s3, s4, s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"ddeq"));
    CHECK(arr[1]->compare((char*)"draef"));
    CHECK(arr[2]->compare((char*)"drsda"));
    CHECK(arr[3]->compare((char*)"feadd"));
    CHECK(arr[4]->compare((char*)"fread"));
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
  }
  SUBCASE("Random Test 2") {
    String* s1 = new String((char*)"dasdweq");
    String* s2 = new String((char*)"asdqwead");
    String* s3 = new String((char*)"zxcawe");
    String* s4 = new String((char*)"vasdzx");
    String* s5 = new String((char*)"daqwe");
    String* arr[] = {s1, s2, s3, s4, s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"asdqwead"));
    CHECK(arr[1]->compare((char*)"daqwe"));
    CHECK(arr[2]->compare((char*)"dasdweq"));
    CHECK(arr[3]->compare((char*)"vasdzx"));
    CHECK(arr[4]->compare((char*)"zxcawe"));
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
  }
  SUBCASE("Random Test 3") {
    String* s1 = new String((char*)"hnams");
    String* s2 = new String((char*)"ham");
    String* s3 = new String((char*)"hjus");
    String* s4 = new String((char*)"hrtasd");
    String* s5 = new String((char*)"husda");
    String* arr[] = {s1, s2, s3, s4, s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"ham"));
    CHECK(arr[1]->compare((char*)"hjus"));
    CHECK(arr[2]->compare((char*)"hnams"));
    CHECK(arr[3]->compare((char*)"hrtasd"));
    CHECK(arr[4]->compare((char*)"husda"));
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
  }
  SUBCASE("Random Test 4") {
    String* s1 = new String((char*)"jushyg");
    String* s2 = new String((char*)"jhays");
    String* s3 = new String((char*)"jasbsd");
    String* s4 = new String((char*)"jlzmx");
    String* s5 = new String((char*)"jmnhhasd");
    String* arr[] = {s1, s2, s3, s4, s5};
    sort(arr, 5);
    CHECK(arr[0]->compare((char*)"jasbsd"));
    CHECK(arr[1]->compare((char*)"jhays"));
    CHECK(arr[2]->compare((char*)"jlzmx"));
    CHECK(arr[3]->compare((char*)"jmnhhasd"));
    CHECK(arr[4]->compare((char*)"jushyg"));
    delete s1;
    delete s2;
    delete s3;
    delete s4;
    delete s5;
  }
}

#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include "doctest/doctest/doctest.h"

/** Absolute Value
 * Converts any integer to its absolute value.
 * O(1) and Omega(1), thus,
 * Theta(1)
 */
int abs_val(int x);

TEST_CASE("Testing the absolute value function") {
    CHECK(abs_val(1) == 1);
    CHECK(abs_val(-1) == 1);
    CHECK(abs_val(-60) == 60);
    CHECK(abs_val(60) == 60);
    CHECK(abs_val(33) == 33);
    CHECK(abs_val(-33) == 33);
    CHECK(abs_val(14) == 14);
    CHECK(abs_val(0) == 0);
}

/** Power
 * Raise the given base to the given power.
 * O(?)
 */
int pow(int base, int num);

TEST_CASE("Testing the power function") {
    CHECK(pow(1,0) == 1);
    CHECK(pow(10,0) == 1);
    CHECK(pow(100,0) == 1);
    CHECK(pow(1,2) == 1);
    CHECK(pow(1,5) == 1);
    CHECK(pow(1,10) == 1);
    CHECK(pow(2,1) == 2);
    CHECK(pow(2,3) == 8);
    CHECK(pow(2,5) == 32);
    CHECK(pow(5,2) == 25);
    CHECK(pow(3,3) == 27);
}

/** Logarithm
 * Brief
 * O(?)
 */
int log(int base, int num);

TEST_CASE("Testing the logarithm function") {
    CHECK(log(3,27) == 3);
    CHECK(log(2,4) == 2);
    CHECK(log(2,8) == 3);
    CHECK(log(2,10) == 3);
    CHECK(log(5,25) == 2);
}

/** Function name
 * Brief
 * O(?)
 */
int chartoint(char c);

TEST_CASE("Testing the character to integer function") {
    CHECK(chartoint('0') == 0);
    CHECK(chartoint('1') == 1);
    CHECK(chartoint('2') == 2);
    CHECK(chartoint('3') == 3);
    CHECK(chartoint('4') == 4);
    CHECK(chartoint('5') == 5);
    CHECK(chartoint('6') == 6);
    CHECK(chartoint('7') == 7);
    CHECK(chartoint('8') == 8);
    CHECK(chartoint('9') == 9);
}

/** Function name
 * Brief
 * O(?)
 */
char inttochar(int x);

TEST_CASE("Testing the integer to character function") {
    CHECK(inttochar(0) == '0');
    CHECK(inttochar(1) == '1');
    CHECK(inttochar(2) == '2');
    CHECK(inttochar(3) == '3');
    CHECK(inttochar(4) == '4');
    CHECK(inttochar(5) == '5');
    CHECK(inttochar(6) == '6');
    CHECK(inttochar(7) == '7');
    CHECK(inttochar(8) == '8');
    CHECK(inttochar(9) == '9');
}

/** Function name
 * Brief
 * O(?)
 */
char chr(int);

TEST_CASE("chr()") {
    CHECK(chr(43) == '+');
    CHECK(chr(40) == '(');
    CHECK(chr(48) == '0');
    CHECK(chr(122) == 'z');
}

/** Function name
 * Brief
 * O(?)
 */
int ord(char);

TEST_CASE("ord()") {
    CHECK(ord('c') == 99);
    CHECK(ord('O') == 79);
    CHECK(ord('|') == 124);
}

/** Function name
 * Brief
 * O(?)
 */
int max(int, int);
int max(int, int, int);

TEST_CASE("Max") {
    SUBCASE("Two variables") {
        CHECK(max(1, 2) == 2);
        CHECK(max(2, 1) == 2);
        CHECK(max(-50, 50) == 50);
        CHECK(max(0, 0) == 0);
    }
    SUBCASE("Three variables") {
        CHECK(max(1, 2, 3) == 3);
        CHECK(max(3, 2, 1) == 3);
        CHECK(max(1, 1, 1) == 1);
        CHECK(max(0, 4, 0) == 4);
    }
}

/** Function name
 * Brief
 * O(?)
 */
int min(int, int);
int min(int, int, int);

TEST_CASE("Min") {
    SUBCASE("Two variables") {
        CHECK(min(1, 2) == 1);
        CHECK(min(2, 1) == 1);
        CHECK(min(1, 1) == 1);
        CHECK(min(-20, 20) == -20);
    }
    SUBCASE("Three variables") {
        CHECK(min(1, 2, 3) == 1);
        CHECK(min(3, 2, 1) == 1);
        CHECK(min(1, 1, 1) == 1);
        CHECK(min(0, 4, 0) == 0);
    }
}

/** Function name
 * Brief
 * O(?)
 */
int round(double, char);

TEST_CASE("Round a float.") {
    SUBCASE("Up") {
        CHECK(round(2.1, 'u') == 3);
        CHECK(round(-4.6, 'u') == 4);
    }
    SUBCASE("Down") {
        CHECK(round(4.6, 'd') == 4);
        CHECK(round(-5.5, 'd') == -5);
    }
}

/** Function name
 * Brief
 * O(?)
 */
bool prime(int);

TEST_CASE("Checking if a number is prime.") {
    REQUIRE(prime(2));
    REQUIRE(prime(3));
    REQUIRE_FALSE(prime(4));
    REQUIRE(prime(5));
    REQUIRE_FALSE(prime(6));
    REQUIRE(prime(7));
    REQUIRE_FALSE(prime(8));
    REQUIRE_FALSE(prime(9));
    REQUIRE_FALSE(prime(10));

    REQUIRE_FALSE(prime(66));
    REQUIRE(prime(97));
}

/** Function name
 * Brief
 * O(?)
 */
long fibonacci(int);

TEST_CASE("Fibonacci numbers.") {
    CHECK(fibonacci(0) == 0);
    CHECK(fibonacci(1) == 1);
    CHECK(fibonacci(2) == 1);
    CHECK(fibonacci(6) == 8);
    CHECK(fibonacci(16) == 987);
}

/** Function name
 * Brief
 * O(?)
 */
long factorial(int);

TEST_CASE("Factorial") {
    CHECK(factorial(0) == 1);
    CHECK(factorial(4) == 24);
    CHECK(factorial(8) == 40320);
}

#endif
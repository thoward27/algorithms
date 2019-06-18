#pragma once

/** Absolute Value.
 * Converts any integer to its absolute value.
 * O(1) and Omega(1), thus,
 * Theta(1)
 */
int abs_val(int x);

/** Power.
 * Raise the given base to the given power.
 * O(?)
 */
int pow(int base, int num);

/** Logarithm.
 * Returns an integer such that base^{integer} = number.
 * O(?)
 */
int log(int base, int num);

/** Character to Int.
 * Returns the integer value of the given character [0, 9].
 * O(?)
 */
int chartoint(char c);

/** Int to Character.
 * Returns the character represented by the given integer [0, 9].
 * O(?)
 */
char inttochar(int x);

/** Character.
 * Returns the character represented by the integer give.
 * O(?)
 */
char chr(int);

/** Ordinal.
 * Returns the index of the ASCII character given.
 * O(?)
 */
int ord(char);

/** Max.
 * Returns the maximum element from the parameters given.
 * O(?)
 */
int max(int, int);
int max(int, int, int);
int max(int arr[], int n);

/** Min.
 * Returns the minimum element from the parameters given.
 * O(?)
 */
int min(int, int);
int min(int, int, int);
int min(int arr[], int n);

/** Round a float.
 * Rounds a float either (u)p or (d)own, depending on the char given.
 * O(?)
 */
int round(double, char);

/** All true.
 * Checks if all elements in the array are true.
 * O(?)
 */
bool all(bool arr[], int n);

/** Any true
 * Returns whether or not any element is true.
 * O(?)
 */
bool any(bool arr[], int n);

/** Frequency of x.
 * Returns the frequency of x in the given array.
 * O(?)
 */
int frequency(int arr[], int n, int x);

/** Sum.
 * Returns the sum of all elements in the array.
 * O(?)
 */
long sum(int arr[], int n);

/** Index.
 * Returns the index of the given substring if found, or -1.
 * O(?)
 */
int index(char str[], char substr[]);

/** Is sorted.
 * Returns whether or not an array is monotonically increasing or decreasing.
 * O(?)
 */
bool is_sorted(int arr[], int n);

/** Primality testing.
 * Checks if a given number is prime
 * O(?)
 */
bool prime(int);

/** Fibonacci numbers
 * Returns the fibonacci number of the given index.
 * O(?)
 */
long fibonacci(int);

/** Factorial
 * Returns n!
 * O(?)
 */
long factorial(int);

/** String Length
 * Returns the length of the given C-String
 * O(?)
 */
int strlen(char string[]);

/** String to Int
 * Returns the given string as an integer
 * O(?)
 */
int stringtoint(char string[]);

/** Reverse
 * Reverses the array in-place.
 * O(?)
 */
void reverse(int* arr, int n);
void reverse(char* arr, int n);
void reverse(char* arr);

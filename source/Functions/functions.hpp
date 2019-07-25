#pragma once

#ifndef RECURSIVE
#define RECURSIVE false
#endif

/** Absolute Value.
 * Converts any integer to its absolute value.
 * 
 * Inputs:
 * @param x: An integer to evaluate absolute value of
 * 
 * Outputs:
 * An integer representing the absolute value of x
 * 
 * Examples:
 * abs(1) == 1, abs(-2) == 2
 * 
 * Runtime:
 * O(1) 
 */
int abs_val(int x);

/** Power.
 * Raise the given base to the given power.
 * 
 * Inputs:
 * @param base: An integer number to be raised to num power
 * @param num: An integer power to raise base by
 * 
 * Outputs:
 * An integer representing the result of base^power
 * 
 * Examples:
 * pow(2,3) == 8, pow(4,2) == 16
 * 
 * Runtime:
 * O(n)
 */
int pow(int base, int num);

/** Logarithm.
 * Returns an integer representing the result of the log function on a number.
 * 
 * Inputs:
 * @param base: An integer representing the base of the log function
 * @param num: An integer representing the num to run through the log function
 * 
 * Outputs:
 * An integer representing the result of base^{integer} = number
 * 
 * Examples:
 * log(2,8) == 3, log(4,16) == 2
 * 
 * Runtime:
 * O(n)
 */
int log(int base, int num);

/** Character to Int.
 * Returns the integer value of the given character [0, 9].
 * 
 * Inputs:
 * @param c: A character representing a number
 * 
 * Outputs:
 * An integer representing the ASCII code for the number represented by c
 * 
 * Examples:
 * chartoint('1') == 49
 * 
 * Runtime:
 * O(1)
 */
int chartoint(char c);

/** Int to Character.
 * Returns the character represented by the given integer [0, 9].
 * 
 * Inputs:
 * @param x: An integer to be converted to its character equivalent
 * 
 * Output:
 * A character that represents the integer given by x
 * 
 * Examples:
 * inttochar(49) == '1'
 * 
 * Runtime:
 * O(1)
 */
char inttochar(int x);

/** Character.
 * Returns the character represented by the integer given.
 * 
 * Inputs:
 * @param int: An integer representing an ASCII code to be converted to its character equivalent
 * 
 * Outputs:
 * A character corresponding to the ASCII code value for int
 * 
 * Examples:
 * chr(65) == 'A'
 * 
 * Runtime:
 * O(1)
 */
char chr(int);

/** Ordinal.
 * Returns the index of the ASCII character given.
 * 
 * Inputs:
 * @param char: A character to be converted to its ASCII code
 * 
 * Outputs:
 * The ASCII code value that corresponds to char
 * 
 * Examples:
 * ord('A') == 65
 * 
 * Runtime:
 * O(1)
 */
int ord(char);

/** Max.
 * Returns the maximum element from the parameters given.
 * 
 * Inputs:
 * @param int: A set of integers (either in an array or small numbers of integers) to find the max of
 * 
 * Outputs:
 * The value of the max value in the set of integers
 * 
 * Examples:
 * max(1,5) == 5, max(1,4,8) == 8, max([12,3,14,15], 4) == 15
 * 
 * Runtime:
 * O(n)
 */
int max(int, int);
int max(int, int, int);
int max(int arr[], int n);

/** Min.
 * Returns the minimum element from the parameters given.
 * 
 * Inputs:
 * @param int: A set of integers (either in an array or small numbers of integers) to find the min of
 * 
 * Outputs:
 * The value of the min value in the set of integers
 * 
 * Examples:
 * min(1,5) == 1, min(1,4,8) == 1, min([12,3,14,15], 4) == 3
 * 
 * Runtime:
 * O(n)
 */
int min(int, int);
int min(int, int, int);
int min(int arr[], int n);

/** Round a float.
 * Rounds a float either (u)p or (d)own, depending on the char given.
 * 
 * Inputs:
 * @param double: Value to be rounded
 * @param char: Switch to determine rounding strategy
 * 
 * Outputs:
 * When char == 'u' : rounds up the double param to the nearest integer
 * When char == 'd' : rounds down the double param to the nearest integer
 * 
 * Examples:
 * round(1.23,'u') == 2,  round(1.23, 'd') == 1
 * 
 * Runtime:
 * O(1)
 */
int round(double, char);

/** All true.
 * Checks if all elements in the array are true.
 * Inputs:
 * @param arr: An array of booleans
 * @param n: size of the arr param
 * 
 * Outputs:
 * True if every element in the arr param is true
 * False otherwise
 * 
 * Examples:
 * all([1,1,1], 3) == 1, all([1,0,1], 3) == 0
 * 
 * Runtime:
 * O(n)
 */
bool all(bool arr[], int n);

/** Any true
 * Returns whether or not any element is true.
 * 
 * Inputs:
 * @param arr: an array of a given type
 * @param n: size of the arr param
 * 
 * Outputs:
 * True if at least one element in the arr param is true
 * False otherwise
 * 
 * Examples:
 * any([1,0,0], 3) == 1, any([0,0,0], 3) == 0
 * 
 * Runtime: 
 * O(n)
 */
template <class T>
bool any(T* arr, unsigned int n) {
  return n == 0 ? false : arr[0] || any(arr + 1, n - 1);
}

/** Frequency of x.
 * Returns the frequency of x in the given array.
 * 
 * Inputs:
 * @param arr: an array of integers to search
 * @param n: size of the arr param
 * @param x: integer value to search for
 * 
 * Outputs:
 * The number of times the value of x appears in the arr param
 * 
 * Examples:
 * frequency([1,1,3,4,1,0], 6, 1) == 3
 * 
 * Runtime:
 * O(n)
 */
int frequency(int arr[], int n, int x);

/** Sum.
 * Returns the sum of all elements in the array.
 * 
 * Inputs:
 * @param arr: an array of a given type to sum the elements of
 * @param n: size of the arr param
 * 
 * Outputs:
 * The sum of all elements in the arr param
 * 
 * Examples:
 * sum([1,2,3,4], 4) == 10
 * 
 * Runtime:
 * O(n)
 */
template <class T>
long sum(T* arr, unsigned int n) {
  return n == 0 ? 0 : arr[0] + sum(arr + 1, n - 1);
}

/** Index.
 * Returns the index of the given substring if found, or -1.
 * 
 * Inputs:
 * @param str: string to search for the substr param in
 * @param substr: string to search for in the str param
 * 
 * Outputs:
 * The index of the start of the substr in the str param
 * -1 if the substr was not found
 * 
 * Examples:
 * index("Hello", "e") == 1, index("Hello", "z") == -1
 * 
 * Runtime:
 * O(n^2)
 */
int index(char str[], char substr[]);

/** Is sorted.
 * Returns whether or not an array is monotonically increasing or decreasing.
 * 
 * Inputs:
 * @param arr: an array to check for order
 * @param n: size of the arr param
 * 
 * Outputs:
 * True if the arr param is in some degree of order
 * False otherwise
 * 
 * Examples:
 * is_sorted([1,2,3],3) == 1, is_sorted([3,2,1],3) == 1, is_sorted([3,2,3],3) == 0
 * 
 * Runtime:
 * O(n)
 */
bool is_sorted(int arr[], int n);

/** Primality testing.
 * Checks if a given number is prime
 * 
 * Inputs:
 * @param int: integer to check for primality
 * 
 * Outputs:
 * True if the given int is a prime number
 * False otherwise
 * 
 * Examples:
 * primte(5) == 1, prime(10) == 0
 * 
 * Runtime:
 * O(n)
 */
bool prime(int);

/** Fibonacci numbers
 * Returns the fibonacci number of the given index.
 * 
 * Inputs:
 * @param int: the nth fibonacci number to find
 * 
 * Outputs:
 * The nth fibonacci number
 * 
 * Examples:
 * fibonacci(4) == 5
 * 
 * Runtime:
 * O(?)
 */
long fibonacci(int);

/** Factorial
 * Returns n!
 * 
 * Inputs:
 * @param int: integer to run the factorial operation on
 * 
 * Outputs:
 * The value of n!
 * 
 * Examples:
 * factorial(3) == 6
 * 
 * Runtime:
 * O(?)
 */
long factorial(int);

/** String Length
 * Returns the length of the given C-String
 * 
 * Inputs: 
 * @param string: a c-string
 * 
 * Outputs:
 * The length of the given c-string
 * 
 * Examples:
 * strlen("hello") == 5
 * 
 * Runtime:
 * O(n)
 */
int strlen(char string[]);

/** String to Int
 * Returns the given string as an integer
 * 
 * Inputs:
 * @param string: a c-string representing a number
 * 
 * Outputs:
 * The integer equivalent of the given string
 * 
 * Examples:
 * stringtoint("1234") == 1234
 * 
 * Runtime:
 * O(n)
 */
int stringtoint(char string[]);

/** Reverse
 * Reverses the array in-place.
 * 
 * Inputs:
 * @param arr: array to be reversed
 * @param n: length of the arr param 
 * 
 * Side Effects:
 * The reverse of the initial array
 * 
 * Examples:
 * reverse([1,2,3],3) == [3,2,1], reverse("Hello") == "olleH"
 * 
 * Runtime:
 * O(n)
 */
void reverse(int* arr, int n);
void reverse(char* arr, int n);
void reverse(char* arr);

/** Binary Search
 * Finds a given key in a given sorted array.
 * 
 * Inputs:
 * @param arr: array to be searched
 * @param n: size of the arr param
 * @param key: value to be searched for
 * 
 * Outputs:
 * The index the value was found at
 * -1 if the search fails
 * 
 * Examples:
 * binsearch([1,2,3,4], 4, 3) == 2, binsearch([1,2,3,4], 4, 5) == -1
 * 
 * Runtime:
 * O(log n)
 */
int binsearch(int* arr, int n, int key);

/** Copy Array
 * Copies an array from A to B
 * 
 * Inputs:
 * @param A: array to copy from
 * @param B: array to copy to
 * @param n: size of both arrays
 * 
 * Side Effects:
 * A copy of A inside B
 * 
 * Examples:
 * A = [1,2,3] B = [] : copy(A, B, 3) : B = [1,2,3]
 * 
 * Runtime:
 * O(n)
 */
void copy(int* A, int* B, int n);

/** Swap
 * Swaps two elements
 * 
 * Inputs:
 * @param *a: an address to copy data from
 * @param *b: an address to copy data from
 * 
 * Side Effects:
 * The value of a will be in b and the value of b will be in a
 * 
 * Examples:
 * a = 3 b = 8 : swap(&a, &b) : a = 8 b = 3
 * 
 * Runtime:
 * O(1)
 */
void swap(int* a, int* b);

/** Merge
 * A helper function for merge sort, takes a partially sorted 
 * array and puts all elements in sorted order
 * 
 * Inputs:
 * @param arr: arr containing data
 * @param n: size of arr param
 * @param mid: delimiter between sorted portions
 * 
 * Side Effects:
 * Edits the arr param in place to sort all elements
 * 
 * Examples:
 * merge([3,7,4,8], 4, 2) == [3,4,7,8]
 * 
 * Runtime:
 * O(n)
 */
void merge(int* arr, int n, int mid);

/** Partition
 * Helper function for quicksort, partitions the array into 
 * two sections, those less than partition val 
 * and those greater than partition val
 * 
 * Inputs:
 * @param arr: array to partition
 * @param lo: left most value of the array
 * @param hi: right most value of the array
 * 
 * Outputs:
 * A partition array with two portions, those less than pivot 
 * and those greater than pivot and returns the partition pivot
 * 
 * Examples:
 * partition([3,5,4,2,1], 0, 4) == [2,1,3,5,4] 
 * 
 * Runtime:
 * O(log n)
 */
int partition(int* arr, int lo, int hi);

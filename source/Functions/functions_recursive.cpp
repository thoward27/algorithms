#include "functions.hpp"

bool r_prime(int n, int k) {
  return (k <= 1) ? true : (n % k != 0) && r_prime(n, k - 1);
}

bool prime(int n) {
  return r_prime(n, n / 2);
}

long fibonacci(int n) {
  return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

long factorial(int n) {
  return (!n) ? 1 : n * factorial(n - 1);
}

int abs_val(int x) {
  return (x >= 0) ? x : abs_val(-x);
}

int pow(int base, int num) {
  return (!num) ? 1 : base * pow(base, num - 1);
}

bool all(bool arr[], int n) {
  if (!n)
    return false;
  else if (n == 1)
    return arr[0];
  return arr[0] && all(arr + 1, n - 1);
}

bool any(bool arr[], int n) {
  if (!n)
    return false;
  return arr[0] || any(arr + 1, n - 1);
}

int frequency(int arr[], int n, int x) {
  if (!n)
    return 0;
  return (arr[0] == x) + frequency(arr + 1, n - 1, x);
}

int strlen(char* string) {
  int length = 0;
  while (string[length])
    ++length;
  return length;
}

bool exact_match(char* a, char* b) {
  return (!b[0]) ? true : a[0] == b[0] && exact_match(a + 1, b + 1);
}
int r_index(char str[], char substr[]) {
  if (!substr[0] || exact_match(str, substr))
    return 0;
  else if (!str[0])
    return 1;
  return 1 + r_index(str + 1, substr);
}

int index(char* str, char* substr) {
  int idx = r_index(str, substr);
  return idx <= strlen(str) ? idx : -1;
}

bool is_increasing(int arr[], int n) {
  return (n < 2) ? true : arr[0] <= arr[1] && is_increasing(arr + 1, n - 1);
}

bool is_decreasing(int arr[], int n) {
  return (n < 2) ? true : arr[0] >= arr[1] && is_decreasing(arr + 1, n - 1);
}

bool is_sorted(int arr[], int n) {
  return is_decreasing(arr, n) || is_increasing(arr, n);
}

int max(int a, int b) {
  return (a >= b) ? a : max(b, a);
}

int max(int a, int b, int c) {
  return max(a, max(b, c));
}

int round(double x, char c) {
  if ((int)x == x)
    return x;
  else if (x < 0)
    return -round(-x, (c == 'd') ? 'u' : 'd');
  else
    return round((int)x + (c == 'u'), c);
}

int stringtoint(char* string) {
  int length = strlen(string);
  return (length) ? chartoint(string[0]) * pow(10, length - 1) +
                        stringtoint(string + 1)
                  : 0;
}

/* NOT RECURSIVE */
int chartoint(char c) {
  return (c >= '0' && c <= '9') ? c - '0' : throw "bad input";
}

/* NOT RECURSIVE */
int ord(char c) {
  return c;
}

/* NOT RECURSIVE */
char chr(int x) {
  return x;
}

/* NOT RECURSIVE */
char inttochar(int x) {
  return (x >= 0 && x <= 9) ? x + 48 : throw "bad input";
}

int max(int arr[], int n) {
  if (n == 1)
    return arr[0];
  int sub_max = max(arr + 1, n - 1);
  return (arr[0] > sub_max) ? arr[0] : sub_max;
}

int min(int a, int b) {
  return (a <= b) ? a : min(b, a);
}

int min(int a, int b, int c) {
  return min(a, min(b, c));
}

int min(int arr[], int n) {
  if (n == 1)
    return arr[0];
  int sub_min = min(arr + 1, n - 1);
  return (arr[0] < sub_min) ? arr[0] : sub_min;
}

int order(int arr[], int n) {
  if (n == 1)
    return 0;
  if (n == 2) {
    if (arr[0] < arr[1])
      return 1;
    if (arr[0] > arr[1])
      return -1;
    return 0;
  }
  int sub_order = order(arr + 1, n - 1);
  if (!sub_order)
    return 0;
  if (sub_order == 1 && arr[0] < arr[1])
    return 1;
  if (sub_order == -1 && arr[0] > arr[1])
    return -1;
  return 0;
}

void reverse(int* arr, int n) {
  if (n <= 1)
    return;
  int tmp = arr[0];
  arr[0] = arr[n - 1];
  arr[n - 1] = tmp;
  reverse(arr + 1, n - 2);
}

void reverse(char* arr, int n) {
  if (n <= 1)
    return;
  char tmp = arr[0];
  arr[0] = arr[n - 1];
  arr[n - 1] = tmp;
  reverse(arr + 1, n - 2);
}

void reverse(char* arr) {
  int len;
  for (len = 0; arr[len] != '\0'; ++len) {
  }
  reverse(arr, len);
}

long sum(int arr[], int n) {
  if (n == 0)
    return 0;
  return arr[0] + sum(arr + 1, n - 1);
}

int log(int base, int num) {
  return (num == 1) ? 0 : 1 + log(base, num / base);
}

int binsearch(int* arr, int n, int key) {}
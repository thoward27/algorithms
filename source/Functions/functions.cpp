#include "functions.hpp"

int chartoint(char c) {
  return (c >= '0' && c <= '9') ? c - '0' : throw "bad input";
}

int ord(char c) {
  return c;
}

char chr(int x) {
  return x;
}

char inttochar(int x) {
  return (x >= 0 && x <= 9) ? x + 48 : throw "bad input";
}

void swap(int* a, int* b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void merge(int* arr, int n, int mid) {
  int* temp = new int[n];
  copy(arr, temp, n);

  int j = 0;
  int k = mid;
  for (int i = 0; i < n; i++) {
    // If k is consumed, or the element at j is better, take j.
    if (k >= n || (j < mid && temp[j] <= temp[k]))
      arr[i] = temp[j++];
    // Otherwise take k.
    else
      arr[i] = temp[k++];
  }
  delete[] temp;
}

int partition(int* arr, int lo, int hi) {
  int i = lo + 1, j = hi;
  while (i <= j) {
    while (i < hi && arr[i] <= arr[lo])
      i++;
    while (j > lo && arr[j] >= arr[lo])
      j--;
    if (j <= i) {
      break;
    }
    swap(&arr[i], &arr[j]);
  }
  if (lo != j)
    swap(&arr[lo], &arr[j]);
  return j;
}

#if RECURSIVE
/** Recursive Solutions
 *
 */
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
  if (!length)
    return 0;
  else if (string[0] == '-')
    return -1 * stringtoint(string + 1);
  else
    return chartoint(string[0]) * pow(10, length - 1) + stringtoint(string + 1);
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

int binsearch(int* arr, int lo, int hi, int key) {
  if (lo > hi)
    return -1;
  else {
    int mid = lo + (hi - lo) / 2;
    if (arr[mid] == key)
      return mid;
    else
      return (arr[mid] < key) ? binsearch(arr, mid + 1, hi, key)
                              : binsearch(arr, lo, mid - 1, key);
  }
}

int binsearch(int* arr, int n, int key) {
  return binsearch(arr, 0, n, key);
}

void copy(int* A, int* B, int n) {
  if (!n)
    return;
  B[0] = A[0];
  return copy(A + 1, B + 1, n - 1);
}
#else
/** Iterative Solutions
 *
 */

int abs_val(int x) {
  return (x > 0) ? x : x * -1;
}

int pow(int base, int num) {
  int ret = 1;
  for (int i = 0; i < num; ++i) {
    ret *= base;
  }
  return ret;
}

int log(int base, int num) {
  int count = 0;
  while (num > 1) {
    num /= base;
    ++count;
  }
  return count;
}

int max(int x, int y) {
  return (x > y) ? x : y;
}

int max(int x, int y, int z) {
  return max(x, max(y, z));
}

int min(int x, int y) {
  return (x < y) ? x : y;
}

int min(int x, int y, int z) {
  return min(x, min(y, z));
}

int round(double x, char c) {
  if (x > 0) {
    return (c == 'd') ? (int)x : (int)x + 1;
  } else {
    return (c == 'd') ? (int)x - 1 : (int)x;
  }
}

int stringtoint(char string[]) {
  int out = 0;
  int len = strlen(string) - 1;
  for (int i = 0; i <= len; ++i) {
    if (i == len && string[0] == '-')
      continue;
    out += chartoint(string[len - i]) * pow(10, i);
  }
  return (string[0] == '-') ? -1 * out : 1 * out;
}

int max(int arr[], int n) {
  int max = arr[0];
  for (int i = 1; i < n; ++i) {
    if (arr[i] > max)
      max = arr[i];
  }
  return max;
}

int min(int arr[], int n) {
  int min = arr[0];
  for (int i = 1; i < n; ++i) {
    if (arr[i] < min)
      min = arr[i];
  }
  return min;
}

bool all(bool arr[], int n) {
  for (int i = 0; i < n; ++i) {
    if (!arr[i])
      return false;
  }
  return true;
}

bool any(bool arr[], int n) {
  for (int i = 0; i < n; ++i) {
    if (arr[i])
      return true;
  }
  return false;
}

int frequency(int arr[], int n, int x) {
  int count = 0;
  for (int i = 0; i < n; ++i) {
    if (arr[i] == x)
      count++;
  }
  return count;
}

long sum(int arr[], int n) {
  long sum = 0;
  for (int i = 0; i < n; ++i)
    sum += arr[i];
  return sum;
}

int index(char str[], char substr[]) {
  int i = 0;
  int j = 0;
  while (str[i] != '\0') {
    if (substr[j] == '\0')
      return i - j;
    if (str[i] == substr[j])
      ++j;
    else
      j = 0;
    ++i;
  }
  if (substr[j] == '\0')
    return i - j;
  return -1;
}

bool is_sorted(int arr[], int n) {
  if (n <= 2)
    return true;
  else {
    int increasing = 1, decreasing = 1;
    for (int i = 0; i < (n - 1); ++i) {
      if (arr[i] <= arr[i + 1])
        ++increasing;

      if (arr[i] >= arr[i + 1])
        ++decreasing;
    }
    return (increasing == n || decreasing == n);
  }
}

void reverse(char* arr) {
  int len = strlen(arr);
  for (int i = 0; i < len / 2; ++i) {
    char tmp = arr[i];
    arr[i] = arr[len - i - 1];
    arr[len - i - 1] = tmp;
  }
}

void reverse(int* arr, int n) {
  for (int i = 0; i < n / 2; ++i) {
    int tmp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = tmp;
  }
}

void reverse(char* arr, int n) {
  for (int i = 0; i < n / 2; ++i) {
    char tmp = arr[i];
    arr[i] = arr[n - i - 1];
    arr[n - i - 1] = tmp;
  }
}

int strlen(char string[]) {
  int out = 0;
  for (int i = 0; string[i]; ++i) {
    ++out;
  }

  return out;
}

bool prime(int x) {
  for (int i = 2; i <= x / 2; ++i) {
    if (x % i == 0)
      return false;
  }
  return true;
}

long factorial(int x) {
  long ret = 1;
  for (int i = 2; i <= x; ++i)
    ret *= i;
  return ret;
}

long fibonacci(int n) {
  long a = 0, b = 1, temp;
  for (int i = 0; i < n; ++i) {
    temp = a + b;
    a = b;
    b = temp;
  }
  return a;
}

int binsearch(int* arr, int n, int key) {
  int lo = 0, hi = n;
  while (lo <= hi) {
    int idx = lo + (hi - lo) / 2;
    if (arr[idx] == key)
      return idx;
    else if (arr[idx] < key)
      lo = idx + 1;
    else
      hi = idx - 1;
  }
  return -1;
}

void copy(int* A, int* B, int n) {
  for (int i = 0; i < n; ++i)
    B[i] = A[i];
}

#endif
#include "functions.hpp"

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

int chartoint(char c) {
  if (c < '0' || c > '9')
    throw "Bad character";
  return c - '0';
}

char inttochar(int x) {
  return (char)(x + '0');
}

char chr(int x) {
  return (char)x;
}

int ord(char c) {
  return (int)c;
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
  int len = strlen(string);
  int out = 0;

  for (int i = 0; i < len; ++i) {
    out += chartoint(string[len - i - 1]) * pow(10, i);
  }

  return out;
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
  int len;
  for (len = 0; arr[len] != '\0'; ++len) {
  }
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
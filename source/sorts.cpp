#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubble_sort(int* arr, int n) {
  bool sorted = false;
  while (!sorted) {
    sorted = true;
    for (int j = 0; j < n - 1; ++j) {
      if (arr[j] > arr[j + 1]) {
        swap(arr + j, arr + j + 1);
        sorted = false;
      }
    }
  }
}

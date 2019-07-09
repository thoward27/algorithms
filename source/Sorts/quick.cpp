#include <sstream>
#include "../doctest.h"
#include "sort.hpp"

// O(n)

// Best Case: O(n log n)
// Worst Case: O(n^2)
void quicksort(int* arr, int lo, int hi) {
  if (lo < hi) {
    int p = partition(arr, lo, hi);
    quicksort(arr, lo, p - 1);
    quicksort(arr, p + 1, hi);
  }
}
// Wrapper function to normalize sorts API.
void sort(int* arr, int n) {
  quicksort(arr, 0, n - 1);
}

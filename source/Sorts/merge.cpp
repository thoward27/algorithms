#include <sstream>
#include "../doctest.h"
#include "sort.hpp"

// O(n log n)
void sort(int* arr, int n) {
  if (n > 1) {
    sort(arr, n / 2);
    sort(arr + (n / 2), n - n / 2);
    merge(arr, n, n / 2);
  }
}

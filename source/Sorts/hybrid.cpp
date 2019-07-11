#include <sstream>
#include "sort.hpp"

namespace insertion {
#include "insertion.cpp"
}

/** Hybrid Merge + Insertion
 * All Cases: O(n log n)
 * Splits arrays down into small chunks,
 * runs insertion sort on those chunks,
 * then merges the results.
 */
void sort(int* arr, int n) {
  // Run insertion sort on small arrays.
  if (n <= 10) {
    insertion::sort(arr, n);
    // Otherwise, break it up more.
  } else {
    sort(arr, n / 2);
    sort(arr + (n / 2), n - (n / 2));
    merge(arr, n, n / 2);
  }
}
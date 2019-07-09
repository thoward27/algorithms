#include <sstream>
#include "sort.hpp"

#ifndef TOGGLE
#define TOGGLE true
#endif

#if TOGGLE

namespace bubble {
#include "bubble.cpp"
}

/** Hybrid Quick + Bubble
 * Worst Case: O(n^2)
 * Best Case: O(n log n)
 * Partitions the arrays into small chunks,
 * which are then sorted with bubble sort.
 * This does not avoid the worst case for quicksort.
 */
void sort(int* arr, int lo, int hi) {
  if (hi - lo <= 10) {
    // Insertion sort small segments
    bubble::sort(arr + lo, hi - lo + 1);
  } else {
    // Otherwise partition and call further.
    // This drives towards insertion sorts' best case O(kn).
    // But, doesn't actually save us from the worst case of quicksort.
    int p = partition(arr, lo, hi);
    sort(arr, lo, p - 1);
    sort(arr, p + 1, hi);
  }
}

void sort(int* arr, int n) {
  sort(arr, 0, n - 1);
}

#else

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
#endif
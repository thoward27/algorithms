#include <sstream>
#include "sort.hpp"

// Worst Case: O(n^2)
// Best Case: O(n)
void sort(int* arr, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      swap(&arr[j], &arr[j - 1]);
    }
  }
}

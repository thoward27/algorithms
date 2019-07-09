#include <sstream>
#include "sort.hpp"

// Worst Case: O(n^2)
// Best Case: O(n^2)
void sort(int* arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min])
        min = j;
    }
    if (min != i)
      swap(&arr[min], &arr[i]);
  }
}

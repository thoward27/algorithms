#include <sstream>
#include "sort.hpp"

// Worst Case: O(n^2)
// Best Case: O(n)
void sort(int* arr, int n) {
  for (int i = 0; i < (n - 1); i++) {
    if (arr[i] > arr[i + 1]) {
      arr[i] = arr[i] xor arr[i + 1];
      arr[i + 1] = arr[i] xor arr[i + 1];
      arr[i] = arr[i] xor arr[i + 1];
    }
  }
  if (n != 1) {
    sort(arr, n - 1);
  }
}

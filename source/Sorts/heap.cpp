#include "../Trees/MinHeap.hpp"
#include "sort.hpp"

void sort(int* arr, int n) {
  MinHeap h;
  for (int i = 0; i < n; ++i)
    h.push(arr[i]);
  for (int i = 0; i < n; ++i)
    arr[i] = h.pop();
  return;
}
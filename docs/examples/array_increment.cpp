#include <iostream>

#define N 10

void array_increment(int*, int);

int main() {
  // Instantiate an array on the heap.
  int* arr = new int[N]();

  // Print it out.
  for (int i = 0; i < N; ++i)
    std::cout << arr[i] << ", ";
  std::cout << std::endl;

  // Call our function.
  array_increment(arr, N);

  // Print modified array.
  for (int i = 0; i < N; ++i)
    std::cout << arr[i] << ", ";
  std::cout << std::endl;

  return 0;
}

void array_increment(int* arr, int n) {
  for (int i = 0; i < n; ++i) {
    ++arr[i];
  }
}
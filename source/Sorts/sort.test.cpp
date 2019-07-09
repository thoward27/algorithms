#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "sort.hpp"

#include <chrono>
#include <iostream>
#include <numeric>
#include <vector>

#define CASES 11

/** Input Types */
namespace fill {
void random(int* arr, int n, int shift) {
  for (int i = 0; i < n; ++i)
    arr[i] = (rand() % 1000) + shift;
  return;
}

void ascending(int* arr, int n, int shift) {
  for (int i = 0; i < n; ++i)
    arr[i] = i + shift;
  return;
}

void descending(int* arr, int n, int shift) {
  for (int i = 0; i < n; ++i)
    arr[i] = n - i + shift;
  return;
}

void equal(int* arr, int n, int shift) {
  int x = (rand() % 1000) + shift;
  for (int i = 0; i < n; ++i)
    arr[i] = x;
  return;
}
}  // namespace fill

inline bool increasing(int* arr, int n) {
  return (n < 2) ? true : arr[0] <= arr[1] && increasing(arr + 1, n - 1);
}

typedef void (*fill_fn)(int*, int, int);
fill_fn fillers[] = {fill::random, fill::ascending, fill::descending,
                     fill::equal};
char filler_names[][20] = {"Random", "Ascending", "Descending", "Equal"};

TEST_CASE("Sorting") {
  for (size_t i = 0; i < sizeof(fillers) / sizeof(fill_fn); ++i) {
    SUBCASE(filler_names[i]) {
      for (int shift = -1000; shift <= 1000; shift += 500) {
        for (int n = 1; n < CASES; ++n) {
          int arr[n];
          fillers[i](arr, n, shift);

          int freq[6000] = {};
          for (int i = 0; i < n; ++i)
            freq[arr[i] + 2000] += 1;

          sort(arr, n);

          for (int i = 0; i < n; ++i)
            freq[arr[i] + 2000] -= 1;

          REQUIRE(increasing(arr, n));
          REQUIRE(sum(freq, 6000) == 0);
        }
      }
    }
  }
}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "../Functions/functions.hpp"
#include "sorts.hpp"

#include <chrono>
#include <iostream>
#include <vector>
#include <numeric>

#define CASES 11

/** Sorting Functions */
typedef void (*sort_fn)(int*, int);

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

typedef void (*fill_fn)(int*, int, int);
fill_fn fillers[] = {fill::random, fill::ascending, fill::descending,
                     fill::equal};
char filler_names[][20] = {"Random", "Ascending", "Descending", "Equal"};

void test_sort(sort_fn func) {
  for (size_t i = 0; i < sizeof(fillers) / sizeof(fill_fn); ++i) {
    SUBCASE(filler_names[i]) {
      for (int shift = -1000; shift <= 1000; shift += 500) {
        for (int n = 1; n < CASES; ++n) {
          int arr[n];
          fillers[i](arr, n, shift);

          int freq[6000] = {};
          for (int i = 0; i < n; ++i)
            freq[arr[i] + 2000] += 1;

          func(arr, n);
          REQUIRE(is_sorted(arr, n));

          for (int i = 0; i < n; ++i)
            freq[arr[i] + 2000] -= 1;
          REQUIRE_EQ(sum(freq, 6000), 0);
        }
      }
    }
  }
}

// TEST_CASE("Benchmark") { 
//   int size = 1000000;
//   int arr[size]; 

//   std::vector<int> vec;
//   for (int i = 0; i < 20; ++i) {
//     fill::random(arr, size, 0);
    
//     auto start = std::chrono::high_resolution_clock::now();
//     advancedsort(arr, size);
//     auto stop = std::chrono::high_resolution_clock::now();
    
//     auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
//     vec.push_back(duration);
//   }
//   std::cout << "Averaged runtime: ";
//   std::cout << std::accumulate(vec.begin(), vec.end(), 0.0)/vec.size() << " ms";
//   std::cout << std::endl;
// }

TEST_CASE("Bubble Sort") {
  test_sort(bubble_sort);
}

TEST_CASE("Insertion Sort") {
  test_sort(insertion_sort);
}

TEST_CASE("Selection Sort") {
  test_sort(selection_sort);
}

TEST_CASE("MergeSort") {
  test_sort(mergesort);
  SUBCASE("Merge Function") {
    int arr1[1] = {1};
    int arr2[2] = {2, 1};
    int arr3[5] = {4, 5, 1, 2, 3};
    int arr4[10] = {23, 41, 54, 64, 92, 28, 35, 40, 81, 82};
    int arr4_sorted[10] = {23, 28, 35, 40, 41, 54, 64, 81, 82, 92};
    int arr5[10] = {1, 1, 2, 3, 3, 1, 2, 2, 2, 3};
    int arr5_sorted[10] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};
    int arr6[5] = {1, 3, 2, 4, 5};

    merge(arr1, 1, 1 / 2);
    CHECK(arr1[0] == 1);

    merge(arr2, 2, 2 / 2);
    CHECK(arr2[0] == 1);
    CHECK(arr2[1] == 2);

    merge(arr3, 5, 5 / 2);
    for (int j = 0; j < 5; ++j) {
      CHECK(arr3[j] == j + 1);
    }

    merge(arr4, 10, 10 / 2);
    for (int j = 0; j < 10; ++j) {
      CHECK(arr4[j] == arr4_sorted[j]);
    }

    merge(arr5, 10, 10 / 2);
    for (int j = 0; j < 10; ++j) {
      CHECK(arr5[j] == arr5_sorted[j]);
    }

    merge(arr6, 5, 5 / 2);
    for (int j = 0; j < 5; ++j) {
      CHECK(arr6[j] == j + 1);
    }
  }
}

TEST_CASE("QuickSort") {
  test_sort(quicksort);
  SUBCASE("Partition Function") {
    int arr1[1] = {1};
    int arr2[2] = {2, 1};
    int arr3[5] = {5, 4, 3, 2, 1};
    int arr4[10] = {23, 41, 54, 64, 92, 28, 35, 40, 81, 82};
    int arr5[10] = {1, 1, 2, 3, 3, 1, 2, 2, 2, 3};

    int p1 = partition(arr1, 0, 0);
    CHECK(p1 == 0);
    CHECK(arr1[0] == 1);

    partition(arr2, 0, 1);
    CHECK(arr2[0] == 1);
    CHECK(arr2[1] == 2);

    int p3 = partition(arr3, 0, 4);
    for (int i = 0; i < p3; ++i) {
      CHECK(arr3[i] <= arr3[p3]);
    }
    for (int i = p3 + 1; i < 5; ++i) {
      CHECK(arr3[i] >= arr3[p3]);
    }

    int p4 = partition(arr4, 0, 9);
    for (int i = 0; i < p4; ++i) {
      CHECK(arr4[i] <= arr4[p4]);
    }
    for (int i = p4 + 1; i < 10; ++i) {
      CHECK(arr4[i] >= arr4[p4]);
    }

    int p5 = partition(arr5, 0, 9);
    for (int i = 0; i < p5; ++i) {
      CHECK(arr5[i] <= arr5[p5]);
    }
    for (int i = p5 + 1; i < 10; ++i) {
      CHECK(arr5[i] >= arr5[p5]);
    }
  }
}

TEST_CASE("Hybrid Sort") {
  test_sort(hybridsort);
}

TEST_CASE("Tree Sort") {
  test_sort(treesort);
}
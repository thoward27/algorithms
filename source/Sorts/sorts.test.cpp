#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "../Functions/functions.hpp"
#include "sorts.hpp"

#define CASES 11

/** Sorting Functions */
typedef void (*sort_fn)(int*, int);

/** Input Types */
void fill_random(int* arr, int n) {
  for (int i = 0; i < n; ++i)
    arr[i] = rand() % 1000;
  return;
}

void fill_ascending(int* arr, int n) {
  for (int i = 0; i < n; ++i)
    arr[i] = i;
  return;
}

void fill_descending(int* arr, int n) {
  for (int i = 0; i < n; ++i)
    arr[i] = n - i;
  return;
}

void fill_equal(int* arr, int n) {
  int x = rand() % 1000;
  for (int i = 0; i < n; ++i)
    arr[i] = x;
  return;
}

typedef void (*fill_fn)(int*, int);
fill_fn fillers[] = {fill_random, fill_ascending, fill_descending, fill_equal};
char filler_names[][20] = {"Random", "Ascending", "Descending", "Equal"};

void test_sort(sort_fn func) {
  for (size_t i = 0; i < sizeof(fillers) / sizeof(fill_fn); ++i) {
    SUBCASE(filler_names[i]) {
      for (int n = 1; n < CASES; ++n) {
        int arr[n];
        fillers[i](arr, n);
        func(arr, n);
        REQUIRE(is_sorted(arr, n));
      }
    }
  }
}

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
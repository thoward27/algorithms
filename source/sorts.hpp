#ifndef __SORTS__
#define __SORTS__

#include "doctest/doctest/doctest.h"

/* Sorting Algorithms */

typedef void (*sort_fn)(int*, int);

void bubble_sort(int* arr, int n);

TEST_CASE("Testing sorting functions") {
  int arr1[1] = {1};
  int arr2[2] = {2, 1};
  int arr3[5] = {5, 4, 3, 2, 1};
  int arr4[10] = {92, 64, 54, 41, 23, 35, 82, 28, 81, 40};
  int arr4_sorted[10] = {23, 28, 35, 40, 41, 54, 64, 81, 82, 92};
  int arr5[10] = {3, 1, 3, 2, 1, 3, 2, 2, 1, 2};
  int arr5_sorted[10] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};

  SUBCASE("Bubble") {
    bubble_sort(arr1, 1);
    CHECK(arr1[0] == 1);

    bubble_sort(arr2, 2);
    CHECK(arr2[0] == 1);
    CHECK(arr2[1] == 2);

    bubble_sort(arr3, 5);
    for (int j = 0; j < 5; ++j) {
      CHECK(arr3[j] == j + 1);
    }

    bubble_sort(arr4, 10);
    for (int j = 0; j < 10; ++j) {
      CHECK(arr4[j] == arr4_sorted[j]);
    }

    bubble_sort(arr5, 10);
    for (int j = 0; j < 10; ++j) {
      CHECK(arr5[j] == arr5_sorted[j]);
    }
  }
}

#endif
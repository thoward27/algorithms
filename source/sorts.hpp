#pragma once
#include "doctest/doctest/doctest.h"

/* Auxiliary Functions */

void swap(int* a, int* b);

void merge(int* arr, int n, int mid);

TEST_CASE("Testing merge function") {
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

int partition(int* arr, int lo, int hi);

TEST_CASE("Testing partition function") {
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

/* Sorting Algorithms */

typedef void (*sort_fn)(int*, int);

void bubble_sort(int* arr, int n);

void insertion_sort(int* arr, int n);

void selection_sort(int* arr, int n);

void mergesort(int* arr, int n);

void quicksort(int* arr, int n);

void quicksort(int* arr, int lo, int hi);

sort_fn sorts[] = {bubble_sort, insertion_sort, selection_sort, mergesort,
                   quicksort};
char names[][20] = {"Bubble sort", "Insertion sort", "Selection sort",
                    "Mergesort", "Quicksort"};

TEST_CASE("Testing sorting functions") {
  int arr1[1] = {1};
  int arr2[2] = {2, 1};
  int arr3[5] = {5, 4, 3, 2, 1};
  int arr4[10] = {92, 64, 54, 41, 23, 35, 82, 28, 81, 40};
  int arr4_sorted[10] = {23, 28, 35, 40, 41, 54, 64, 81, 82, 92};
  int arr5[10] = {3, 1, 3, 2, 1, 3, 2, 2, 1, 2};
  int arr5_sorted[10] = {1, 1, 1, 2, 2, 2, 2, 3, 3, 3};

  for (int i = 0; i < sizeof(sorts) / sizeof(sort_fn); ++i) {
    SUBCASE(names[i]) {
      sorts[i](arr1, 1);
      CHECK(arr1[0] == 1);

      sorts[i](arr2, 2);
      CHECK(arr2[0] == 1);
      CHECK(arr2[1] == 2);

      sorts[i](arr3, 5);
      for (int j = 0; j < 5; ++j) {
        CHECK(arr3[j] == j + 1);
      }

      sorts[i](arr4, 10);
      for (int j = 0; j < 10; ++j) {
        CHECK(arr4[j] == arr4_sorted[j]);
      }

      sorts[i](arr5, 10);
      for (int j = 0; j < 10; ++j) {
        CHECK(arr5[j] == arr5_sorted[j]);
      }
    }
  }
}
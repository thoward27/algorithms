#pragma once

/**
 *
 * Sorting Algorithms
 *
 */

/** Bubble Sort */
void bubble_sort(int*, int);

/** Insertion Sort */
void insertion_sort(int*, int);

/** Selection Sort */
void selection_sort(int*, int);

/** MergeSort */
void mergesort(int*, int);

/** Quicksort */
void quicksort(int*, int);

/** HybridSort */
void hybridsort(int*, int);

/** Tree Sort */
void treesort(int*, int);

/**
 *
 * Helpers
 *
 */

void swap(int*, int*);

void merge(int*, int, int);

int partition(int*, int, int);
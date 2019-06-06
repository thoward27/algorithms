#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

/** Bubble Sort
 *  O(n^2), Omega(n)
 */
void bubble_sort(int* arr, int n) {
  for (int i = 0; i < (n - 1); i++) {
    if (arr[i] > arr[i + 1]) {
      arr[i] = arr[i] xor arr[i + 1];
      arr[i + 1] = arr[i] xor arr[i + 1];
      arr[i] = arr[i] xor arr[i + 1];
    }
  }
  if (n != 1) {
    bubble_sort(arr, n - 1);
  }
}


void swap(int * y, int * x) {
  int temp;
  temp = *y;
  *y = *x;
  *x = temp;
}

void selection_sort(int* arr, int n) {
 
  for(int i = 0; i < (n-1); i++) {
    int min = i;
    for (int j = i + 1; j < n ; j++) {
        if(arr[j] < arr[min]) min = j;
    }
    swap(&arr[min],&arr[i]);
    
  }
}

void insertion_sort(int* arr, int n) {
    for(int i = 0; i < n; i++) {
      // Set j = i 
      // j > 0 -> for each j from i to 0
      // if the element at j-1 is greater than the element at j 
      // -> arr[j] < arr[j-1]
      for(int j = i; j > 0 && arr[j] < arr[j-1]; j--) {
        //then swap the elements
        swap(&arr[j],&arr[j-1]);
      }
    }

}






/** Selection Sort
 * O(?), Omega(?), Theta(?)
 */

/** Insertion Sort
 * O(?), Omega(?), Theta(?)
 */

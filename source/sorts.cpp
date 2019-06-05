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

/** Selection Sort
 * O(n^2), Omega(n^2), Theta(n^2)
 */
void selection_sort(int * arr, int n)
{
  int min;
  for(int i = 0; i < (n - 1); i++)
  {
    min = i;
    for(int j = i+1; j < n ; j++)
    {
      if(arr[j]<arr[min])
      {
        min = j;
      }
    }
    int temp = arr[i];
    arr[i] = arr[min];
    arr[min]=temp;
  }
}
/** Insertion Sort
 * O(n^2), Omega(n), Theta(N/A) Average(n^2)
 * 
 */

void insertion_sort(int* arr, int n)
 {
   
   int min;
  for(int i =0; i < n; i++)
  {
    min = i;
    for(int j = i; j > 0  ; j--)
    {
      if(arr[j-1] > arr[j])
      {
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j]=temp;
      }
      else
      {
        break;
      }
      
    }
  }
  
 }
 

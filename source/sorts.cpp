#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "sorts.hpp"

void bubble_sort(int *arr, int n) {
    int temp = 0;
    for(int i = 0; i < (n - 1); i++) {
        if(arr[i] > arr[i + 1]){
            temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
            bubble_sort(arr, n);
        }
    }
    if (temp != 0) {
        bubble_sort(arr, n);
    }
}

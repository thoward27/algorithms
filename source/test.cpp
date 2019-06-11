#include <iostream>

void swap(int *y, int *x)
{
    int temp;
    temp = *y;
    *y = *x;
    *x = temp;
}
void quicksort(int *arr, int n)
{
    int lo, hi;
    lo = 0;
    hi = n - 1;
    quicksort(arr, lo, hi);
}
void quicksort(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(arr, lo, hi);
        quicksort(arr, lo, p - 1);
        quicksort(arr, p + 1, hi);
    }
}

int partition(int *arr, int lo, int hi)
{
    int i = lo + 1, j = hi;
    while (true)
    {
        while (arr[i] < arr[lo])
        {
            i++;
        }
        while (arr[j] > arr[lo])
        {
            j--;
        }
        if (j <= i)
        {
            break;
        }
        swap(&arr[i], &arr[j]);
    }

    swap(&arr[lo], &arr[j]);
    return j;
}

void printArray(int arr[], int size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            std::cout << arr[i] << "," << std::flush;
        }
        else
        {
            std::cout << arr[i] << std::flush;
        }
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {100, 200, 5, 37, 58, 44, 5, 67, 90, 78, 20, 18, 16, 44, 0, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Start: ";
    printArray(arr, n);
    quicksort(arr, 0, n - 1);
    std::cout << "Finish: ";
    printArray(arr, n);
    return 0;
}
#include <iostream>

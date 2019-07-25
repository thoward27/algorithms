#pragma once
#include "../Functions/functions.hpp"

/** sort
 * Sort the given array using the algorithm included at compilation
 * 
 * Inputs:
 * @param arr: the arry to be sorted
 * @param n: size of arr param
 * 
 * Outputs:
 * A sorted array within arr
 * 
 * Examples:
 * sort([4,1,3,5,2], 5) == [1,2,3,4,5]
 * 
 * Runtime:
 * Dependant on Algorithm used: see .cpp sort files for runtimes
 */
void sort(int* array, int n);

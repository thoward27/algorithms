#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

// Use this in your sorting implementations
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Your implementation of Insertion Sort
void in_sort(int *arr, int len) {
    // TODO: Implement the insertion sort algorithm
}

// Your implementation of Selection Sort
void sel_sort(int *arr, int len) {
    // TODO: Implement the selection sort algorithm
}

// C++ built-in sorting
void cpp_sort(int *arr, int len) {
    std::sort(arr, arr+len);
}

// Generate a random, unsorted list
int *gen_list_unsorted(int size) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int *nlist = new int[size];
    for (int i = 0; i < size; ++i) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

// Generate a sorted list
int *gen_list_sorted(int size) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int *nlist = new int[size];
    for (int i = 0; i < size; ++i) {
        nlist[i] = distribution(generator);
    }
    std::sort(nlist, nlist+size);
    return nlist;
}

// Generate a list that is sorted in reverse
int *gen_list_reversed(int size) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int *nlist = new int[size];
    for (int i = 0; i < size; ++i) {
        nlist[i] = distribution(generator);
    }
    std::sort(nlist, nlist+size);
    for (int i = 0; i < size/2; ++i) {
        swap(nlist+i, nlist+(size-i-1));
    }
    return nlist;
}

// Generate a list that is almost sorted
int *gen_list_partial_sorted(int size) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    std::uniform_int_distribution<int> index_distribution(0,size-1);
    int *nlist = new int[size];
    for (int i = 0; i < size; ++i) {
        nlist[i] = distribution(generator);
    }
    std::sort(nlist, nlist+size);
    for (int i = 0; i < size; ++i) {
        int idx1 = index_distribution(generator);
        int idx2 = index_distribution(generator);
        swap(nlist+idx1, nlist+idx2);
    }
    return nlist;
}

// Use this function to make copies of the generated arrays
// so you can sort with your in-place algorithms
int *copy_array(int *arr, int len) {
    int *copy = new int[len];
    for (int i = 0; i < len; ++i) {
        copy[i] = arr[i];
    }
    return copy;
}

// An empty function that will be called at the start of main,
// and thus a good place to write test code. Feel free to modify as needed
void test_sorts() {
    // TODO: Write code to test in_sort and sel_sort
}

// This function formats and prints your benchmarking data
void print_table(char names[][30], double times[][4]){
    // Printing the input sizes with formatting.
    std::cout << "    ";
    // This counter keeps track of the total width of the table
    int total_width = 6;
    for (int i = 0; i < 4; ++i) {
        int width = 0;
        // These two loops ensure the length of each column is 10 characters,
        // first printing the input size, then whitespace.
        while (names[i][width] != '\0') {
            std::cout << names[i][width];
            ++width;
            ++total_width;
        }
        while (width < 10) {
            std::cout << ' ';
            ++width;
            ++total_width;
        }
        std::cout << ' ';
        ++total_width;
    }
    std::cout << std::endl;
    total_width = 47;

    // Printing the rest with formatting.
    for (int i = 0; i < 7; ++i) {
        if (i % 2 == 0) {
            // Prints bars and underscores on every other line as separators.
            std::cout << "   ";
            for (int j = 3; j < total_width; ++j) {
                if (j % 11 == 3) {
                    std::cout << '|';
                } else {
                    std::cout << '_';
                }
            }
            std::cout << '|' << std::endl;
        } else {
            // Prints the rows with actual table content.
            std::cout << 'A' << (i+1)/2 << ' ';
            for (int j = 3; j < total_width; ++j) {
                // Prints a separator between each column
                if (j % 11 == 3) {
                    std::cout << '|';
                } else {
                    double t = times[(i-1)/2][(j-4)/11];
                    // One way to handle algorithms that run too long
                    if (t >= 60) {
                        std::cout << "N/A       ";
                    } else {
                        // floor(log10(t)) is the number of digits of t, which is used to calculate the precision
                        (log10(t) >= 1) ? std::cout.precision(7 - floor(log10(t))) : std::cout.precision(7);
                        std::cout << std::fixed << times[(i-1)/2][(j-4)/11] << ' ';
                    }
                    j += 9;
                }
            }
            std::cout << '|' << std::endl;
        }
    }
}

// -------------------------------------------------
// -------------------------------------------------
// Main function
// -------------------------------------------------
// -------------------------------------------------
int main() {
    test_sorts();

    // Setting Up //

    // Array of pointers (each pointer will point to an array of integers)
    int *lists[4];

    // Array to store your collected runtimes
    // Each row (first index) corresponds to one of the sort algorithms, each column (second index) to an array type
    double times[3][4];


    // The number stored here decides the size of the randomly generated arrays you will use
    int input_size = 5000;
    char names[4][30] = {"Random", "Sorted", "Reversed", "Partially"}; // For printing the table.

    // Fills lists[] with the four array types in the order specified by `names` above.
    typedef int *(*gen)(int);
    gen listmake[] = {gen_list_unsorted, gen_list_sorted, gen_list_reversed,gen_list_partial_sorted};
    for(int i = 0; i < 4; ++i) {
        lists[i] = listmake[i](input_size);
    }


    // Sorting and Benchmarking //

    // Tracks which row of times[][] you are writing into
    int idx = 0;

    // Insertion sort
    for (int j = 0; j < 4; ++j) {
        // TODO
        // Capture runtimes from insertion sort
        // Look into the cpp_sort below before writing your code
    }

    // Move to next row of times[][]
    ++idx;

    // Selection sort
    for (int j = 0; j < 4; ++j) {
        // TODO
        // Capture runtimes from selection sort
        // Look into the cpp_sort below before writing your code
    }

    // Move to last row of times[][]
    ++idx;

    // cpp_sort
    for (int j = 0; j < 4; ++j) {
        int *copy = copy_array(lists[j], input_size);

        // Time the sorting algorithm on the copied array
        auto start = std::chrono::steady_clock::now();
        cpp_sort(copy, input_size);
        auto end = std::chrono::steady_clock::now();

        // Record the time in the 2D array
        times[idx][j] = std::chrono::duration<double> (end - start).count();

        // Delete the copy
        delete [] copy;
    }


    // Printing //

    print_table(names, times);


    // Cleaning Up //

    // Deallocate dynamic arrays in lists[]
    for (int i = 0; i < 4; ++i) {
        delete [] lists[i];
    }

    return 0;
}

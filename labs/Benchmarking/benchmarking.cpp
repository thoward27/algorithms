#include <iostream>
#include <chrono>
#include <random>
#include <cmath>

#define t_p std::chrono::time_point<std::chrono::steady_clock>

int check_time(t_p);

int num_in_array(const int* arr, int len, int num) {
    // TODO: Implement num_in_array

    // Uncomment the following lines once you're working on the table printing.
    // auto start = std::chrono::steady_clock::now(); // Keep this at the top of the function

    // if (check_time(start)) return -1; // Keep this at the end of your innermost loop

    return 0;
}

int sum2_in_array(const int* arr, int len, int num) {
    // TODO: Implement sum2_in_array

    // Uncomment the following lines once you're working on the table printing.
    // auto start = std::chrono::steady_clock::now(); // Keep this at the top of the function

    // if (check_time(start)) return -1; // Keep this at the end of your innermost loop

    return 0;
}

int sum3_in_array(const int* arr, int len, int num) {
    // TODO: Implement sum3_in_array

    // Uncomment the following lines once you're working on the table printing.
    // auto start = std::chrono::steady_clock::now(); // Keep this at the top of the function

    // if (check_time(start)) return -1; // Keep this at the end of your innermost loop

    return 0;
}

// Generate an array of random integers. The range is +/- the size of the array
int* gen_rand_list(int size) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(-size,size);
    int* nlist = new int[size];
    for (int i = 0; i < size; i++) {
        nlist[i] = distribution(generator);
    }
    return nlist;
}

// Generate a random integer. The range is from min to max
int gen_rand_int(int min, int max) {
    std::random_device sd;
    std::mt19937 generator(sd());
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(generator);
}

// Deallocate an array on the heap. A function alias for the delete keyword
void delete_list(int* arr) {
    delete [] arr;
}

// Auxiliary function to keep the program from running too long
int check_time(t_p start_time) {
    auto curr_time = std::chrono::steady_clock::now();
    double t = std::chrono::duration<double> (curr_time - start_time).count();
    return (t > 15) ? 1 : 0;
}

int main() {
    /* Creates an array of pointer to functions
     *
     * To call a function from this array, use the following line:
     *
     *      functions[i](arr, len, num);
     *
     * Where i is the index of the function to be used, and a, b are the parameters
     *    i = 0 : num_in_array
     *    i = 1 : sum2_in_array
     *    i = 2 : sum3_in_array
     *
     * This can be used to benchmark the different implementations without having to
     * repeat code.
     */
    typedef int (*sum_fn)(const int*, int, int);
    sum_fn functions[] = {num_in_array, sum2_in_array, sum3_in_array};

    //
    // Example usage: this shows how to call the three functions applied to the same random sequence
    //
    // Create a list of 20 random numbers (allocate the array dynamically in the heap)
    int *arr = gen_rand_list(20);
    // Create a single random integer between -10 and 10. This does not need to be deallocated
    int num = gen_rand_int(-10, 10);
    // Apply the three functions to the array with lenght=20 and num randomly generated
    for (int i = 0; i < 3; i++) {
        functions[i](arr, 20, num);
    }
    // Since the array was allocated on the heap, it needs to be deallocated, which is what the following function does
    delete_list(arr);

    // Student code starts here
    // TODO
    // you can use/modify the example above to print the table with running times
    
    // the following lines can be used to capture the runtime
    // auto start = std::chrono::steady_clock::now();
    // call your function here
    // auto end = std::chrono::steady_clock::now();
    // the following line can be used to calculate the difference (runtime)
    // double t = std::chrono::duration<double> (end - start).count();
    
    return 0;
}

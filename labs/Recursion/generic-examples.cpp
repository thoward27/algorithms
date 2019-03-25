#include <iostream>

void print_binary(int n) {
    if (n > 0) {
        print_binary(n/2);
        std::cout << n % 2;
    }
}

int power(int x, int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    // recursive call
    return x * power(x, n-1);
}


int factorial(int n) {
    // base case
    if (n == 0) {
        return 1;
    }
    // recursive call
    return n * factorial(n-1);
}

int main() {
    int array[5] = {1, 2, 3, 4, 5};
    std::cout << factorial(5) << std::endl;
    std::cout << power(2, 8) << std::endl;
    print_binary(27);
    std::cout << std::endl;
}

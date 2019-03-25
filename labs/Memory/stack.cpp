#include <iostream>
#include <cmath>

int multiply(unsigned int, unsigned int);
int factorial(int n);
void finish();
int foo(int);
int bar(int);
void print(char**);

// TODO Functions
int gcd(unsigned int, unsigned int);
void print_reversed(int);


int main(int argc, char *argv[]) {
    int n = foo(argc);
    n = multiply(n, n);
    n = foo(n);
    std::cout << "n is somehow: " << n << std::endl;

    print(argv);

    int x = 10;
    int y = foo(x);
    std::cout << x << " * " << y << " = " << multiply(x, y) << std::endl;

    y = factorial(5);
    std::cout << "bar(" << y << ") = " << bar(y) << std::endl;
    std::cout << "foo(" << y << ") = " << foo(y) << std::endl;
    return 0;
}

int multiply(unsigned int x, unsigned int y) {
    return (y == 0) ? 0 : x + multiply(x, --y);
}

int factorial(int n) {
    return (n <= 0) ? 1 : n * factorial(--n);
}

void finish() {
    std::cout << "The program has completed." << std::endl;
}

int foo(int n) {
    if (n < 0) {
        return -n;
    } else if (n > 0) {
        return n * 2;
    } else {
        return factorial(n);
    }
}

int bar(int n) {
    if (n >= 10) {
        return 1 + bar(n / 10);
    } else {
        return 1;
    }
}

void print(char *argv[]) {
    std::cout << "bar(argv[0][0]) = " << bar(argv[0][0]) << std::endl;
}

// TODO Functions
int gcd(int x, int y) {
    return 0;
}

void print_reversed(int n) {
    std::cout << n << std::endl;
}

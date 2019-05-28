#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.hpp"

/**Absolute Value */
int abs_val(int x) {
    return (x > 0) ? x : x * -1;
}

/**Power */
int pow(int base, int num) {
    if (num == 0) return 1;
    else {
        return base * pow(base, num-1);
    }
}

/**Logarithm */
int log(int base, int num) {
    int count = 0;
    while (num > 1) {
        num /= base;
        count++;
    }
    return count;
}

/**Character to integer */
int chartoint(char c) {
    int result = (int) c;
    result -= 48;
    return result;
}

/**Integer to character */
char inttochar(int x) {
    return (char) (x + 48);
}

/**ASCII Bullshit */
char chr(int x) {
    return (char) x;
}


int ord(char c) {
    return (int) c;
}

int max(int x, int y) {
    return (x>=y) ? x : y;
}

int max(int x, int y, int z) {
    if (x > y && x > z) {
        return x;
    } else if (y > z && y>x) {
        return y;
    } else {
        return z;
    }
}

int min(int x, int y) {
    return (x <= y) ? x : y;
}

int min(int x, int y, int z) {
    if (x < y && x < z) {
        return x;
    } else if (y <  z && y < x) {
        return y;
    } else {
        return z;
    }
}

int round(double x, char c) {
    if (c == 'u') {
        return (int) (x + 1);
    } else {
        return (int) x;
    }
}

bool prime(int) {
    return true;
}

long fibonacci(int) {
    return 1;
}

long factorial(int) {
    return 1;
}
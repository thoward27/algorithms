#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.hpp"

/** Absolute Value
 * Converts any integer to its absolute value.
 * O(1) and Omega(1), thus,
 * Theta(1)
 */
int abs_val(int x){
    if(x < 0){
        return x * -1;
    }else{
        return x;
    }
}
/** Power
 * Raise the given base to the given power.
 * O(n)
 * omega(1)
 */
int pow(int base , int num){
    if (num == 0){
        return 0;
    }else if(num == 1){
        return base;
    }else{
        int ans = base;
        for(int i = 0; i < num; ++i){
            ans *= base;
        }
        return ans;
    }
    
}
/** Logarithm
 * Calculates the log of num with base
 * O(n)
 * omega(0)
 */
int log(int base, int num){
    if(base==0){
        return 0;
    }else if(base == 1){
        return num;
    }else{
        int n = num;
        for(int i =0; i < num; ++i){
            n /= num;
        }
        return n;
    }

}
/** Chartoint
 * Takes an char c and returns its integer value
 * O(1)
 * omega(1)
 */
int chartoint(char c){
    return ((int)c)-48;
}
/** Inttochar
 * Takes an int and returns its char
 * O(1)
 * omega(1)
 */
char inttochar(int x){
    return (char)(x+48);
}
/** Chr
 * Takes any int and returns its ascii val
 * O(1)
 * omega(1)
 */
char chr(int x){
    return (char)(x);
}
/** Ord
 * Takes any char and returns int val
 * O(1)
 * omega(1)
 */

int ord(char x){
    return int(x);
}
/** Max
 * Returns the largest number of given ints
 * O(1)
 * omega(1)
 */

int max(int x, int y){
    return(x > y)? x : y;
}
int max(int x, int y, int z){
    int max1 = (x > y)? x : y;
    return (max1 > z)? max1 : z;

}
/** Min
 * Returns the smallest number of given ints
 * O(1)
 * omega(1)
 */

int min(int x, int y){
    return(x < y)? x : y;
}
int min(int x, int y, int z){
    int min1 = (x < y)? x : y;
    return (min1 < z)? min1 : z;
}
/** Round
 * Takes a floating point number and rounds it up or down
 * O(2)
 * omega(2)
 */
int round(double x, char c){
    if(c == 'd'){
        return (int)x;
    }else{
        return (int)(x+1);
    }
}
/** Prime
 * Tests if a number is prime
 * O(2)
 * omega(2)
 */
bool prime(int){

    return true;

}
long fibonacci(int){
    return 1;

}
long factorial(int){
    return 1;

}

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "functions.hpp"

int abs_val(int x) {
    return (x > 0) ? x : x * -1;
}

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

int log(int base, int num) {
    int count = 0;
    while (num > 1) {
        num /= base;
        count++;
    }
    return count;
}

int chartoint(char c) {
    int result = (int) c;
    result -= 48;
    return result;
}

char inttochar(int x) {
    return (char) (x + 48);
}

char chr(int x) {
    return (char) x;
}


int ord(char c) {
    return (int) c;
}

int max(int x, int y){
    return(x > y)? x : y;
}

int max(int x, int y, int z){
    int max1 = (x > y)? x : y;
    return (max1 > z)? max1 : z;

}

int min(int x, int y){
    return(x < y)? x : y;
}

int min(int x, int y, int z){
    int min1 = (x < y)? x : y;
    return (min1 < z)? min1 : z;
}

}   

char chr(int x){
    return (char)(x);
}

int ord(char x){
    return int(x);
}


int round(double x, char c){
    if(c == 'd'){
        return (int)x;
    }else{
        return (int)(x+1);
    }
}

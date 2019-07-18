#include <iostream>

int main(){
    int points = 4;
    int iter;
    std::cin >> iter;
    for(int i = 0; i < iter; ++i){
        points *= 2;
        points += iter;
    }
    std::cout << points << std::endl;
}
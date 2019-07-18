#include <iostream>

int main(){
    int N, T, temp;
    int num = 1;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> T;
        num = 1;
        for(int j = 1; j <= T; ++j){
            num *= j;
        }
        if(num >= 10){
            temp = (num/10);
            num = num - (temp * 10);
        }
        std::cout << num << std::endl;
    }
}
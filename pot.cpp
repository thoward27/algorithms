#include <iostream>

int main(){
    int n, base, powe, temp;
    int expo = 1;
    long total = 0;
    std::cin >> n;
    for(int i = 0; i < n; ++i){
        std::cin >> base;
        temp = (base/10);
        powe = base - (temp * 10);
        for(int j = 0; j < powe; ++j){
            expo *= temp;
        }
        total += expo;
        expo = 1;
    }
    std::cout << total << std::endl;
}
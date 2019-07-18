#include <iostream>

int main(){
    int P, K, N;
    int posSum = 0;
    int oddSum = 0;
    int evenSum = 0;
    std::cin >> P;
    for(int i = 0; i < P; ++i){
        std::cin >> K >> N;
        int posSum = 0;
        int oddSum = 0;
        int evenSum = 0;
        for(int j = 0; j <= 2*N; ++j){
            if(j%2 == 0){
                evenSum += j;
            }else if(j%2 > 0){
                oddSum += j;
            }
        }
        for(int l = 0; l <= N; ++l){
            posSum += l;
        }
        std::cout << K << " " << posSum << " " << oddSum << " " << evenSum << std::endl;
    }
}
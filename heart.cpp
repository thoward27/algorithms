#include <iostream>

int main(){
    int N, b;
    float p, BPM, ABPM;
    std::cin >> N;
    for(int i = 0; i < N; ++i){
        std::cin >> b >> p;
        BPM = (60 * b) / p;
        ABPM = 60 / p;
        std::cout << BPM - ABPM << " " << BPM << " " << BPM + ABPM << std::endl;
    }
}
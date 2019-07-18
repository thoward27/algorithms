#include <iostream>

int main(){
    int score = 0;
    char suit, card, color;
    int hands;
    std::cin >> hands >> suit;
    for(int i = 0; i < 4*hands; ++i){
        std::cin >> card >> color;
        switch(card){
            case 'A':
                score += 11;
                break;
            case 'K':
                score += 4;
                break;
            case 'Q':
                score += 3;
                break;
            case 'J':
                if(color == suit){
                    score += 20;
                    break;
                }else{
                    score += 2;
                    break;
                }
            case 'T':
                score += 10;
                break;
            case '9':
                if(color == suit){
                    score += 14;
                    break;
                }else{
                    break;
                }
            default:
                break;
        }
    }
    std::cout << score << std::endl;
    return 0;
}
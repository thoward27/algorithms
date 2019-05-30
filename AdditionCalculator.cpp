#include <iostream>
#include <string>

int main() {
    std::cout << "Enter first number: ";

    std::string firstNum;
    std::cin >> firstNum;
    int a = std::stoi(firstNum);

    std::cout <<"Enter operator: ";

    char op;
    std::cin >> op;

    std::cout << "Enter second number: ";

    std::string secondNum;
    std::cin >> secondNum;
    int b = std::stoi(secondNum);

    switch (op) {
        case '+':
            std::cout << "Answer: " << a + b << std::endl;
            break;
        case '-':
            std::cout << "Answer: " << a - b << std::endl;
            break;
        case '*':
            std::cout << "Answer: " << a * b << std::endl;
            break;
        case '/':
            std::cout << "Answer: " << a / b << std::endl;
            break;
        default:
            std::cout << "Invalid operator!" << std::endl;
    }

    return 0;
}
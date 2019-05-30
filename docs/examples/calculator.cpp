#include <iostream>
#include <string>

int main() {
  // Get the numbers.
  std::cout << "Enter the two numbers: ";
  std::string stringa, stringb;
  std::cin >> stringa >> stringb;
  int a = std::stoi(stringa);
  int b = std::stoi(stringb);

  // Get the operator.
  std::cout << "Enter operator: ";
  char op;
  std::cin >> op;

  // Switch on all possible operators.
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
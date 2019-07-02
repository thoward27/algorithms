#include <iostream>
#include "source/Algorithms/twostack.hpp"

/** Pseudocode for your program.
 * While True
 *   Read an expression from the user.
 *   Evaluate the expression.
 *   If the expression is valid, print it.
 *   Otherwise, print an exception.
 */
int main() {
  char expression[100];
  while (true) {
    std::cout << "Enter an Expression: ";
    std::cin.getline(expression, 100);
    try {
      std::cout << expression << " = " << twostack(expression);
    } catch (...) {
      std::cout << "Bad Expression";
    }
    std::cout << std::endl;
  }
  return 0;
}

#include <iostream>
#include <string>

int main() {
  // Get their name.
  std::cout << "First and last name? ";

  std::string first, last;
  std::cin >> first >> last;

  // Build the greeting.
  std::string greeting = "* Hello, " + first + " " + last + "! *";
  std::string stars(greeting.size(), '*');

  // Print it out.
  std::cout << std::endl;
  std::cout << stars << std::endl;
  std::cout << greeting << std::endl;
  std::cout << stars << std::endl;

  return 0;
}
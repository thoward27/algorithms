#include <iostream>
#include <string>

int main() {
    std::cout << "First name? ";

    std::string firstName;
    std::cin >> firstName;

    std::cout << "Last name? ";

    std::string lastName;
    std::cin >> lastName;

    std::string greeting = "* Hello, " + firstName + " " + lastName + "! *";
    std::string stars(greeting.size(), '*');

    std::cout << std::endl;
    std::cout << stars << std::endl;
    std::cout << greeting << std::endl;
    std::cout << stars << std::endl;

    return 0;
}
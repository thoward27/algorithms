#include <iostream>

// Function Prototype
void printMessage(char *charray, int typeSize);

int main (int argc, char **argv) {
    // The size of our array
    int arraySize = 5;

    // Declare the array
    long secret_message[arraySize];

    //The size of our number type
    int typeSize = sizeof(long);

    // Why choose these numbers?
    secret_message[0] = 478560413032;
    secret_message[1] = 431316168567;
    secret_message[2] = 7827304;
    secret_message[3] = 6648417;
    secret_message[4] = 7696249;

    // Call our method to print secret message
    for (int i = 0; i < arraySize; i++)
    {
        printMessage((char*) &secret_message[i], typeSize);
    }

    std::cout << std::endl;

    return 0;
}

// What does this function do and why?
// Note that size was passed with the array
void printMessage(char *charray, int typeSize) {
    for (int j = 0; j < sizeof(long); j++)
    {
        std::cout << charray[j];
    }
    std::cout << " ";
}

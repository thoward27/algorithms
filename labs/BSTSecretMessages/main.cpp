#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "bst.hpp"

int main(int argc, char** argv) {
    if (argc != 4) {
        std::cout << "Error: Invalid arguments" << std::endl;
        std::cout << "Usage: ./main filename n_entries search_val" << std::endl;
        exit(1);
    }

    // TODO: Create and fill BSTree and search for secret message

    return 0;
}
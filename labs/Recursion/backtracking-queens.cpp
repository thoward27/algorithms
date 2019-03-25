#include <iostream>
#include <cstdlib>

bool queens(bool **, int, int);
bool safe_for_queen(bool **, int, int, int);

// Creates a length by length 2D array of bools with all values initialized to 0
bool **empty_solutions_grid(int len) {
    bool **grid = new bool*[len];
    for (int i = 0 ; i < len ; i ++) {
        grid[i] = new bool[len];
        for (int j = 0 ; j < len ; j ++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

// Deallocates a 2D array created by empty_solutions_grid()
void free_solutions_grid(bool **grid, int len) {
    for (int i = 0 ; i < len ; i ++) {
        delete [] grid[i];
    }
    delete [] grid;
}

// Prints the data stored in a 2D array created by empty_solutions_grid()
void print_solutions_grid(bool **grid, int len) {
    for (int i = 0 ; i < len ; i ++) {
        for (int j = 0 ; j < len ; j ++) {
            std::cout << grid[j][i] << ' ';
        }
        std::cout << std::endl << std::endl;
    }
}

int main(int argc, char** argv) {
    int n = 8;
    if (argc > 2) {
        std::cerr << "Too many args." << std::endl;
        exit(1);
    } else if (argc == 2) {
        n = atoi(argv[1]);
    }

    bool **grid = empty_solutions_grid(n);
    bool result = queens(grid, n, 0);
    if (!result) {
        std::cout << "NO SOLUTION EXISTS" << std::endl;
    }
    print_solutions_grid(grid, n);
    free_solutions_grid(grid, n);
    return 0;
}

bool queens(bool **grid, int n, int col) {
    //
    // TODO
    // Implement the N-Queens algorithm here. This should be recursive.
    //
    return true;
}

bool safe_for_queen(bool **grid, int n, int col, int row) {
    //
    // TODO
    // Implement your algorithm to check if a queen can be placed
    // at a given location col,row
    //
    return true;
}

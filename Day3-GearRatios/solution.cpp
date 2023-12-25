#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>

// Function to check if a character is a symbol (not a digit or period)
bool isSymbol(char ch) {
    return !isdigit(ch) && ch != '.';
}

// Function to check if a cell is adjacent to a symbol
bool isAdjacentToSymbol(size_t x, size_t y, const std::vector<std::string>& grid) {
    static const int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
    static const int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

    for (int i = 0; i < 8; ++i) {
        size_t newX = x + dx[i];
        size_t newY = y + dy[i];

        if (newX < grid.size() && newY < grid[0].size()) {
            if (isSymbol(grid[newX][newY])) {
                return true;
            }
        }
    }
    return false;
}

// Function to check if a cell is the start of a number
bool isStartOfNumber(size_t x, size_t y, const std::vector<std::string>& grid) {
    return isdigit(grid[x][y]) && (y == 0 || !isdigit(grid[x][y-1]));
}

int main() {
    std::ifstream file("input.txt");
    std::vector<std::string> grid;
    std::string line;

    // Read the file into the grid
    while (std::getline(file, line)) {
        grid.push_back(line);
    }

    int sum = 0;
    // Iterate through each cell in the grid
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (isStartOfNumber(i, j, grid)) {
                int num = 0;
                size_t k = j;
                bool adjacentToSymbol = false;
                // Collect the entire number and check if any digit is adjacent to a symbol
                while (k < grid[i].size() && isdigit(grid[i][k])) {
                    num = num * 10 + (grid[i][k] - '0');
                    if (isAdjacentToSymbol(i, k, grid)) {
                        adjacentToSymbol = true;
                    }
                    ++k;
                }
                // Add the number to the sum if it's adjacent to a symbol
                if (adjacentToSymbol) {
                    sum += num;
                }
            }
        }
    }

    std::cout << "Sum of all part numbers: " << sum << std::endl;
    return 0;
}

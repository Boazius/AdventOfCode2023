#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

// Function to check if a character is a symbol
bool isSymbol(char c) {
    return c == '*' || c == '#' || c == '+' || c == '$';
}

// Function to check if the coordinates are within bounds of the engine schematic
bool isValid(int x, int y, int rows, int cols) {
    return x >= 0 && x < rows && y >= 0 && y < cols;
}

// Function to calculate the sum of part numbers in the engine schematic
int sumPartNumbers(const std::vector<std::string>& schematic) {
    int rows = schematic.size();
    if (rows == 0) return 0;

    int cols = schematic[0].size();
    int sum = 0;

    // Define 8 possible directions (including diagonals)
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (std::isdigit(schematic[i][j]) && !isSymbol(schematic[i][j])) {
                int currentNumber = 0;
                int digits = 0;

                // Parse the multi-digit number
                while (isValid(i, j + digits, rows, cols) && std::isdigit(schematic[i][j + digits])) {
                    currentNumber = currentNumber * 10 + (schematic[i][j + digits] - '0');
                    digits++;
                }

                // Check adjacent cells in all directions
                bool adjacentToSymbol = false;
                for (int k = 0; k < 8; ++k) {
                    int newX = i + dx[k];
                    int newY = j + dy[k];

                    if (isValid(newX, newY, rows, cols) && isSymbol(schematic[newX][newY])) {
                        adjacentToSymbol = true;
                        break;
                    }
                }

                if (adjacentToSymbol) {
                    sum += currentNumber; // Add the part number
                }
            }
        }
    }

    return sum;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::vector<std::string> schematic;
    std::string line;

    // Read the engine schematic from the file
    while (std::getline(inputFile, line)) {
        schematic.push_back(line);
    }

    inputFile.close(); // Close the input file

    // Calculate the sum of part numbers in the engine schematic
    int totalSum = sumPartNumbers(schematic);

    // Output the sum of part numbers
    std::cout << "The sum of all part numbers in the engine schematic is: " << totalSum << std::endl;

    return 0;
}

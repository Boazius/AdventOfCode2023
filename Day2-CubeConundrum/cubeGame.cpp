#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <cctype>

// Constants for valid cube counts
const int VALID_RED_CUBES = 12;
const int VALID_GREEN_CUBES = 13;
const int VALID_BLUE_CUBES = 14;

// Function to check if the game is valid based on cube counts
bool isValidGame(const std::string &line) {
    int maxGreen = 0, maxRed = 0, maxBlue = 0;

    // Define a regex pattern to match cube counts and colors
    std::regex pattern(R"((\d+)\s(green|red|blue))");
    std::smatch match;

    // Iterate through the line to find cube counts for each color
    auto words_begin = std::sregex_iterator(line.begin(), line.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        int count = std::stoi(match[1].str());
        std::string color = match[2].str();

        // Update max counts for each color
        if (color == "green" && count > maxGreen) {
            maxGreen = count;
        } else if (color == "red" && count > maxRed) {
            maxRed = count;
        } else if (color == "blue" && count > maxBlue) {
            maxBlue = count;
        }
    }

    // Check if max counts exceed the valid limits
    return (maxGreen <= VALID_GREEN_CUBES && maxRed <= VALID_RED_CUBES && maxBlue <= VALID_BLUE_CUBES);
}

// Function to extract the first number from a string
int extractFirstNumber(const std::string &input) {
    int result = 0;
    bool foundNumber = false;

    // Iterate through the characters in the string
    for (char c : input) {
        if (std::isdigit(c)) {
            foundNumber = true;
            result = result * 10 + (c - '0'); // Accumulate the number
        } else if (foundNumber) {
            break; // Stop if a non-digit is encountered after finding a number
        }
    }

    return foundNumber ? result : -1; // Return the first number found or -1 if none
}

int main() {
    int sum = 0;
    std::ifstream inputFile("input.txt");
    if (!inputFile) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        int gameNum = extractFirstNumber(line); // Extract the first number from the line
        if (isValidGame(line)) { // Check if the game is valid
            sum += gameNum; // Add the number to the sum if the game is valid
        }
    }

    inputFile.close(); // Close the input file

    // Output the sum of all valid games
    std::cout << "The sum of all valid games is: " << sum << std::endl;

    return 0;
}

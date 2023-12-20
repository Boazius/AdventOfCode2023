#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>

// Map to store number words and their corresponding values
std::unordered_map<std::string, int> numberMap = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
    {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
};

// Function to find number substrings in a given line
int findNumberSubstring(const std::string& line, bool fromStart) {
    std::string currentSubstring;
    int increment = fromStart ? 1 : -1; // Adjusts iteration direction

    for (size_t i = fromStart ? 0 : line.length() - 1;
         fromStart ? (i < line.length()) : (i >= 0);
         i += increment) {
        if (std::isdigit(line[i])) {
            return line[i] - '0'; // Found a digit, return its integer value
        } else if (std::isalpha(line[i])) {
            currentSubstring = (fromStart ? currentSubstring + line[i] : line[i] + currentSubstring);

            // Check for matches in the numberMap
            for (const auto& entry : numberMap) {
                if (currentSubstring.find(entry.first) != std::string::npos) {
                    return entry.second; // Return the corresponding numeric value
                }
            }
        } else {
            currentSubstring.clear(); // Reset the substring if non-alphabetic character encountered
        }
    }
    return -1; // Indicates no valid number substring found
}

int main() {
    int sum = 0;
    std::ifstream inputFile("input.txt");
    std::string line;

    if (inputFile.is_open()) {
        // Read lines from the file
        while (std::getline(inputFile, line)) {
            // Calculate the sum of the number substrings from both ends of each line
            int numberSubstring = findNumberSubstring(line, true) * 10 + findNumberSubstring(line, false);
            sum += numberSubstring; // Add to the running sum
        }
        inputFile.close(); // Close the file
    } else {
        std::cout << "Failed to open the file." << std::endl;
        return 1; // Exit with an error code
    }

    std::cout << "The sum of all numbers is: " << sum << std::endl; // Display the final sum
    return 0; // Exit successfully
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <cctype>
#include <limits>

// Function to calculate the points for a single card.
// Points start at 1 for the first winning number and double for each subsequent match.
int calculateCardPoints(const std::set<int>& winningNumbers, const std::vector<int>& yourNumbers) {
    int points = 0;
    for (int num : yourNumbers) {
        if (winningNumbers.find(num) != winningNumbers.end()) {
            points = points == 0 ? 1 : points * 2;
        }
    }
    return points;
}

// Parses a single line of numbers from the input stream.
// Stops reading when it encounters the '|' character or end of the line.
std::vector<int> parseNumbers(std::istringstream& iss) {
    std::vector<int> numbers;
    std::string segment;
    while (iss >> segment) {
        if (segment == "|") {
            break;
        }
        numbers.push_back(std::stoi(segment));
    }
    return numbers;
}

int main() {
    std::ifstream file("input.txt");
    std::string line;
    int totalPoints = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);

        // Skip the "Card X:" prefix in each line
        iss.ignore(std::numeric_limits<std::streamsize>::max(), ':');

        // Read and parse winning numbers
        std::vector<int> winningNumbers = parseNumbers(iss);
        std::set<int> winningSet(winningNumbers.begin(), winningNumbers.end());

        // Read and parse your numbers
        std::vector<int> yourNumbers = parseNumbers(iss);

        // Calculate and accumulate points for each card
        totalPoints += calculateCardPoints(winningSet, yourNumbers);
    }

    std::cout << "Total points: " << totalPoints << std::endl;
    return 0;
}


#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // For isdigit function

int main() {
    int sum = 0;

    std::ifstream inputFile("input.txt");
    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            if (!line.empty()) {
                int firstDigit = -1, lastDigit = -1;

                // Find first digit
                for (char c : line) {
                    if (std::isdigit(c)) {
                        firstDigit = c - '0';
                        break;
                    }
                }

                // Find last digit
                for (int i = line.size() - 1; i >= 0; i--) {
                    if (std::isdigit(line[i])) {
                        lastDigit = line[i] - '0';
                        break;
                    }
                }

                if (firstDigit != -1 && lastDigit != -1) {
                    int appendedNumber = firstDigit * 10 + lastDigit;
                    sum += appendedNumber;
                }
            }
        }
        inputFile.close();

        std::cout << "The SUM IS: " << sum << std::endl;
    } else {
        std::cout << "Failed to open input.txt" << std::endl;
    }

    return 0;
}

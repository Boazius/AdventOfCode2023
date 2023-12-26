#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

/**
 * Function to calculate the number of ways to beat the record for a single race.
 * @param raceTime Total time allowed for the race.
 * @param recordDistance The record distance that needs to be beaten.
 * @return The number of ways to beat the record.
 */
long long calculateWaysToWin(long long raceTime, long long recordDistance) {
    long long ways = 0;
    for (long long holdTime = 0; holdTime < raceTime; ++holdTime) {
        long long travelTime = raceTime - holdTime;
        long long distance = holdTime * travelTime;
        if (distance > recordDistance) {
            ++ways;
        }
    }
    return ways;
}

int main() {
    std::ifstream inputFile("input.txt");
    long long time = 0, distance = 0;

    // Reading input from the file
    if (inputFile.is_open()) {
        std::string line;

        // First line for time
        if (getline(inputFile, line)) {
            std::istringstream iss(line.substr(line.find(':') + 1));
            std::string number;

            while (iss >> number) {
                for (char &c : number) {
                    if (c != ' ') {
                        time = time * 10 + (c - '0');
                    }
                }
            }
        }

        // Second line for distance
        if (getline(inputFile, line)) {
            std::istringstream iss(line.substr(line.find(':') + 1));
            std::string number;

            while (iss >> number) {
                for (char &c : number) {
                    if (c != ' ') {
                        distance = distance * 10 + (c - '0');
                    }
                }
            }
        }

        inputFile.close();
    } else {
        std::cerr << "Unable to open input.txt" << std::endl;
        return 1;
    }

    std::cout << "Total ways to win all races: " << calculateWaysToWin(time, distance) << std::endl;
    return 0;
}

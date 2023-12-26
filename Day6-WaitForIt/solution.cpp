#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Function to calculate the number of ways to beat the record for a single race
int calculateWaysToWin(int raceTime, int recordDistance) {
    int ways = 0;
    for (int holdTime = 0; holdTime < raceTime; ++holdTime) {
        int travelTime = raceTime - holdTime;
        int distance = holdTime * travelTime;
        if (distance > recordDistance) {
            ++ways;
        }
    }
    return ways;
}

int main() {
    std::ifstream inputFile("input.txt");
    std::vector<int> times, distances;

    // Reading input from the file
    if (inputFile.is_open()) {
        std::string line;
        // First line for times
        if (getline(inputFile, line)) {
            std::istringstream iss(line.substr(line.find(':') + 1));
            int time;
            while (iss >> time) {
                times.push_back(time);
            }
        }
        // Second line for distances
        if (getline(inputFile, line)) {
            std::istringstream iss(line.substr(line.find(':') + 1));
            int distance;
            while (iss >> distance) {
                distances.push_back(distance);
            }
        }
        inputFile.close();
    } else {
        std::cerr << "Unable to open input.txt" << std::endl;
        return 1;
    }

    long long totalWays = 1;
    for (size_t i = 0; i < times.size(); ++i) {
        totalWays *= calculateWaysToWin(times[i], distances[i]);
    }

    std::cout << "Total ways to win all races: " << totalWays << std::endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <limits>
#include <algorithm>

using ull = unsigned long long;
using namespace std;

class SeedMap {
private:
    int stage;
    vector<tuple<ull, ull, ull>> mappings;

public:
    // Constructor initializes SeedMap with a specific stage
    SeedMap(int stage) : stage(stage) {}

    // Adds a mapping of three unsigned long long values to the mappings vector
    // a is the lower bound of the destination value, b is the lower bound of the source value, and c is the range length
    // for example if a mapping is (10, 5, 5) then the source value 5 maps to the destination value 10, and the source value 6 maps to the destination value 11.. until 9 maps to 14
    void addMapping(ull a, ull b, ull c) {
        mappings.emplace_back(a, b, c);
    }

    // Maps a source value to its destination based on the mappings
    ull toNextStageMap(ull source) {
        for (const auto& [a, b, c] : mappings) {
            if (b <= source && source < b + c) {
                return source + (a - b);
            }
        }
        return source;
    }
};

int main() {
    // Reading seeds and mappings from input file
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    string line;
    vector<ull> seeds;

    // Read and parse the first line for seeds
    if (getline(inputFile, line)) {
        stringstream ss(line.substr(7));  // Extracts after "seeds: "
        ull seed;
        while (ss >> seed) {
            seeds.push_back(seed);
        }
    }

    vector<SeedMap> seedMaps;
    int currentStage = -1;

    // Reading and parsing mapping data
    while (getline(inputFile, line)) {
        if(line.empty()) continue;
        if (line.find("map:") != string::npos) {
            currentStage++;
            seedMaps.emplace_back(currentStage);
        } else {
            ull a, b, c;
            stringstream ss(line);
            ss >> a >> b >> c;
            seedMaps.back().addMapping(a, b, c);
        }
    }

    inputFile.close();

    // Mapping seeds through each stage and finding the lowest location
    ull lowestLocation = numeric_limits<ull>::max();

    for (ull seed : seeds) {
        ull currentLocation = seed;

        for (SeedMap& seedMap : seedMaps) {
            currentLocation = seedMap.toNextStageMap(currentLocation);
        }

        lowestLocation = min(lowestLocation, currentLocation);
    }

    // Output the result
    cout << "Lowest Location: " << lowestLocation << endl;

    return 0;
}

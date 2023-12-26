#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <climits>
#include <fstream>

using namespace std;

// Type aliases for convenience
using ll = long long;
using pll = pair<ll, ll>;

// Struct to represent a mapping from one range to another
struct Mapping {
    ll dest;   // Destination start
    ll src;    // Source start
    ll range;  // Range length
};

// Function to read and parse seed ranges from the file
static vector<pll> readSeedRanges(ifstream& file) {
    string line;
    getline(file, line);
    stringstream ss(line);

    // Skip the initial part of the line (label)
    string tempStr;
    ss >> tempStr;

    vector<pll> seedRanges;
    ll start, range;
    while (ss >> start >> range) {
        seedRanges.push_back({start, range});
    }

    // Skip the empty line after seed ranges
    getline(file, tempStr);

    return seedRanges;
}

// Function to read and parse mappings from the file
static vector<Mapping> readMapping(ifstream& file) {
    vector<Mapping> mapping;
    string line;

    // Read each line and parse it into Mapping objects
    while (getline(file, line) && line != "") {
        stringstream ss(line);
        ll dest, src, range;
        while (ss >> dest >> src >> range) {
            mapping.push_back({dest, src, range});
        }
    }

    return mapping;
}

// Function to apply mappings to the given key ranges
static vector<pll> lookUp(vector<pll> keyRanges, const vector<Mapping>& mp) {
    vector<pll> results;

    // Iterate through each key range
    for (const auto& keyRange : keyRanges) {
        ll minKey = keyRange.first; // Start of the current key range
        ll maxKey = minKey + keyRange.second - 1; // End of the current key range

        vector<pll> usedRanges; // Stores ranges that are used in mapping

        // Iterate through each mapping in the current mapping phase
        for (const auto& mapping : mp) {
            ll minMapping = mapping.src; // Start of the source range in mapping
            ll maxMapping = mapping.src + mapping.range - 1; // End of the source range in mapping

            // Check for overlap between the key range and the mapping range
            if (minMapping > maxKey || minKey > maxMapping) {
                continue; // Skip the mapping if there's no overlap
            }

            // Calculate the intersection of the key range and the mapping range
            ll minResult = max(minKey, minMapping); // Start of the intersection
            ll maxResult = min(maxKey, maxMapping); // End of the intersection
            usedRanges.push_back({minResult, maxResult}); // Store the used range
            ll range = maxResult - minResult + 1; // Length of the intersection

            // Adjust the start of the intersection based on the mapping
            ll delta = mapping.dest - mapping.src; // Shift amount from source to destination
            results.push_back({minResult + delta, range}); // Add the adjusted range to results
        }

        // Sort the used ranges to process them in order
        sort(usedRanges.begin(), usedRanges.end());

        // Fill in gaps in the key range that were not covered by mappings
        ll start = minKey; // Start of the gap
        for (const auto& usedRange : usedRanges) {
            if (start < usedRange.first) {
                // If there's a gap before the used range, add it to results
                results.push_back({start, usedRange.first - start});
            }
            // Move to the end of the used range
            start = usedRange.second + 1;
        }
        // Check for a gap after the last used range
        if (start <= maxKey) {
            results.push_back({start, maxKey - start + 1});
        }
    }
    return results;
}

// Function to find the minimum value in a range of pairs
static ll getMin(ll current, const vector<pll>& ranges) {
    ll ans = current;
    for (const auto& range : ranges) {
        ans = min(ans, range.first);
    }
    return ans;
}

int main() {
    constexpr int NUM_MAPPINGS = 7; // Number of mappings to process

    ifstream file("input.txt");
    if (!file) {
        cerr << "Unable to open file input.txt";
        return 1;
    }

    // Read seed ranges and mappings from the file
    vector<pll> seedRanges = readSeedRanges(file);
    vector<vector<Mapping>> mappings(NUM_MAPPINGS);
    for (auto& mapping : mappings) {
        mapping = readMapping(file);
    }

    // Find the minimum location number that corresponds to any of the initial seed numbers
    ll ans = LONG_LONG_MAX;
    for (const auto& seedRange : seedRanges) {
        vector<pll> current = {seedRange};
        for (const auto& mapping : mappings) {
            current = lookUp(current, mapping);
        }
        ans = min(ans, getMin(LLONG_MAX, current));
    }

    file.close();
    cout << ans << endl;

    return 0;
}

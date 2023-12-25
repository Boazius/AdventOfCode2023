#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include <string>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

// Function to parse numbers from a string stream until a "|" character is found.
// It returns an unordered set of the parsed numbers.
unordered_set<int> parseNumbers(istringstream& iss) {
    unordered_set<int> numbers;
    string segment;
    while (iss >> segment) {
        if (segment == "|") break;  // Stop parsing if "|" is encountered
        numbers.insert(stoi(segment)); // Convert string to integer and insert into set
    }
    return numbers;
}

// Function to count the number of matches between a set of winning numbers
// and a vector of your numbers. It returns the count of matches.
int countMatches(const unordered_set<int>& winningNumbers, const vector<int>& yourNumbers) {
    int matches = 0;
    for (int num : yourNumbers) {
        if (winningNumbers.find(num) != winningNumbers.end()) {
            ++matches; // Increment match count if number is found in winning numbers
        }
    }
    return matches;
}

int main() {
    ifstream file("input.txt"); // Open the file for reading
    string line;
    vector<pair<unordered_set<int>, vector<int>>> cards; // Store pairs of winning numbers and your numbers

    // Read each line from the file
    while (getline(file, line)) {
        istringstream iss(line);
        iss.ignore(numeric_limits<streamsize>::max(), ':'); // Ignore characters until ':' is found

        // Parse winning numbers and your numbers from the line
        unordered_set<int> winningNumbersSet = parseNumbers(iss);
        vector<int> winningNumbers(winningNumbersSet.begin(), winningNumbersSet.end());
        unordered_set<int> yourNumbersSet = parseNumbers(iss);
        vector<int> yourNumbers(yourNumbersSet.begin(), yourNumbersSet.end());

        // Store the parsed numbers as a pair in the cards vector
        cards.emplace_back(move(winningNumbersSet), move(yourNumbers));
    }

    int totalCards = 0;
    queue<size_t> cardQueue; // Queue to manage card processing

    // Initialize the queue with indices of all cards
    for (size_t i = 0; i < cards.size(); ++i) {
        cardQueue.push(i);
    }

    // Process each card in the queue
    while (!cardQueue.empty()) {
        size_t cardIndex = cardQueue.front(); // Get the index of the current card
        cardQueue.pop();
        totalCards += 1; // Increment total cards processed

        // Count matches for the current card
        int matches = countMatches(cards[cardIndex].first, cards[cardIndex].second);

        // Enqueue additional cards based on the number of matches
        for (int j = 1; j <= matches && cardIndex + j < cards.size(); ++j) {
            cardQueue.push(cardIndex + j);
        }
    }

    // Output the total number of scratchcards processed
    cout << "Total scratchcards: " << totalCards << endl;
    return 0;
}

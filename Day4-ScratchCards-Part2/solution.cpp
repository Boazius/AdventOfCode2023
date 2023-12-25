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

unordered_set<int> parseNumbers(istringstream& iss) {
    unordered_set<int> numbers;
    string segment;
    while (iss >> segment) {
        if (segment == "|") 
            break;
        numbers.insert(stoi(segment));
    }
    return numbers;
}

int countMatches(const unordered_set<int>& winningNumbers, const vector<int>& yourNumbers) {
    int matches = 0;
    for (int num : yourNumbers) {
        if (winningNumbers.find(num) != winningNumbers.end()) {
            ++matches;
        }
    }
    return matches;
}

int main() {
    ifstream file("input.txt");
    string line;
    vector<pair<unordered_set<int>, vector<int>>> cards;

    while (getline(file, line)) {
        istringstream iss(line);
        iss.ignore(numeric_limits<streamsize>::max(), ':');
        unordered_set<int> winningNumbersSet = parseNumbers(iss);
        vector<int> winningNumbers(winningNumbersSet.begin(), winningNumbersSet.end());
        unordered_set<int> yourNumbersSet = parseNumbers(iss);
        vector<int> yourNumbers(yourNumbersSet.begin(), yourNumbersSet.end());
        cards.emplace_back(move(winningNumbersSet), move(yourNumbers));
    }

    int totalCards = 0;
    queue<size_t> cardQueue;

    for (size_t i = 0; i < cards.size(); ++i) {
        cardQueue.push(i);
    }

    while (!cardQueue.empty()) {
        size_t cardIndex = cardQueue.front();
        cardQueue.pop();
        totalCards += 1;

        int matches = countMatches(cards[cardIndex].first, cards[cardIndex].second);
        for (int j = 1; j <= matches && cardIndex + j < cards.size(); ++j) {
            cardQueue.push(cardIndex + j);
        }
    }

    cout << "Total scratchcards: " << totalCards << endl;
    return 0;
}

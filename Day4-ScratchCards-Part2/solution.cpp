#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <limits>
#include <algorithm>
#include <set>

int calculateCardPoints(const std::set<int> &winningNumbers, const std::vector<int> &yourNumbers)
{
    return std::count_if(yourNumbers.begin(), yourNumbers.end(),
                         [&winningNumbers](int num)
                         { return winningNumbers.find(num) != winningNumbers.end(); });
}

// Parses a single line of numbers from the input stream.
// Stops reading when it encounters the '|' character or end of the line.
std::vector<int> parseNumbers(std::istringstream &iss)
{
    std::vector<int> numbers;
    std::string segment;
    while (iss >> segment)
    {
        if (segment == "|")
        {
            break;
        }
        numbers.push_back(std::stoi(segment));
    }
    return numbers;
}

int main()
{
    std::ifstream file("input.txt");
    std::string line;
    std::vector<int> cardCounts;
    cardCounts.push_back(1);
    int currCardIdx{0};

    while (std::getline(file, line))
    {
        std::istringstream iss(line);

        // Skip the "Card X:" prefix in each line
        iss.ignore(std::numeric_limits<std::streamsize>::max(), ':');

        // Read and parse winning numbers
        std::vector<int> winningNumbers = parseNumbers(iss);
        std::set<int> winningSet(winningNumbers.begin(), winningNumbers.end());

        // Read and parse your numbers
        std::vector<int> yourNumbers = parseNumbers(iss);

        // Calculate and accumulate points for each card
        int currCardWins = calculateCardPoints(winningSet, yourNumbers);

        // Ensure cardCounts is large enough by adding new elements if needed
        int requiredSize = currCardIdx + 1 + currCardWins;
        if (static_cast<int>(cardCounts.size()) < requiredSize)
        {
            // Add '1's to cardCounts to represent the original card
            cardCounts.resize(requiredSize, 1);
        }

        // Distribute the count of the current card to the next currCardWins cards
        int endIdx = std::min(currCardIdx + 1 + currCardWins, static_cast<int>(cardCounts.size()));
        for (int i = currCardIdx + 1; i < endIdx; ++i)
        {
            cardCounts[i] += cardCounts[currCardIdx];
        }
        currCardIdx++;
    }

    int totalCards = 0;
    // return sum of cardCounts
    for (int i = 0; i < static_cast<int>(cardCounts.size()); i++)
    {
        totalCards += cardCounts[i];
    }
    std::cout << "Total cards: " << totalCards << std::endl;
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm> // Add this include statement
#include <map>       // Add this include statement
#include <vector>    // Add this include statement

const std::map<char, int> cardValues = {
    {'A', 14},
    {'K', 13},
    {'Q', 12},
    {'J', 1}, // fixed Joker to be weaker than 2
    {'T', 10},
    {'9', 9},
    {'8', 8},
    {'7', 7},
    {'6', 6},
    {'5', 5},
    {'4', 4},
    {'3', 3},
    {'2', 2}};

enum HandType
{
    HIGH_CARD = 0,
    ONE_PAIR = 1,
    TWO_PAIR = 2,
    THREE_OF_A_KIND = 3,
    FULL_HOUSE = 4,
    FOUR_OF_A_KIND = 5,
    FIVE_OF_A_KIND = 6
};

class camelHand
{
public:

    std::string handString;
    int bid;
    HandType handType;

    // constructor
    camelHand(const std::string &handString, int bid) : handString(handString), bid(bid)
    {
        handType = getHandType(handString);
    }

    // custom comparator - used to sort camelHands by rank
    bool operator<(const camelHand &other) const
    {
        // Return true if this object is less than the other object, false otherwise
        // compare hand types first
        if (handType != other.handType)
        {
            return handType < other.handType;
        }
        else
        {
            // if same hand type compare each char using the map
            for (size_t i = 0; i < handString.size(); i++)
            {
                if (handString[i] != other.handString[i])
                {
                    return (cardValues.at(handString[i]) < cardValues.at(other.handString[i]));
                }
            }
        }
        return false;
    }

    HandType getHandType(const std::string& str)
    {
        std::map<char, int> charCount;
        for (char c : str)
        {
            charCount[c]++;
        }
        // check if there is J in the countCharMap, if yes, add it to the maxKey and remove it from the map
        if (charCount.find('J') != charCount.end())
        {
            char maxKey = ' ';
            int maxValue = 0;

            for (const auto &pair : charCount)
            {
                if (pair.first != 'J' && pair.second > maxValue)
                {
                    maxKey = pair.first;
                    maxValue = pair.second;
                }
            }
            //add 'J' value to the maxKey in the tempMap
            charCount[maxKey] += charCount['J'];
            // remove 'J' from the tempMap
            charCount.erase('J');
        }

        // if there are 5 of the same card return FIVE_OF_A_KIND
        if (charCount.size() == 1)
        {
            return FIVE_OF_A_KIND;
        }

        if (charCount.size() == 2)
        {
            // if there are 4 of the same card return FOUR_OF_A_KIND
            for (auto it = charCount.begin(); it != charCount.end(); ++it)
            {
                if (it->second == 4)
                {
                    return FOUR_OF_A_KIND;
                }
            }
            // if there are 3 of the same card and 2 of the same card return FULL_HOUSE
            return FULL_HOUSE;
        }

        if (charCount.size() == 3)
        {
            // if there are 3 of the same card return THREE_OF_A_KIND
            for (auto it = charCount.begin(); it != charCount.end(); ++it)
            {
                if (it->second == 3)
                {
                    return THREE_OF_A_KIND;
                }
            }
            // if there are 2 of the same card twice return TWO_PAIR
            return TWO_PAIR;
        }
        // if there are 2 of the same card return ONE_PAIR
        for (auto it = charCount.begin(); it != charCount.end(); ++it)
        {
            if (it->second == 2)
            {
                return ONE_PAIR;
            }
        }

        return HIGH_CARD;
    }
};

int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile)
    {
        std::cerr << "Failed to open input file." << std::endl;
        return 1;
    }

    std::vector<camelHand> hands;
    // Read input from the file
    std::string input;
    while (std::getline(inputFile, input))
    {
        std::istringstream iss(input);

        std::string handString;
        int bid;
        if (iss >> handString >> bid)
        {
            camelHand hand(handString, bid);
            hands.push_back(hand);
        }
    }

    inputFile.close();
    // sort hands
    std::sort(hands.begin(), hands.end());

    int currRank{0};
    long long totalWinnings{0};
    for (auto hand : hands)
    {
        currRank++;
        totalWinnings += (hand.bid * currRank);
    }
    std::cout << "The total winnings is : " << totalWinnings << std::endl;

    return 0;
}

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
#include <unordered_map>
#include <algorithm>

/**
 * Calculates the sum of gear ratios that have exactly two associated star signs.
 *
 * @param grid A 2D grid represented as a vector of strings, containing numbers and '*'.
 * @return The sum of the gear ratios associated with exactly two star signs.
 */
int calculateGearRatioSum(const std::vector<std::string> &grid)
{
    // Map to store star sign data: key is the index in the grid, value is a pair of count of adjacent numbers and the product of these numbers
    std::unordered_map<int, std::pair<int, int>> starSigns;

    // Iterate over each row of the grid
    for (int j = 0; j < static_cast<int>(grid.size()); ++j)
    {
        // Iterate over each column of the grid
        for (int i = 0; i < static_cast<int>(grid[j].length()); ++i)
        {
            int currentNumber = 0;
            const int currNumStartIdx = i; // Start index of the current number

            // Extracting the number from the grid
            while (i < static_cast<int>(grid[j].length()) && isdigit(grid[j][i]))
            {
                currentNumber = (currentNumber * 10) + (grid[j][i] - '0');
                ++i;
            }

            // Process only if a number is found
            if (i > currNumStartIdx)
            {
                // Check adjacent cells for stars
                for (int x = std::max(j - 1, 0); x < std::min(j + 2, static_cast<int>(grid.size())); ++x)
                {
                    for (int y = std::max(currNumStartIdx - 1, 0); y < std::min(i + 1, static_cast<int>(grid[j].length())); ++y)
                    {
                        // If a star is found
                        if (grid[x][y] == '*')
                        {
                            // Unique key for the star's position
                            int key = x * grid[0].length() + y;

                            // If the key is not present in the map, add it

                            starSigns.emplace(key, std::make_pair(0, 1));

                            // Increment count and multiply the product for the star sign
                            ++starSigns[key].first;
                            starSigns[key].second *= currentNumber;
                        }
                    }
                }
            }
        }
    }

    int result = 0;
    // Calculate the sum of gear ratios for star signs with exactly two adjacent numbers
    for (const auto &[key, value] : starSigns)
    {
        if (value.first == 2)
        {
            result += value.second;
        }
    }
    return result;
}

int main()
{
    std::ifstream file("input.txt");
    std::vector<std::string> grid;
    std::string line;

    // Read the file line by line and populate the grid
    while (std::getline(file, line))
    {
        grid.push_back(line);
    }

    // Output the result
    std::cout << "Sum of all part numbers: " << calculateGearRatioSum(grid) << std::endl;
    return 0;
}

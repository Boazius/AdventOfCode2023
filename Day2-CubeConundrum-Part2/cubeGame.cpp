#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <unordered_map>

// Function to find the power set for a given game line
int getPowerSet(const std::string &line)
{
    // Create a map to store counts of each cube color
    std::unordered_map<std::string, int> maxCounts = {{"green", 0}, {"red", 0}, {"blue", 0}};

    // Define a regex pattern to match cube counts and colors
    std::regex pattern(R"((\d+)\s(green|red|blue))");

    // Iterate through the line to find cube counts for each color
    for (std::sregex_iterator i = std::sregex_iterator(line.begin(), line.end(), pattern);
         i != std::sregex_iterator(); ++i)
    {
        std::smatch match = *i;
        int count = std::stoi(match[1].str());
        std::string color = match[2].str();

        // Update max counts for each color
        maxCounts[color] = std::max(maxCounts[color], count);
    }

    // Calculate the power of the set of cubes for this game
    return maxCounts["green"] * maxCounts["red"] * maxCounts["blue"];
}

int main()
{
    int totalPower = 0;

    std::ifstream inputFile("input.txt");
    if (!inputFile)
    {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        totalPower += getPowerSet(line);
    }

    inputFile.close(); // Close the input file

    // Output the sum of all valid games' powers
    std::cout << "The total power of all games is: " << totalPower << std::endl;

    return 0;
}

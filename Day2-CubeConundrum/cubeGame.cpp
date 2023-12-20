#include <iostream>
#include <fstream>
#include <string>

#include <iostream>
#include <fstream>
#include <string>
#include <cctype> // Include the <cctype> library

int main()
{
    std::ifstream inputFile("input.txt");
    if (!inputFile)
    {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    std::string line;
    //Game 1: 8 green, 4 red, 4 blue; 1 green, 6 red, 4 blue;...
    while (std::getline(inputFile, line))
    {
        // Find the first digit in the line
        char firstDigit = '\0';
        for (char c : line)
        {
            if (std::isdigit(c))
            {
                firstDigit = c;
                break;
            }
        }
    }

    inputFile.close();

    return 0;
}

#include "Graph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

int main() {
    Graph myGraph;

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
        return 1;
    }

    std::string directionsString; // this is "RLRLLRLLRL" etc..
    std::getline(inputFile, directionsString); // Read the first line


    // read the rest of the file
    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        if (line.empty()) {
            continue;
        }
        std::string nodeName, equals, left, comma, right;
        if (iss >> nodeName >> equals >> left >> right) {
            // Removing parentheses and comma from node names
            left = left.substr(1);
            left.pop_back();
            right.pop_back();
            myGraph.addNode(nodeName, {left, right});
        }
    }

    inputFile.close();
    int stepsTaken = 0;
    // find the AAA node in the graph
    std::string currNode = "AAA";
    // start from first index in the directions string
    int currentIndex = 0;
    // while we haven't reached ZZZ, keep goin
    while(currNode != "ZZZ")
    {
        // if currentDirection is L , take the left connection from currNode
        if(directionsString[currentIndex] == 'L')
        {
            currNode = myGraph.adjacencyList[currNode].first;
        }
        // if currentDirection is R , take the right connection from currNode
        else if(directionsString[currentIndex] == 'R')
        {
            currNode = myGraph.adjacencyList[currNode].second;
        }
        currentIndex = (currentIndex + 1) % directionsString.size();
        stepsTaken++;
    }

    std::cout << "Steps taken: " << stepsTaken << std::endl;

    

    return 0;
}

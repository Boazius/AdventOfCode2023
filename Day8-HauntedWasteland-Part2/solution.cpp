#include "Graph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <thread>
#include <numeric>

int main()
{
    Graph myGraph;

    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening input.txt" << std::endl;
        return 1;
    }

    std::string directionsString;              // this is "RLRLLRLLRL" etc..
    std::getline(inputFile, directionsString); // Read the first line

    // read the rest of the file
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        if (line.empty())
        {
            continue;
        }
        std::string nodeName, equals, left, comma, right;
        if (iss >> nodeName >> equals >> left >> right)
        {
            // Removing parentheses and comma from node names
            left = left.substr(1);
            left.pop_back();
            right.pop_back();
            myGraph.addNode(nodeName, {left, right});
        }
    }
    inputFile.close();

    // find every starting node - ones that the last letter is A
    // iterate every key in the adjacency list
    std::vector<std::string> currNodes;
    for (auto &node : myGraph.adjacencyList)
    {
        // if the last letter of the key is A, add it to the currNodes vector
        if (node.first.back() == 'A')
        {
            currNodes.push_back(node.first);
        }
    }

    // start from first index in the directions string
    int currentIndex = 0;

    // for every node in currNodes, check how many steps it takes to reach Z node, use threads to do it.
    std::vector<long long> stepsResults;

    // Function to be executed by each thread
    auto checkSteps = [&myGraph, &directionsString, &currentIndex, &stepsResults](std::string currNode)
    {
        long long steps = 0;
        // while we haven't reached **Z, keep going
        while (currNode.back() != 'Z')
        {
            // if currentDirection is L, take the left connection from currNode
            if (directionsString[currentIndex] == 'L')
            {
                currNode = myGraph.adjacencyList[currNode].first;
            }
            // if currentDirection is R, take the right connection from currNode
            else if (directionsString[currentIndex] == 'R')
            {
                currNode = myGraph.adjacencyList[currNode].second;
            }
            currentIndex = (currentIndex + 1) % directionsString.size();
            steps++;
        }
        stepsResults.push_back(steps);
    };

    // // Create a vector of threads
    // std::vector<std::thread> threads;

    // // Create and start a thread for each node in currNodes
    // for (auto node : currNodes)
    // {
    //     threads.emplace_back(checkSteps, node);
    // }

    // // Join all the threads
    // for (auto &thread : threads)
    // {
    //     thread.join();
    // }
    // // print all steps results
    // for (auto &steps : stepsResults)
    // {
    //     std::cout << steps << std::endl;
    // }

    for(auto node : currNodes)
    {
        checkSteps(node);
    }


    // get lcm of all the steps
    long long lcm = std::accumulate(stepsResults.begin(), stepsResults.end(), 1, [](long long a, long long b)
                              { return std::lcm(a, b); });
    std::cout << "Steps taken: " << lcm << std::endl;
}

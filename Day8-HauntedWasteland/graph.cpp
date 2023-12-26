#include "Graph.h"
#include <iostream>

void Graph::addNode(const std::string& nodeName, const std::pair<std::string, std::string>& connections) {
    adjacencyList[nodeName] = connections;
}

void Graph::printGraph() const {
    for (const auto& node : adjacencyList) {
        std::cout << node.first << " = (" << node.second.first << ", " << node.second.second << ")\n";
    }
}
#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>
#include <utility>

class Graph {
public:
    void addNode(const std::string& nodeName, const std::pair<std::string, std::string>& connections);
    void printGraph() const;

    std::map<std::string, std::pair<std::string, std::string>> adjacencyList; // map of node name to pair of left and right connections
};

#endif // GRAPH_H

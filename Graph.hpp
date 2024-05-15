/*
ID: 212487144
Email: nbashar4@gmail.com
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> adjacencyMatrix;
    int numVertices;
    bool isDirected;

public:
    Graph();
    void loadGraph(const std::vector<std::vector<int>> &matrix);
    void printGraph();
    int getNumVertices();
    bool getIsDirected();
    std::vector<std::vector<int>> &getAdjacencyMatrix();

    // operations
    Graph &operator+(const Graph &g);
    Graph &operator+=(const Graph &g);
    Graph &operator+();
    Graph &operator-(const Graph &g);
    Graph &operator-=(const Graph &g);
    Graph &operator-();
    bool operator>(const Graph &g);
    bool operator>=(const Graph &g);
    bool operator<(const Graph &g);
    bool operator<=(const Graph &g);
    bool operator==(const Graph &g);
    bool operator!=(const Graph &g);
    Graph &operator++();
    Graph &operator--();
    Graph &operator*(int);
    Graph &operator*(const Graph &g);
    Graph &operator*=(int);
    Graph &operator*=(const Graph &g);
    Graph &operator/(int);
    Graph &operator/=(int);

    // print operator
    friend std::ostream &operator<<(std::ostream &os, const Graph &g);
};

#endif // GRAPH_HPP

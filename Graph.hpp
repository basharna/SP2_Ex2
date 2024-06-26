/*
ID: 212487144
Email: nbashar4@gmail.com
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
using namespace std;

class Graph
{
private:
    vector<vector<int>> adjacencyMatrix;
    int numVertices;
    int numEdges;
    bool isDirected;
    bool isSubgraphOfHelper(const vector<vector<int>> &subAdj, const vector<vector<int>> &adj, vector<int> &mapping, vector<bool> &visited, size_t index) const;

public:
    Graph();
    void loadGraph(const vector<vector<int>> &matrix);
    void printGraph();
    int getNumVertices();
    bool getIsDirected();
    vector<vector<int>> &getAdjacencyMatrix();
    bool isSubgraphOf(const Graph &g) const;

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
    Graph operator++(int);
    Graph &operator--();
    Graph operator--(int);
    Graph &operator*(int);
    Graph &operator*(const Graph &g);
    Graph &operator*=(int);
    Graph &operator*=(const Graph &g);
    Graph &operator/(int);
    Graph &operator/=(int);

    // print operator
    friend ostream &operator<<(ostream &os, const Graph &g);
};

#endif // GRAPH_HPP

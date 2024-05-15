/*
ID: 212487144
Email: nbashar4@gmail.com
*/
#include "Graph.hpp"
#include <iostream>
using namespace std;

Graph::Graph() : numVertices(0) {}

void Graph::loadGraph(const vector<vector<int>> &matrix)
{
    if (matrix.size() != matrix[0].size())
    {
        throw invalid_argument("Invalid graph: The graph is not a square matrix.");
    }
    adjacencyMatrix = matrix;
    numVertices = matrix.size();

    // Check if the graph is directed or not
    isDirected = false;
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i])
            {
                isDirected = true;
                break;
            }
        }
    }
}

void Graph::printGraph()
{
    int numEdges = 0;
    for (int i = 0; i < numVertices; ++i)
    {
        for (int j = 0; j < numVertices; ++j)
        {
            if (adjacencyMatrix[i][j] != 0)
            {
                numEdges++;
            }
        }
    }
    cout << "Graph with " << numVertices << " vertices and " << numEdges << " edges" << endl;
}

int Graph::getNumVertices()
{
    return numVertices;
}

bool Graph::getIsDirected()
{
    return isDirected;
}

vector<vector<int>> &Graph::getAdjacencyMatrix()
{
    return adjacencyMatrix;
}

Graph &Graph::operator+(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        throw invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }

    vector<vector<int>> newMatrix(this->numVertices, vector<int>(this->numVertices, 0));
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            newMatrix[i][j] = this->adjacencyMatrix[i][j] + g.adjacencyMatrix[i][j];
        }
    }

    Graph *newGraph = new Graph();
    newGraph->loadGraph(newMatrix);
    return *newGraph;
}

Graph &Graph::operator+=(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        throw invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }

    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] += g.adjacencyMatrix[i][j];
        }
    }

    return *this;
}

Graph &Graph::operator+()
{
    return *this;
}

Graph &Graph::operator-(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        throw invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }

    vector<vector<int>> newMatrix(this->numVertices, vector<int>(this->numVertices, 0));
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            newMatrix[i][j] = this->adjacencyMatrix[i][j] - g.adjacencyMatrix[i][j];
        }
    }

    Graph *newGraph = new Graph();
    newGraph->loadGraph(newMatrix);
    return *newGraph;
}

Graph &Graph::operator-=(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        throw invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }

    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] -= g.adjacencyMatrix[i][j];
        }
    }

    return *this;
}

Graph &Graph::operator-()
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] = -adjacencyMatrix[i][j];
        }
    }

    return *this;
}

Graph &Graph::operator*(int scalar)
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] *= scalar;
        }
    }

    return *this;
}

Graph &Graph::operator*(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        throw invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }

    vector<vector<int>> newMatrix(this->numVertices, vector<int>(this->numVertices, 0));
    // Matrix multiplication
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            for (int k = 0; k < this->numVertices; ++k)
            {
                newMatrix[i][j] += this->adjacencyMatrix[i][k] * g.adjacencyMatrix[k][j];
            }
        }
    }

    Graph *newGraph = new Graph();
    newGraph->loadGraph(newMatrix);
    return *newGraph;
}

Graph &Graph::operator*=(int scalar)
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] *= scalar;
        }
    }

    return *this;
}

Graph &Graph::operator*=(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        throw invalid_argument("Invalid operation: The graphs have different number of vertices.");
    }

    vector<vector<int>> newMatrix(this->numVertices, vector<int>(this->numVertices, 0));
    // Matrix multiplication
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            for (int k = 0; k < this->numVertices; ++k)
            {
                newMatrix[i][j] += this->adjacencyMatrix[i][k] * g.adjacencyMatrix[k][j];
            }
        }
    }

    this->loadGraph(newMatrix);
    return *this;
}

Graph &Graph::operator/(int scalar)
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] /= scalar;
        }
    }

    return *this;
}

Graph &Graph::operator/=(int scalar)
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j] /= scalar;
        }
    }

    return *this;
}

Graph &Graph::operator++()
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j]++;
        }
    }

    return *this;
}

Graph Graph::operator++(int)
{
    Graph* temp = new Graph(*this);
    ++(*this); // Use the prefix increment operator
    return *temp;
}

Graph &Graph::operator--()
{
    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            this->adjacencyMatrix[i][j]--;
        }
    }

    return *this;
}

bool Graph::operator==(const Graph &g)
{
    if (this->numVertices != g.numVertices)
    {
        return false;
    }

    for (int i = 0; i < this->numVertices; ++i)
    {
        for (int j = 0; j < this->numVertices; ++j)
        {
            if (this->adjacencyMatrix[i][j] != g.adjacencyMatrix[i][j])
            {
                return false;
            }
        }
    }

    return true;
}

bool Graph::operator!=(const Graph &g)
{
    return !(*this == g);
}

ostream &operator<<(ostream &os, const Graph &g)
{
    // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]
    for (int i = 0; i < g.numVertices; ++i)
    {
        os << "[";
        for (int j = 0; j < g.numVertices; ++j)
        {
            os << g.adjacencyMatrix[i][j];
            if (j != g.numVertices - 1)
            {
                os << ", ";
            }
        }
        os << "]";
        if (i != g.numVertices - 1)
        {
            os << ", ";
        }
    }
    os << endl;
    return os;
}


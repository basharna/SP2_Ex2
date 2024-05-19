/*
ID: 7144
Email: nbashar4@gmail.com
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Algorithms.hpp"
#include "Graph.hpp"
#include "doctest.h"

TEST_CASE("isConnected")
{
    SUBCASE("Connected Graph")
    {
        // Connected graph
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        CHECK(Algorithms::isConnected(g) == true);
    }

    SUBCASE("Connected Directed Graph")
    {
        // Connected graph
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 0, 0, 5, 0},
            {0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0},
            {0, 0, -9, 0, 5},
            {0, 0, 0, 0, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        CHECK(Algorithms::isConnected(g) == true);
    }

    SUBCASE("Disconnected Graph")
    {
        // Disconnected graph
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 1},
            {0, 0, 1, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        CHECK(Algorithms::isConnected(g) == false);
    }
    SUBCASE("Disconnected Directed Graph")
    {
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 0, 0, 5, 0},
            {0, 0, 0, 0, 0},
            {0, 5, 0, 0, 0},
            {0, 0, 0, 0, 5},
            {0, 0, 0, 0, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);
        CHECK(Algorithms::isConnected(g) == false);
    }
}

TEST_CASE("shortestPath")
{
    // Graph with a known shortest path
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 1, 0, 1},
        {0, 0, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    Graph g;
    g.loadGraph(adjacencyMatrix);

    // Graph with weighted edges
    std::vector<std::vector<int>> adjacencyMatrixWeighted = {
        {0, 1, 0, 7},
        {0, 0, 2, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0}};
    Graph gWeighted;
    gWeighted.loadGraph(adjacencyMatrixWeighted);

    SUBCASE("Shortest Path Exists")
    {
        std::vector<int> expectedPath = {0, 3};
        CHECK(Algorithms::shortestPath(g, 0, 3) == expectedPath);
        std::vector<int> expectedPathWeighted = {0, 1, 2, 3};
        CHECK(Algorithms::shortestPath(gWeighted, 0, 3) == expectedPathWeighted);
    }

    SUBCASE("No Shortest Path")
    {
        CHECK(Algorithms::shortestPath(g, 3, 0).empty());
        CHECK(Algorithms::shortestPath(g, 0, 0).empty());
        CHECK(Algorithms::shortestPath(gWeighted, 3, 0).empty());
    }

    SUBCASE("Shortest Path with Negative Weights")
    {
        // Graph with negative weights
        std::vector<std::vector<int>> adjacencyMatrixNegative = {
            {0, 1, 0, 7},
            {0, 0, -2, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 0}};
        Graph gNegative;
        gNegative.loadGraph(adjacencyMatrixNegative);

        std::vector<int> expectedPathNegative = {0, 1, 2, 3};
        CHECK(Algorithms::shortestPath(gNegative, 0, 3) == expectedPathNegative);
    }
}

TEST_CASE("isContainsCycle")
{

    SUBCASE("Directed Cycle")
    {
        // Graph with a known cycle
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
            {1, 0, 0, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);
        std::vector<int> expectedCycle = {0, 1, 2, 3, 0};
        CHECK(Algorithms::isContainsCycle(g) == expectedCycle);
    }

    SUBCASE("No Directed Cycle")
    {
        // Graph with no cycle
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1},
            {0, 0, 0, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);
        CHECK(Algorithms::isContainsCycle(g).empty());
    }

    SUBCASE("Undirected Cycle")
    {
        // Undirected cycle
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 1, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 1, 1},
            {1, 0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        std::vector<int> expectedCycle = {0, 1, 2, 3, 0};
        CHECK(Algorithms::isContainsCycle(g) == expectedCycle);
    }

    SUBCASE("No Undirected Cycle")
    {
        // Undirected graph with no cycle
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 0, 0, 0, 0},
            {1, 0, 1, 0, 0, 0},
            {0, 1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);
        CHECK(Algorithms::isContainsCycle(g).empty());
    }
}

TEST_CASE("isBipartite")
{

    SUBCASE("Undirected Bipartite Graph")
    {
        // Bipartite graph
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 1, 0},
            {1, 0, 0, 1},
            {1, 0, 0, 1},
            {0, 1, 1, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        std::pair<std::vector<int>, std::vector<int>> bipartiteSets = Algorithms::isBipartite(g);
        std::vector<int> &setA = bipartiteSets.first;
        std::vector<int> &setB = bipartiteSets.second;
        std::vector<int> expectedSetA = {0, 3}; // Vertices in one set
        std::vector<int> expectedSetB = {1, 2}; // Vertices in the other set
        CHECK(setA == expectedSetA);
        CHECK(setB == expectedSetB);
    }
    SUBCASE("Undirected Not Bipartite Graph")
    {
        // Not bipartite graph
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 1, 2, 0, 0},
            {1, 0, 3, 0, 0},
            {2, 3, 0, 4, 0},
            {0, 0, 4, 0, 5},
            {0, 0, 0, 5, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        std::pair<std::vector<int>, std::vector<int>> bipartiteSets = Algorithms::isBipartite(g);
        std::vector<int> &setA = bipartiteSets.first;
        std::vector<int> &setB = bipartiteSets.second;
        CHECK(setA.empty());
        CHECK(setB.empty());
    }

    SUBCASE("Directed Bipartite Graph")
    {
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 0, 0, 0, 5, 0},
            {0, 0, 0, 0, 3, 0},
            {0, 0, 0, 11, 0, 5},
            {1, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0},
            {0, 11, 0, 0, 0, 0}};
        Graph g;
        g.loadGraph(adjacencyMatrix);

        std::pair<std::vector<int>, std::vector<int>> bipartiteSets = Algorithms::isBipartite(g);
        std::vector<int> &setA = bipartiteSets.first;
        std::vector<int> &setB = bipartiteSets.second;
        std::vector<int> expectedSetA = {0, 1, 2}; // Vertices in one set
        std::vector<int> expectedSetB = {3, 4, 5}; // Vertices in the other set
        CHECK(setA == expectedSetA);
        CHECK(setB == expectedSetB);
    }
}

TEST_CASE("negativeCycle")
{

    SUBCASE("Negative Cycle Exists")
    {
        // Graph with a negative cycle
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 0, 0, 0},
            {4, 0, -6, 0},
            {0, 0, 0, 5},
            {0, -2, 0, 0}};

        Graph g;
        g.loadGraph(adjacencyMatrix);
        std::vector<int> expectedCycle = {3, 1, 2};
        CHECK(Algorithms::negativeCycle(g) == expectedCycle);
    }

    SUBCASE("No Negative Cycle")
    {
        // graph with no negative cycle
        std::vector<std::vector<int>> adjacencyMatrix = {
            {0, 0, 0, 6},
            {4, 0, 6, 0},
            {0, 0, 0, 0},
            {0, 2, 0, 0}};

        Graph g;
        g.loadGraph(adjacencyMatrix);
        CHECK(Algorithms::negativeCycle(g).empty());
    }

    // SUBCASE("test")
    // {
    //     // Graph with a negative cycle
    //     std::vector<std::vector<int>> adjacencyMatrix = {
    //         {0, -1, 0},
    //         {-1, 0, -1},
    //         {0, -1, 0}};

    //     Graph g;
    //     g.loadGraph(adjacencyMatrix);
    //     std::vector<int> expectedCycle = {3, 1, 2};
    //     CHECK(Algorithms::negativeCycle(g).empty());
    // }
}

TEST_CASE("Invalid Graph")
{
    // Invalid graph
    std::vector<std::vector<int>> adjacencyMatrix = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    Graph g;
    CHECK_THROWS(g.loadGraph(adjacencyMatrix));
}

TEST_CASE("Addition")
{
    SUBCASE("g3 = g1 + g2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 1, 0},
            {1, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        Graph g3;

        g3 = g1 + g2;

        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0}, {2, 0, 4}, {0, 2, 0}});
    }

    SUBCASE("g1 += g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 1, 0},
            {1, 0, 3},
            {0, 3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        g1 += g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0}, {2, 0, 4}, {0, 2, 0}});

        vector<vector<int>> adjmat3 = {
            {0, -2, 0, 5, 0, 0, 0, 0, 3, 0},
            {-2, 0, 4, 0, 0, 0, 0, 7, 0, -1},
            {0, 4, 0, 0, 6, 0, 8, 0, 0, 0},
            {5, 0, 0, 0, 0, 2, 0, -3, 0, 0},
            {0, 0, 6, 0, 0, -4, 0, 0, 0, 0},
            {0, 0, 0, 2, -4, 0, 9, 0, 1, 0},
            {0, 0, 8, 0, 0, 9, 0, 5, 0, -2},
            {0, 7, 0, -3, 0, 0, 5, 0, 0, 0},
            {3, 0, 0, 0, 0, 1, 0, 0, 0, 4},
            {0, -1, 0, 0, 0, 0, -2, 0, 4, 0}};
        g1.loadGraph(adjmat3);

        vector<vector<int>> adjmat4 = {
            {0, 0, -5, 0, 3, 0, 2, 0, 0, 1},
            {0, 0, 4, 0, 0, -2, 0, 0, 6, 0},
            {-5, 4, 0, 7, 0, 1, 0, -4, 0, 0},
            {0, 0, 7, 0, -3, 0, 0, 0, 0, 8},
            {3, 0, 0, -3, 0, 5, 0, 0, 7, 0},
            {0, -2, 1, 0, 5, 0, 6, 0, 0, 0},
            {2, 0, 0, 0, 0, 6, 0, 9, 0, -7},
            {0, 0, -4, 0, 0, 0, 9, 0, 2, 0},
            {0, 6, 0, 0, 7, 0, 0, 2, 0, -1},
            {1, 0, 0, 8, 0, 0, -7, 0, -1, 0}};
        g2.loadGraph(adjmat4);

        g1 += g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{
                                             {0, -2, -5, 5, 3, 0, 2, 0, 3, 1},
                                             {-2, 0, 8, 0, 0, -2, 0, 7, 6, -1},
                                             {-5, 8, 0, 7, 6, 1, 8, -4, 0, 0},
                                             {5, 0, 7, 0, -3, 2, 0, -3, 0, 8},
                                             {3, 0, 6, -3, 0, 1, 0, 0, 7, 0},
                                             {0, -2, 1, 2, 1, 0, 15, 0, 1, 0},
                                             {2, 0, 8, 0, 0, 15, 0, 14, 0, -9},
                                             {0, 7, -4, -3, 0, 0, 14, 0, 2, 0},
                                             {3, 6, 0, 0, 7, 1, 0, 2, 0, 3},
                                             {1, -1, 0, 8, 0, 0, -9, 0, 3, 0}});
    }

    SUBCASE("graph++")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, -3, 5, 0, 2},
            {-3, 0, 4, 7, -1},
            {5, 4, 0, -2, 3},
            {0, 7, -2, 0, 6},
            {2, -1, 3, 6, 0}};
        g1.loadGraph(adjmat1);
        g1++;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, -2, 6, 0, 3}, {-2, 0, 5, 8, 0}, {6, 5, 0, -1, 4}, {0, 8, -1, 0, 7}, {3, 0, 4, 7, 0}});
    }

    SUBCASE("++graph")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g1.loadGraph(adjmat1);

        ++g1;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 7, 0, 4, -3}, {7, 0, -1, 0, 2}, {0, -1, 0, 6, 0}, {4, 0, 6, 0, -2}, {-3, 2, 0, -2, 0}});
    }
}

TEST_CASE("Subtraction")
{
    SUBCASE("g3 = g1 - g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        Graph g3;

        g3 = g1 - g2;

        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{0, 3, 0}, {0, 0, 2}, {0, 5, 0}});
    }

    SUBCASE("graph--")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g1.loadGraph(adjmat1);

        g1--;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 5, 0, 2, -5}, {5, 0, -3, 0, 0}, {0, -3, 0, 4, 0}, {2, 0, 4, 0, -4}, {-5, 0, 0, -4, 0}});
    }

    SUBCASE("--graph")
    {
        Graph g1;
        vector<vector<int>> adjmat2 = {
            {0, 0, 0, 0, 0, 0},
            {0, 0, 3, 7, 0, 0},
            {0, 3, 0, 0, 8, 0},
            {0, 7, 0, 0, -3, -2},
            {0, 0, 8, -3, 0, 1},
            {0, 0, 0, -2, 1, 0}};
        g1.loadGraph(adjmat2);

        --g1;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 0, 0, 0, 0, 0}, {0, 0, 2, 6, 0, 0}, {0, 2, 0, 0, 7, 0}, {0, 6, 0, 0, -4, -3}, {0, 0, 7, -4, 0, 0}, {0, 0, 0, -3, 0, 0}});
    }

    SUBCASE("g1 -= g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        g1 -= g2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 3, 0}, {0, 0, 2}, {0, 5, 0}});
    }
}

TEST_CASE("Multiplication")
{
    SUBCASE("g3 = g1 * g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        Graph g3;
        g3 = g1 * g2;
        CHECK(g3.getAdjacencyMatrix() == vector<vector<int>>{{2, 0, 2}, {0, -4, 0}, {4, 0, 4}});
    }

    SUBCASE("g1 *= g2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        g1 *= g2;
        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{2, 0, 2}, {0, -4, 0}, {4, 0, 4}});
    }

    SUBCASE("g2 = g1 * scalar")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        g2 = g1 * -2;

        CHECK(g2.getAdjacencyMatrix() == vector<vector<int>>{{0, -4, 0}, {-2, 0, -6}, {0, -8, 0}});
    }

    SUBCASE("g1 *= scalar")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        g1 *= 2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 4, 0}, {2, 0, 6}, {0, 8, 0}});
    }
}

TEST_CASE("Division")
{
    SUBCASE("g2 = g1 / scalar")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        g2 = g1 / 2;

        CHECK(g2.getAdjacencyMatrix() == vector<vector<int>>{{0, 1, 0}, {0, 0, 1}, {0, 2, 0}});
    }

    SUBCASE("g1 /= scalar")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        g1 /= 2;

        CHECK(g1.getAdjacencyMatrix() == vector<vector<int>>{{0, 1, 0}, {0, 0, 1}, {0, 2, 0}});
    }
}

TEST_CASE("Comparison")
{
    SUBCASE("g1 == g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {0, 2, 0},
            {1, 0, 3},
            {0, 4, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 == g2);

        vector<vector<int>> adjmat3 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat3);

        CHECK_FALSE(g1 == g2);
    }

    SUBCASE("graph1 != graph2")
    {
        Graph g1;
        Graph g2;
        vector<vector<int>> adjmat1 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g1.loadGraph(adjmat1);

        vector<vector<int>> adjmat2 = {
            {0, 0, 0},
            {0, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat2);

        CHECK(g1 != g2);

        vector<vector<int>> adjmat3 = {
            {0, 3, 6, 0},
            {3, 0, 3, 7},
            {6, 3, 0, 0},
            {0, 7, 0, 0}};
        g2.loadGraph(adjmat3);

        CHECK(g1 != g2);

        vector<vector<int>> adjmat4 = {
            {0, -1, 0},
            {1, 0, 1},
            {0, -1, 0}};
        g2.loadGraph(adjmat4);

        CHECK_FALSE(g1 != g2);
    }

    SUBCASE("g1 > g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {6, 0, 3, -4},
            {0, -2, 0, 1},
            {-2, 0, 5, 0},
            {0, 5, 0, -3}};
        g2.loadGraph(adjmat2);

        CHECK(g1 > g2);

        vector<vector<int>> adjmat3 = {
            {0, 1, 1, 1, 1},
            {1, 0, 1, 1, 1},
            {1, 1, 0, 1, 1},
            {1, 1, 1, 0, 1},
            {1, 1, 1, 1, 0}};
        g2.loadGraph(adjmat3);

        CHECK(g2 > g1);
    }

    SUBCASE("g1 < g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {6, 0, 3, -4},
            {0, -2, 0, 1},
            {-2, 0, 5, 0},
            {0, 5, 0, -3}};
        g2.loadGraph(adjmat2);

        CHECK(g2 < g1);
    }

    SUBCASE("g1 >= g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {6, 0, 3, -4},
            {0, -2, 0, 1},
            {-2, 0, 5, 0},
            {0, 5, 0, -3}};
        g2.loadGraph(adjmat2);

        CHECK(g1 >= g2);

        Graph g3;
        vector<vector<int>> adjmat3 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g3.loadGraph(adjmat3);
        CHECK(g1 >= g3);
        CHECK(g3 >= g1);
    }

    SUBCASE("g1 <= g2")
    {
        Graph g1;
        vector<vector<int>> adjmat1 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g1.loadGraph(adjmat1);

        Graph g2;
        vector<vector<int>> adjmat2 = {
            {6, 0, 3, -4},
            {0, -2, 0, 1},
            {-2, 0, 5, 0},
            {0, 5, 0, -3}};
        g2.loadGraph(adjmat2);

        CHECK(g2 <= g1);

        Graph g3;
        vector<vector<int>> adjmat3 = {
            {0, 6, 0, 3, -4},
            {6, 0, -2, 0, 1},
            {0, -2, 0, 5, 0},
            {3, 0, 5, 0, -3},
            {-4, 1, 0, -3, 0}};
        g3.loadGraph(adjmat3);
        CHECK(g3 <= g1);
        CHECK(g1 <= g3);
    }
}

TEST_CASE("Error")
{
    Graph g1;
    vector<vector<int>> adjmat1 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g1.loadGraph(adjmat1);

    Graph g2;
    vector<vector<int>> adjmat2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 1, 0}};
    g2.loadGraph(adjmat2);

    CHECK_THROWS(g1 + g2);
    CHECK_THROWS(g1 - g2);
    CHECK_THROWS(g1 * g2);
}
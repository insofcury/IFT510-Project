// A C++ program for Bellman-Ford's single source
// shortest path algorithm.
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <stack>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <sstream>
#include <iomanip>
using namespace std;

// Defining the edges
struct Edge
{
    int src, dest, weight;
};

//Defining the graph
struct Graph
{
    int V, E;

    // Declaring array of edges.
    struct Edge *edge;
};

// Creates a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

// Print the Distance matrix with U being the starting node
void printArr(int dist[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << dist[i] << "\t\t";
    }
    cout << endl << endl;
}

//This function is reponsible for Implementing the Bellman-Ford algorithm
void BellmanFord(struct Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    vector<int> hop(V, 0);

    // create a distance vector that would contain distance of all the nodes from the U node. Initialize all the nodes with INT_MAX as before beign discovered they all are
    // unreachable. Also distance of U from U would be 0
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 0; i < graph->V; i++)
    {
        cout << "\t\t" << (char)(85 + i) << " ";
    }
    cout << endl << endl;
    hop[5] += 2;

    //Since the maximum edges required to reach from one node to another node can be V-1 i.e number of nodes - 1 the total number of iterations needed would be V-1
    for (int i = 1; i <= V - 1; i++)
    {
        cout << "ITR" << i << "\t\t";
        if (i == 1)
        {
            cout << 0 << "\t\t" << INT_MAX << "      " << INT_MAX << "      " << INT_MAX << "      " << INT_MAX << "      " << INT_MAX << endl << endl;
        }
        else
        {
            printArr(dist, V);
        }

        //Implementing Dynamic Programming we already have previous distances stored in the dist array and we update the value when distance to the destination is
        //greater than the distance to the source + weight of the edge
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
            {
                if (dist[v] > (dist[u] + weight))
                    hop[v]++;
                dist[v] = dist[u] + weight;
            }
        }
    }

    //Print the hop count of  all the nodes from the start node U
    cout << "Node    "<< "Hop Count" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << (char)(i + 85) << "\t" << hop[i] << endl;
    }

    //Bellman ford algorithm doesnt work for cycle with negative sum, so checking if the sum is negative for any cycle
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;

        // If we detect negative cycle exit the program
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            printf("Graph contains negative weight cycle");
            exit(0);
        }
    }
}

int main()
{
    //Creating the graph

    int V = 6;  // Number of vertices in graph
    int E = 20; // Number of edges in graph
    struct Graph *graph = createGraph(V, E);

    //Edge U-V
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 3;

    graph->edge[10].src = 1;
    graph->edge[10].dest = 0;
    graph->edge[10].weight = 3;

    //Edge U-X
    graph->edge[11].src = 3;
    graph->edge[11].dest = 0;
    graph->edge[11].weight = 1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 1;

    //Edge U-W
    graph->edge[2].src = 0;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 7;

    graph->edge[12].src = 2;
    graph->edge[12].dest = 0;
    graph->edge[12].weight = 7;

    //Edge V-X
    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 1;

    graph->edge[13].src = 3;
    graph->edge[13].dest = 1;
    graph->edge[13].weight = 1;

    //Edge V-W
    graph->edge[4].src = 1;
    graph->edge[4].dest = 2;
    graph->edge[4].weight = 1;

    graph->edge[14].src = 2;
    graph->edge[14].dest = 1;
    graph->edge[14].weight = 1;

    //Edge W-X
    graph->edge[5].src = 2;
    graph->edge[5].dest = 3;
    graph->edge[5].weight = 4;

    graph->edge[15].src = 3;
    graph->edge[15].dest = 2;
    graph->edge[15].weight = 4;

    //Edge W-Y
    graph->edge[6].src = 2;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 5;

    graph->edge[16].src = 4;
    graph->edge[16].dest = 2;
    graph->edge[16].weight = 5;

    ///Edge X-Y
    graph->edge[7].src = 3;
    graph->edge[7].dest = 4;
    graph->edge[7].weight = 2;

    graph->edge[17].src = 4;
    graph->edge[17].dest = 3;
    graph->edge[17].weight = 2;

    //Edge Y-Z
    graph->edge[8].src = 4;
    graph->edge[8].dest = 5;
    graph->edge[8].weight = 3;

    graph->edge[18].src = 5;
    graph->edge[18].dest = 4;
    graph->edge[18].weight = 3;

    //Edge W-Z
    graph->edge[9].src = 2;
    graph->edge[9].dest = 5;
    graph->edge[9].weight = 6;

    graph->edge[19].src = 5;
    graph->edge[19].dest = 2;
    graph->edge[19].weight = 6;

    BellmanFord(graph, 0);

    return 0;
}
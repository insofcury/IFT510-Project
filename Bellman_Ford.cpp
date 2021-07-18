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

//To represent the edge
struct Edge
{
    int source, destination, weight;
};

//To represent the graph
struct Graph
{
    int V, E;

    struct Edge *edge;
};

//Construct the graph
struct Graph *makeGraph(int V, int E)
{
    struct Graph *graph = new Graph;
    graph->V = V;
    graph->E = E;
    graph->edge = new Edge[E];
    return graph;
}

void printTable(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << (char)(i + 85) << "\t\t" << arr[i] << endl;
    }
    cout << endl;
}

void implementBellmanFordAlgorithm(struct Graph *g, int s)
{
    int v = g->V;
    int e = g->E;

    vector<int> distance(v, INT_MAX);

    distance[0] = 0;

    for (int i = 1; i <= v - 1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int a = g->edge[j].source;
            int b = g->edge[j].destination;
            int weight = g->edge[j].weight;
            if (distance[a] + weight < distance[b] && distance[a] != INT_MAX)
                distance[b] = distance[a] + weight;
        }
    }
    printTable(distance, v);

    for (int i = 0; i < e; i++)
    {
        int a = g->edge[i].source;
        int b = g->edge[i].destination;
        int weight = g->edge[i].weight;
        if (distance[a] + weight < distance[b] && distance[a] != INT_MAX)
        {
            printf("There is a negative weight cycle therfore the Bellman-Ford algorithm will fail in this case");
            exit(0);
        }
    }
}

int32_t main()
{
    int no_of_vertices = 6;
    int no_of_edges = 10;

    struct Graph *graph = makeGraph(no_of_vertices, no_of_edges);

    //Let's consider the graph's vertex as U - 0, V - 1, W - 2, X - 3, Y - 4, Z - 5

    //Edge U-V
    graph->edge[0].source = 0;
    graph->edge[0].destination = 1;
    graph->edge[0].weight = 3;

    //Edge U-X
    graph->edge[1].source = 0;
    graph->edge[1].destination = 3;
    graph->edge[1].weight = 1;

    //Edge U-W
    graph->edge[2].source = 0;
    graph->edge[2].source = 2;
    graph->edge[2].source = 7;

    //Edge V-X
    graph->edge[3].source = 1;
    graph->edge[3].source = 3;
    graph->edge[3].source = 1;

    //Edge V-W
    graph->edge[4].source = 1;
    graph->edge[4].source = 2;
    graph->edge[4].source = 1;

    //Edge W-X
    graph->edge[5].source = 2;
    graph->edge[5].source = 3;
    graph->edge[5].source = 4;

    //Edge W-Y
    graph->edge[6].source = 2;
    graph->edge[6].source = 4;
    graph->edge[6].source = 5;

    //Edge X-Y
    graph->edge[7].source = 3;
    graph->edge[7].source = 4;
    graph->edge[7].source = 2;

    //Edge Y-Z
    graph->edge[8].source = 4;
    graph->edge[8].source = 5;
    graph->edge[8].source = 3;

    //Edge W-Z
    graph->edge[9].source = 2;
    graph->edge[9].source = 5;
    graph->edge[9].source = 6;

    implementBellmanFordAlgorithm(graph, 0);
}
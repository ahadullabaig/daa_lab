#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minVertex(vector<int>& minWt, vector<bool>& visited, int V)
{
    int min = INT_MAX, min_index = -1;

    for(int v=0; v<V; v++)
    {
        if (!visited[v] && minWt[v] < min)
        {
            min = minWt[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void prims(vector<vector<int>>& graph, int src, int V)
{
    vector<int> parent(V);
    vector<int> minWt(V, INT_MAX);
    vector<bool> visited(V, false);

    minWt[src] = 0;
    parent[src] = -1;

    for(int i=0; i < (V-1); i++)
    {
        int u = minVertex(minWt, visited, V);

        visited[u] = true;

        for(int v=0; v<V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                graph[u][v] < minWt[v])
            {
                parent[v] = u;
                minWt[v] = graph[u][v];
            }
        }
    }

    int minCost = 0;

    cout << "\nMinimum Spanning Tree (Prim's Algorithm):" << endl;
    cout << "Edge \tWeight" << endl;
    
    for(int v=0; v<V; v++)
    {
        if(parent[v] != -1)
        {
            cout << parent[v] << " - " << v << " \t" << minWt[v] << endl;

            minCost += minWt[v];
        }
    }
    
    cout << "\nMinimum Total Cost: " << minCost << endl;
}

int main()
{
    int V = 5;
    
    vector<vector<int>> graph = {
        {0, 4, 0, 8, 0},
        {4, 0, 3, 1, 0},
        {0, 3, 0, 7, 8},
        {8, 1, 7, 0, 3},
        {0, 0, 8, 3, 0}
    };

    int src = 0;
    
    cout << "Starting Prim's MST from node " << src << endl;

    prims(graph, src, V);

    return 0;
}

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minVertex(vector<int>& minWt, vector<bool>& visited, int V)
{
    int min = INT_MAX;

    int min_index;

    for(int v=0; v<V; v++)
    {
        if (visited[v] == false &&
            minWt[v] < min)
        {
            min = minWt[v];
            min_index = v;
        }
    }
    
    return min_index;
}

void prims(vector<vector<int>>& edges, int V, int src)
{
    vector<int> parent(V);
    vector<int> minWt(V, INT_MAX);
    vector<bool> visited(V, false);

    minWt[src] = 0;
    parent[src] = -1;

    for(int count = 0; count < (V-1); count++)
    {
        int u = minVertex(minWt, visited, V);

        visited[u] = true;

        for(int v=0; v<V; v++)
        {
            if (edges[u][v] != 0 &&
                visited[v] == false &&
                edges[u][v] < minWt[v])
            {
                parent[v] = u;
                minWt[v] = edges[u][v];
            }
        }
    }

    int minCost = 0;

    cout << "\nMinimum Spanning Tree (Prim's Algorithm):" << endl;
    cout << "Edge \tWeight" << endl;
    
    for(int i=0; i<V; i++)
    {
        if(parent[i] != -1)
        {
            cout << parent[i] << " - " << i << " \t" << edges[i][parent[i]] << endl;

            minCost += edges[i][parent[i]];
        }
    }
    
    cout << "\nMinimum Total Cost: " << minCost << endl;
}

int main()
{
    int V = 5;
    
    vector<vector<int>> edges = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int src = 0;
    
    cout << "Starting Prim's MST from node " << src << endl;
    prims(edges, V, src);

    return 0;
}

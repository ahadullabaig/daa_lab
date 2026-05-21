#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet, int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

void primMST(vector<vector<int>>& graph, int V, int startNode)
{
    vector<int> parent(V);
    vector<int> key(V, INT_MAX);
    vector<bool> mstSet(V, false);

    key[startNode] = 0;
    parent[startNode] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int minCost = 0;
    cout << "Minimum Spanning Tree (Prim's Algorithm):" << endl;
    cout << "Edge \tWeight" << endl;
    for (int i = 0; i < V; i++)
    {
        if (parent[i] != -1)
        {
            cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << endl;
            minCost += graph[i][parent[i]];
        }
    }
    cout << "Minimum Total Cost: " << minCost << endl;
}

int main()
{
    int V = 5;
    
    // Adjacency matrix representation
    vector<vector<int>> graph = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    int startNode = 0; // The driver can start at any arbitrary location
    
    cout << "Starting Prim's MST from node " << startNode << endl;
    primMST(graph, V, startNode);

    return 0;
}

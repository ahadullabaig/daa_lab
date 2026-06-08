#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

bool compareEdge(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int findParent(int i, vector<int>& parent)
{
    if (parent[i] == i) return i;

    parent[i] = findParent(parent[i], parent);

    return parent[i];
}

void kruskals(vector<Edge>& edges, int V)
{
    sort(edges.begin(), edges.end(), compareEdge);
    
    vector<int> parent(V);

    for(int v=0; v<V; v++)
    {
        parent[v] = v;
    }

    vector<Edge> result;

    int minCost = 0;
    
    for(auto edge : edges)
    {
        int rootSrc = findParent(edge.src, parent);

        int rootDest = findParent(edge.dest, parent);
        
        if(rootSrc != rootDest)
        {
            result.push_back(edge);

            minCost += edge.weight;
            
            parent[rootSrc] = rootDest;
        }
    }
    
    cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
    cout << "Edge \tWeight" << endl;

    for(auto edge : result)
    {
        cout << edge.src << " - " << edge.dest << " \t" << edge.weight << endl;
    }
    
    cout << "Minimum Total Cost: " << minCost << endl;
}

int main()
{
    int V = 6;
    
    vector<Edge> edges = {
        {1, 5, 5},
        {1, 2, 10},
        {5, 2, 7},
        {5, 3, 6},
        {5, 4, 3},
        {4, 3, 2},
        {4, 2, 6},
        {3, 2, 1}
    };
    
    kruskals(edges, V);
    
    return 0;
}

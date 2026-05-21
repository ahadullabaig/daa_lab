#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Sort edges by weight
bool compareEdge(Edge a, Edge b)
{
    return a.weight < b.weight;
}

struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    int find(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY;
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX;
            else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

void kruskalMST(vector<Edge>& edges, int V)
{
    vector<Edge> result;
    int minCost = 0;
    
    sort(edges.begin(), edges.end(), compareEdge);
    
    DisjointSet ds(V);
    
    for (auto edge : edges)
    {
        int rootSrc = ds.find(edge.src);
        int rootDest = ds.find(edge.dest);
        
        if (rootSrc != rootDest)
        {
            result.push_back(edge);
            minCost += edge.weight;
            ds.unite(rootSrc, rootDest);
        }
    }
    
    cout << "Minimum Spanning Tree (Kruskal's Algorithm):" << endl;
    cout << "Edge \tWeight" << endl;
    for (auto edge : result)
    {
        cout << edge.src << " - " << edge.dest << " \t" << edge.weight << endl;
    }
    cout << "Minimum Total Cost: " << minCost << endl;
}

int main()
{
    int V = 5;
    
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    
    kruskalMST(edges, V);
    
    return 0;
}

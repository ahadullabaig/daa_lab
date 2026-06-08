#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(vector<Edge>& edges, int src, int V)
{
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;

    for(int i=1; i <= (V - 1); i++)
    {
        for(auto e : edges)
        {
            if (dist[e.src] != INT_MAX &&
                dist[e.src] + e.weight < dist[e.dest])
            {
                dist[e.dest] = dist[e.src] + e.weight;
            }
        }
    }

    for(auto e : edges)
    {
        if (dist[e.src] != INT_MAX &&
            dist[e.src] + e.weight < dist[e.dest])
        {
            cout << "Graph contains a negative-weight cycle!\n";
            return;
        }
    }

    cout << "\nShortest distances from vertex " << src << ":\n";

    for(int v=0; v<V; v++)
    {
        cout << v << " = ";

        if (dist[v] == INT_MAX) cout << "INF\n";

        else cout << dist[v] << "\n";
    }
}

int main()
{
    int V = 5;
    
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},
        {1, 2, 3}, {1, 3, 2}, {1, 4, 2},
        {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    
    int src = 0;
    
    bellmanFord(edges, src, V);
    
    return 0;
}

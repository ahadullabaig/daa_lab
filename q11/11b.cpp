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

    for(int i=0; i < (V - 1); i++)
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

    for(int v=0; v<V; v++) cout << v << " = " << dist[v] << "\n";
    
    cout << endl;
}

int main()
{
    int V = 6;

    vector<Edge> edges = {
        {0, 1, -4}, // a -> b
        {0, 5, -3}, // a -> t

        {1, 3, -1}, // b -> d
        {1, 4, -2}, // b -> e

        {3, 0, 6},  // d -> a
        {3, 5, 4},  // d -> t

        {4, 2, -3}, // e -> c
        {4, 5, 2},  // e -> t

        {2, 1, 8},  // c -> b
        {2, 5, 3}   // c -> t
    };

    int src = 0; // a

    bellmanFord(edges, src, V);

    return 0;
}

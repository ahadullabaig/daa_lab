#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;

int findMinDistance(vector<int>& dist, vector<bool>& visited, int V)
{
    int min = INT_MAX, min_index = -1;

    for(int v = 0; v < V; v++)
    {
        if(!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void displayPaths(vector<int>& dist, int source, int V)
{
    cout << "Shortest distances from Location " << source + 1 << ":" << endl;
    cout << "Destination \t Distance" << endl;

    for(int i = 0; i < V; i++)
    {
        cout << i + 1 << " \t\t ";
    
        if(dist[i] == INT_MAX) cout << "Unreachable" << endl;
    
        else cout << dist[i] << endl;
    }
}

void dijkstra(vector<vector<int>>& graph, int src, int V)
{
    vector<int> dist(V, INT_MAX);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for(int count = 0; count < V - 1; count++)
    {
        int u = findMinDistance(dist, visited, V);
    
        if(u == -1) break; 
        
        visited[u] = true;

        for(int v = 0; v < V; v++)
        {
            if(!visited[v] && graph[u][v] && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    displayPaths(dist, src, V);
}

int main()
{
    int V = 5;
    
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {0, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int src = 0;

    dijkstra(graph, src, V);

    return 0;
}

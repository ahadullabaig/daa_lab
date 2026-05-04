#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

void findReachable(int source, map<int, vector<int>>& adj)
{
    set<int> visited;
    queue<int> q;

    q.push(source);
    visited.insert(source);

    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        for (int neighbor : adj[current])
        {
            if (visited.find(neighbor) == visited.end())
            {
                visited.insert(neighbor);
                q.push(neighbor);
            }
        }
    }

    cout << "Nodes reachable from source " << source << ": ";
    
    for (int node : visited)
    {
        cout << node << " ";
    }
    
    cout << endl;
}

int main()
{
    map<int, vector<int>> adj;

    adj[1] = {2, 3, 4};
    adj[2] = {3, 5};
    adj[3] = {4, 5};
    adj[4] = {3, 5};
    adj[5] = {};

    int sourceNode = 1;
    
    findReachable(sourceNode, adj);

    return 0;
}

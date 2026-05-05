#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool isBipartite(int startNode, map<int, vector<int>>& adj)
{
    map<int, int> color;

    queue<int> q;

    q.push(startNode);

    color[startNode] = 1; 

    while(!q.empty())
    {
        int curr = q.front();
    
        q.pop();

        for(int neighbor : adj[curr])
        {
            if(color.find(neighbor) == color.end() || color[neighbor] == 0)
            {
                color[neighbor] = -color[curr];
                q.push(neighbor);
            }
            else if(color[neighbor] == color[curr])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    map<int, vector<int>> adj;
    
    adj[1] = {2, 3};
    adj[2] = {1, 3, 4, 5};
    adj[3] = {1, 2, 6, 7};
    adj[4] = {2, 5, 8, 9};
    adj[5] = {2, 4, 9};
    adj[6] = {3, 7};
    adj[7] = {3, 6};
    adj[8] = {4, 9};
    adj[9] = {4, 5, 8, 10};
    adj[10] = {9};

    if (isBipartite(1, adj))
    {
        cout << "The graph is Bipartite." << endl;
    }
    else {
        cout << "The graph is NOT Bipartite (contains odd cycles)." << endl;
    }

    return 0;
}

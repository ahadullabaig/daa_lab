#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Request {
    int id;
    int start;
    int finish;
    int value;
};

bool compareRequests(Request a, Request b)
{
    return a.finish < b.finish;
}

int latestNonConflict(const vector<Request>& reqs, int i)
{
    for (int j = i - 1; j >= 0; j--)
    {
        if (reqs[j].finish <= reqs[i].start) return j;
    }

    return -1;
}

void maxProfit(vector<Request>& reqs)
{
    sort(reqs.begin(), reqs.end(), compareRequests);
    
    int n = reqs.size();
    
    vector<int> dp(n);
    
    dp[0] = reqs[0].value;
    
    for (int i = 1; i < n; i++)
    {
        int inclProfit = reqs[i].value;

        int l = latestNonConflict(reqs, i);
    
        if (l != -1) inclProfit += dp[l];
        
        dp[i] = max(inclProfit, dp[i - 1]);
    }
    
    cout << "Maximum profit for the drama venue: " << dp[n - 1] << endl;
}

int main()
{
    vector<Request> requests = {
        {1, 1, 2, 100},
        {2, 2, 5, 200},
        {3, 3, 6, 300},
        {4, 4, 8, 400},
        {5, 5, 9, 500},
        {6, 6, 10, 100}
    };
    
    maxProfit(requests);
    
    return 0;
}

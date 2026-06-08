#include <iostream>
#include <vector>

using namespace std;

void knapsack(int W, vector<int>& weight, vector<int>& value, int n)
{
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int w = 1; w <= W; w++)
        {
            if (weight[i-1] <= w)
                dp[i][w] = max(value[i-1] + dp[i-1][w - weight[i-1]], dp[i-1][w]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    cout << "Maximum value accommodated: " << dp[n][W] << endl;
    cout << "Items selected: ";

    int w = W;
    
    for (int i = n; i > 0; i--)
    {
        if (dp[i][w] != dp[i-1][w])
        {
            cout << "Item " << i << " (Weight: " << weight[i-1] << ", Value: " << value[i-1] << ") ";
            w -= weight[i-1];
        }
    }

    cout << endl;
}

int main()
{
    vector<int> weight = {3, 5, 6, 2};
    vector<int> value = {10, 4, 9, 11};

    int W = 7;
    
    int n = value.size();

    knapsack(W, weight, value, n);

    return 0;
}

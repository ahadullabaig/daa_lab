#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

void solve()
{
    int n = 3;
    
    vector<string> men = {"A", "B", "C"};
    vector<string> women = {"V", "W", "X"};

    map<string, vector<string>> men_prefs;
    men_prefs["A"] = {"V", "W", "X"};
    men_prefs["B"] = {"W", "V", "X"};
    men_prefs["C"] = {"V", "W", "X"};

    map<string, vector<string>> women_prefs;
    women_prefs["V"] = {"A", "B", "C"};
    women_prefs["W"] = {"B", "C", "A"};
    women_prefs["X"] = {"C", "A", "B"};

    map<string, map<string, int>> women_rank;

    for(auto& w : women)
    {
        for(int i = 0; i < n; i++)
        {
            women_rank[w][women_prefs[w][i]] = i;
        }
    }

    map<string, string> engaged_to; 
    map<string, int> next_proposal;
    queue<string> free_men;

    for(auto& m : men)
    {
        free_men.push(m);
        next_proposal[m] = 0;
    }

    while(!free_men.empty())
    {
        string m = free_men.front();
        free_men.pop();

        if(next_proposal[m] >= n) continue;

        string w = men_prefs[m][next_proposal[m]++];

        if(engaged_to.find(w) == engaged_to.end())
        {
            engaged_to[w] = m;
        }
        else
        {
            string current_m = engaged_to[w];
        
            if(women_rank[w][m] < women_rank[w][current_m])
            {
                engaged_to[w] = m;
                free_men.push(current_m);
            }
            else
            {
                free_men.push(m);
            }
        }
    }

    for(auto& [woman, man] : engaged_to)
    {
        cout << man << " is married to " << woman << endl;
    }
}

int main()
{
    solve();

    return 0;
}

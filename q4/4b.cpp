#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

long long mergeAndCount(vector<int>& arr, int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++) left[i] = arr[l + i];

    for(int i = 0; i < n2; i++) right[i] = arr[m + 1 + i];

    long long count = 0;

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
            count += (n1 - i); 
        }
    }

    while(i < n1) arr[k++] = left[i++];

    while(j < n2) arr[k++] = right[j++];

    return count;
}

long long countInversions(vector<int>& arr, int l, int r)
{
    long long count = 0;

    if(l < r)
    {
        int m = l + (r - l) / 2;
    
        count += countInversions(arr, l, m);
    
        count += countInversions(arr, m + 1, r);
    
        count += mergeAndCount(arr, l, m, r);
    }
    
    return count;
}

int main()
{
    srand(time(0));

    int num_songs = 8;

    for (int user = 1; user <= 3; user++)
    {
        vector<int> playlist = {1, 2, 3, 4, 5, 6, 7, 8};
    
        shuffle(playlist.begin(), playlist.end(), mt19937(random_device()()));

        cout << "User " << user << " Playlist: ";
    
        for (int s : playlist) cout << s << " ";
        
        vector<int> temp = playlist;

        long long inv_count = countInversions(temp, 0, num_songs - 1);
        
        cout << "\nInversion Count: " << inv_count << endl;
        
        cout << "-----------------------------------" << endl;
    }

    return 0;
}

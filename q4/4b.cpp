#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

int mergeAndCount(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for(int i = 0; i < n1; i++) L[i] = arr[left + i];
    for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int count = 0;

    int i = 0, j = 0, k = left;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++; k++;
        }
        else
        {
            arr[k] = R[j];
            j++; k++;
            count += (n1 - i); 
        }
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++; k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++; k++;
    }

    return count;
}

int countInversions(vector<int>& arr, int left, int right)
{
    int count = 0;

    if(left < right)
    {
        int mid = (right + left) / 2;
    
        count += countInversions(arr, left, mid);
        count += countInversions(arr, mid + 1, right);
    
        count += mergeAndCount(arr, left, mid, right);
    }
    
    return count;
}

int main()
{
    int n = 8;

    for(int i = 1; i <= 3; i++)
    {
        vector<int> playlist = {1, 2, 3, 4, 5, 6, 7, 8};
    
        shuffle(playlist.begin(), playlist.end(), mt19937(random_device()()));

        cout << "User " << i << " Playlist: ";
        for (int s : playlist) cout << s << " ";
        
        int count = countInversions(playlist, 0, n - 1);
        
        cout << "\nInversion Count: " << count << endl << endl;
    }

    return 0;
}

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

int partition(vector<int>& arr, int left, int right)
{
    int pivot = arr[right];

    int i = (left - 1); 

    for(int j = left; j <= right - 1; j++)
    {
        if(arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i+1], arr[right]);
    
    return (i + 1);
}

void quickSort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int pi = partition(arr, left, right);

        quickSort(arr, left, pi - 1);

        quickSort(arr, pi + 1, right);
    }
}

void printArray(const vector<int>& arr)
{
    for (int x : arr) cout << x << " ";

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of random elements to sort: ";
    cin >> n;
    
    if (n <= 0) return 0;

    vector<int> data(n);

    srand(time(0));

    for(int i=0; i<n; i++)
    {
        data[i] = rand() % 10000; 
    }

    if(n <= 20)
    {
        cout << "\nUnsorted Array: " << endl;
        printArray(data);
    }

    clock_t start = clock();
    quickSort(data, 0, n - 1);
    clock_t end = clock();

    if (n <= 20)
    {
        cout << "\nSorted Array: " << endl;
        printArray(data);
    }

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSuccessfully sorted " << n << " elements." << endl;
    cout << "Execution time: " << fixed << setprecision(6) << time_taken << " seconds" << endl;

    return 0;
}

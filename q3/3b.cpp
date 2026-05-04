#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;

void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    vector<int> data(n);

    srand(time(0));

    for (int i = 0; i < n; i++)
    {
        data[i] = rand() % 10000; 
    }

    cout << "\nUnsorted Array: " << endl;
    printArray(data);

    clock_t start = clock();
    mergeSort(data, 0, n - 1);
    clock_t end = clock();

    cout << "\nSorted Array: " << endl;
    printArray(data);

    double time_taken = double(end - start) / CLOCKS_PER_SEC;

    cout << "\nSuccessfully sorted " << n << " elements." << endl;
    cout << "Execution time: " << fixed << setprecision(6) << time_taken << " seconds" << endl;

    return 0;
}

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void proveTheta()
{
    double c1 = 7.0;
    double c2 = 19.0;
    int n0 = 1;

    cout << left << setw(5) << "n" 
         << setw(15) << "c1*n^2" 
         << setw(20) << "f(n)=7n^2+7n+5" 
         << setw(15) << "c2*n^2" 
         << "Theta holds?" << endl;

    cout << "----------------------------------------------------------------------" << endl;

    for (int n = 1; n <= 10; ++n)
    {
        long long fn = 7LL * n * n + 7LL * n + 5;
        double lower = c1 * n * n;
        double upper = c2 * n * n;
    
        string status = (fn >= lower && fn <= upper) ? "Yes" : "No";

        cout << left << setw(5) << n 
             << setw(15) << (long long)lower 
             << setw(20) << fn 
             << setw(15) << (long long)upper 
             << status << endl;
    }
}

int main()
{
    proveTheta();

    return 0;
}

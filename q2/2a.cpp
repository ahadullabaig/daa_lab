#include <iostream>
#include <iomanip>

using namespace std;

void proveBigOmega()
{
    int c = 10;
    int n0 = 1;

    cout << left << setw(10) << "n" 
         << setw(20) << "f(n)=3n^2+4n+3" 
         << setw(15) << "c*g(n)=10n" 
         << "f(n) >= c*g(n)?" << endl;

    cout << "------------------------------------------------------------" << endl;

    for(int n = 1; n <= 10; ++n)
    {
        long fn = 3 * n * n + 4 * n + 3;
        long cgn = c * n;
    
        string result = (fn >= cgn) ? "True" : "False";

        cout << left << setw(10) << n 
             << setw(20) << fn 
             << setw(15) << cgn 
             << result << endl;
    }
}

int main()
{
    proveBigOmega();

    return 0;
}

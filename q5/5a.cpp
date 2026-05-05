#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void proveBigOmega()
{
    int c = 5;
    int n0 = 1;

    cout << left << setw(10) << "n" 
         << setw(15) << "f(n)=5n+5" 
         << setw(15) << "c*g(n)=5n" 
         << "f(n) >= c*g(n)?" << endl;

    cout << "------------------------------------------------------------" << endl;

    for(int n = 1; n <= 10; ++n)
    {
        long fn = 5 * n + 5;
        long cgn = c * n;
    
        string result = (fn >= cgn) ? "True" : "False";

        cout << left << setw(10) << n 
             << setw(15) << fn 
             << setw(15) << cgn 
             << result << endl;
    }
}

int main()
{
    proveBigOmega();

    return 0;
}

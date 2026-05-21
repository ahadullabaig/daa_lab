#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void proveBigO()
{
    int c = 10;
    int n0 = 1;

    cout << left << setw(10) << "n" 
         << setw(18) << "f(n)=6n^2+2n+2" 
         << setw(15) << "c*g(n)=10n^2" 
         << "f(n) <= c*g(n)?" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (int n = 1; n <= 10; ++n)
    {
        long long fn = 6LL * n * n + 2LL * n + 2;
        long long cgn = (long long)c * n * n;
    
        string result = (fn <= cgn) ? "True" : "False";

        cout << left << setw(10) << n 
             << setw(18) << fn 
             << setw(15) << cgn 
             << result << endl;
    }
}

int main()
{
    proveBigO();

    return 0;
}

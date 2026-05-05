#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void proveBigO()
{
    int c = 14;
    int n0 = 1;

    cout << left << setw(10) << "n" 
         << setw(18) << "f(n)=8n^2+3n+3" 
         << setw(15) << "c*g(n)=14n^2" 
         << "f(n) <= c*g(n)?" << endl;

    cout << "------------------------------------------------------------" << endl;

    for (int n = 1; n <= 10; ++n)
    {
        long long fn = 8LL * n * n + 3LL * n + 3;
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

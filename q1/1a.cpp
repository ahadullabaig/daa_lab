#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void proveBigO()
{
    int c = 8;
    int n0 = 5;

    cout << left << setw(10) << "n" 
         << setw(15) << "f(n)=7n+5" 
         << setw(15) << "c*g(n)=8n" 
         << "f(n) <= c*g(n)?" << endl;

    cout << "------------------------------------------------------------" << endl;

    for(int n = 10; n <= 30; ++n)
    {
        long fn = 7 * n + 5;
        long cgn = c * n;
    
        string result = (fn <= cgn) ? "True" : "False";

        cout << left << setw(10) << n 
             << setw(15) << fn 
             << setw(15) << cgn 
             << result << endl;
    }
}

int main()
{
    proveBigO();

    return 0;
}

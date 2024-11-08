// parallel_factorial.cpp
// The programs calculates factorial with two different ways.
#include <iostream>
using namespace std;

long long factorial(int n);             // Common version.
long long factorial_2(int n);           // Parallel version.

int main(void)
{
    int n = 5;

    cout << "The common factorial " << n << "! = " << factorial(n) << endl;
    cout << "The parallel factorial " << n << "! = " << factorial_2(n) << endl;

    return 0;
}

long long factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; ++i)
        fact *= i;

    return fact;
}

long long factorial_2(int n)
{
    long long fact_odd = 1;
    long long fact_even = 1;
    for (int i = 1; i <= n; i += 2)
    {
        fact_odd *= i;
        fact_even *= i + 1;
    }
    if (n & 1)                          // If n is odd.
        fact_even /= n + 1;

    return fact_odd * fact_even;
}

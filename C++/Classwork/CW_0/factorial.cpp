// factorial.cpp
// Demonstrates two different realizations of factorial funciton.
#include <iostream>
using namespace std;

long long factorial(int num);
long long factorial_2(int num);

int main(void)
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << num << "! = " << factorial(num) << endl;
    cout << num << "! = " << factorial_2(num) << endl;

    return 0;
}

long long factorial(int num)
{
    long long res = 1;
    for (int i = 2; i <= num; ++i)
        res *= i;

    return res;
}

long long factorial_2(int num)
{
    long long res = 1;
    while (num > 1)
        res *= num--;

    return res;
}

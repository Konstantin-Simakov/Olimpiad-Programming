// count.cpp
// Demonstrates recursive and common count algorithm.
#include <iostream>
using namespace std;

void count(int num);
void count_2(int num);      // Recursive version.

int main(void)
{
    count(5);
    cout << endl;
    count_2(5);
    cout << endl;

    return 0;
}

void count(int num)
{
    for (int i = 1; i <= num; ++i)
        cout << i << ' ';
}

void count_2(int num)
{
    if (num > 1)
        count_2(num - 1);
    cout << num << ' ';
}

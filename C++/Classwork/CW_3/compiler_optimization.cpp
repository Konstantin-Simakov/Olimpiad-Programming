// assembler.cpp
// Testing "-S" flag generating output file with AT&T assmbler syntax 
// (with file extension ".s", not ".asm" in Unix-like systems).
// Don't forget to use flag -O2 to optimize the code below.
#include <iostream>
using namespace std;

#pragma GCC target("arch=x86-64")

int main(void)
{
    cout << "Done!\n";

    return 0;
}

int collatz(int n) 
{
    if (n % 2 == 0)
        return n / 2;
    else
        return 3 * n + 1;
}

void test(int n)
{
    int s = 0;
    for (int i = 1; i <= n; ++i)
        s += i;
}

int sum_one_bits(int n)
{
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        cnt += __builtin_popcount(i);

    return cnt;
}

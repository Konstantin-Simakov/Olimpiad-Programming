// two_queens.cpp
// The program calculates the number of arrangements of two queens on nxn board.
#include <iostream>
#include <cmath>                    // For pow(), floor()
using namespace std;

double two_queens_1(long long n);   // First version; runtime: O(n), auxiliary memory: O(n).
double two_queens_2(long long n);   // Second version; runtime: O(1), auxiliary memory: O(1).

int main(void)
{
    long long size;
    cout << "Enter a size of the board (one side): ";
    cin >> size;

    cout << "1st way: The number of arrangements q(" << size << ") = " 
         << two_queens_1(size) << endl;
    cout << "2nd way: The number of arrangements q(" << size << ") = " 
         << two_queens_2(size) << endl;

    return 0;
}

// The solution with reccurence formula.
double two_queens_1(long long n)
{
    if (n < 3)      // Base case.
        return 0;
    else            // Recursive case.
        return two_queens_1(n - 1) + 2 * pow(n - 1, 2) * (n - 2);
}

// The solution with closed formula.
double two_queens_2(long long n)
{
    if (n < 3)
        return 0;
    else
        return floor((pow(n, 4) / 2) - (5 * pow(n, 3) / 3) + (3 * pow(n, 2) / 2) - (n / 3));
}

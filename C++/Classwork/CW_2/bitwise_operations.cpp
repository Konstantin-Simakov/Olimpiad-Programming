// bitwise_operations.cpp
// Demonstrates some features of bitwise operations.
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;

void to_bin(int num);               
int builtin_clz(int num);           // The number of leading zeroes in BIN.
int builtin_ctz(int num);           // The number of ending zeroes in BIN.
int builtin_popcount(int num);      // The number of ones in BIN.
bool builtin_parity(int num);       // Parity of ones in BIN.

int main(void)
{
    // Program preparation.
    const int K = 2;
    string suffix;
    if (K <= 0)
    {
        cout << "Entered incorrect bitwise shift (K <= 0). Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    else if (K == 1)
        suffix = "st";
    else if (K == 2)
        suffix = "nd";
    else if (K == 3)
        suffix = "rd";
    else
        suffix = "th";

    // Source data input.
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    cout << "Source number:\n";
    to_bin(num);
    
    cout << "\n\n(Bit numbering starts from zero, as for arrays, but from right to left.)\n\n";

    // Test bitwise operaions and functions.
    int res;
    cout << "1. Simple cases.\n";
    cout << "Set the " << K << suffix << " bit to 1:\n";
    res = num | (1 << K);
    to_bin(res);
    cout << "\nReset the " << K << suffix << " bit to 0:\n";
    res = num & ~(1 << K);
    to_bin(res);
    cout << "\nInvert the " << K << suffix << " bit:\n"; 
    res = num ^ (1 << K);
    to_bin(res);

    cout << "\n\n2. More difficult cases.\n";
    cout << "Reset the last one bit to 0:\n";
    res = num & (num - 1);
    to_bin(res);
    cout << "\nReset all one bits to 0 except the last one:\n";
    res = num & -num;
    to_bin(res);
    cout << "\nSet all bits after the last one to one:\n";
    res = num | (num - 1);
    to_bin(res);

    cout << "\n\n";
    to_bin(num);
    cout << " (" << num << ") ";
    if ((num & (num - 1)) == 0)
        cout << "is power of 2.\n";
    else
        cout << "isn\'t power of 2.\n";

    cout << "\n3. Built-in functions.\n";
    to_bin(num);
    cout << " (" << num << ")\n";
    cout << "The number of leading zeros in binary representation: "
         << __builtin_clz(num) << endl;
    cout << "The number of leading zeros in binary representation (my version): "
         << builtin_clz(num) << endl;
    cout << "The number of ending zeros in binary representation: "
         << __builtin_ctz(num) << endl;
    cout << "The number of ending zeros in binary representation (my version): "
         << builtin_ctz(num) << endl;
    cout << "The number of ones in binary representation: "
         << __builtin_popcount(num) << endl;
    cout << "The number of ones in binary representation (my version): "
         << builtin_popcount(num) << endl;
    cout << "The number of ones in binary representation is ";
    if (__builtin_parity(num))
        cout << "odd.\n";
    else
        cout << "even.\n";
    cout << "The number of ones in binary representation is ";
    if (builtin_parity(num))
        cout << "odd.";
    else
        cout << "even.";
    cout << " (my version)\n";

    return 0;
}

void to_bin(int num)
{
    for (int k = sizeof num * CHAR_BIT - 1; k >= 0; --k)
    {
        if (num & (1 << k))
            cout << '1';
        else
            cout << '0';
        if (!(k & 3))
            cout.put(' ');
    }
    cout << '\b';
}

int builtin_clz(int num)
{
    int count = 0;
    for (int k = sizeof num * CHAR_BIT - 1; k >= 0; --k)
    {
        if (!(num & (1 << k)))
            count++;
        else
            break;
    }

    return count;
}

int builtin_ctz(int num)
{
    int count = 0;
    for (size_t k = 0; k < sizeof num * CHAR_BIT; ++k)
    {
        if (!(num & (1 << k)))
            count++;
        else
            break;
    }

    return count;
}

int builtin_popcount(int num)
{
    int count = 0;
    for (size_t k = 0; k < sizeof num * CHAR_BIT; ++k)
    {
        if (num & (1 << k))
            count++;
    }

    return count;
}

bool builtin_parity(int num)
{
    enum Parity {EVEN, ODD};
    bool parity;

    if (!(builtin_popcount(num) & 1))
        parity = EVEN;
    else
        parity = ODD;

    return parity;
}


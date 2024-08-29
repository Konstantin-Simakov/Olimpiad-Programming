// bitwise_operations.cpp
// Demonstrates some features of bitwise operations.
#include <iostream>
#include <climits>
using namespace std;

void dec_to_bin(int num);

int main(void)
{
    int num;
    cout << "Enter an integer: ";
    cin >> num;

    cout << "Source number:\n";
    dec_to_bin(num);
    
    cout << "\n\n(Bit numbering starts from zero, as for arrays.)\n\n";

    int res;
    int k = 2;
    cout << "1. Simple cases.\n";
    cout << "Set the 2nd bit to 1:\n";
    res = num | (1 << k);
    dec_to_bin(res);
    cout << "\nReset the 2nd bit to 0:\n";
    res = num & ~(1 << k);
    dec_to_bin(res);
    cout << "\nInvert the 2nd bit:\n"; 
    res = num ^ (1 << k);
    dec_to_bin(res);

    cout << "\n\n2. More difficult cases.\n";
    cout << "Reset the last one bit to 0:\n";
    res = num & (num - 1);
    dec_to_bin(res);
    cout << "\nReset all one bits to 0 except the last one:\n";
    res = num & -num;
    dec_to_bin(res);
    cout << "\nSet all bits after the last one to one:\n";
    res = num | (num - 1);
    dec_to_bin(res);

    cout << "\n\n";
    dec_to_bin(num);
    cout << " (" << num << ") ";
    if ((num & (num - 1)) == 0)
        cout << "is power of 2.\n";
    else
        cout << "isn\'t power of 2.\n";

    cout << "\n3. Built-in functions.\n";
    dec_to_bin(num);
    cout << " (" << num << ")\n";
    cout << "The number of leading zeros in binary representation: "
         << __builtin_clz(num) << endl;
    cout << "The number of ending zeros in binary representation: "
         << __builtin_ctz(num) << endl;
    cout << "The number of ones in binary representation: "
         << __builtin_popcount(num) << endl;
    cout << "The number of ones in binary representation is ";
    if (__builtin_parity(num))
        cout << "odd.\n";
    else
        cout << "even.\n";

    return 0;
}

void dec_to_bin(int num)
{
    for (int k = sizeof(int) * CHAR_BIT - 1; k >= 0; --k)
    {
        if (num & (1 << k))
            cout << '1';
        else
            cout << '0';
    }
}

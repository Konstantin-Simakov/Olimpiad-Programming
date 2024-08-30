// bitset.cpp
// Presentation of sets with bitwise operations.
#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

void display_bitset(int x);

int main(void)
{   
    // 1. Create subset {1, 3, 4, 8} with bitset.
    int x = 0;
    x |= (1 << 1);
    x |= (1 << 3);
    x |= (1 << 4);
    x |= (1 << 8);
    display_bitset(x);

    // 2. Set operations.
    int y = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    int z = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int t = y | z;
    display_bitset(t);

    // 3. Iterate over all subsets of the set {0, 1,..., SET_POWER - 1}.
    const int SET_POWER = 3;
    cout << endl;
    for (int a = 0; a < (1 << SET_POWER); ++a)
        display_bitset(a);

    // 4. Iterate over all subsets of the set {0, 1,..., SET_POWER - 1} having SUBSET_POWER elements.
    const int SUBSET_POWER = 2;
    cout << endl;
    for (int b = 0; b < (1 << SET_POWER); ++b)
        if (__builtin_popcount(b) == SUBSET_POWER)
            display_bitset(b);

    // 5. Iterate over all subsets of the set x.
    cout << endl;
    int c = 0;
    do
    {
        display_bitset(c);
    } while ((c = (c - x) & x));

    // 6. Use bitset from C++ STL.
    bitset<10> bs;
    bs[1] = 1;
    bs[3] = 1;
    bs[4] = 1;
    bs[7] = 1;
    cout << "\nbs[4] = " << bs[4] << endl;    // 1
    cout << "bs[5] = " << bs[5] << endl;      // 0
    cout << "Bitset power is " << bs.count() << endl;

    return 0;
}

void display_bitset(int bitset)
{
    cout << "\nThe power of the set is " << __builtin_popcount(bitset) << endl;
    if (__builtin_popcount(bitset) > 0)
    {
        cout << "{";
        for (size_t i = 0; i < sizeof(int) * CHAR_BIT; ++i)
            if (bitset & (1 << i))
                cout << i << ", ";
        cout << "\b\b}\n";        
    }
    else
        cout << "{<empty set>}\n";
}

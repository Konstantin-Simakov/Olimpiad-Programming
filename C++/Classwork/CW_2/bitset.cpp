// bitset.cpp
// Presentation of sets with bitwise operations.
#include <iostream>
#include <bitset>
#include <climits>
using namespace std;

void display_bitset(int x);
void display_bitset(const bitset<10> & bs);

int main(void)
{   
    // 1. Create set {1, 3, 4, 8} with bitset.
    int x = 0;
    x |= (1 << 1);
    x |= (1 << 3);
    x |= (1 << 4);
    x |= (1 << 8);
    display_bitset(x);

    // 2. Set operations.
    int y = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    cout << "\nSource set y:\n";
    display_bitset(y);
    int z = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    cout << "Source set z:\n";
    display_bitset(z);
    int t = y | z;
    display_bitset(t);
    t = y & z;
    display_bitset(t);
    t = ~y;
    display_bitset(t);
    t = y & ~z;
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
        c = (c - x) & x;
    } while (c);

    // 6. Use bitset from C++ STL.
    bitset<10> bs;
    bs[1] = 1;
    bs[3] = 1;
    bs[4] = 1;
    bs[7] = 1;
    cout << "\nbs[4] = " << bs[4] << endl;    // 1
    cout << "bs[5] = " << bs[5] << endl;      // 0
    display_bitset(bs);

    // 7. Use bitwise operations with bitset from C++ STL.
    bitset<10> ba, bb;
    ba[2] = 1;
    ba[3] = 1;
    ba[4] = 1;
    bb[2] = 1;
    bb[5] = 1;
    bitset<10> bc = ba & bb;
    bitset<10> bd = ba | bb;
    display_bitset(ba);
    display_bitset(bb);
    display_bitset(bc);
    display_bitset(bd);

    return 0;
}

void display_bitset(int bitset)
{
    cout << "The power of the set is " << __builtin_popcount(bitset) << endl;
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
    cout << endl;
}

void display_bitset(const bitset<10> & bs)
{
    cout << "The power of the set is " << bs.count() << endl;
    if (bs.count() > 0)
    {
        cout << "{";
        for (int i = 0; i < 10; ++i)
            if (bs[i])
                cout << i << ", ";
        cout << "\b\b}\n";

    }
    else
        cout << "{<empty set>}\n";
    cout << endl;
}

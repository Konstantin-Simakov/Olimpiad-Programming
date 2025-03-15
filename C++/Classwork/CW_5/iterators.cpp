// iterators.cpp
// Demonstrate iterators and ranges.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<int> & vi);

int main(void)
{
    vector<int> vi = {5, 2, 3, 1, 2, 5, 7, 1};
    cout << "Source vector:\n";
    display(vi);

    std::sort(vi.begin(), vi.end());
    cout << "\nSorted vector by ascending order:\n";
    display(vi);

    std::reverse(vi.begin(), vi.end());
    cout << "\nReversed vector:\n";
    display(vi);

    std::random_shuffle(vi.begin(), vi.end());
    cout << "\nRandom shuffled vector:\n";
    display(vi);

    cout << "\nThe first element of the vector is " << *vi.begin() << endl;

    std::sort(vi.begin(), vi.end());
    cout << "\nSorted vector by ascending order again:\n";
    display(vi);
    // Continiously a vector must be sorted.
    auto iter_low = std::lower_bound(vi.begin(), vi.end(), 5);
    auto iter_up = std::upper_bound(vi.begin(), vi.end(), 5);
    cout << "iter_low = " << *iter_low << ", iter_up = " << *iter_up << endl;
    // Display this subrange.
    cout << "According subrange:\n";
    while (iter_low <= iter_up)
        cout << *iter_low++ << ' ';
    cout << endl;

    return 0;
}

void display(const vector<int> & vi)
{
    for (auto x: vi)
        cout << x << ' ';
    cout << endl;
}

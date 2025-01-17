// unique_elements.cpp
// The program check that all elements in the array are unique.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_unique(const vector<int> & vec, int n);
bool is_unique_2(vector<int> & vec, int n);

int main(void)
{
    vector<int> vec = {1, 2, 3, 4, 5, 5, 7, 8};

    // 1.
    if (is_unique(vec, vec.size()))
        cout << "Array is unique.\n";
    else
        cout << "Array isn\'t unique.\n";

    // 2.
    if (is_unique_2(vec, vec.size()))
        cout << "Array is unique.\n";
    else
        cout << "Array isn\'t unique.\n";

    return 0;
}

bool is_unique(const vector<int> & vec, int n)
{
    // Compare all possible pairs of elements in the array.
    bool all_is_unique = true;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (vec[i] == vec[j])
            {
                all_is_unique = false;
                break;
            }            
        }
        if (!all_is_unique)
            break;
    }

    return all_is_unique;
}

bool is_unique_2(vector<int> & vec, int n)
{
    // Firstly sort the array for O(n * log(n)).
    // Auxilary memory: O(n).
    std::sort(vec.begin(), vec.end());

    // Then search non-unique elements for O(n) (search by contradiction).
    bool all_is_unique = true;
    for (int i = 0; i < n - 1; ++i)
        if (vec[i] == vec[i + 1])
        {
            all_is_unique = false;
            break;
        }

    return all_is_unique;
}

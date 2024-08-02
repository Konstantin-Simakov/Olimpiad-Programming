// subset_generation.cpp
// Recursive algorithm for generating numerical subsets.
#include <iostream>
#include <vector>
using namespace std;

const int N = 3;            // Max element in the set.

// Launch it with k = 1, N > k.
void search(int k, vector<int> & subset);
void display(const vector<int> & subset);

int main(void)
{
    vector<int> subset;     // Preserves subsets across each recursive function call.

    search(1, subset);

    return 0;
}

void search(int k, vector<int> & subset)
{
    if (k >= N + 1)
    {
        // Process the subset.
        display(subset);
    }
    else
    {
        // Include k in the subset.
        subset.push_back(k);
        search(k + 1, subset);

        // Exclude k from the subset.
        subset.pop_back();
        search(k + 1, subset);
    }
}

void display(const vector<int> & subset)
{
    if (subset.size() > 0)
    {
        cout << "{";
        for (const auto & item: subset)
            cout << item << ", ";
        cout << "\b\b}\n";        
    }
    else
        cout << "{<emtpy set>}\n";
}

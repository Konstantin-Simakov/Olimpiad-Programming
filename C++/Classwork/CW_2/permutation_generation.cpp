// permutation_generation.cpp
// Generation of permutations with recursive algorithm.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3;                // Max number in the set.

void search(vector<int> & permutation, bool chosen[]);      // First version.
void search_2(vector<int> & permutation);                   // Second version.
void display(const vector<int> & permutation);

int main(void)
{
    vector<int> permutation;
    bool chosen[N + 1];        // Here we need exactly (n + 1) elements, since the array is processed from 1 (by index).

    search(permutation, chosen);
    cout << endl;
    search_2(permutation);

    return 0;
}

void search(vector<int> & permutation, bool chosen[])
{
    if (permutation.size() == N)
    {
        // Process the permutation.
        display(permutation);
    }
    else
    {
        for (int i = 1; i <= N; ++i)
        {
            if (chosen[i])        // i is already in a permutation,
                continue;         // so skip it.
            else
            {
                // Add i in a permutation.
                chosen[i] = true;
                permutation.push_back(i);
                search(permutation, chosen);

                // Delete i from the permutation.
                chosen[i] = false;
                permutation.pop_back();
            }
        }
    }
}

void search_2(vector<int> & permutation)
{
    // Set the first permutation in lexicographical order.
    for (int i = 1; i <= N; ++i)
        permutation.push_back(i);

    // Own algorithm.
    do
    {
        display(permutation);
    } while (next_permutation(permutation.begin(), permutation.end()));

}

void display(const vector<int> & permutation)
{
    cout << "(";
    for (const auto & item: permutation)
        cout << item << ", ";
    cout << "\b\b)\n";        
}

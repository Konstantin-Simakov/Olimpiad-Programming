// sets.cpp
// Demonstrates working with sets in C++.
#include <iostream>
#include <set>
using namespace std;

void display(const std::set<int> & set);

int main(void)
{
    std::set<int> set;
    set.insert(3);
    set.insert(3);      // Repeat adding.
    set.insert(3);      // Repeat adding.
    set.insert(2);
    set.insert(5);
    cout << "The set:\n";
    display(set);
    cout << "The element 3 is " << (set.count(3) ? "" : "not ") << "in the set.\n";
    cout << "The number of element 3 is " << set.count(3) << endl;
    cout << "The element 4 is " << (set.count(4) ? "" : "not ") << "in the set.\n";

    set.erase(3);
    set.erase(3);       // Repeat deleting.
    set.insert(4);
    cout << "\nThe set now:\n";
    cout << "The element 3 is " << (set.count(3) ? "" : "not ") << "in the set.\n";
    cout << "The element 4 is " << (set.count(4) ? "" : "not ") << "in the set.\n";

    // Alternative search for an element in a set (recommended form).
    if (set.find(6) != set.end())
        cout << "The element 6 is in the set.\n";
    else
        cout << "The element 6 is not in the set.\n";

    return 0;
}

void display(const std::set<int> & set)
{
    // Set can be printed only with for-loop-range 
    // because [] operator is forbiden for one.
    for (auto item: set)
        cout << item << ' ';
    cout << endl;
}

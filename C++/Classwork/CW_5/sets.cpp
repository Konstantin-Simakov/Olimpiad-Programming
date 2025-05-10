// sets.cpp
// Demonstrate working with sets in C++.
#include <iostream>
#include <set>          // For set and multiset STL classes.
using namespace std;

void display(const std::set<int> & set);
void display(const std::multiset<int> & mset);

int main(void)
{
    std::set<int> set;  // All element are unique in regular set.
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
    display(set);
    cout << "The element 3 is " << (set.count(3) ? "" : "not ") << "in the set.\n";
    cout << "The element 4 is " << (set.count(4) ? "" : "not ") << "in the set.\n";

    // Alternative search for an element in a set (recommended form).
    if (set.find(6) != set.end())
        cout << "The element 6 is in the set.\n";
    else
        cout << "The element 6 is not in the set.\n";

    // Set are ordered, so it could be find min and max elements in it.
    std::set<int> set_2 = {-2, 3, 5};
    
    cout << "\nNew set:\n";
    display(set_2);
    auto first_elem = set_2.begin();
    auto last_elem = set_2.end(); --last_elem;
    cout << "The min element of set_2 is " << *first_elem << endl;
    cout << "The max element of set_2 is " << *last_elem << endl;
    cout << "The lower bound of 3 is " << *set_2.lower_bound(3) << endl;    // 3
    cout << "The upper bound of 3 is " << *set_2.upper_bound(3) << endl;    // 5

    std::multiset<int> mset;    // Not all elements need to be unique.
    mset.insert(5);
    mset.insert(5);
    mset.insert(5);
    cout << "\nThe multiset:\n";
    display(mset);
    cout << "The number of fives is " << mset.count(5) << endl;     // 3
    
    mset.erase(mset.find(5));
    cout << "Now the number of fives is " << mset.count(5) << endl; // 2

    mset.erase(5);         
    cout << "Now the number of fives is " << mset.count(5) << endl; // 0

    return 0;
}

void display(const std::set<int> & set)
{
    // Set can be printed only with for-loop-range 
    // because [] operator is forbiden for one.
/*    
    for (auto item: set)
        cout << item << ' ';
    cout << endl;
*/    
    for (auto iter = set.begin(); iter != set.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
    
}

void display(const std::multiset<int> & mset)
{
    // Set can be printed only with for-loop-range 
    // because [] operator is forbiden for one.
    for (auto item: mset)
        cout << item << ' ';
    cout << endl;
}

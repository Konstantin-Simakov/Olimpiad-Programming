// policy_based.cpp
// The program demonstrates policy-based data structure (in particular indexed set).
#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update> Indexed_Set;

void display(const Indexed_Set & i_set);

int main(void)
{
    Indexed_Set i_set;
    i_set.insert(2);
    i_set.insert(7);
    i_set.insert(3);
    i_set.insert(9);

    cout << "Here is the indexed (and sorted) set:\n";
    display(i_set);

    // Search by index.
    auto x = i_set.find_by_order(2);
    cout << "\nThe element by index 2 is " << *x << endl;  // 7

    // Search by value.
    cout << "\nThe index by element 7 is (must be) " << i_set.order_of_key(7) << endl;     // 2
    // The assumed index of a non-existent value in the indexed set.
    cout << "The index by element 6 is (must be) " << i_set.order_of_key(6) << endl;       // 2
    cout << "The index by element 8 is (must be) " << i_set.order_of_key(8) << endl;       // 3

    return 0;
}

void display(const Indexed_Set & i_set)
{
    // Or:
/*    
    for (auto iter = i_set.begin(); iter != i_set.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
*/
    for (const auto & item: i_set)
        cout << item << ' ';
    cout << endl;
}

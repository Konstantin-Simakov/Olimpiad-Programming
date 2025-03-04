// vectors.cpp
// Remind about vectors.
#include <iostream>
#include <vector>
using namespace std;

const int SIZE = 5;

void display(const int arr[], int n);
void display(const vector<int> & vec);

int main(void)
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    cout << "Content of \'arr\':\n";
    display(arr, SIZE);

    // Initially the vector is empty with size equalled 0, 
    // than it's initialized with push_back() method.
    vector<int> vec;    
    vec.push_back(3);
    vec.push_back(2);
    vec.push_back(5);
    cout << "\nContent of \'vec\':\n";
    display(vec);

    // List elements of a vector.
    vector<int> vec_2 = {2, 4, 2, 5, 1};
    cout << "\nContent of \'vec_2\':\n";
    display(vec_2);

    // Use other constructors of the vector class.
    vector<int> vec_3(8);       // Size is 8, initial value is 0 for each element.
    cout << "\nContent of \'vec_3\':\n";
    display(vec_3);
    vector<int> vec_4(8, 2);    // Size is 8, initial value is 2 for each element.
    cout << "\nContent of \'vec_4\':\n";
    display(vec_4);

    // Use back() and pop_back() methods of the vector class.
    // Time complexity of pop_back() and push_back() methods: O(1), i.e. very fast.
    vector<int> vec_5 = {2, 1, 2, 5, 1};
    cout << "\nContent of \'vec_5\':\n";
    display(vec_5);
    // vec_5 is unchanged after the next code line.
    cout << "The last element of vec_5 is " << vec_5.back() << endl;
    // Delete the last element without any message.
    vec_5.pop_back();
    // Check it with back() method, value has to be another.
    cout << "After deleting the last element of vec_5 a new last element is " << vec_5.back() << endl;

    return 0;
}

void display(const int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << endl;
}

void display(const vector<int> & vec)
{
    for (unsigned i = 0; i < vec.size(); ++i)
        cout << vec[i] << ' ';
    cout << endl;

    /*
    for (auto x: vec)
        cout << x << ' ';
    cout << endl;
    */
}

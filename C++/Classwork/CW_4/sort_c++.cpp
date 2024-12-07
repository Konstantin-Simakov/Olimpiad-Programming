// sort_c++.cpp
// Sorting in C++ instead of user sorting algorithm.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void display(const vector<int> & vec);
void display(int * start, const int * end);
void display(const string & str);

int main(void)
{
    // Sorting the vector.
    vector<int> vec = {4, -2, 5, 3, 5, 8, 3};
    cout << "Source vector:\n";
    display(vec);

    cout << "\nSorted vector by ascending:\n";
    std::sort(vec.begin(), vec.end());
    display(vec);

    cout << "\nSorted vector by descending:\n";
    std::random_shuffle(vec.begin(), vec.end());
    std::sort(vec.rbegin(), vec.rend());
    display(vec);

    // Sorting the array.
    const int N = 7;
    int arr[N] = {4, -2, 5, 3, 5, 8, 3};
    cout << "\nSource array:\n";
    display(arr, arr + N);

    cout << "\nSorted array by ascending:\n";
    std::sort(arr, arr + N);
    display(arr, arr + N);

    cout << "\nSorted array by descending:\n";
    std::random_shuffle(arr, arr + N);
    std::sort(std::rbegin(arr), std::rend(arr));
    display(arr, arr + N);

    // Soring the string.
    string str = "monkey";
    cout << "\nSource string:\n";
    display(str);

    cout << "\nSorted string by alphabetical:\n";
    std::sort(str.begin(), str.end());
    display(str);

    cout << "\nSorted string by reverse alphabetical:\n";
    std::random_shuffle(str.begin(), str.end());
    std::sort(str.rbegin(), str.rend());
    display(str);    

    return 0;
}

void display(const vector<int> & vec)
{
    for (const auto & item: vec)
        cout << item << ' ';
    cout << endl;
}

void display(int * start, const int * end)
{
    while (start != end)
        cout << *start++ << ' ';
    cout << endl;
}

void display(const string & str)
{
    cout << str << endl;
}

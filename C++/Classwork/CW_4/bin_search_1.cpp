// bin_search_1.cpp
// The first binary search method for an array.
#include <iostream>
using namespace std;

// x is the desired element in the array.
int bin_search(const int arr[], int n, int x);

int main(void)
{
    const int SIZE = 5;
    int arr[SIZE] = {-1, 2, 3, 4, 5};   // The array must be sorted previously.
    int value = 3;                      // Element to search.

    int index = bin_search(arr, SIZE, value);
    if (-1 == index)
        cout << "Element " << value << " is not found in the array.\n";
    else
        cout << "Element " << value << " is found in the array by index " << index << ".\n"; 

    return 0;
}

int bin_search(const int arr[], int n, int x)
{
    int a = 0, b = n - 1;       // The initial range of search. 
    int i = -1;                 // The index of the desired element; -1 if element isn't found.
    while (a <= b)
    {
        int k = (a + b) / 2;
        if (arr[k] == x)
        {
            i = k;
            break;
        }
        else if (arr[k] < x)
            a = k + 1;
        else
            b = k - 1;
    }

    return i;
}

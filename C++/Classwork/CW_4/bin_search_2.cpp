// bin_search_2.cpp
// The second binary search method for an array.
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
    int k = 0;
    // b is the length of the current jump.
    for (int b = n / 2; b >= 1; b /= 2)
    {
        // Inside 'while' loop executes not more than 2 times.
        while (k + b < n && arr[k + b] <= x)
            k += b;
    }
    if (arr[k] != x)
        k = -1;         // Element x is not found in the array.

    return k;
}

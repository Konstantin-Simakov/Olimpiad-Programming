// search_element.cpp
// The program searches for an element in the array.
#include <iostream>
using namespace std;

bool search_element(int item, const int arr[], int n);
bool search_element_2(int item, const int arr[], int n);
bool search_element_3(int item, int arr[], int n);

int main(void)
{
    const int NUMS = 5;
    int arr[NUMS + 1] = {1, 2, 3, 4, 5};
    int item = 6;

    cout << "The element " << item << " is " << (search_element(item, arr, NUMS) ? "" : "not ")
         << "in the array.\n";
    cout << "The element " << item << " is " << (search_element_2(item, arr, NUMS) ? "" : "not ")
         << "in the array.\n";
    cout << "The element " << item << " is " << (search_element_3(item, arr, NUMS) ? "" : "not ")
         << "in the array.\n";

    return 0;
}

bool search_element(int item, const int arr[], int n)
{
    bool is_found = false;
    for (int i = 0; i < n; ++i)
        if (item == arr[i])
            is_found = true;

    return is_found;
}

bool search_element_2(int item, const int arr[], int n)
{
    bool is_found = false;
    for (int i = 0; i < n; ++i)
    {
        if (item == arr[i])
        {
            is_found = true;
            break;
        }
    }

    return is_found;
}

bool search_element_3(int item, int arr[], int n)
{
    int i;
    bool is_found = false;

    arr[n] = item;
    for (i = 0; arr[i] != item; ++i)
        continue;

    if (i < n)
        is_found = true;

    return is_found;
}

// max_subarray.cpp
// Search for the max sum of a subarray in the array.
#include <iostream>
#include <algorithm>        // For std::max()
#include <climits>          // For INT_MIN
using namespace std;

int max_subarray_1(const int arr[], int n);
int max_subarray_2(const int arr[], int n);
int max_subarray_3(const int arr[], int n);
void print_subarray(const int * start, const int * end);

int main(void)
{
    const int N = 8;
    int arr[N] = {-1, 2, -4, -3, 5, 8, -5, 6};

    cout << max_subarray_1(arr, N) << endl;
    cout << max_subarray_2(arr, N) << endl;
    cout << max_subarray_3(arr, N) << endl;

    return 0;
}

int max_subarray_1(const int arr[], int n)
{
    int best = INT_MIN;
    int left_index, right_index;                // Indices of the max subarray.
    
    for (int a = 0; a < n; ++a)                 // Left side of a subarray.
    {
        for (int b = a; b < n; ++b)             // Rigth side of a subarray.
        {
            // Calculates the max sum of the subarray.
            int sum = 0;                    
            for (int k = a; k <= b; ++k)
                sum += arr[k];
            if (sum > best)
            {
                best = sum;
                left_index = a;
                right_index = b;
            }
        }
    }
    print_subarray(arr + left_index, arr + right_index);

    return best;
}

int max_subarray_2(const int arr[], int n)
{
    int best = INT_MIN;
    for (int a = 0; a < n; ++a)                 // Left side of a subarray.
    {
        // Calculate the max sum of a subarray while 
        // shifting the right boundary of the subarray.
        int sum = 0;
        for (int b = a; b < n; ++b)
        {
            sum += arr[b];
            best = std::max(best, sum);
        }
    }

    return best;
}

int max_subarray_3(const int arr[], int n)
{
    int best = INT_MIN, sum = 0;
    for (int k = 0; k < n; ++k)
    {
        sum = std::max(arr[k], sum + arr[k]);
        best = std::max(best, sum);
    }

    return best;
}

void print_subarray(const int * start, const int * end)
{
    while (start != end)
        cout << *start++ << ' ';
    cout << *start << endl;
}

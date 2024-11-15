// sort.cpp
// Different sorting algorithms in acsending order.
#include <iostream>
#include <vector>
#include <algorithm>        // For std::random_shuffle()
using namespace std;

void bubble_sort(vector<int> & data);
void bubble_sort_2(vector<int> & data);     // Improved version.
void swap_int(int & a, int & b);            // Swap two integers.
void display(const vector<int> & data);

int main(void)
{
    vector<int> data = {1, 2, 2, 6, 3, 5, 9, 8};

    cout << "Source array:\n";
    display(data);

    bubble_sort(data);
    cout << "\nSorted data by bubble sorting:\n";
    display(data);

    srand(time(0));
    std::random_shuffle(data.begin(), data.end());
    cout << "Shuffle the data:\n";
    display(data);

    bubble_sort_2(data);
    cout << "\nAgain sorted data by improved bubble sorting:\n";
    display(data);

    return 0;
}

void bubble_sort(vector<int> & data)
{
    const int SIZE = data.size();
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE - 1; ++j)
        {
            if (data[j] > data[j + 1])
                swap(data[j], data[j + 1]);
        }
    }
}

void bubble_sort_2(vector<int> & data)
{
    const int SIZE = data.size();
    for (int i = 0; i < SIZE; ++i)
    {
        bool did_swap = false;
        for (int j = 0; j < SIZE - 1 - i; ++j)
        {
            if (data[j] > data[j + 1])
            {
                swap_int(data[j], data[j + 1]);
                did_swap = true;
            }
        }
        if (!did_swap)
            break;
    }
}

void display(const vector<int> & data)
{
    const int SIZE = data.size();
    for (int i = 0; i < SIZE; ++i)
        cout << data[i] << ' ';
    cout << endl;
}

void swap_int(int & a, int & b)
{
    a += b;
    b = a - b;
    a -= b;
}

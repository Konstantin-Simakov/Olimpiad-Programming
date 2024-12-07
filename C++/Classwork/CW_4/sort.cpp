// sort.cpp
// Different sorting algorithms in acsending order.
#include <iostream>
#include <vector>
#include <algorithm>        // For std::random_shuffle()
using namespace std;

void bubble_sort(vector<int> & data);
void bubble_sort_2(vector<int> & data);                 // Improved version.
void merge_sort(vector<int> & data, int l, int r);      // l -- left index, r -- rigth index of the subarray.
void merge(vector<int> & data, int l, int m, int r);    // l -- left index, r -- rigth index of the subarray.
void counting_sort(char * str);                         // Sort a string in alphabetic order; only for C strings.
void swap_int(int & a, int & b);                        // Swap two integers.
void display(const vector<int> & data);

int main(void)
{
    vector<int> data = {1, -2, 2, 6, 3, 5, 9, 8, -1};
    cout << "Source data:\n";
    display(data);

    bubble_sort(data);
    cout << "Sorted data by bubble sorting:\n";
    display(data);

    srand(time(0));
    std::random_shuffle(data.begin(), data.end());
    cout << "\nShuffle the data:\n";
    display(data);

    bubble_sort_2(data);
    cout << "Again sorted data by improved bubble sorting:\n";
    display(data);

    std::random_shuffle(data.begin(), data.end());
    cout << "\nShuffle the data again:\n";
    display(data);

    merge_sort(data, 0, data.size() - 1);
    cout << "Again sorted data by merge sorting:\n";
    display(data);

    // Sort the string by counting sorting in alphabetical order.
    char str[] = "Hello, dear friend!";
    cout << "\nSource string: " << str << endl;
    counting_sort(str);
    cout << "Sorted string: " << str << endl;

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
                std::swap(data[j], data[j + 1]);
        }
    }
}

void bubble_sort_2(vector<int> & data)
{
    const int SIZE = data.size();
    for (int i = 0; i < SIZE - 1; ++i)
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

void merge_sort(vector<int> & data, int l, int r)
{
    // While l != r, i.e. until length of every subbarray is 1, 
    // divide the subarray again 
    // and then merge every subarray after comparing them
    // into a single common array.
    if (l < r)
    {
        int m = (r + l) / 2;
        merge_sort(data, l, m);
        merge_sort(data, m + 1, r);
        merge(data, l, m, r);
    }
}

void merge(vector<int> & data, int l, int m, int r)
{
    int i, j, k;
    int size_l = (m - l) + 1;
    int size_r = r - m;
    vector<int> temp_l(size_l), temp_r(size_r);

    // Construct a left subarray.
    for (i = 0; i < size_l; ++i)
        temp_l[i] = data[l + i];
    // Construct a right subarray.
    for (j = 0; j < size_r; ++j)
        temp_r[j] = data[(m + 1) + j];

    i = 0;
    j = 0;
    k = l;
    // Initialize the "data" array until elements of any subarray is ended.
    while (i < size_l && j < size_r)
    {
        if (temp_l[i] <= temp_r[j])
        {
            data[k] = temp_l[i];
            ++i;
        }
        else
        {
            data[k] = temp_r[j];
            ++j;
        }
        ++k;
    }

    // Add the remainder from a remain subarray to the "data" array as is.
    while (i < size_l)
    {
        data[k] = temp_l[i];
        ++i;
        ++k;
    }
    while (j < size_r)
    {
        data[k] = temp_r[j];
        ++j;
        ++k;
    }
}

void counting_sort(char * str)
{ 
    const int RANGE = 256;      // The number of characters according to extended ASCII code.
    int cnt[RANGE] = {0};       // Auxiliary array for counting the elements of the original array.
    int i, j, c;
    
    // Store count of an each input character.
    for(i = 0; str[i]; ++i)
        ++cnt[(int) str[i]];
    
    // Sort string by alphabetic order.
    for (i = 0, j = 0; j < RANGE; ++j)
        for (c = 0; c < cnt[j]; ++c)
            str[i++] = j;       // Place the character 'j' into the string 'str'.
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
    // int temp = a;
    // a = b;
    // b = temp;

    a += b;
    b = a - b;
    a -= b;
}

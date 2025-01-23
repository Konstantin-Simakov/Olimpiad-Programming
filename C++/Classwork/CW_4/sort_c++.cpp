// sort_c++.cpp
// Sorting in C++ instead of user sorting algorithm.
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

class Point {
    friend ostream & operator<<(ostream & os, const Point & p);
private:
    int x;
    int y;
public:
    Point(int a, int b): x(a), y(b) {}

    bool operator<(const Point & p)
    {
        if (x == p.x)
            return y < p.y;
        else
            return x < p.x;
    }
};

void display(const vector<int> & vec);
void display(const vector<pair<int, int>> & vp);
void display(const vector<tuple<int, int, int>> & vt);
void display(const vector<Point> & vpt);
void display(const int * start, const int * const end);
void display(const string & str);
void display(const vector<string> & vs);
bool comp(const string & s1, const string & s2);

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
    srand(time(0));
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
    // std::sort(arr, arr + N, [](int a, int b) {return a > b;});      // Using lambda expression.
    // std::sort(arr, arr + N, std::greater<int>());                   // Using predicat (boolean function).
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

    // Comparison operators.
    vector<pair<int, int>> vp;
    vp.push_back({1, 5});  
    vp.push_back({2, 3});  
    vp.push_back({1, 2});
    cout << "\nSource vector of pairs:\n";
    display(vp);

    std::sort(vp.begin(), vp.end());
    cout << "\nSorted vector of pairs:\n";
    display(vp);

    vector<tuple<int, int, int>> vt;
    vt.push_back(std::make_tuple(2, 1, 4));
    vt.push_back(std::make_tuple(1, 5, 3));
    vt.push_back(std::make_tuple(2, 1, 3));
    cout << "\nSource vector of tuples:\n";
    display(vt);

    std::sort(vt.begin(), vt.end());
    cout << "\nSorted vector of tuples:\n";
    display(vt);

    vector<Point> vpt;
    vpt.push_back(Point(2, 5));
    vpt.push_back(Point(2, 7));
    vpt.push_back(Point(2, 3));
    vpt.push_back(Point(1, 3));
    cout << "\nSource vector of points:\n";
    display(vpt);

    std::sort(vpt.begin(), vpt.end());      // Use operator<() operator (method).
    cout << "\nSorted vector of points:\n";
    display(vpt);

    // Comparison functions.
    vector<string> vs;
    vs.push_back("some string");
    vs.push_back("some a bit string");
    vs.push_back("big strings");
    vs.push_back("a big and big string");
    cout << "\nSource vector of strings:\n";
    display(vs);

    std::sort(vs.begin(), vs.end(), comp);
    cout << "\nSorted vector of strings:\n";
    display(vs);

    return 0;
}

void display(const vector<string> & vs)
{
    for (const auto & item: vs)
        cout << item << endl;
}

bool comp(const string & s1, const string & s2)
{
    if (s1.size() == s2.size())
        return s1 < s2;         // Compare in lexicographical order.
    else
        return s1.size() < s2.size();
}

void display(const vector<Point> & vpt)
{
    for (const auto & item: vpt)
        cout << item << endl;
}

ostream & operator<<(ostream & os, const Point & p)
{
    os << p.x << ' ' << p.y;

    return os;
}

void display(const vector<int> & vec)
{
    for (auto item: vec)
        cout << item << ' ';
    cout << endl;
}

void display(const vector<pair<int, int>> & vp)
{
    for (const auto & item: vp)
        cout << item.first << ' ' << item.second << endl;
}

void display(const vector<tuple<int, int, int>> & vt)
{
    for (const auto & item: vt)
        cout << std::get<0>(item) << ' ' << std::get<1>(item) << ' ' << std::get<2>(item) << endl;
}

void display(const int * start, const int * const end)
{
    while (start < end)
        cout << *start++ << ' ';
    cout << endl;
}

void display(const string & str)
{
    cout << str << endl;
}

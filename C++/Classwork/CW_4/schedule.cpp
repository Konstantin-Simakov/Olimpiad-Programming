// schedule.cpp
// The task is to create a schedule 
// that includes as many events as possible.
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(const pair<int, int> & p1, const pair<int, int> & p2);
void greedy_algorithm(vector<pair<int, int>> & res, const vector<pair<int, int>> & events);
void display(const vector<pair<int, int>> & vp);

int main(void)
{
    vector<pair<int, int>> events = {
        {0, 7},         // 1.
        {9, 12},        // 2. 
        {8, 12},        // 3.
        {14, 18},       // 4.
    };
    vector<pair<int, int>> res;

    std::sort(events.begin(), events.end(), comp);
    cout << "Source sorted data:\n";
    display(events);    // Just checking.
        
    greedy_algorithm(res, events);
    cout << "\nResults:\n";
    display(res);

    return 0;
}

bool comp(const pair<int, int> & p1, const pair<int, int> & p2)
{
    if (p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}

void greedy_algorithm(vector<pair<int, int>> & res, const vector<pair<int, int>> & events)
{
    // Vector of pairs 'vp' has already sorted in ascending order 
    // by the second element in a pair that is event finish time.
    res.push_back(events[0]);
    int j = 0;
    for (unsigned i = 0; i < events.size(); ++i)
    {
        if (res[j].second < events[i].first)
        {
            res.push_back(events[i]);
            ++j;
        }
    }
}

void display(const vector<pair<int, int>> & vp)
{
    for (const auto & item: vp)
        cout << "Start time: " << item.first << ", finish time: " << item.second << endl;
}

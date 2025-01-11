// sweeping_line.cpp
// Sweeping line algorithm.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int sweeping_line(const vector<pair<int, bool>> & times);
void init(vector<pair<int, bool>> & times, const vector<pair<int, int>> & clients);

int main(void)
{
    // First item is client arrival time,
    // second item is client departure time.
    vector<pair<int, int>> clients = {
        {12, 20},       // Client A.
        {7, 14},        // Client B.
        {18, 22},       // Client C. 
        {5, 16},        // Client D.
    };
    vector<pair<int, bool>> times(2 * clients.size());  // Auxilary memory: O(2n) => O(n).
    init(times, clients);

    // The algorithm itself.
    std::sort(times.begin(), times.end());
    int max_clients = sweeping_line(times);

    // Output results.
    cout << "The max number of clients in the restaurant\n"
         << "at the same time during the day is " << max_clients << endl;

    return 0;
}

void init(vector<pair<int, bool>> & times, const vector<pair<int, int>> & clients)
{
    int j = 0;
    for (unsigned i = 0; i < clients.size(); ++i)
    {
        times[j].first = clients[i].first;
        times[j].second = true;
        ++j;

        times[j].first = clients[i].second;
        times[j].second = false;
        ++j;        
    }
}

int sweeping_line(const vector<pair<int, bool>> & times)
{
    int ctr = 0;
    int max = 0;
    for (unsigned i = 0; i < times.size(); ++i)
    {
        if (times[i].second)
            ++ctr;
        else
            --ctr; 

        if (max < ctr)
            max = ctr;
    }

    return max;
}

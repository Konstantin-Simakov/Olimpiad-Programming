// deadlines.cpp
// Solving the problem of works and deadlines. 
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <iomanip>
using namespace std;

const int TIME_LIMIT = 12;

int count_scores(const vector<tuple<char, int, int>> & works);
void display(const vector<tuple<char, int, int>> & vt);
bool comp(const tuple<char, int, int> & t1, const tuple<char, int, int> & t2);

int main(void)
{
    // The first value is a name of a work, 
    // the second value is its duration,
    // the third value is its deadline.
    vector<tuple<char, int, int>> works = {
        {'A', 4, 2},     // A.
        {'B', 3, 10},    // B.
        {'C', 2, 8},     // C.
        {'D', 4, 15},    // D.
    };

    // Sort the works by duration in ascending order to optimal planning.
    std::sort(works.begin(), works.end(), comp);
    cout << "Data after sorting:\n";
    display(works);     // Just checking.
    // Count and display scores of every completed work and count total score.
    int total_score = count_scores(works);
    cout << "Total score is " << total_score << endl;

    return 0;
}

int count_scores(const vector<tuple<char, int, int>> & works)
{
    int total_score = 0;        // Total customer satisfaction score.
    int total_duration = 0;     // Total work duration.

    for (unsigned i = 0; i < works.size(); ++i)
    {   
        // Score for a work.
        int work_score = std::get<2>(works[i]) - (std::get<1>(works[i]) + total_duration); 
        
        total_duration += std::get<1>(works[i]);
        if (total_duration > TIME_LIMIT)
            break;
        
        cout << "The work score " << std::get<0>(works[i]) << " is " << work_score << endl;
        total_score += work_score;
    }

    return total_score;
}

bool comp(const tuple<char, int, int> & t1, const tuple<char, int, int> & t2) 
{
    if (std::get<1>(t1) == std::get<1>(t2))
        return (std::get<2>(t1) < std::get<2>(t2));
    else
        return (std::get<1>(t1) < std::get<1>(t2));
}

void display(const vector<tuple<char, int, int>> & vt)
{
    cout << setw(15) << "Name" << setw(15) << "Duration" << setw(15) << "Deadline" << endl;
    for (const auto & item: vt)
        cout << setw(15) << std::get<0>(item) << setw(15) << std::get<1>(item) << setw(15) << std::get<2>(item) << endl;
}

// bin_search.cpp
// 
// It is necessary to perform k tasks on n machines. 
// Each machine i is assigned an integer p_i, i.e. the time of execution of one task (machine capacity). 
// In what minimum time can all tasks be processed?
//
#include <iostream>
#include <vector>
using namespace std;

int bin_search(const vector<int> & machines, int tasks);
// max_time is the current max time of task processing.
bool valid(int max_time, const vector<int> & machines, int tasks);

int main(void)
{
    // The processing time of each machine, 
    // the number of which is equal to the size of the array.
    vector<int> machines = {2, 3, 7}; 
    // The number of tasks for machines; 
    // k > size else the problem has no point.
    int tasks = 8;        

    int min_time_proc = bin_search(machines, tasks);
    cout << "The minimum time of execution all tasks is " << min_time_proc << endl;

    return 0;
}

int bin_search(const vector<int> & machines, int tasks)
{
    int upper = tasks * machines[0];    // Upper limit when valid() is true.
    int t = -1;                         // The target value of time.
    for (int b = upper; b >= 1; b /= 2)
    {
        while (!valid(t + b, machines, tasks))
            t += b;
    }

    return t + 1;                       // The minimum time when valid() is true.           
}

bool valid(int max_time, const vector<int> & machines, int tasks)
{
    bool ret_val;
    int total_tasks = 0;

    for (unsigned i = 0; i < machines.size(); ++i)
        total_tasks += max_time / machines[i];

    if (total_tasks >= tasks)
        ret_val = true;
    else
        ret_val = false;

    return ret_val;
}

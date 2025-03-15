// bin_search.cpp
// 
// It is necessary to perform k tasks on n machines. 
// Each machine i is assigned an integer p_i, i.e. the time of execution of one task (ith machine power). 
// In what minimum time can all tasks be processed?
//
#include <iostream>
#include <vector>
using namespace std;

int bin_search(const vector<int> & machines, int tasks);
// The function determines whether the current solution (deadline) is acceptable (true) or not (false);
// 'deadline' is the current deadline time for processing all tasks.
bool valid(int deadline, const vector<int> & machines, int tasks);

int main(void)
{
    // The processing time of each machine, 
    // the number of which is equal to the size of the array.
    vector<int> machines = {2, 3, 7}; 
    // The number of tasks for machines; 
    int tasks = 8;        

    int min_time_proc = bin_search(machines, tasks);
    cout << "The minimum time of execution all tasks is " << min_time_proc << endl;

    return 0;
}

int bin_search(const vector<int> & machines, int tasks)
{
    int upper = tasks * machines[0];    // Upper limit when valid() is true.
    int t = -1;                         // The target value of time.
    for (int j = upper; j >= 1; j /= 2) // j is a time jump.
    {
        // While the solution to the problem is unacceptable, 
        // look for the maximum unacceptable solution to the problem.
        while (!valid(t + j, machines, tasks))
            t += j;
    }

    // Then the next solution will be the minimum acceptable solution (optimum).
    return t + 1;                       // The minimum time when valid() is true.           
}

bool valid(int deadline, const vector<int> & machines, int tasks)
{
    bool ret_val;
    int total_tasks = 0;

    for (unsigned i = 0; i < machines.size(); ++i)
        total_tasks += deadline / machines[i];

    if (total_tasks >= tasks)
        ret_val = true;
    else
        ret_val = false;

    return ret_val;
}

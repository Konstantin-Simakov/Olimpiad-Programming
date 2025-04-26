// priority_queue.cpp
// Demonstrate priority_queue STL container.
#include <iostream>
#include <queue>
using namespace std;

void display(std::priority_queue<int> & pr_que);
void display(std::priority_queue<int, std::vector<int>, std::greater<int>> & reverse_pr_que);

int main(void)
{
    // By default this DS is sorted by descending order (from max to min).
    std::priority_queue<int> pr_que;
    pr_que.push(3);
    pr_que.push(5);
    pr_que.push(7);
    pr_que.push(2);                 // {7, 5, 3, 2}
    pr_que.pop();                   // {5, 3, 2}
    pr_que.pop();                   // {3, 2}
    pr_que.push(6);                 // {6, 3, 2}
    pr_que.pop();                   // {3, 2}
    cout << "Priority queue by descending order:\n";
    display(pr_que);

    // Now the same DS is sorted by ascending order (from min to max).
    std::priority_queue<int, std::vector<int>, std::greater<int>> reverse_pr_que;
    reverse_pr_que.push(3);
    reverse_pr_que.push(5);
    reverse_pr_que.push(7);
    reverse_pr_que.push(2);         // {2, 3, 5, 7}
    reverse_pr_que.pop();           // {3, 5, 7}
    reverse_pr_que.pop();           // {5, 7}
    reverse_pr_que.push(6);         // {5, 6, 7}
    reverse_pr_que.pop();           // {6, 7}
    cout << "\nPriority queue by ascending order:\n";
    display(reverse_pr_que);

    return 0;
}

void display(std::priority_queue<int> & pr_que)
{
    while (!pr_que.empty())
    {
        cout << pr_que.top() << ' ';            // Print the first item
        pr_que.pop();                           // Delete it
    }
    cout << endl;
}

void display(std::priority_queue<int, std::vector<int>, std::greater<int>> & reverse_pr_que)
{
    while (!reverse_pr_que.empty())
    {
        cout << reverse_pr_que.top() << ' ';    // Print the first item
        reverse_pr_que.pop();                   // Delete it
    }
    cout << endl;
}

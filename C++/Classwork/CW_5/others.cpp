// others.cpp
// Other data structures: deque, stack, queue.
#include <iostream>
#include <deque>
#include <stack>
#include <queue>
using namespace std;

void display(const deque<int> & deq);
void reverse_display(stack<int> & st);
void display(queue<int> & que);

int main(void)
{   
    // Deque.
    deque<int> deq;
    deq.push_back(5);       // {5}
    deq.push_back(2);       // {5, 2}
    deq.push_front(3);      // {3, 5, 2}
    cout << "Deque:\n";
    display(deq);
    deq.pop_back();         // {3, 5}
    deq.pop_front();        // {5}
    cout << "Now deque:\n";
    display(deq);

    // Stack.
    stack<int> st;
    st.push(2);             // {2}
    st.push(5);             // {2, 5}
    st.push(3);             // {2, 5, 3}
    cout << "\nStack in reverse order:\n";
    reverse_display(st);    // All element of the stack will be removed after it. 

    // Queue.
    queue<int> que;
    que.push(2);            // {2}
    que.push(5);            // {2, 5}
    que.push(3);            // {2, 5, 3}
    cout << "\nQueue:\n";
    cout << "The last element of the queue is " << que.back() << endl;
    display(que);           // All element of the queue will be removed after it.

    return 0;
}

void display(const deque<int> & deq)
{
    // Since deque supports begin()/end() methods, 
    // it can also be used with for-range-loop or with common for-loop
    // (according to the C++ standard).
    for (auto iter = deq.begin(); iter != deq.end(); iter++)
        cout << *iter << ' ';
    cout << endl;
}

void reverse_display(stack<int> & st)
{
    while (!st.empty())                 // While a stack is not empty.
    {
        cout << st.top() << ' ';        // Get (read) the last element of the stack.
        st.pop();                       // Remove the last elemet of the stack.
    }
    cout << endl;
}

void display(queue<int> & que)
{
    while (!que.empty())                // While a queue is not empty.
    {
        cout << que.front() << ' ';     // Get (read) the first element of the queue.
        que.pop();                      // Remove the first element of the queue.
    }
    cout << endl;
}

//  Implement Queue using stack
#include <iostream>
#include <stack>
using namespace std;
class Queue
{
public:
    stack<int> s1, s2;
    bool isEmpty();
    void enqueue(int data);
    int front();
    int dequeue();
};
bool Queue::isEmpty()
{
    if(s1.empty()){
        return true;
    }
    else{
        return false;
    }
}
void Queue ::enqueue(int data)
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(data);
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
}
int Queue::front()
{
    if (s1.empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
       return s1.top();
    }
}
int Queue::dequeue()
{
    if (s1.empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        int ans = s1.top();
        s1.pop();
        return ans;
    }
}
int main(void)
{
     Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
 
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    return 0;
}
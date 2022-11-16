// Implement Queue using stack
// #include <iostream>
// #include <stack>
// using namespace std;
// class Queue
// {
// public:
//     stack<int> s1, s2;
//     bool isEmpty();
//     bool enqueue(int data);
//     int dequeue();
//     int front();
// };
// bool Queue ::isEmpty()
// {
//     if (s1.empty())
//     {
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
// bool Queue ::enqueue(int data)
// {
//     while (!s1.empty())
//     {
//         s2.push(s1.top());
//         s1.pop();
//     }
//     s1.push(data);
//     while (!s2.empty())
//     {
//         s1.push(s2.top());
//         s2.pop();
//     }
//     return true;
// }
// int Queue ::dequeue()
// {
//     if (s1.empty())
//     {
//         cout << "Queue is empty" << endl;
//         return -1;
//     }
//     else
//     {
//         int ans = s1.top();
//         s1.pop();
//         return ans;
//     }
// }
// int Queue::front()
// {
//     if (s1.empty())
//     {
//         cout << "Queue is empty" << endl;
//         return -1;
//     }
//     else
//     {
//         return s1.top();
//     }
// }
// int main(void)
// {
//     Queue q;
//     q.enqueue(1);
//     q.enqueue(2);
//     q.enqueue(3);
//     q.enqueue(400);

//     cout << q.dequeue() << '\n';
//     cout << q.dequeue() << '\n';
//     cout << q.dequeue() << '\n';
//     cout << q.front() << '\n';
//     return 0;
// }

// Implement Queue using stack

#include <iostream>
#include <stack>
using namespace std;
class Queue
{
public:
    stack<int> s1, s2;
    bool isEmpty();
    bool enqueue(int data);
    int dequeue();
    int front();
};
bool Queue ::isEmpty()
{
    if (s1.empty())
    {
        cout << "Queue is empty" << endl;
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue ::enqueue(int data)
{
    s1.push(data);
    return true;
}
int Queue ::dequeue()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    int ans = s2.top();
    s2.pop();
    return ans;
}
int Queue::front()
{
    if (s2.empty())
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
    }

    return s2.top();
}
int main(void)
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(400);

    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.dequeue() << '\n';
    cout << q.front() << '\n';
    return 0;
}
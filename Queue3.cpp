// Implement circular queue using an array
#include <iostream>
using namespace std;
class Queue
{
private:
    int *arr;
    int head;
    int rear;
    int size;

public:
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        head = rear = -1;
    }
    bool isEmpty();
    bool enqueue(int data);
    int dequeue();
    int front();
    void display();
};
bool Queue ::isEmpty()
{
    if ((head == -1) && (rear == -1))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Queue ::enqueue(int data)
{
    if (isEmpty())
    {
        if ((head == -1) && (rear == -1))
        {
            head++;
            rear++;
            arr[rear] = data;
            return true;
        }
        else
        {
            rear++;
            arr[rear] = data;
            return true;
        }
    }
    else if (head == (rear + 1) % size)
    {
        cout << "Queue is overflowed" << endl;
        return false;
    }
    else
    {
        rear = (rear + 1) % size;
        arr[rear] = data;
        return true;
    }
}
int Queue ::dequeue()
{
    if ((head == -1) && (rear == -1))
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
    {
        int ans = arr[head];
        head++;
        return ans;
    }
}
int Queue ::front()
{
    if ((head == -1) && (rear == -1))
    {
        cout << "Queue is Empty" << endl;
        return -1;
    }
    else
    {
        return arr[head];
    }
}
void Queue ::display()
{
    int i = head;
    while (i != rear)
    {
        cout << arr[i] << "\t";
        i = (i + 1) % size;
    }
    cout << arr[i] << endl;
}
int main(void)
{
    Queue q(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    cout << "Elements of the Queue are => " << endl;
    q.display();
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    q.enqueue(35);
    q.enqueue(40);
    cout << "Elements of the Queue element => " << endl;
    q.display();
    q.enqueue(45);
    q.enqueue(50);
    return 0;
}
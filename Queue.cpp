// A queue is a data structure for storing data (simillar to linked list and stacks).Queue is a linear data structure which is open at both ends and the operations are performed at the both ends.
// A queue is ordered list  in which first element is inserted at the one end (rear) and deletion are done at the one end (front).The first element to be inserted is the first one to be deleted
// In queue operations are performed in FIFO(First In First Out) or LILO (Last In Last Out) manner.

// Insertion is known as EnQueue.
// Deletion is known as DeQueue.
// DeQueueing an empty queue is called underflow and EnQueuing an element in a full queue is called overflow

// The following operations make a queue an ADT. The insertion and deletion in the queue must follow the FIFO scheme.
// EnQueue => Inserting a data.
// DeQueue => Removing a data.
// InFront() => Return the element at the front without removing it.
// size() => number of element present in the queue.
// isEmpty()

// Implementing Queue using an array
#include <iostream>
using namespace std;
class Queue
{
private:
    int *arr;
    int size;
    int head;
    int rear;

public:
    Queue(int size)
    {
        arr = new int[size];
        this->size = size;
        head = -1;
        rear = -1;
    }
    bool isEmpty();
    bool enqueue(int data);
    int dequeue();
    int front();
    void display();
};

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
    else
    {
        cout << "Queue is overflowed" << endl;
        return false;
    }
}
bool Queue ::isEmpty()
{
    if ((head == -1) && (rear == -1))
    {
        return true;
    }
    else if (rear == size - 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int Queue ::dequeue()
{
    if ((head == -1) && (rear == -1))
    {
        return -1;
    }
    else
    {
        int ans = arr[head];
        head++;
        if (head == rear)
        {
            head = -1;
            rear = -1;
        }
        return ans;
    }
}
int Queue ::front()
{
    if ((head == -1) && (rear == -1))
    {
        return -1;
    }
    else
    {
        return arr[head];
    }
}

void Queue ::display()
{
    for (int i = head; i < rear; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
int main(void)
{
    Queue q(10);
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    q.enqueue(25);
    q.enqueue(30);
    cout << "Elements of the queue are => " << endl;
    q.display();
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.front() << endl;
    cout << "Elements of the queue are => " << endl;
    q.display();
    return 0;
}
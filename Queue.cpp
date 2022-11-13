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
// Implement Queue using an array
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
    else if (rear == size - 1)
    {
        return false;
    }
    else
    {
        return true;
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
    else
    {
        cout << "Queue is overflowed" << endl;
        return false;
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
    for (int i = head; i <= rear; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
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
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << "Elements of the Queue after removing element => " << endl;
    q.display();
    cout << q.front() << endl;
    q.enqueue(35);
    q.enqueue(40);
    return 0;
}
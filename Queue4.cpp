// Implementing Queue using linked list
// Implement Queue using linked list
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
};
class Queue
{
private:
    Node *new_node;
    Node *head;
    Node *rear;

public:
    Queue()
    {
        head = rear = NULL;
    }
    bool isEmpty();
    bool enqueue(int data);
    int dequeue();
    int front();
    void display();
};
bool Queue ::isEmpty()
{
    if ((rear == NULL) && (head == NULL))
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
    new_node = new Node();
    Node *temp;
    if (!new_node)
    {
        cout << "Something going on wrong" << endl;
        return false;
    }
    else
    {
        new_node->data = data;
        if ((rear == NULL) && (head == NULL))
        {

            head = rear = new_node;
            rear->next = head;
            return true;
        }
        else
        {
            rear->next = new_node;
            rear = new_node;
            rear->next = head;
            return true;
        }
    }
}
int Queue ::dequeue()
{
    if ((rear == NULL) && (head == NULL))
    {
        return -1;
    }
    else
    {
        Node *temp = head;
        int ans = head->data;
        head = head->next;
        rear->next = head;
        free(temp);
        return ans;
    }
}
int Queue ::front()
{
    if ((rear == NULL) && (head == NULL))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        return head->data;
    }
}
void Queue ::display()
{
    Node *temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data << "\t";
    cout << endl;
}
int main(void)
{
    Queue q;
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
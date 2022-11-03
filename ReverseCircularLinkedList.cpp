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
class linked_list
{
private:
    Node *head, *temp, *tail, *new_node;

public:
    linked_list()
    {
        head = NULL;
    }
    void create_list();
    void display_list();
    void reverse_list();
};
void linked_list::create_list()
{
    int choice = 1;
    while (choice)
    {
        new_node = new Node();
        cout << "Enter the element of the linked list " << endl;
        cin >> new_node->data;
        if (head == NULL)
        {
            head = temp = tail = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
            tail = temp;
        }
        tail->next = head;
        cout << "Do you want to continue (0,1) : " << endl;
        cin >> choice;
    }
}
void linked_list ::reverse_list()
{
    Node *next_node;
    temp  = head;
    while (next_node != head)
    {
        next_node = temp->next;
        temp->next = tail;
        tail = temp;
        temp = next_node;
    }
    head = tail;
}
void linked_list ::display_list()
{
    temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << temp->data << endl;
}
int main(void)
{
    linked_list list;
    list.create_list();
    cout << "Elements of the linked list are => " << endl;
    list.display_list();

    list.reverse_list();
    cout << "Elements of the linked list after reversing => " << endl;
    list.display_list();
    return 0;
}
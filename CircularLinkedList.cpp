// Creation of circular linked list and display the elements
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
    void insert_at_beg();
    void insert_at_end();
    void insert_at_pos();
    void delete_at_beg();
    void delete_at_end();
    void delete_at_pos();
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

void linked_list ::insert_at_beg()
{
    int choice = 1;
    while (choice)
    {
        new_node = new Node();
        cout << "Enter the element at the beginning of the linked list " << endl;
        cin >> new_node->data;
        new_node->next = head;
        head = new_node;
        tail->next = head;
        cout << "Do you want to continue (0,1) : " << endl;
        cin >> choice;
    }
}

void linked_list ::insert_at_end()
{
    int choice = 1;
    while (choice)
    {
        new_node = new Node();
        cout << "Enter the element at the end of the linked list " << endl;
        cin >> new_node->data;
        tail->next = new_node;
        new_node->next = head;
        tail = new_node;
        cout << "Do you want to continue (0,1) : " << endl;
        cin >> choice;
    }
}

void linked_list ::insert_at_pos()
{
    int position, i = 1;
    temp = head;
    cout << "Enter the position at which you want to insert the element" << endl;
    cin >> position;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    new_node = new Node();
    cout << "Enter the element at the specific position " << endl;
    cin >> new_node->data;
    new_node->next = temp->next;
    temp->next = new_node;
}
void linked_list ::delete_at_beg()
{
    temp = head;
    head = head->next;
    tail->next = head;
    delete temp;
}
void linked_list ::delete_at_end()
{
    Node *prev_node;
    temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    prev_node = temp;
    temp = temp->next;
    prev_node->next = head;
    delete temp;
}
void linked_list ::delete_at_pos()
{
    int position, i = 1;
    Node *next_node;
    temp = head;
    cout << "Enter the position from which you want to delete the element " << endl;
    cin >> position;
    next_node = head->next;
    while (i < position - 1)
    {
        next_node = next_node->next;
        temp = temp->next;
        i++;
    }
    temp->next = next_node->next;
    delete next_node;
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

    // list.insert_at_beg();
    // cout << "Elements of the linked list after inserting an element at the beginning are => " << endl;
    // list.display_list();

    // list.insert_at_end();
    // cout << "Elements of the linked list after inserting an element at the end are => " << endl;
    // list.display_list();

    // list.insert_at_pos();
    // cout << "Elements of the linked list after inserting an element at the specific position => " << endl;
    // list.display_list();
    // list.delete_at_beg();
    // cout << "Elements of the linked list after deleting an element from the end => " << endl;
    // list.display_list();

    // list.delete_at_end();
    // cout << "Elements of the linked list after deleting an element from the end => " << endl;
    // list.display_list();

    list.delete_at_pos();
    cout << "Elements of the linked list after deleting an element from the specific position => " << endl;
    list.display_list();
    return 0;
}
// Creation of doubly linked list and display the elements
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev, *next;
    Node()
    {
        data = 0;
        prev = NULL;
        next = NULL;
    }
};
class linked_list
{
private:
    Node *head, *new_node, *tail;

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

void linked_list ::create_list()
{
    Node *temp;
    int choice = 1;
    while (choice)
    {
        new_node = new Node();
        cout << "Enter the element of the linked list => " << endl;
        cin >> new_node->data;
        if (head == NULL)
        {
            head = temp = tail = new_node;
        }
        else
        {
            temp->next = new_node;
            new_node->prev = temp;
            temp = new_node;
            tail = new_node;
        }
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
        cout << "Enter the element at the beginning of the linked list => " << endl;
        cin >> new_node->data;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
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
        cout << "Enter a element at the end of the linked list => " << endl;
        cin >> new_node->data;
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        cout << "Do you want to continue (0,1) : " << endl;
        cin >> choice;
    }
}
void linked_list ::insert_at_pos()
{
    int position, i = 1;
    Node *temp;
    temp = head;
    cout << "Enter the position at which you want to insert the element " << endl;
    cin >> position;
    while (i < position - 1)
    {
        temp = temp->next;
        i++;
    }
    new_node = new Node();
    cout << "Enter the element at the specific position " << endl;
    cin >> new_node->data;
    new_node->prev = temp;
    new_node->next = temp->next;
    temp->next->prev = new_node;
    temp->next = new_node;
}

void linked_list ::delete_at_beg()
{
    Node *temp = head;
    if (head->next == NULL)
    {
        return;
    }
    head = head->next;
    head->prev = NULL;
    delete temp;
}
void linked_list ::delete_at_end()
{
    Node *temp = tail;
    if (head->next == NULL)
    {
        return;
    }
    else
    {
        tail->prev->next = NULL;
        tail = tail->prev;
        delete temp;
    }
}
void linked_list ::delete_at_pos()
{
    int position, i = 1;
    Node *temp = head;
    cout << "Enter the position from which you want to delete the element " << endl;
    cin >> position;
    while (i < position )
    {
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
}
void linked_list ::display_list()
{
    Node *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "\t";
        temp = temp->next;
    }
    cout << endl;
}
int main(void)
{
    linked_list list;
    list.create_list();
    cout << "Element of the doubly linked list are => " << endl;
    list.display_list();

    // list.insert_at_beg();
    // cout << "Elements of list after inserting element at beginning => " << endl;
    // list.display_list();

    // list.insert_at_end();
    // cout << "Elements of list after inserting element at end => " << endl;
    // list.display_list();

    // list.insert_at_pos();
    // cout << "Elements of list after inserting element at specific position => " << endl;
    // list.display_list();

    // list.delete_at_beg();
    // cout << "Elements of list after deleting element from beginning => " << endl;
    // list.display_list();

    // list.delete_at_end();
    // cout << "Elements of list after deleting element from beginning => " << endl;
    // list.display_list();

    list.delete_at_pos();
    cout << "Elements of list after deleting element from beginning => " << endl;
    list.display_list();
    return 0;
}
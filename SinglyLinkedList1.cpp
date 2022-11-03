// Creation of the singly linked list and display the elements
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
    Node *head, *new_node, *temp;

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
    int choice;
    while (choice)
    {
        new_node = new Node();
        cout << "Enter the element of the linked list " << endl;
        cin >> new_node->data;
        if (head == NULL)
        {
            temp = head = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
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
        cout << "Enter the element at the beginning of the linked list " << endl;
        cin >> new_node->data;
        new_node->next = head;
        head = new_node;
        cout << "Do you want to continue (0,1) : " << endl;
        cin >> choice;
    }
}

void linked_list ::insert_at_pos()
{
    int position, i = 1;
    cout << "Enter the position at which you want to insert the element " << endl;
    cin >> position;
    temp = head;
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

void linked_list ::insert_at_end()
{
    int choice = 1;
    temp = head;
    while (choice)
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        new_node = new Node();
        cout << "Enter the element at the end of the linked list " << endl;
        cin >> new_node->data;
        temp->next = new_node;
        cout << "Do you want to continue (0,1) : " << endl;
        cin >> choice;
    }
}

void linked_list ::delete_at_beg()
{
    temp = head;
    head = temp->next;
    delete temp;
}
void linked_list ::delete_at_end()
{
    temp = head;
    Node *prev_node;
    while (temp->next != NULL)
    {
        prev_node = temp;
        temp = temp->next;
    }
    prev_node->next = NULL;
    delete temp;
}
void linked_list ::delete_at_pos()
{
    int position, i = 1;
    cout << "Enter the position from which you want to delete the element " << endl;
    cin >> position;
    temp = head;
    Node *prev;
    while (i < position )
    {
        prev = temp;
        temp = temp->next;
        i++;
    }
    prev->next = temp->next;
    delete temp;
}
void linked_list ::display_list()
{
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
    cout << "Element of the linked list are => " << endl;
    list.display_list();

    // list.insert_at_beg();
    // cout << "Element of the linked list after inserting element at beginning => " << endl;
    // list.display_list();

    // list.insert_at_end();
    // cout << "Element of the linked list after inserting element at end => " << endl;
    // list.display_list();

    // list.insert_at_pos();
    // cout << "Element of the linked list after inserting element at end => " << endl;
    // list.display_list();

    // list.delete_at_beg();
    // cout << "Element of the linked list after deleting element from beginning => " << endl;
    // list.display_list();

    // list.delete_at_end();
    // cout << "Element of the linked list after deleting element from end => " << endl;
    // list.display_list();
    list.delete_at_pos();
    cout << "Element of the linked list after deleting element from end => " << endl;
    list.display_list();

    return 0;
}
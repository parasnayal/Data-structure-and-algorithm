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
    Node *reverse(Node *node);
    void set_head()
    {
        Node *node = head;
        tail = head;
        head = reverse(node);
        cout << "Elements of list after reversing are => " << endl;
        display_list();
    }
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

// Reverse the linked list using iterative method
// void linked_list ::reverse_list()
// {
//     Node *temp, *next_node;
//     temp = head;
//     while (temp != NULL)
//     {
//         next_node = temp->next;
//         temp->next = temp->prev;
//         temp->prev = next_node;
//         temp = next_node;
//     }
//     temp = head;
//     head = tail;
//     tail = temp;
// }

// Reverse the linked list Recursive method

Node *linked_list ::reverse(Node *node)
{
    if (!node)
    {
        return NULL;
    }
    else
    {
        Node *temp = node->next;
        node->next = node->prev;
        node->prev = temp;

        if (!node->prev)
        {
            return node;
        }
        else
        {
            return reverse(node->prev);
        }
    }
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

    // list.reverse_list();
    // cout << "Elememts of the list after reversing are => " << endl;
    // list.display_list();

    list.set_head();
    return 0;
}
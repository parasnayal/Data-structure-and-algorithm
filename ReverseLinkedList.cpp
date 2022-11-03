// Reverse the linked using recursion and iteration method
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
    Node *head;

public:
    linked_list()
    {
        head = NULL;
    }
    void create_list();
    void display_list();
    // void reverse_list (Node **head1 , Node *cur_node , Node *prev_node);
    Node *reverse_list(Node *&head1);
    void set_head()
    {
        // Node * prev_node = NULL;
        // Node *cur_node = head;
        // reverse_list(&head , cur_node , prev_node);
        head = reverse_list(head);
        display_list();
    }
};
void linked_list ::create_list()
{
    Node *new_node, *temp;
    int choice = 1;
    while (choice)
    {
        new_node = new Node();
        cout << "Enter the element of the linked list " << endl;
        cin >> new_node->data;
        if (head == NULL)
        {
            head = temp = new_node;
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
Node *linked_list ::reverse_list(Node *&head1)
{
    if (head1 == NULL || head1->next == NULL)
    {
        return head1;
    }
    else
    {
        Node *rest = reverse_list(head1->next);
        head1->next->next = head1;
        head1->next = NULL;
        return rest;
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
    cout << "Element of the linked list are => " << endl;
    list.display_list();

    list.set_head();
    return 0;
}
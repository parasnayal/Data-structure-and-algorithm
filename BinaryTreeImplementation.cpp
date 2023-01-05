// Implementation of binary tree
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *create_binary_tree(Node *root);
int main(void)
{
    Node *root;
    root = create_binary_tree(root);
    return 0;
}
Node *create_binary_tree(Node *root)
{
    int data;
    cout << "Enter the data(-1 for no node)" << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter the data in left child node" << endl;
    root->left = create_binary_tree(root->left);
    cout << "Enter the data in right child node" << endl;
    root->right = create_binary_tree(root->right);
    return root;
}
// Infix => Is the way to write a expression
// <operand><operator><operand>
// Example => a+b

// Postfix => Reverse polish notation
// <operand><operand><operator>
// Example => ab+

// Prefix => Polish notation
// <operator><operand><operand>
// Example => +ab

#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node()
    {
        data = 0;
        prev = NULL;
    }
};
class stack
{
private:
    Node *top;

public:
    stack()
    {
        top = NULL;
    }
    bool push(int data);
    bool isEmpty();
    int pop();
    int peek();
    void display();
    bool isOperand(char ch);
    int precedence(char ch);
    string infixToPostfix(string infix);
};

bool stack ::isEmpty()
{
    if (top == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool stack ::isOperand(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int stack ::precedence(char ch)
{
    if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '^')
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

string stack ::infixToPostfix(string infix)
{
    string postfix = "";
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            postfix += infix[i];
        }
        else
        {
            if (isEmpty())
            {
                push(infix[i]);
            }
            else
            {
                if (precedence(infix[i]) > precedence(peek()))
                {
                    push(infix[i]);
                }
                else if (infix[i] == '(')
                {
                    push('(');
                }
                else if (infix[i] == ')')
                {
                    while (peek() != '(')
                    {
                        postfix += peek();
                        pop();
                    }
                    pop();
                }
                else
                {
                    while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
                    {
                        postfix += peek();
                        pop();
                    }
                    push(infix[i]);
                }
            }
        }
    }
    while (!isEmpty())
    {
        postfix += peek();
        pop();
    }
    return postfix;
}
bool stack ::push(int data)
{
    Node *temp = new Node();
    if (!temp)
    {
        cout << "Stack is underflowed" << endl;
        return false;
    }
    else
    {
        temp->data = data;
        temp->prev = top;
        top = temp;
        return true;
    }
}
int stack ::peek()
{
    if (isEmpty())
    {
        cout << "Stack is underflowed" << endl;
        return -1;
    }
    else
    {
        return top->data;
    }
}
int stack ::pop()
{
    if (isEmpty())
    {
        cout << "Stack is underflowed" << endl;
        return -1;
    }
    else
    {
        Node *temp = top;
        int element = top->data;
        top = top->prev;
        free(temp);
        return element;
    }
}
void stack ::display()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->prev;
    }
}

int main(void)
{
    stack s;
    string input = "a+b*(c^d-e)^(f+g*h)-i";

    string output = s.infixToPostfix(input);
    cout << "Postfix of input is => " << output << endl;
    // abcd^e-fgh*+^*+i-
    return 0;
}
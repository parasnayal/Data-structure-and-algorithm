// Rules for the conversion of infix to prefix expression:

// First, reverse the infix expression given in the problem.
// Scan the expression from left to right.
// Whenever the operands arrive, print them.
// If the operator arrives and the stack is found to be empty, then simply push the operator into the stack.
// If the incoming operator has higher precedence than the TOP of the stack, push the incoming operator into the stack.
// If the incoming operator has the same precedence with a TOP of the stack, push the incoming operator into the stack.
// If the incoming operator has lower precedence than the TOP of the stack, pop, and print the top of the stack. Test the incoming operator against the top of the stack again and pop the operator from the stack till it finds the operator of a lower precedence or same precedence.
// If the incoming operator has the same precedence with the top of the stack and the incoming operator is ^, then pop the top of the stack till the condition is true. If the condition is not true, push the ^ operator.
// When we reach the end of the expression, pop, and print all the operators from the top of the stack.
// If the operator is ')', then push it into the stack.
// If the operator is '(', then pop all the operators from the stack till it finds ) opening bracket in the stack.
// If the top of the stack is ')', push the operator on the stack.
// At the end, reverse the output.

#include <iostream>
#include <string>
#include <algorithm>
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
    string infixToPrefix(string infix);
    
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


string stack ::infixToPrefix(string infix)
{
    string prefix = "";
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    for (int i = 0; i < infix.length(); i++)
    {
        if (isOperand(infix[i]))
        {
            prefix += infix[i];
        }
        else
        {
            if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (!isEmpty() && peek() != '(')
                {
                    prefix += peek();
                    pop();
                }
                pop();
            }
            else
            {
                if (infix[i] == '^')
                {
                    while (!isEmpty() && precedence(infix[i]) <= precedence(peek()))
                    {
                        prefix += peek();
                        pop();
                    }
                }
                else
                {
                    while (!isEmpty() && precedence(infix[i]) < precedence(peek()))
                    {
                        prefix += peek();
                        pop();
                    }
                }
                push(infix[i]);
            }
        }
    }
    while (!isEmpty())
    {
        prefix += peek();
        pop();
    }
    reverse(prefix.begin(), prefix.end());
   
    cout<<prefix<<endl;
    return "Hello world";
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

        cout << "Iam peek" << endl;
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

    string output = s.infixToPrefix(input);
    cout << "Prefix of input is => " << input << endl;
    // abcd^e-fgh*+^*+i-
    return 0;
}
// Postfix to infix conversion using stack
#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOperand(char ch)
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
string postfixToInfix(string postfix)
{
    stack<string> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            string op(1, postfix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push('(' + op2 + postfix[i] + op1 + ')');
        }
    }
    return s.top();
}
int main(void)
{
    string exp = "ab*c+";
    cout << postfixToInfix(exp);
    return 0;
}
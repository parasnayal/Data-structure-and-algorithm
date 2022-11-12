// Evaluation of postfix expression
#include <iostream>
#include <string>
#include <stack>
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
int evaluatePostfix(string postfix)
{
    stack<int> s;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (isOperand(postfix[i]))
        {
            s.push(int(postfix[i] - '0'));
        }
        else
        {
            int opr1 = s.top();
            s.pop();
            int opr2 = s.top();
            s.pop();

            switch (postfix[i])
            {
            case '+':
                s.push(opr2 + opr1);
                break;
            case '-':
                s.push(opr2 - opr1);
                break;
            case '*':
                s.push(opr2 * opr1);
                break;
            case '/':
                s.push(opr2 / opr1);
                break;
            }
        }
    }
    return s.top();
}
int main(void)
{
    int result = evaluatePostfix("23*45+*");
    cout<<result<<endl;
    return 0;
}
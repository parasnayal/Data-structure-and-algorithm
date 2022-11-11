// Algorithm for Prefix to Infix:

// Read the Prefix expression in reverse order (from right to left)
// If the symbol is an operand, then push it onto the Stack
// If the symbol is an operator, then pop two operands from the Stack
// Create a string by concatenating the two operands and the operator between them.
// string = (operand1 + operator + operand2)
// And push the resultant string back to Stack
// Repeat the above steps until the end of Prefix expression.
// At the end stack will have only 1 string i.e resultant string
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
string prefixToInfix(string prefix)
{
    stack<string> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            string op(1, prefix[i]);
            s.push(op);
        }
        else
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op1 + prefix[i] + op2 + ")");
        }
    }
    return s.top();
}
int main(void)
{
    string exp = "*-A/BC-/AKL";
    cout << prefixToInfix(exp) << endl;
    return 0;
}
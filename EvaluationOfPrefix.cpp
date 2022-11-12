// Step 1: Put a pointer P at the end of the end
// Step 2: If character at P is an operand push it to Stack
// Step 3: If the character at P is an operator pop two
//         elements from the Stack. Operate on these elements
//         according to the operator, and push the result
//         back to the Stack
// Step 4: Decrement P by 1 and go to Step 2 as long as there
//         are characters left to be scanned in the expression.
// Step 5: The Result is stored at the top of the Stack,
//         return it
// Step 6: End

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
int evaluatePrefix(string prefix)
{
    stack<int> s;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isOperand(prefix[i]))
        {
            s.push(int(prefix[i] - '0'));
        }
        else
        {
            int opr1 = s.top();
            s.pop();
            int opr2 = s.top();
            s.pop();

            switch (prefix[i])
            {
            case '+':
                s.push(opr1 + opr2);
                break;
            case '-':
                s.push(opr1 - opr2);
                break;
            case '*':
                s.push(opr1 * opr2);
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
    string exprsn = "+9*26";
    cout << evaluatePrefix(exprsn) << endl;
    return 0;
}
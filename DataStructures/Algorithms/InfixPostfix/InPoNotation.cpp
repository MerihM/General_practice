#include <iostream>
#include <string>
// #include <cstring>
#include <stack>

using namespace std;
bool isOperator(char s)
{
    return (s == '+' || s == '-' || s == '*' || s == '/');
}

int calculate(string o1, string o2, char op)
{
    switch (op)
    {
    case '+':
        return (stoi(o1) + stoi(o2));
    case '-':
        return (stoi(o1) - stoi(o2));
    case '*':
        return (stoi(o1) * stoi(o2));
    case '/':
        return (stoi(o1) / stoi(o2));
    default:
        break;
    }
    cout << "\t" << stoi(o1) + stoi(o2) << endl;
    return 0;
}

// Get Infix for a given postfix
// expression
string getInfix(string exp)
{
    stack<string> st;
    for (int i = 0; i < exp.length(); i++)
    {
        if (!isOperator(exp[i]))
        {
            string op(1, exp[i]);
            st.push(op);
        }
        else if (isOperator(exp[i]) && st.size() >= 2)
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push(to_string(calculate(op1, op2, exp[i])));
        }
        else if (isOperator(exp[i]) && st.size() < 2)
        {
            return "ERROR";
        }
    }
    if (st.size() > 1)
        return "ERROR";
    return st.top();
}

int main()
{
    string exp = "33+3*23-+";
    cout << "When calculated, expression " << exp << " results in : " << endl;
    cout << getInfix(exp) << endl;
    return 0;
}
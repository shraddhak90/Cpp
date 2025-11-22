#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValidParenthesis(string& str)
{
    stack<char> s;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(' || str[i] == '[' || str[i] == '{')
        {
            s.push(str[i]);
        }
        else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
        {
            if (s.empty())
            {
                return false;
            }
            if ((str[i] == ')'  && s.top() != '(')
                || (str[i] == ']' && s.top() != '[')
                || (str[i] == '}' && s.top() != '{'))
            {
              return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string test1 = "()[]{}";
    string test2 = "([{}])";
    string test3 = "([)]";
    string test4 = "";
    string test5 = "(";

    cout << "Testing valid parentheses function:\n";
    cout << "\"" << test1 << "\" -> " << (isValidParenthesis(test1) ? "Valid" : "Invalid") << "\n";
    cout << "\"" << test2 << "\" -> " << (isValidParenthesis(test2) ? "Valid" : "Invalid") << "\n";
    cout << "\"" << test3 << "\" -> " << (isValidParenthesis(test3) ? "Valid" : "Invalid") << "\n";
    cout << "\"" << test4 << "\" -> " << (isValidParenthesis(test4) ? "Valid" : "Invalid") << "\n";
    cout << "\"" << test5 << "\" -> " << (isValidParenthesis(test5) ? "Valid" : "Invalid") << "\n";

    return 0;
}
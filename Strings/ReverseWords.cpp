#include <iostream>
#include <stack>
#include <string> 
using namespace std;

string reverseWords(string str)
{
    stack<string> stk;
    string temp="";

    for (int i =0; i< str.size(); i++)
    {
        if (str[i] == ' ')
        {
            stk.push(temp);
            temp = "";
        }
        else
        {
            temp+= str[i];
        }
    }
    stk.push(temp);

    string result = "";
    while (!stk.empty())
    {
        result += stk.top();
        stk.pop();
        result = result + " ";
    }
    return result;
}

//str =  We are family of five people
int main()
{
    string sentence = "We are family of five people";

    cout <<reverseWords(sentence)<<endl;

    return 0;
}
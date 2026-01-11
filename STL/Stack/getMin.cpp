#include <iostream>
#include <stack>
using namespace std;

class SpecialStack
{
    private:
    stack<int> stk;
    stack<int> minStack;

    public:
    void push(int x)
    {
        stk.push(x);

        if (minStack.empty() || x < minStack.top())
        {
            minStack.push(x);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        if (stk.empty())
        {
            return;
        }
        stk.pop();
        minStack.pop();
    }

    int getMin()
    {
        if (minStack.empty())
        {
            return -1;
        }
        return minStack.top();
    }
};

int main()
{
    SpecialStack s;
    s.push(6);
    s.push(3);
    s.push(10);

    cout << "Minimum of Stack: " << s.getMin() << endl;

    s.push(1);
    cout << "Minimum of Stack: " << s.getMin() << endl;
    s.push(2);
    s.pop();
    cout << "Minimum of Stack: " << s.getMin() << endl;
    s.pop();
    cout << "Minimum of Stack: " << s.getMin() << endl;
    return 0;
}
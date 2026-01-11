#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack
{
  private:
  stack<int> s1, s2;

  public:

  void enqueue(int d)
  {
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }

    s1.push(d);

    while(!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
  }

  void dequeue()
  {
    if (s1.empty())
    {
        cout<<"queue empty"<<endl;
        return;
    }
    s1.pop();
  }

  int getfront()
  {
    if (!s1.empty())
    {
        return s1.top();
    }
    return -1;
  }
};

int main()
{
    QueueUsingStack q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    std::cout << "Front element: "<<q.getfront()<<std::endl;

    //q.remove();
    q.dequeue();

    std::cout << "Front element: "<<q.getfront()<<std::endl;
    q.dequeue();

    std::cout << "Front element: "<<q.getfront()<<std::endl;
    q.dequeue();
    std::cout << "Front element: "<<q.getfront()<<std::endl;
    return 0;
}
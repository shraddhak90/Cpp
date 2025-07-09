#include <iostream>

class Node
{
  private:
  Node* next;
  Node* prev;
  int data;

  public:
  void setData(int d)
  {
    data = d;
  }

  void setNext(Node* n)
  {
    next = n;
  }

  void setPrev(Node* p)
  {
    prev = p;
  }

  int getData()
  {
    return data;
  }

  Node* getNext()
  {
    return next;
  }

  Node* getPrev()
  {
    return prev;
  }
};
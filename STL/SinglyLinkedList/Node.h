#include <iostream>

class Node
{
    Node* next;
    int data;

public:
  Node()
  {
    next = nullptr;
    data = 0;
  }

  Node( int d)
  {
    next = nullptr;
    data =d;
  }

  void setNext(Node* n)
  {
    next = n;
  }

  void setData(int d)
  {
    data = d;
  }

  Node* getNext()
  {
    return next;
  }

  int getData()
  {
    return data;
  }

};
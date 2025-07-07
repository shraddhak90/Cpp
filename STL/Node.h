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
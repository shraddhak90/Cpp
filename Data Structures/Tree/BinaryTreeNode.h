#include <iostream>

class Node
{
  public:
    int data;
    Node* left;
    Node* right;

  Node(int item)
  {
    data = item;
    left = nullptr;
    right = nullptr;
  }
};